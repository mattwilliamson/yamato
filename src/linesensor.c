#include "linesensor.h"

#define ADC_GRP_NUM_CHANNELS   4
#define ADC_GRP_BUF_DEPTH      16

static adcsample_t adcLightSamples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH] = {0};
static adcsample_t adcLightSamplesAvg[ADC_GRP_NUM_CHANNELS] = {0};

/*
 * ADC streaming callback.
 */
static void adcCbReady(ADCDriver *adcp, adcsample_t *buffer, size_t n) {
    (void)adcp;
    (void)buffer;
    (void)n;

    uint8_t c, i;
    adcsample_t avg[ADC_GRP_NUM_CHANNELS] = {0};

    // Sum up all samples
    for(i = 0; i < ADC_GRP_BUF_DEPTH; i++) {
        c = i % ADC_GRP_NUM_CHANNELS;
        avg[c] += adcLightSamples[i];
    }

    // Average them out
    for(c = 0; c < ADC_GRP_NUM_CHANNELS; c++) {
        adcLightSamplesAvg[c] = avg[c] / ADC_GRP_NUM_CHANNELS;
    }
}

static void adcCbError(ADCDriver *adcp, adcerror_t err) {
    (void)adcp;
    (void)err;
}

/*
 * ADC conversion group.
 * Mode:        Continuous, 16 samples of 8 channels, SW triggered.
 * Channels:    IN10, IN11, Sensor, VRef.
 * Pins:        PC0, PC1
 */
static const ADCConversionGroup adcLightSensorCfg = {
    TRUE,
    ADC_GRP_NUM_CHANNELS,
    adcCbReady,
    adcCbError,
    ADC_CFGR1_RES_12BIT,                              /* CFGRR1 */
    ADC_TR(0, 0),                                     /* TR */
    ADC_SMPR_SMP_28P5,                                /* SMPR */
    ADC_CHSELR_CHSEL10 | ADC_CHSELR_CHSEL11 |
    ADC_CHSELR_CHSEL16 | ADC_CHSELR_CHSEL17           /* CHSELR */
};

void lineInit(void) {
    palSetPadMode(GPIOC, GPIOC_PIN0, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOC, GPIOC_PIN1, PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);

    /*
    * Activates the ADC1 driver and the temperature sensor.
    */
    adcStart(&ADCD1, NULL);
    adcSTM32SetCCR(ADC_CCR_VBATEN | ADC_CCR_TSEN | ADC_CCR_VREFEN);

    /*
    * Starts an ADC continuous conversion.
    */
    adcStartConversion(&ADCD1, &adcLightSensorCfg, adcLightSamples, ADC_GRP_BUF_DEPTH);
}

// GND -> CDS -> PC0
// With 5mm transparent directional yellow led at 330ohm
// line color   close   far
// white        1500    640
// black        640     550

adcsample_t lineAvg(line_channel_t channel) {
    if(channel < ADC_GRP_NUM_CHANNELS) {
        return adcLightSamplesAvg[channel];
    }

    return 0;
}
