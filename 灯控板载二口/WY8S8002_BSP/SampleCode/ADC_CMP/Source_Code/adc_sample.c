#include "adc_sample.h"
#include "adc.h"
#include "delay.h"
static uint8_t  s_sample_index;
static uint16_t xdata s_adc_raw[ADC_SAMPLE_CHANNEL_COUNT];
static uint16_t xdata s_adc_mv[ADC_SAMPLE_CHANNEL_COUNT];
static const uint8_t code s_adc_channels[ADC_SAMPLE_CHANNEL_COUNT] = {
    ADC_AIN7, /* P02 */
    ADC_AIN6, /* P03 */
    ADC_AIN5, /* P04 */
    ADC_AIN4  /* P05 */
};
void AdcSample_Init(void)
{
    uint8_t i;
    s_sample_index = 0;
    for(i = 0; i < ADC_SAMPLE_CHANNEL_COUNT; i++)
    {
        s_adc_raw[i] = 0;
        s_adc_mv[i] = 0;
        ADC_ConfigChannel(s_adc_channels[i], ADC_DIV_4);
    }
    ADC_SMP_SEL(ADC_CLKP_8);
    ADC_ConfigSWCVT();
    ENABLE_ADC;
    Timer0_Delay_ms(1);
}
void AdcSample_Task(void)
{
    uint16_t raw;
    ADC_ConfigChannel(s_adc_channels[s_sample_index], ADC_DIV_4);
    ADC_StartSWCVT();
    raw = ADC_GetResultQueryMode();
    s_adc_raw[s_sample_index] = raw;
    s_adc_mv[s_sample_index] = (uint16_t)(((uint32_t)raw * BOARD_ADC_REF_MV) / 4095UL);

    s_sample_index++;
    if(s_sample_index >= ADC_SAMPLE_CHANNEL_COUNT)
    {
        s_sample_index = 0;
    }
}
uint16_t AdcSample_GetRaw(uint8_t index)
{
    if(index >= ADC_SAMPLE_CHANNEL_COUNT)
    {
        return 0;
    }
    return s_adc_raw[index];
}
uint16_t AdcSample_GetMv(uint8_t index)
{
    if(index >= ADC_SAMPLE_CHANNEL_COUNT)
    {
        return 0;
    }
    return s_adc_mv[index];
}

uint16_t AdcSample_GetVoltageMv(uint8_t pair_index)
{
    uint32_t voltage_mv;

    if(pair_index > ADC_SAMPLE_WIRED_INDEX)
    {
        return 0;
    }

    voltage_mv = (uint32_t)s_adc_mv[pair_index] * ADC_SAMPLE_VOLTAGE_SCALE;
    if(voltage_mv > 65535UL)
    {
        return 65535U;
    }
    return (uint16_t)voltage_mv;
}

uint32_t AdcSample_GetCurrentMa(uint8_t pair_index)
{
    uint8_t channel_index;

    if(pair_index > ADC_SAMPLE_WIRED_INDEX)
    {
        return 0;
    }

    channel_index = (uint8_t)(pair_index + 2U);
    return ((uint32_t)s_adc_mv[channel_index] * 1000UL) / ADC_SAMPLE_SHUNT_MOHM;
}
