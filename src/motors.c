#include "motors.h"

/* Motors
PB0 EVENTOUT TIM3_CH3 TIM1_CH2N TSC_G3_IO2             PWM
PC6 I/O FT TIM3_CH1 -
PB2 TSC_G3_IO4

PB1 TIM14_CH1 TIM3_CH4 TIM1_CH3N TSC_G3_IO3            PWM
PC7 I/O FT TIM3_CH2 -
PB15 

Left and right Motors
*/
static motor_t const motors[] = {
    /* Left - pwm timer 3 channel 3 */
    {
        &PWM_SHARED, 2, 1,
        GPIOB, GPIOB_PIN0, 
        GPIOC, GPIOC_PIN6, 
        GPIOB, GPIOB_PIN2
    },

    /* Right - pwm timer 3 channel 4 */
    {
        &PWM_SHARED, 3, 1, 
        GPIOB, GPIOB_PIN1, 
        GPIOB, GPIOB_PIN15, 
        GPIOC, GPIOC_PIN7
    }
};

static WORKING_AREA(waDriveThread, 128);
static msg_t DriveThread(void *arg)
{
    (void)arg;
    chRegSetThreadName("drive");

    while (TRUE) {
        chThdSleepMilliseconds(1000);
    }

    return 1;
}

void motorsInit()
{
    // Set all pins for motors to output and initialize LOW
    uint8_t i;

    for (i=0; i < MOTOR_COUNT; i++) {
        motor_t m = motors[i];

        // Setup pin as PWM
        palSetPadMode(m.enable_port, m.enable_pad, PAL_MODE_ALTERNATE(m.pwm_afun));

        // Setup pads as outputs
        palSetPadMode(m.fwd_port, m.fwd_pad, PAL_MODE_OUTPUT_PUSHPULL);
        palSetPadMode(m.rev_port, m.rev_pad, PAL_MODE_OUTPUT_PUSHPULL);

        // Set pads low
        palClearPad(m.fwd_port, m.fwd_pad);
        palClearPad(m.rev_port, m.rev_pad);

        // Set channel mode
        pwmSharedConfig.channels[m.pwm_channel].mode = PWM_OUTPUT_ACTIVE_HIGH;

        // Set pulse width to 0 initially
        pwmEnableChannel(m.pwm_driver, m.pwm_channel, PWM_PERCENTAGE_TO_WIDTH(m.pwm_driver, 0));
    }


    chThdCreateStatic(waDriveThread, sizeof(waDriveThread), NORMALPRIO, DriveThread, NULL);
}

void setMotor(motor_index_t motor, motor_direction_t direction, motor_speed_t speed) {
    if(motor >= MOTOR_COUNT) {
        return;
    }

    speed = speed > 100 ? 100 : speed;
    motor_t m = motors[motor];

    switch(direction) {
        case motor_forward:
            palSetPad(m.fwd_port, m.fwd_pad);
            palClearPad(m.rev_port, m.rev_pad);
            break;
        case motor_reverse:
            palClearPad(m.fwd_port, m.fwd_pad);
            palSetPad(m.rev_port, m.rev_pad);
            break;
        default:
            palClearPad(m.fwd_port, m.fwd_pad);
            palClearPad(m.rev_port, m.rev_pad);
            break;
    }

    pwmEnableChannel(m.pwm_driver, m.pwm_channel, PWM_PERCENTAGE_TO_WIDTH(m.pwm_driver, speed * 100));
}