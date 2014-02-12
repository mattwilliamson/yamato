#ifndef _IR_H_
#define _IR_H_

#include "ch.h"
#include "hal.h"

#include "yamato.h"

#define IR_FREQUENCY 38000

typedef struct {
    ioportid_t    port;
    uint16_t      pad;
} ir_led_t;

typedef uint8_t ir_index_t;

void irLedsInit(void);

void pwmCbPeriodIrLedClear(PWMDriver *pwmp);
void pwmCbActiveIrLedPulse(PWMDriver *pwmp);

#endif