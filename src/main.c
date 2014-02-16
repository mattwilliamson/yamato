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
#include "sensors.h"
#include "telemetry.h"

#if YAMATO_MODE == YAMATO_MODE_SUMO
    #include "sumo.h"
#elif YAMATO_MODE == YAMATO_MODE_AVOIDANCE
    #error "YAMATO_MODE_AVOIDANCE not yet implemented"
#else
    #error "No YAMATO_MODE set"
#endif


/* 
We will use PWM3 (TIM3) for both the IR LEDs and the motors.
The motors only need 2 PWM lines and the IR will use the callback
to blink LEDs in a rotating fashion.
*/
PWMConfig pwmSharedConfig = {
    PWM_FREQUENCY,
    10000,
    NULL,
    {
        // Dfaults
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL},
        {PWM_OUTPUT_DISABLED, NULL}
    },
    0,
    0
};

/*
External interrupt callbacks
Currently just used for IR receivers.
*/
EXTConfig extSharedConfig = {
  {
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL}
  }
};

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

    /* Start serial shell */
    telemetryInit();

    /* Set up sensors */
    sensorsInit();

    /* Motors */
    motorsInit();

    /* Start PWM Driver shared by motors and IR LEDs */
    pwmStart(&PWM_SHARED, &pwmSharedConfig);

    /* Start EXT Driver used by IR receivers */
    extStart(&EXTD1, &extSharedConfig);

    /* Start the high level logic */
    #if YAMATO_MODE == YAMATO_MODE_SUMO
        sumoStart();
    #endif

    /*
     * Normal main() thread activity, in this demo it does nothing except
     * sleeping in a loop and check the button state, when the button is
     * pressed the test procedure is launched with output on the serial
     * driver 1.
     */

    while (TRUE) {
        chThdSleepMilliseconds(1000);
    }

    return 1;
}


