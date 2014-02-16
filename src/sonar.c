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
    chSysLockFromIsr();
    sonarState = SONAR_READY;
    lastPulseWidth = icuGetWidth(icup);
    chEvtBroadcastFlagsI(&esSensorEvents, sensor_event_sonar_pong);
    icuDisable(&ICUD1);
    icuStop(&ICUD1);
    chSysUnlockFromIsr();
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
 * @details Starts ping when it receives the @p sensor_event_sonar_ping 
 * from the @p esSensorEvents @p EventSource and upon calulation of distance, 
 * broadcasts @p sensor_event_sonar_pong to the @p esSensorEvents 
 * @p EventSource.
 */
static WORKING_AREA(waSonarThread, 128);
static msg_t SonarThread(void *arg)
{
    (void)arg;

    EventListener el;
    chRegSetThreadName("sonar");
    chEvtRegisterMask(&esSensorEvents , &el , sensor_event_sonar_ping);

    while(TRUE) {
        // Wait for the event to start pinging
        chEvtWaitOne(sensor_event_sonar_ping);

        if(sonarState != SONAR_BUSY) {
            sonarState = SONAR_BUSY;
            palSetPadMode(GPIOA, GPIOA_PIN11, PAL_MODE_OUTPUT_PUSHPULL);
            palSetPadMode(GPIOA, GPIOA_PIN8, PAL_MODE_ALTERNATE(2));

            // Trigger, min. 10us minimum for HC-SRF05
            palSetPad(GPIOA, GPIOA_PIN11);
            chThdSleepMicroseconds(20);
            palClearPad(GPIOA, GPIOA_PIN11);

            // Read how long the line is high
            icuStart(&SONAR_ICU, &icucfg);
            icuEnable(&SONAR_ICU);
        }
    }

    return 1;
}

void sonarStartPing(void)
{
    chEvtBroadcastFlags(&esSensorEvents, sensor_event_sonar_ping);
}

void sonarStartPingI(void)
{
    chEvtBroadcastFlagsI(&esSensorEvents, sensor_event_sonar_ping);
}

void sonarInit(void)
{
    chThdCreateStatic(waSonarThread, sizeof(waSonarThread), NORMALPRIO, SonarThread, NULL);
}
