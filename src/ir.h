/**
 * @file ir.h
 * @brief Infrared LEDs and receivers
 */

#pragma once

#include "yamato.h"
#include <arm_math.h>

#define PWM_SHARED_IR_CHANNEL 1

#define IR_LED_COUNT    sizeof(irLeds) / sizeof(ir_t)
#define IR_RX_COUNT     sizeof(irRxs) / sizeof(ir_t)
#define IR_DUTY_CYCLE   5000
#define IR_LED_BURST_MS 1000
#define IR_LED_VARIANCE 22
#define IR_FREQUENCY    38000
#define IR_RX_PORT      GPIOC
#define IR_RX_VARIANCE  180
#define IR_RX_EXT_MODE  EXT_CH_MODE_FALLING_EDGE    | \
                        EXT_CH_MODE_AUTOSTART       | \
                        EXT_MODE_GPIOC
#define IR_DETECTED(hits) hits > 0

typedef struct {
    ioportid_t    port;
    uint16_t      pad;
    int32_t       angle;
} ir_t;

typedef uint8_t ir_index_t;
typedef int32_t ir_angle_t;

static ir_t const irLeds[] = {
    {GPIOB, 3, -15 * 100},
    {GPIOB, 4,  15 * 100},
    {GPIOC, 9,  0},
    {GPIOC, 8,  0}
};

static ir_t const irRxs[] = {
    /* PC11, 12, 13, 14 */
    {IR_RX_PORT, 11,  -45 * 100},
    {IR_RX_PORT, 12,   45 * 100},
    {IR_RX_PORT, 13,  135 * 100},
    {IR_RX_PORT, 14, -135 * 100}
};

extern ir_angle_t irDetections[IR_RX_COUNT];

void irInit(void);

/*

_|        V        L
  .---------------.
  |R      T      R|
  |               |
  |               |
 >|T             T|<
  |               |
  |               |
  |R      T      R|
_ '---------------' _
 |        ^        |

*/