/**
 * @file    sonar.c
 * @brief   Ultrasonic rangefinder SRF04 and SRF05
 */

#include "sonar.h"

static sonar_state_t sonarState = SONAR_INIT;
static icucnt_t lastPulseWidth;

/**
 * @brief Input Capture Unit callback
 * @details Read how long it takes for the Sonar to echo back a ping
 * 
 * @param icup ICU driver callback was setup with
 */
static void icuCbPulseWidth(ICUDriver *icup)
{
    chprintf(TELEMETRY_STREAM, "Sd\n");
    sonarState = SONAR_READY;
    lastPulseWidth = icuGetWidth(icup);
    chEvtBroadcastFlagsI(&esSensorEvents, SENSOR_EVENT_SONAR_END);
    icuDisable(&ICUD1);
    icuStop(&ICUD1);
}

/**
 * @brief Input Capture Unit configuration
 */
ICUConfig icucfg = {
    ICU_INPUT_ACTIVE_HIGH,
    1000000,
    icuCbPulseWidth,
    NULL, // icuCbPeriod,
    NULL, // icuCbOverflow,
    ICU_CHANNEL_1,
    0
};

/**
 * @brief Gets the last distance detected.
 * @return Distance in CM or 0 if not detected.
 */
unsigned long sonarLastDistance(void)
{
    if (lastPulseWidth > SONAR_MAX_RANGE_US) {
        return US_TO_CM(lastPulseWidth);
    } else {
        /* Nothing detected */
        return 0;
    }
}


/**
 * @brief Starts sonar ping to measure distance.
 * @details Starts ping when it receives the @p SENSOR_EVENT_SONAR_START 
 * from the @p esSensorEvents @p EventSource and upon calulation of distance, 
 * broadcasts @p SENSOR_EVENT_SONAR_END to the @p esSensorEvents 
 * @p EventSource.
 */
static WORKING_AREA(waSonarThread, 128);
static msg_t SonarThread(void *arg)
{
    (void)arg;

    // EventListener el;
    // chRegSetThreadName("sonar");
    // chEvtRegisterMask(&esSensorEvents , &el, SENSOR_EVENT_SONAR_START);

    // while(!chThdShouldTerminate()) {
    //     // Wait for the event to start pinging
    //     chprintf(TELEMETRY_STREAM, "SW\r\n");
    //     eventmask_t em = chEvtWaitOne(SENSOR_EVENT_SONAR_START);
    //     chThdSleepMilliseconds(500);
    //     chprintf(TELEMETRY_STREAM, "Sonar got event %D\r\n", em);

    //     if(sonarState != SONAR_BUSY) {
    //         sonarState = SONAR_BUSY;
    //         chprintf(TELEMETRY_STREAM, "Sp\n");
    //         palSetPadMode(GPIOA, GPIOA_PIN11, PAL_MODE_OUTPUT_PUSHPULL);
    //         palSetPadMode(GPIOA, GPIOA_PIN8, PAL_MODE_ALTERNATE(2));

    //         // Trigger, min. 10us minimum for HC-SRF05
    //         palSetPad(GPIOA, GPIOA_PIN11);
    //         chThdSleepMicroseconds(20);
    //         palClearPad(GPIOA, GPIOA_PIN11);

    //         // Read how long the line is high
    //         icuStart(&SONAR_ICU, &icucfg);
    //         icuEnable(&SONAR_ICU);
    //     }

    //     // This is for testing
    //     chThdSleepMilliseconds(1000);
    // }

    // chEvtUnregister(&esSensorEvents, &el);

    chThdSleepMilliseconds(1000);

    return 0;
}

void sonarStartPing(void)
{
    chEvtBroadcastFlags(&esSensorEvents, SENSOR_EVENT_SONAR_START);
}

void sonarStartPingI(void)
{
    chEvtBroadcastFlagsI(&esSensorEvents, SENSOR_EVENT_SONAR_START);
}

void sonarInit(void)
{
    chThdCreateStatic(waSonarThread, sizeof(waSonarThread), NORMALPRIO, SonarThread, NULL);
}
