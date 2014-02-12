#ifndef _YAMATO_H_
#define _YAMATO_H_

#define SONAR_ICU ICUD1

/* Sonar precision in microseconds */
#define SONAR_PRECISION 1

/* Telemetry */
#define TELEMETRY_SERIAL SD1
#define TELEMETRY_STREAM (BaseSequentialStream *)&TELEMETRY_SERIAL

/* Frequency for Motor and IR PWM */
#define PWM_FREQUENCY 1000000
#define PWM_SHARED PWMD3
#define PWM_SHARED_IR_CHANNEL 1


#endif