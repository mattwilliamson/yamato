#ifndef _IR_H_
#define _IR_H_

#include "ch.h"
#include "hal.h"

#include "yamato.h"

extern PWMConfig pwmSharedConfig;
extern EXTConfig extSharedConfig;

#define PWM_SHARED_IR_CHANNEL 1
#define IR_DUTY_CYCLE 5000
#define IR_LED_COUNT sizeof(irLeds) / sizeof(ir_t)
#define IR_RX_COUNT sizeof(irRxs) / sizeof(ir_t)
#define IR_LED_BURST_MS 20

typedef struct {
    ioportid_t    port;
    uint16_t      pad;
} ir_t;

typedef uint8_t ir_index_t;

void irInit(void);

#endif