/**
 * @file      adc.c
 * @brief     ADC Module Driver Configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "adc.h"
/**
 * Configure ADC Hardware Conversion Mode
 * @param[in] u8channel ADC conversion channel
 * -# ADC_AIN0
 * -# ADC_AIN1
 * -# ADC_AIN2
 * -# ADC_AIN3
 * -# ADC_AIN4
 * -# ADC_AIN5
 * -# ADC_AIN6
 * -# ADC_AIN7
 * -# ADC_INTERNAL_CH
 * @param[in] u8div Clock division
 * -# ADC_DIV_2 : Fsys/2
 * -# ADC_DIV_4 : Fsys/4
 * -# ADC_DIV_8 : Fsys/8
 * -# ADC_DIV_16: Fsys/16
 */
void ADC_ConfigChannel(uint8_t u8channel, uint8_t u8div)
{
    switch(u8channel)
    {
        case ADC_AIN0:
            PORT_SET_MUX(ADC_AIN0_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN0);
            break;
        case ADC_AIN1:
            PORT_SET_MUX(ADC_AIN1_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN1);
            break;
        case ADC_AIN2:
            PORT_SET_MUX(ADC_AIN2_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN2);
            break;
        case ADC_AIN3:
            PORT_SET_MUX(ADC_AIN3_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN3);
            break;
        case ADC_AIN4:
            PORT_SET_MUX(ADC_AIN4_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN4);
            break;
        case ADC_AIN5:
            PORT_SET_MUX(ADC_AIN5_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN5);
            break;
        case ADC_AIN6:
            PORT_SET_MUX(ADC_AIN6_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN6);
            break;
        case ADC_AIN7:
            PORT_SET_MUX(ADC_AIN7_PORT, ANALOG_MUX_MODE);
            ADC_ADCCON2_CHS_SEL(ADC_AIN7);
            break;
        case ADC_INTERNAL_CH:
            ADC_ADCCON2_CHS_SEL(ADC_INTERNAL_CH);
            break;
        default:
            break;
    }
    ADC_ADCCON1_CKS_SEL(u8div);
}
/**
 * Configure ADC Comparator Mode
 * @param[in] u8FBStatus ADC comparator result control for PWM brake enable
 * -# ADC_DISABLE_PWMFB: Disable
 * -# ADC_ENABLE_PWMFB:  Enable
 * @param[in] u8cmpSel ADC comparator output polarity selection
 * -# ADC_CR_GREATER_CMP_1: If ADRH, ADCRL >= ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0
 * -# ADC_CR_LESS_CMP_1:    If ADRH, ADCRL < ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0
 */
void ADC_ConfigCMP(uint8_t u8FBStatus, uint8_t u8cmpSel)
{
    ADC_ADCCON0_FBEN_SET(u8FBStatus);
    ADC_ADCCON0_PPS_SET(u8cmpSel);
}
/**
 * Configure ADC Hardware Conversion Mode
 * @param[in] u8HWsource Hardware source for triggering ADC conversion
 * -# ADC_PWM0
 * -# ADC_PWM2
 * -# ADC_PWM4
 * -# ADC_STADC
 * @param[in] u8trigger Hardware trigger type
 * -# ADC_PWMSTA_RISING :    Rising edge of PWM0/2/4 or STADC pin
 * -# ADC_PWMSTA_FALLING:    Falling edge of PWM0/2/4 or STADC pin
 * -# ADC_PWM_MIDPOINT  : Midpoint of PWM0/2/4 cycle
 * -# ADC_PWM_ENDPOINT  : Endpoint of PWM0/2/4 cycle
 * @param[in] u8delay Hardware delay: total 10 bits, ADCCON2[1:0] for high 2 bits, ADDLYL[7:0] for low 8 bits
 */
void ADC_ConfigHWCVT(uint8_t u8HWsource, uint8_t u8trigger, uint16_t u16delay)
{
    ADC_ADCCON0_SC_SET(ADC_HW_CVT_MODE); /* Select hardware conversion mode */
    ADC_ADCCON1_HWSSEL_SEL(u8HWsource);  /* Select hardware source for triggering ADC conversion */
    ADC_ADCCON1_HWTSEL_SEL(u8trigger);   /* Set hardware trigger type */
    ADC_ADDLY_DATA(u16delay);
}
/**
 * Configure ADC Software Conversion Mode
 */
void ADC_ConfigSWCVT(void)
{
    ADC_ADCCON0_SC_SET(ADC_SW_CVT_MODE);
}
/**
 * Start Software Conversion
 * @note Wait for ADC module to be idle before starting conversion
 */
void ADC_StartSWCVT(void)
{
    while(1 == GET_ADC_ADCCON0_SWS)
        ;
    ENABLE_ADC_SOFT_CVT;
}
/**
 * Get ADC Conversion Result in Query Mode
 * @return ADC conversion result (12-bit width)
 */
uint16_t ADC_GetResultQueryMode(void)
{
    while(0 == IS_ADC_IF_FLAG)
        ;
    CLR_ADC_IF_FLAG;
    return GET_ADC_CVT_12BIT;
}
