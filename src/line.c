#include "line.h"

static adcsample_t adcLightSamples[LINE_ADC_CHANNELS * LINE_ADC_BUF_DEPTH] = {0};
static adcsample_t adcLightSamplesAvg[LINE_ADC_CHANNELS] = {0};
static line_color_t colorDetected[LINE_ADC_CHANNELS] = {LINE_BLACK};

/**
 * @brief ADC streaming callback.
 */
static void adcCbReady(ADCDriver *adcp, adcsample_t *buffer, size_t n)
{
    (void)adcp;
    (void)buffer;
    (void)n;

    uint8_t c, i;
    line_color_t lastColor;
    adcsample_t avg[LINE_ADC_CHANNELS] = {0};

    // Sum up all samples
    for (i = 0; i < LINE_ADC_BUF_DEPTH; i++) {
        c = i % LINE_ADC_CHANNELS;
        avg[c] += adcLightSamples[i];
    }

    // Average them out
    for (c = 0; c < LINE_ADC_CHANNELS; c++) {
        adcLightSamplesAvg[c] = avg[c] / LINE_ADC_CHANNELS;
        lastColor = colorDetected[c];
        colorDetected[c] = adcLightSamplesAvg[c] > LINE_ADC_THRESHOLD;

        // Color detected changed from last reading, send an event
        if(lastColor != colorDetected[c]) {
            chEvtBroadcastFlagsI(&esSensorEvents, sensor_event_line_change);
        }
    }
}

static void adcCbError(ADCDriver *adcp, adcerror_t err)
{
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
    LINE_ADC_CHANNELS,
    adcCbReady,
    adcCbError,
    ADC_CFGR1_RES_12BIT,                              /* CFGRR1 */
    ADC_TR(0, 0),                                     /* TR */
    ADC_SMPR_SMP_28P5,                                /* SMPR */
    LINE_ADC_CHANNEL_SEL
};

void lineInit(void)
{
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
    adcStartConversion(&ADCD1, &adcLightSensorCfg, adcLightSamples, LINE_ADC_BUF_DEPTH);
}

adcsample_t lineAvg(line_channel_t channel)
{
    if (channel < LINE_ADC_CHANNELS) {
        return adcLightSamplesAvg[channel];
    }

    return 0;
}
