/**
 * @file      adc_cmp.c
 * @brief     ADC comparison mode
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"

#include "adc.h"
#include "adc_cmp.h"
#include "gpio.h"
#include "pwm.h"

#define ADCMP_DATA      (0x9B2) /* Comparison voltage of 2V under 3.3V supply, computed as 2000 * 4096 / 3300 */
#define PWM_DIV_DATA    (3)
#define PWM_PERIOD_1MS  (1000)
#define PWM_PERIOD_TIME (PWM_PERIOD_1MS)

static void _GPIO_Test(void);
static void _ADC_ConfigPWM(void);

/**
 * ADC comparison mode setup configuration
 */
void ADC_ConfigCMPInit(void)
{
    _GPIO_Test();
    ADC_ConfigChannel(ADC_AIN0, ADC_DIV_4);
    ADC_ConfigSWCVT();
    ADC_ConfigCMP(ADC_DISABLE_PWMFB, ADC_CR_LESS_CMP_1);
    ADC_CMP_12BIT_SET(ADCMP_DATA);

    ENABLE_ADC;
    ENABLE_ADC_INT;
    ENABLE_ALL_INT;
}

/**
 * ADC comparison mode control PWM brake configuration
 */
void ADC_ConfigCMPFBInit(void)
{
    _GPIO_Test();
    _ADC_ConfigPWM();
    ADC_ConfigChannel(ADC_AIN0, ADC_DIV_4);
    ADC_ConfigSWCVT();
    ADC_ConfigCMP(ADC_ENABLE_PWMFB, ADC_CR_LESS_CMP_1);
    ADC_CMP_12BIT_SET(ADCMP_DATA);

    ENABLE_ADC;
    ENABLE_ADC_INT;
    ENABLE_ALL_INT;
}

/**
 * Comparator output test pin configuration: Use P11 to indicate comparator output results.
 */
static void _GPIO_Test(void)
{
    PORT_SET_MUX(PIO11CFG, GPIO_MUX_MODE);
    GPIO1_ConfigOutput(GPIO_PIN_1, GPIO_PP, GPIO_PULLUP, CURRENT_00);
    P11 = 1;
}

/**
 * PWM output configuration, used for testing ADC controlled PWM brake
 */
static void _ADC_ConfigPWM(void)
{
    uint16_t u16Period;
    uint16_t u16Cmp;

    PORT_SET_MUX(PIO15CFG, PWM0_MUX_MODE);

    ENABLE_PWM;
    PWM_PWMCON_PWMMODE_SET(PWM_INDEPENDENT_MODE);
    PWM_PWMPSC01_DATA(PWM_DIV_DATA);
    PWM_CNTTYPE_SET(PWM_Mid_ALIGN_MODE);

    u16Period = (g_u32SystemClock / (PWM_DIV_DATA + 1)) * PWM_PERIOD_TIME / 1000000 - 1;
    u16Period = u16Period / 2;
    PWM_PWMP0HL_DATA((u16Period >> 8) & 0xFF, u16Period & 0xFF);
    u16Cmp = u16Period * 5 / 10;
    PWM_PWMD0HL_DATA((u16Cmp >> 8) & 0xFF, u16Cmp & 0xFF);

    PWM0_CNT_MODE_SET(AUTOLOAD_MODE);
    ENABLE_PWM0_CNT;
    PWM_StartLoad(PWM_0);
}

/**
 * ADC interrupt service function
 */
static void _ADC_IRQHandler(void) interrupt ADC_VECTOR
{
    if(IS_ADC_IF_FLAG)
    {
        P11 = GET_ADC_ADCMPO; /* Get comparator result, output using P11 */
        CLR_ADC_IF_FLAG;
    }
}
