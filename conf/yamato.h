#ifndef _YAMATO_H_
#define _YAMATO_H_

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "chrtclib.h"

#define SONAR_ICU ICUD1

/* Sonar precision in microseconds */
#define SONAR_PRECISION 1

/* Telemetry */
#define TELEMETRY_SERIAL SD1
#define TELEMETRY_STREAM (BaseSequentialStream *)&TELEMETRY_SERIAL

/* Frequency for Motor and IR PWM */
#define PWM_FREQUENCY 1000000
#define PWM_SHARED PWMD3

#define IR_FREQUENCY 38000
#define IR_RX_PORT GPIOC
#define IR_RX_EXT_MODE EXT_CH_MODE_FALLING_EDGE | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOC


#endif