#include "common.h"
#include "adc.h"
#include "delay.h"
#include "gpio.h"
#include "wdt.h"
//采样次数
#define ADC_SAMPLE_COUNT              (10U)
#define ADC_DISCARD_HIGH_COUNT        (2U)
#define ADC_DISCARD_LOW_COUNT         (2U)
#define ADC_FILTERED_SAMPLE_COUNT \
    (ADC_SAMPLE_COUNT - ADC_DISCARD_HIGH_COUNT - ADC_DISCARD_LOW_COUNT)
//电压量程
#define ADC_REFERENCE_MV              (3300UL)
//12位ADC满量程
#define ADC_FULL_SCALE                (4095UL)
//电阻阻值
#define CURRENT_SENSE_RESISTOR_MOHM   (80UL)
//电流固定点缩放因子
#define CURRENT_FIXED_POINT_SCALE     (10UL)
//三个端口的电流判断值
uint16_t current_threshold_x10_ma0=3000U;
uint16_t current_threshold_x10_ma1=3000U;
uint16_t current_threshold_x10_ma2=4000U;
//采样间隔
#define SAMPLE_INTERVAL_PART_MS       (10U)
//采样100ms间隔次数
#define SAMPLE_INTERVAL_PART_COUNT    (1U)
#define CURRENT_CONVERSION_DIVISOR \
    ((ADC_FULL_SCALE * ADC_FILTERED_SAMPLE_COUNT * CURRENT_SENSE_RESISTOR_MOHM) / 1000UL)

//变化值和钳位值
#define full 3500U
#define limix 5000U
//钳位次数
#define NEW_BATTERY_CONFIRM_COUNT 30U

static void GPIO_InitLedOutputs(void);
static void ADC_InitCurrentInputs(void);
static uint32_t ADC_ReadFilteredCurrentX10Ma(uint8_t channel);
static void DelaySampleInterval(void);

static void GPIO_InitLedOutputs(void)
{
    PORT_SET_MUX(PIO00CFG, GPIO_MUX_MODE);
    PORT_SET_MUX(PIO01CFG, GPIO_MUX_MODE);
    // PORT_SET_MUX(PIO02CFG, GPIO_MUX_MODE);

    GPIO0_ConfigOutput(GPIO_PIN_0, GPIO_PP, GPIO_NOPULL, CURRENT_00);
    GPIO0_ConfigOutput(GPIO_PIN_1, GPIO_PP, GPIO_NOPULL, CURRENT_00);
    // GPIO0_ConfigOutput(GPIO_PIN_2, GPIO_PP, GPIO_NOPULL, CURRENT_00);

    P00 = OUTPUT_LOW;
    P01 = OUTPUT_LOW;
    // P02 = OUTPUT_LOW;
}

static void ADC_InitCurrentInputs(void)
{
    ADC_ConfigChannel(ADC_AIN6, ADC_DIV_4); /* P03 */
    ADC_ConfigChannel(ADC_AIN5, ADC_DIV_4); /* P04 */
    // ADC_ConfigChannel(ADC_AIN4, ADC_DIV_4); /* P05 */
    ADC_ADCCON1_VREF_SEL(ADC_INPUT_VREF_AVDD);
    ADC_SMP_SEL(ADC_CLKP_8);
    ADC_ConfigSWCVT();
    ENABLE_ADC;
    Timer0_Delay_ms(1U);
}

