/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "chrtclib.h"

#include "yamato.h"
#include "motors.h"
#include "ir.h"
#include "sonar.h"
#include "linesensor.h"
#include "telemetry.h"


void sharedPwmInit(void) {
    /* 
    We will use PWM3 (TIM3) for both the IR LEDs and the motors.
    The motors only need 2 PWM lines and the IR will use the callback
    to blink LEDs in a rotating fashion.
    */
    static PWMConfig pwmConfig = {
        PWM_FREQUENCY,                      /* 1mHz PWM clock frequency. */
        PWM_FREQUENCY / IR_FREQUENCY,       /* 38kHz PWM period.         */
        pwmCbPeriodIrLedClear,              /* Turns current LED off     */
        {
            /* Callback to turn current LED on */
            {PWM_OUTPUT_ACTIVE_HIGH, pwmCbActiveIrLedPulse},

            /* Unassigned */
            {PWM_OUTPUT_DISABLED, NULL},

            /* Motors */
            {PWM_OUTPUT_ACTIVE_HIGH, NULL},
            {PWM_OUTPUT_ACTIVE_HIGH, NULL}
        },
        0,
        0
    };

    /* Start the driver */
    pwmStart(&PWM_SHARED, &pwmConfig);
}



/*
 * Application entry point.
 */
int main(void)
{

    /*
     * System initializations.
     * - HAL initialization, this also initializes the configured device drivers
     *     and performs the board-specific initializations.
     * - Kernel initialization, the main() function becomes a thread and the
     *     RTOS is active.
     */
    halInit();
    chSysInit();

    /* LEDs for debugging and such */
    palSetPadMode(GPIOC, GPIOC_LED3, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, GPIOC_LED4, PAL_MODE_OUTPUT_PUSHPULL);

    /* Start PWM Driver shared by motors and IR LEFDs */
    sharedPwmInit();

    /* Start serial shell */
    telemetryInit();

    /* Start up ultrasonic rangefinder */
    sonarInit();

    /* Motors */
    motorsInit();

    /* IR prximity sensors */
    irLedsInit();

    /* PHotoresistor/LDR black/white line detector */
    lineInit();

    /*
     * Normal main() thread activity, in this demo it does nothing except
     * sleeping in a loop and check the button state, when the button is
     * pressed the test procedure is launched with output on the serial
     * driver 1.
     */

    while (TRUE) {
        while (!palReadPad(GPIOA, GPIOA_BUTTON)) {
            chThdSleepMilliseconds(10);
        }

    }

}


