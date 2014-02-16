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


static void cmdMotor(BaseSequentialStream *chp, int argc, char *argv[])
{
    (void)argv;

    uint8_t motor;
    motor_direction_t direction;
    motor_speed_t speed;

    if (argc > 0) {
        if (strcmp(argv[0], "on") == 0) {
            setMotor(MOTOR_LEFT, motor_forward, 100);
            setMotor(MOTOR_RIGHT, motor_forward, 100);
            return;
        } else if (strcmp(argv[0], "off") == 0) {
            setMotor(MOTOR_LEFT, motor_stop, 0);
            setMotor(MOTOR_RIGHT, motor_stop, 0);
            return;
        } else if ((argc > 1)) {
            motor = atoi(argv[0]);
            speed = 100;

            switch (argv[1][0]) {
                case 'f':
                    direction = motor_forward;
                    break;
                case 'r':
                    direction = motor_reverse;
                    break;
                default:
                    direction = motor_stop;
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
    {"motor", cmdMotor},
    {"m", cmdMotor},
    {"line", cmdLineSensor},
    {"l", cmdLineSensor},
    {NULL, NULL}
};

static const ShellConfig shellConfig = {
    TELEMETRY_STREAM,
    commands
};

static SerialConfig serialConfig = {
    TELEMETRY_BITRATE,
    0,
    0,
    0,
};

void telemetryInit()
{
    /* Initialize serial */
    sdStart(&TELEMETRY_SERIAL, &serialConfig);
    TELEMETRY_ALTERNATE_FUNCTION()

    /* Start up the interactive shell */
    shellInit();

    chprintf(TELEMETRY_STREAM, "Telemetry Initialized!\r\n");

    static WORKING_AREA(waShell, 1024);
    shellCreateStatic(&shellConfig, waShell, sizeof(waShell), NORMALPRIO);
}
