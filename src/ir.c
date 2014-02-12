#include "ir.h"

ir_led_t const irLeds[] = {
    /* PA3 TIM2_CH4 AF2 */
    {GPIOA, GPIOA_PIN3}
};

const uint8_t irLedCount = sizeof(irLeds) / sizeof(ir_led_t);

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

void pwmCbPeriodIrLedClear(PWMDriver *pwmp) {
  (void)pwmp;

  palClearPad(GPIOC, GPIOC_LED4);
  palClearPad(GPIOC, GPIOC_LED3);
}

void pwmCbActiveIrLedPulse(PWMDriver *pwmp) {
  (void)pwmp;
  // Blue
  palSetPad(GPIOC, GPIOC_LED4);
}

void setIrLed(ir_index_t irLed, bool enabled) {
    // ir_led_t led = irLeds[irLed];

    if(enabled) {
        pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, 5000));
    } else {
        pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, 0));
    }
}

static WORKING_AREA(waLedThread, 128);
static msg_t LedThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("blinkleds");
    ir_index_t i;

    while (TRUE) {
        // Rotate amongst them, so we don't burn up the LEDs
        for (i = 0; i < irLedCount; ++i) {
            setIrLed(i, true);
            chThdSleepMilliseconds(20);
            setIrLed(i, false);
        }

        // Sleep after the loop, since we can switch to the next immediately
        chThdSleepMilliseconds(20);
    }

    return 0;
}

void irLedsInit(void)
{
    // Set all pins for irLeds to output and initialize LOW
    uint8_t i;

    for (i=0; i < irLedCount; i++) {
        // ir_led_t led = irLeds[i];

        // Setup pin as PWM
        // palSetPadMode(led.port, led.pad, PAL_MODE_ALTERNATE(led.pwm_afun));

        // Set pulse width to 0 initially
        pwmEnableChannel(&PWM_SHARED, PWM_SHARED_IR_CHANNEL, PWM_PERCENTAGE_TO_WIDTH(&PWM_SHARED, 5000));

    }

    chThdCreateStatic(waLedThread, sizeof(waLedThread), NORMALPRIO, LedThread, NULL);
}

