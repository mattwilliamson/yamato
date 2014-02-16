// GND -> CDS -> PC0
// With 5mm transparent directional yellow LED at 330ohm
// line color   close   far
// white        1500    640
// black        640     550

#pragma once

#include "yamato.h"

#define LINE_CHANNEL_LEFT   0
#define LINE_CHANNEL_RIGHT  1
#define LINE_ADC_CHANNELS   2
#define LINE_ADC_BUF_DEPTH  16

/* Below this threshold is black, above is white */
#define LINE_ADC_THRESHOLD  640

/* PC0, PC1 */ 
#define LINE_ADC_CHANNEL_SEL ADC_CHSELR_CHSEL10 | ADC_CHSELR_CHSEL11
#define LINE_BLACK FALSE
#define LINE_WHITE TRUE

typedef size_t line_channel_t;
typedef bool line_color_t;

void lineInit(void);
adcsample_t lineAvg(line_channel_t channel);
