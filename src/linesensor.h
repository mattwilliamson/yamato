#pragma once

#include "yamato.h"

#define LINE_CHANNEL_LEFT 0
#define LINE_CHANNEL_RIGHT 1
#define LINE_CHANNEL_TEMP 2
#define LINE_CHANNEL_VREF 3

typedef size_t line_channel_t;

void lineInit(void);
adcsample_t lineAvg(line_channel_t channel);
