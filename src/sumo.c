#include "sumo.h"

static sumo_state_t sumoState = SUMO_INIT;

static WORKING_AREA(waSumoThread, 128);
static msg_t SumoThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("sumo");

    sumoState = SUMO_SLEEP;

    while (TRUE) {
        chThdSleepMilliseconds(1000);
    }

    return 1;
}

void sumoStart(void) {
    chThdCreateStatic(waSumoThread, sizeof(waSumoThread), NORMALPRIO, SumoThread, NULL);
}