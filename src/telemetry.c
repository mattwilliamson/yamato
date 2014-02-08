#include "telemetry.h"

static void cmdSonar(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void)argv;
    (void)argc;

    chprintf(chp, "Sonar Distance: %D\r\n", sonarLastDistance());
}

static void cmdLineSensor(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void)argv;
    (void)argc;

    chprintf(chp, "LINE_CHANNEL_LEFT: %D\r\n", lineAvg(LINE_CHANNEL_LEFT));
    chprintf(chp, "LINE_CHANNEL_RIGHT: %D\r\n", lineAvg(LINE_CHANNEL_RIGHT));
    chprintf(chp, "LINE_CHANNEL_TEMP: %D\r\n", lineAvg(LINE_CHANNEL_TEMP));
    chprintf(chp, "LINE_CHANNEL_VREF: %D\r\n", lineAvg(LINE_CHANNEL_VREF));
}

static void cmdMemory(BaseSequentialStream *chp, int argc, char *argv[])
{
    size_t n, size;

    (void)argv;
    if (argc > 0) {
        chprintf(chp, "Usage: mem\r\n");
        return;
    }
    n = chHeapStatus(NULL, &size);
    chprintf(chp, "core free memory : %u bytes\r\n", chCoreStatus());
    chprintf(chp, "heap fragments     : %u\r\n", n);
    chprintf(chp, "heap free total    : %u bytes\r\n", size);
}

static void cmdThreads(BaseSequentialStream *chp, int argc, char *argv[])
{
    static const char *states[] = {THD_STATE_NAMES};
    Thread *tp;

    (void)argv;
    if (argc > 0) {
        chprintf(chp, "Usage: threads\r\n");
        return;
    }
    chprintf(chp, "    addr    stack prio refs     state time\r\n");
    tp = chRegFirstThread();
    do {
        chprintf(chp, "%.8lx %.8lx %4lu %4lu %9s %lu\r\n",
                 (uint32_t)tp, (uint32_t)tp->p_ctx.r13,
                 (uint32_t)tp->p_prio, (uint32_t)(tp->p_refs - 1),
                 states[tp->p_state], (uint32_t)tp->p_time);
        tp = chRegNextThread(tp);
    } while (tp != NULL);
}

static void cmdMotor(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void)argv;

    uint8_t motor;
    motor_direction_t direction;
    motor_speed_t speed;

    if (argc > 0) {
        if (strcmp(argv[0], "on") == 0) {
            setMotor(MOTOR_LEFT, MOTOR_DIR_FORWARD, 100);
            setMotor(MOTOR_RIGHT, MOTOR_DIR_FORWARD, 100);
            return;
        } else if (strcmp(argv[0], "off") == 0) {
            setMotor(MOTOR_LEFT, MOTOR_DIR_STOP, 0);
            setMotor(MOTOR_RIGHT, MOTOR_DIR_STOP, 0);
            return;
        } else if ((argc > 1)) {
            motor = atoi(argv[0]);
            speed = 100;

            switch (argv[1][0]) {
                case 'f':
                    direction = MOTOR_DIR_FORWARD;
                    break;
                case 'r':
                    direction = MOTOR_DIR_REVERSE;
                    break;
                default:
                    direction = MOTOR_DIR_STOP;
            }

            if (argc > 2) {
                speed = atoi(argv[2]);
            }

            if (motor < 2) {
                chprintf(chp, "Set motor %d to direction %d and speed %d\r\n", motor, direction, speed);
                setMotor(motor, direction, speed);
                return;
            }
        }
    }

    // Usage
    chprintf(chp, "Usage: motor N <f|b|s> [speed]\r\n");
    chprintf(chp, "       motor 0 forward 50\r\n");
    chprintf(chp, "       motor 1 b\r\n");
    chprintf(chp, "       motor off\r\n");
    chprintf(chp, "where N is motor number, 0-1\r\n");
    chprintf(chp, "and direction f, b or s (forward, backward, stop)\r\n");
    chprintf(chp, "and speed is percentage 0-100\r\n");
}

static const ShellCommand commands[] = {
    {"sonar", cmdSonar},
    {"memory", cmdMemory},
    {"threads", cmdThreads},
    {"motor", cmdMotor},
    {"m", cmdMotor},
    {"line", cmdLineSensor},
    {"l", cmdLineSensor},
    {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
    TELEMETRY_STREAM,
    commands
};

static SerialConfig ser_cfg = {
    38400,
    0,
    0,
    0,
};

void telemetryInit()
{
    /*
     * Activates the serial driver 1 using the driver default configuration.
     * PA9 and PA10 are routed to USART1.
     */
    sdStart(&TELEMETRY_SERIAL, &ser_cfg);
    palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(1));         /* USART1 TX.         */
    palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(1));        /* USART1 RX.         */

    shellInit();

    chprintf(TELEMETRY_STREAM, "Telemetry Initialized!\r\n");
    chprintf(TELEMETRY_STREAM, "Hello.\r\n");

    static WORKING_AREA(waShell, 1024);
    shellCreateStatic(&shell_cfg1, waShell, sizeof(waShell), NORMALPRIO);
}
