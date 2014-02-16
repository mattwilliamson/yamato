#include "sensors.h"

EventSource esSensorEvents;

static WORKING_AREA(waSensorThread, 128);
static msg_t SensorThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("sensors");
    ir_index_t i;
    ir_angle_t angle;

    while (TRUE) {
        /* Start sensors and wait for their events to come back */
        chEvtBroadcastFlags(&esSensorEvents, sensor_event_sonar_ping | \
                                             sensor_event_ir_start);
        chThdSleepMilliseconds(30);
        chEvtWaitAll(sensor_event_sonar_ping | sensor_event_ir_start);

        for (i = 0; i < IR_RX_COUNT; i++) {
            angle = irDetections[i];

            if (angle > 0) {
                // I see the enemy. BONSAIIIII!!!!
            }
        }
    }

    return 1;
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