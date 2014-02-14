#ifndef _MOTORS_H_
#define _MOTORS_H_

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
typedef uint8_t motor_direction_t;
typedef uint8_t motor_speed_t;

#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1

#define MOTOR_DIR_FORWARD 4
#define MOTOR_DIR_REVERSE 8
#define MOTOR_DIR_STOP 16

void motorsInit(void);
void setMotor(uint8_t motor, motor_direction_t direction, motor_speed_t speed);

#endif