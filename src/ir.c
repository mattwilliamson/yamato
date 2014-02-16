#include "ir.h"

static ir_t const irLeds[] = {
    {GPIOC, GPIOC_LED4, -15 * 100},
    {GPIOC, GPIOC_LED3,  15 * 100}
    // {GPIOA, GPIOA_PIN3}
};

static ir_t const irRxs[] = {
    /* PC2, 3, 4, 5 */
    {IR_RX_PORT, 2,  -45 * 100},
    {IR_RX_PORT, 3,   45 * 100},
    {IR_RX_PORT, 4,  135 * 100},
    {IR_RX_PORT, 5, -135 * 100}
};

static ir_index_t currentLedIndex = 0;
static ir_t currentLed;

/* Keep track of IR RX oscillations */
static uint16_t irRxHits[IR_RX_COUNT] = {0};

/* Map IR RX channel to index */
static uint8_t irRxChannelMap[EXT_MAX_CHANNELS] = {0};

/* Angles detected */
ir_angle_t irDetections[IR_RX_COUNT] = {0};

/* Called when the PWM period is reached */
static void pwmCbPeriodIrLedClear(PWMDriver *pwmp)
{
    (void)pwmp;

    // Turn off LED
    palSetPad(currentLed.port, currentLed.pad);
    // palSetPad(GPIOC, GPIOC_LED4);
}

/* Called when the PWM is active */
static void pwmCbActiveIrLedPulse(PWMDriver *pwmp)
{
    (void)pwmp;

    // Turn on LED
    palClearPad(currentLed.port, currentLed.pad);
    // palClearPad(GPIOC, GPIOC_LED4);
}

/* Turn an LED on or off */
static void setIrLed(ir_index_t irLed, uint16_t dutyCycle)
{
    if (irLed < IR_LED_COUNT) {
        palClearPad(currentLed.port, currentLed.pad);
        currentLedIndex = irLed;
        currentLed = irLeds[irLed];

        pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, dutyCycle));
    }
}

/* Simple thread that loops and rotates which LED is on */
static WORKING_AREA(waLedThread, 128);
static msg_t LedThread(void *arg)
{
    (void)arg;

    EventListener el;
    ir_index_t i, j;
    ir_angle_t total;
    uint16_t divisor, totalDivisor;

    chRegSetThreadName("blinkleds");
    chEvtRegisterMask(&esSensorEvents, &el, sensor_event_ir_start);

    while (TRUE) {
        // Wait for event to start
        chEvtWaitOne(sensor_event_ir_start);

        // Rotate amongst them, so we don't burn up the LEDs
        for (i = 0; i < IR_LED_COUNT; i++) {
            total           = 0;
            divisor         = 0;
            totalDivisor    = 0;

            // Turn on LED for a bit
            setIrLed(i, IR_DUTY_CYCLE);
            chThdSleepMilliseconds(IR_LED_BURST_MS);
            setIrLed(i, 0);

            // Average out for now, kalman filter later
            // Weight is based on the square root of the variance
            for (j = 0; j < IR_RX_COUNT; j++) {
                if (IR_DETECTED(irRxHits[j])) {
                    // RX
                    divisor = sqrt(360 * 100 / IR_RX_VARIANCE);
                    totalDivisor += divisor;
                    total += irRxs[j].angle * divisor;

                    // TX
                    divisor = sqrt(360 * 100 / IR_LED_VARIANCE);
                    totalDivisor += divisor;
                    total += irLeds[j].angle * divisor;
                }

                // Save the detection
                irDetections[i] = (total / divisor) % 360 * 100;

                // Reset counter
                irRxHits[j] = 0;
            }
        }

        // Broadcast that reading is  ready
        chEvtBroadcastFlagsI(&esSensorEvents, sensor_event_ir_done);
    }

    return 1;
}

/* Sets up PWM for the IR LEDs */
void irLedsInit(void)
{
    // Turn off all LEDs
    ir_index_t i;

    for (i = 0; i < IR_LED_COUNT; i++) {
        setIrLed(i, 0);
    }

    // Get the global shared PWM
    PWMChannelConfig *channelConfig = &pwmSharedConfig.channels[PWM_SHARED_IR_CHANNEL];

    // Set channel mode for PWM
    channelConfig->mode = PWM_OUTPUT_ACTIVE_HIGH;

    // Set active callback
    channelConfig->callback = pwmCbActiveIrLedPulse;

    // Set period callback
    pwmSharedConfig.callback = pwmCbPeriodIrLedClear;

    // Set PWM period to 38kHz
    pwmSharedConfig.period = PWM_FREQUENCY / IR_FREQUENCY;

    // Enabled PWM channel at 50% duty cycle
    pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, 5000));

    // Start rotator thread
    chThdCreateStatic(waLedThread, sizeof(waLedThread), NORMALPRIO, LedThread, NULL);
}

/* Called when the IR RX signal pin goes low */
static void extCbIrLedSignal(EXTDriver *extp, expchannel_t channel)
{
    (void)extp;

    // Signal went low, IR detected
    ir_index_t i = irRxChannelMap[channel];

    if (irRxHits[i] < 0xFFFF) {
        irRxHits[i]++;
    }
}

/* Add callbacks for each IR RX pin */
void irRxsInit(void)
{
    ir_index_t i;

    for (i = 0; i < IR_RX_COUNT; i++) {
        ir_t rx = irRxs[i];
        EXTChannelConfig *extCfg = &extSharedConfig.channels[rx.pad];

        // Set callback and mode for pin
        extCfg->mode = IR_RX_EXT_MODE;
        extCfg->cb = extCbIrLedSignal;

        // Keep track of which RX is on which channel
        irRxChannelMap[rx.pad] = i;
    }
}

/* Initialize IR LEDs and receivers */
void irInit(void)
{
    irLedsInit();
    irRxsInit();
}