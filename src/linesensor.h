#ifndef _LINESENSOR_H_
#define _LINESENSOR_H_

#include "yamato.h"

#define LINE_CHANNEL_LEFT 0
#define LINE_CHANNEL_RIGHT 1
#define LINE_CHANNEL_TEMP 2
#define LINE_CHANNEL_VREF 3

typedef size_t line_channel_t;

#endif

void lineInit(void);
adcsample_t lineAvg(line_channel_t channel);
