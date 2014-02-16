/**
 * @file    sonar.h
 * @brief   Ultrasonic rangefinder SRF04 and SRF05
 */

#pragma once

// TODO: Make a sonar struct to use multiple sonars

#include "yamato.h"

#define SONAR_SRF05 TRUE
#define SONAR_SRF04 FALSE

#define US_TO_CM(microseconds) microseconds / 58.0

#if SONAR_SRF05
    /* SRF05 4M range */
    #define SONAR_MAX_RANGE_US 25 * 1000
#elif SONAR_SRF04
    /* SRF04 3M range */
    #define SONAR_MAX_RANGE_US 20 * 1000
#endif

#define SONAR_MAX_RANGE_CM US_TO_CM(SONAR_MAX_RANGE_US)

typedef enum {
    SONAR_INIT    = 0, /**< Initial state       */
    SONAR_READY   = 1, /**< Ready for reading   */
    SONAR_BUSY    = 2  /**< Detecting proximity */
} sonar_state_t;

unsigned long sonarLastDistance(void);
void sonarInit(void);