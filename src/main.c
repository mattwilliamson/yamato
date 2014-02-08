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

    // LEDs for debugging and such
    palSetPadMode(GPIOC, GPIOC_LED3, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, GPIOC_LED4, PAL_MODE_OUTPUT_PUSHPULL);

    telemetryInit();
    sonarInit();
    motorsInit();
    irLedsInit();
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


