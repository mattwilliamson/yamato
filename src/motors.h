#pragma once

#include "yamato.h"

extern PWMConfig pwmSharedConfig;

typedef struct {
	PWMDriver     *pwm_driver;
	pwmchannel_t  pwm_channel;
    uint16_t      pwm_afun;
    ioportid_t    enable_port;
    uint16_t      enable_pad;
    ioportid_t    fwd_port;
    uint16_t      fwd_pad;
    ioportid_t    rev_port;
    uint16_t      rev_pad;
} motor_t;

typedef uint8_t motor_index_t;
typedef uint8_t motor_speed_t;
typedef enum {
    motor_forward   = 4,
    motor_reverse   = 8,
    motor_stop      = 16
} motor_direction_t;

#define MOTOR_COUNT sizeof(motors) / sizeof(motor_t)

#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1

void motorsInit(void);
void setMotor(uint8_t motor, motor_direction_t direction, motor_speed_t speed);
