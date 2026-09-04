#include "common.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"
//采样次数
#define ADC_SAMPLE_COUNT              (10U)
//电压量程
#define ADC_REFERENCE_MV              (3300UL)
//12位ADC满量程
#define ADC_FULL_SCALE                (4095UL)
//电阻阻值
#define CURRENT_SENSE_RESISTOR_MOHM   (200UL)
//电流固定点缩放因子
#define CURRENT_FIXED_POINT_SCALE     (10UL)
//三个端口的电流阈值
uint16_t current_threshold_x10_ma0=1000U;
uint16_t current_threshold_x10_ma1=1000U;
uint16_t current_threshold_x10_ma2=1000U;
//采样间隔
#define SAMPLE_INTERVAL_PART_MS       (100U)
//采样100ms间隔次数
#define SAMPLE_INTERVAL_PART_COUNT    (2U)
#define CURRENT_CONVERSION_DIVISOR \
    ((ADC_FULL_SCALE * ADC_SAMPLE_COUNT * CURRENT_SENSE_RESISTOR_MOHM) / 1000UL)

static void GPIO_InitLedOutputs(void);
static void ADC_InitCurrentInputs(void);
static uint32_t ADC_ReadFilteredCurrentX10Ma(uint8_t channel);
static void DelaySampleInterval(void);

static void GPIO_InitLedOutputs(void)
{
    PORT_SET_MUX(PIO00CFG, GPIO_MUX_MODE);
    PORT_SET_MUX(PIO01CFG, GPIO_MUX_MODE);
    PORT_SET_MUX(PIO02CFG, GPIO_MUX_MODE);

    GPIO0_ConfigOutput(GPIO_PIN_0, GPIO_PP, GPIO_NOPULL, CURRENT_00);
    GPIO0_ConfigOutput(GPIO_PIN_1, GPIO_PP, GPIO_NOPULL, CURRENT_00);
    GPIO0_ConfigOutput(GPIO_PIN_2, GPIO_PP, GPIO_NOPULL, CURRENT_00);

    P00 = OUTPUT_LOW;
    P01 = OUTPUT_LOW;
    P02 = OUTPUT_LOW;
}

static void ADC_InitCurrentInputs(void)
{
    ADC_ConfigChannel(ADC_AIN6, ADC_DIV_4); /* P03 */
    ADC_ConfigChannel(ADC_AIN5, ADC_DIV_4); /* P04 */
    ADC_ConfigChannel(ADC_AIN4, ADC_DIV_4); /* P05 */
    ADC_ADCCON1_VREF_SEL(ADC_INPUT_VREF_AVDD);
    ADC_SMP_SEL(ADC_CLKP_8);
    ADC_ConfigSWCVT();
    ENABLE_ADC;
    Timer0_Delay_ms(1U);
}

static uint32_t ADC_ReadFilteredCurrentX10Ma(uint8_t channel)
{
    uint8_t sample;
    uint32_t adc_sum = 0UL;

    ADC_ConfigChannel(channel, ADC_DIV_4);
    for(sample = 0U; sample < ADC_SAMPLE_COUNT; sample++)
    {
        ADC_StartSWCVT();
        adc_sum += ADC_GetResultQueryMode();
    }

    return (adc_sum * ADC_REFERENCE_MV * CURRENT_FIXED_POINT_SCALE) /
           CURRENT_CONVERSION_DIVISOR;
}

static void DelaySampleInterval(void)
{
    uint8_t part;

    for(part = 0U; part < SAMPLE_INTERVAL_PART_COUNT; part++)
    {
        Timer0_Delay_ms(SAMPLE_INTERVAL_PART_MS);
    }
}

int main(void)
{
    uint32_t current_x10_ma0=0U;
    uint32_t current_x10_ma1=0U;
    uint32_t current_x10_ma2=0U;
    uint8_t sign0=0;
    uint8_t sign1=0;
    uint8_t sign2=0;
    System_ConfigCLK(SYSCLK_HRC, CLK_DIV_2,WAITS_INST_VDD_LT3600MV_CLK_GE15_LT20M);
    GPIO_InitLedOutputs();
    ADC_InitCurrentInputs();
    while(1)
    {
        //端口一
        current_x10_ma0 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN6);
        //进入特殊处理环节
        if(sign0==1&&current_x10_ma0<1000U)
        {
            current_threshold_x10_ma0=1500U;
        }
        //退出特殊处理环节
        else if(sign0==1&&current_x10_ma0>1500U)
        {
            current_threshold_x10_ma0=1000U;
        }
        P00 = (current_x10_ma0 > current_threshold_x10_ma0) ? OUTPUT_HIGH : OUTPUT_LOW;
        sign0 = (current_x10_ma0 > current_threshold_x10_ma0) ? 1 : 0;

         //端口二
        current_x10_ma1 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN5);
        if(sign1==1&&current_x10_ma1<1000U)
        {
            current_threshold_x10_ma1=1500U;
        }
        //退出特殊处理环节
        else if(sign1==1&&current_x10_ma1>1500U)
        {
            current_threshold_x10_ma1=1000U;
        }
        P01 = (current_x10_ma1 > current_threshold_x10_ma1) ? OUTPUT_HIGH : OUTPUT_LOW;
        sign1 = (current_x10_ma1 > current_threshold_x10_ma1) ? 1 : 0;


         //端口三
        current_x10_ma2 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN4);
        if(sign2==1&&current_x10_ma2<1000U)
        {
            current_threshold_x10_ma2=1500U;
        }
        //退出特殊处理环节
        else if(sign2==1&&current_x10_ma2>1500U)
        {
            current_threshold_x10_ma2=1000U;
        }
        P02 = (current_x10_ma2 > current_threshold_x10_ma2) ? OUTPUT_HIGH : OUTPUT_LOW;
        sign2 = (current_x10_ma2 > current_threshold_x10_ma2) ? 1 : 0;

        DelaySampleInterval();
    }
}
