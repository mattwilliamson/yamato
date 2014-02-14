#include "ir.h"

ir_t const irLeds[] = {
    {GPIOC, GPIOC_LED4},
    {GPIOC, GPIOC_LED3}
    // {GPIOA, GPIOA_PIN3}
};

ir_t const irRxs[] = {
    /* PC2, 3, 4, 5 */
    {IR_RX_PORT, 2},
    {IR_RX_PORT, 3},
    {IR_RX_PORT, 4},
    {IR_RX_PORT, 5}
};

const uint8_t irLedCount = IR_LED_COUNT;
const uint8_t irRxCount = IR_RX_COUNT;

ir_index_t currentLedIndex = 0;
ir_t currentLed;

/* Keep track of IR RX oscillations */
uint16_t irRxHits[IR_RX_COUNT] = {0};

/* Map IR RX channel to index */
uint8_t irRxChannelMap[EXT_MAX_CHANNELS] = {0};


/*

_|        V        L
  .---------------.
  |R      T      R|
  |               |
  |               |
 >|T             T|<
  |               |
  |               |
  |R      T      R|
_ '---------------' _
 |        ^        |

*/

static void pwmCbPeriodIrLedClear(PWMDriver *pwmp)
{
    (void)pwmp;

    // Turn off LED
    palSetPad(currentLed.port, currentLed.pad);
    // palSetPad(GPIOC, GPIOC_LED4);
}

static void pwmCbActiveIrLedPulse(PWMDriver *pwmp)
{
    (void)pwmp;

    // Turn on LED
    palClearPad(currentLed.port, currentLed.pad);
    // palClearPad(GPIOC, GPIOC_LED4);
}

void setIrLed(ir_index_t irLed, uint16_t dutyCycle)
{
    if(irLed < irLedCount) {
        palClearPad(currentLed.port, currentLed.pad);
        currentLedIndex = irLed;
        currentLed = irLeds[irLed];

        pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, dutyCycle));
    }
}

static WORKING_AREA(waLedThread, 128);
static msg_t LedThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("blinkleds");
    ir_index_t i;

    while (TRUE) {
        // Sleep after the loop, since we can switch to the next immediately
        chThdSleepMilliseconds(IR_LED_BURST_MS);

        // Rotate amongst them, so we don't burn up the LEDs
        for (i = 0; i < irLedCount; i++) {
            setIrLed(i, IR_DUTY_CYCLE);
            chThdSleepMilliseconds(IR_LED_BURST_MS);
            setIrLed(i, 0);
        }
    }

    return 0;
}

void irLedsInit(void)
{
    ir_index_t i;

    for (i = 0; i < irLedCount; i++) {
        setIrLed(i, 0);
    }

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

static void extCbIrLedSignal(EXTDriver *extp, expchannel_t channel)
{
    (void)extp;

    // Signal went low, IR detected
    ir_index_t i = irRxChannelMap[channel];

    if(irRxHits[i] < 0xFFFF) {
        irRxHits[i]++;
    }
}

void irRxsInit(void)
{
    ir_index_t i;

    for (i = 0; i < irRxCount; i++) {
        ir_t rx = irRxs[i];
        EXTChannelConfig *extCfg = &extSharedConfig.channels[rx.pad];

        // Set callback and mode for pin
        extCfg->mode = IR_RX_EXT_MODE;
        extCfg->cb = extCbIrLedSignal;

        // Keep track of which RX is on which channel
        irRxChannelMap[rx.pad] = i;
    }
}

void irInit(void)
{
    irLedsInit();
    irRxsInit();
}