static uint32_t ADC_ReadFilteredCurrentX10Ma(uint8_t channel)
{
    uint8_t sample;
    uint16_t adc_value;
    uint16_t min_value1 = 0xFFFFU;
    uint16_t min_value2 = 0xFFFFU;
    uint16_t max_value1 = 0U;
    uint16_t max_value2 = 0U;
    uint32_t adc_sum = 0UL;

    ADC_ConfigChannel(channel, ADC_DIV_4);
    for(sample = 0U; sample < ADC_SAMPLE_COUNT; sample++)
    {
        ADC_StartSWCVT();
        adc_value = ADC_GetResultQueryMode();
        adc_sum += adc_value;

        if(adc_value < min_value1)
        {
            min_value2 = min_value1;
            min_value1 = adc_value;
        }
        else if(adc_value < min_value2)
        {
            min_value2 = adc_value;
        }

        if(adc_value > max_value1)
        {
            max_value2 = max_value1;
            max_value1 = adc_value;
        }
        else if(adc_value > max_value2)
        {
            max_value2 = adc_value;
        }
    }

    adc_sum -= (uint32_t)min_value1 + min_value2 + max_value1 + max_value2;

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
    // uint32_t current_x10_ma2=0U;
    uint8_t confirm_count0=0U;
    uint8_t confirm_count1=0U;
    // uint8_t sign2=0;
    System_ConfigCLK(SYSCLK_HRC, CLK_DIV_2,WAITS_INST_VDD_LT3600MV_CLK_GE15_LT20M);
    GPIO_InitLedOutputs();
    ADC_InitCurrentInputs();
    // WDT_ConfigMode(WDT_DIV_1024, ENABLE_OVER_RST, WDT_IDLE_SLEEP_MODE);
    // WDT_Run(ENABLE_WDT);
    //延迟等待硬件稳定
    Timer0_Delay_ms(5);
    while(1)
    {
        //端口一模拟输入
        current_x10_ma0 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN6);
        if(current_threshold_x10_ma0 == full)
        {
            confirm_count0 = 0U;
            /* 正常充电阶段 */
            if(current_x10_ma0 < full)
            {
                /* 充满：亮绿灯并进入钳位状态 */
                P00 = OUTPUT_LOW;
                current_threshold_x10_ma0 = limix;
            }
            else
            {
                /* 电流尚未降到full以下 */
                P00 = OUTPUT_HIGH;
            }
        }
        else
        {
            /* 充满后的钳位阶段 */
            if(current_x10_ma0 > limix)
            {
                confirm_count0++;
                if(confirm_count0 >= NEW_BATTERY_CONFIRM_COUNT)
                {
                    /* 检测到新电池：亮红灯并恢复正常判断值 */
                    P00 = OUTPUT_HIGH;
                    current_threshold_x10_ma0 = full;
                    confirm_count0 = 0U;
                }
                else
                {
                    P00 = OUTPUT_LOW;
                }
            }
            else
            {
                /* 波动未超过钳位值，保持绿灯 */
                P00 = OUTPUT_LOW;
                confirm_count0 = 0U;
            }
        }


        //端口二模拟输入
        current_x10_ma1 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN5);
        if(current_threshold_x10_ma1 == full)
        {
            confirm_count1 = 0U;
            /* 正常充电阶段 */
            if(current_x10_ma1 < full)
            {
                /* 充满：亮绿灯并进入钳位状态 */
                P01 = OUTPUT_LOW;
                current_threshold_x10_ma1 = limix;
            }
            else
            {
                /* 电流尚未降到full以下 */
                P01 = OUTPUT_HIGH;
            }
        }
        else
        {
            /* 充满后的钳位阶段 */
            if(current_x10_ma1 > limix)
            {
                confirm_count1++;
                if(confirm_count1 >= NEW_BATTERY_CONFIRM_COUNT)
                {
                    /* 检测到新电池：亮红灯并恢复正常判断值 */
                    P01 = OUTPUT_HIGH;
                    current_threshold_x10_ma1 = full;
                    confirm_count1 = 0U;
                }
                else
                {
                    P01 = OUTPUT_LOW;
                }
            }
            else
            {
                /* 波动未超过钳位值，保持绿灯 */
                P01 = OUTPUT_LOW;
                confirm_count1 = 0U;
            }
        }

        
         //端口三模拟输入
        /*current_x10_ma2 = ADC_ReadFilteredCurrentX10Ma(ADC_AIN4);
        if(sign2==1&&current_x10_ma2<full)
        {
            current_threshold_x10_ma2=limix;
        }
        //退出特殊处理环节
        else if(sign2==1&&current_x10_ma2>limix)
        {
            current_threshold_x10_ma2=full;
        }
        P02 = (current_x10_ma2 > current_threshold_x10_ma2) ? OUTPUT_HIGH : OUTPUT_LOW;
        sign2 = (current_x10_ma2 > current_threshold_x10_ma2) ? 1 : 0;*/

        DelaySampleInterval();
        // //看门狗复位
        // WDT_ClearWDT(); 
    }
}
