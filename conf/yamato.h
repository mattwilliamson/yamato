#pragma once

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "chrtclib.h"

/* Ultrasonic rangefinder */
#define SONAR_ICU ICUD1

/* Frequency for Motor and IR PWM */
#define PWM_FREQUENCY   1000000
#define PWM_SHARED      PWMD3

/**
 * @brief Sensor event masks
 */
#define SENSOR_EVENT_LINE_CHANGE    1
#define SENSOR_EVENT_SONAR_START    2
#define SENSOR_EVENT_SONAR_END      4
#define SENSOR_EVENT_IR_START       8
#define SENSOR_EVENT_IR_END         16

/* Event source used for all sensors to notify they have a reading */
extern EventSource esSensorEvents;

/* PWM Config shared among motors and IR LEDs */
extern PWMConfig pwmSharedConfig;

/* PWM Config shared among IR RXs and potentially rotary encoders */
extern EXTConfig extSharedConfig;

/* Telemetry
 * Activates the serial driver 1 using the driver default configuration.
 * PA9 and PA10 are routed to USART1 TX and RX.
 */
#define TELEMETRY_SERIAL SD1
#define TELEMETRY_STREAM (BaseSequentialStream *)&TELEMETRY_SERIAL
#define TELEMETRY_BITRATE 38400
#define TELEMETRY_ALTERNATE_FUNCTION() \
        palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(1));  \
        palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(1));

/* Define which mode the robot will operate under:
 *  YAMATO_MODE_SUMO      Seek another bot and push out of ring avoiding edge
 *  YAMATO_MODE_AVOIDANCE Just drive around and avoid obstacles
*/
#define YAMATO_MODE_SUMO        1
#define YAMATO_MODE_AVOIDANCE   2
#define YAMATO_MODE             YAMATO_MODE_SUMO