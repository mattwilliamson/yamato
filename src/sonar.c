#include "sonar.h"

volatile icucnt_t lastPulseWidth, last_period;
volatile unsigned long distance;

// ICU to read how long it takes for the Sonar to echo

static void icuCbPulseWidth(ICUDriver *icup)
{
    lastPulseWidth = icuGetWidth(icup);
    distance = US_TO_CM(lastPulseWidth);
    // chprintf(TELEMETRY_STREAM, "Pong: %D\r\n", distance);
    icuDisable(&ICUD1);
    icuStop(&ICUD1);
}

// static void icuCbPeriod(ICUDriver *icup)
// {
//     last_period = icuGetPeriod(icup);
// }

// static void icuCbOverflow(ICUDriver *icup)
// {
//     (void)icup;
// }

static WORKING_AREA(waSonarThread, 128);
static msg_t SonarThread(void *arg)
{

    (void)arg;
    chRegSetThreadName("sonar");

    // Input Capture Unit - read pulse in
    ICUConfig icucfg = {
        ICU_INPUT_ACTIVE_HIGH,
        1000000,
        icuCbPulseWidth,
        NULL, // icuCbPeriod,
        NULL, // icuCbOverflow,
        ICU_CHANNEL_1,
        0
    };

    palSetPadMode(GPIOA, GPIOA_PIN11, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, GPIOA_PIN8, PAL_MODE_ALTERNATE(2));

    while (TRUE) {
        // Trigger, min. 10us minimum for HC-SRF05
        palSetPad(GPIOA, GPIOA_PIN11);
        chThdSleepMicroseconds(20);
        palClearPad(GPIOA, GPIOA_PIN11);

        // Read how long the line is high
        icuStart(&SONAR_ICU, &icucfg);
        icuEnable(&SONAR_ICU);

        chThdSleepMilliseconds(2000);
    }

    return 0;
}

unsigned long sonarLastDistance(void)
{
    return distance;
}

void sonarInit(void)
{
    chThdCreateStatic(waSonarThread, sizeof(waSonarThread), NORMALPRIO, SonarThread, NULL);
}
