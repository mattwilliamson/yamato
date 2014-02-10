#ifndef _IR_H_
#define _IR_H_

#include "ch.h"
#include "hal.h"

#include "yamato.h"

#define IR_FREQUENCY 38000

typedef struct {
    PWMDriver     *pwm_driver;
    pwmchannel_t  pwm_channel;
    uint16_t      pwm_afun;
    ioportid_t    port;
    uint16_t      pad;
} ir_led_t;

typedef uint8_t ir_index_t;

void irLedsInit(void);

#endif