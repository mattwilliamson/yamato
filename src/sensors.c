#include "sensors.h"

EventSource esSensorEvents;

static WORKING_AREA(waSensorThread, 128);
static msg_t SensorThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("sensors");

    ir_index_t i;
    ir_angle_t angle;
    EventListener el;

    chEvtRegisterMask(&esSensorEvents, &el, SENSOR_EVENT_SONAR_END |\
                                            SENSOR_EVENT_IR_END);

    while(!chThdShouldTerminate()) {
        // /* Start sensors and wait for their events to come back */
        // chEvtBroadcastFlags(&esSensorEvents, SENSOR_EVENT_SONAR_START | \
        //                                      SENSOR_EVENT_IR_START);
        // chThdSleepMilliseconds(30);
        // chEvtWaitAll(SENSOR_EVENT_SONAR_START | SENSOR_EVENT_IR_START);

        // for (i = 0; i < IR_RX_COUNT; i++) {
        //     angle = irDetections[i];

        //     if (angle > 0) {
        //         // I see the enemy. BONSAIIIII!!!!
        //     }
        // }

        chThdSleepMilliseconds(30);
    }

    chEvtUnregister(&esSensorEvents, &el);

    return 0;
}

void sensorsInit(void)
{
    /* Event Source for sensor events */
    chEvtInit(&esSensorEvents);

    /* Start up ultrasonic rangefinder */
    sonarInit();

    /* IR prximity sensors */
    irInit();

    /* Photoresistor/LDR black/white line detector */
    lineInit();

    /* Sensor reading thread */
    chThdCreateStatic(waSensorThread, sizeof(waSensorThread), NORMALPRIO, SensorThread, NULL);
}