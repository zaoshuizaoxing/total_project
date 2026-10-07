/**
 * @file      adc.h
 * @brief     ADC driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __ADC_H__
#define __ADC_H__

#include "WY8S8002xx.h"
#include "common.h"

/**@name ADC channel corresponding to PORT pins
 * @{
 */
#define ADC_AIN0_PORT (PIO16CFG)
#define ADC_AIN1_PORT (PIO15CFG)
#define ADC_AIN2_PORT (PIO07CFG)
#define ADC_AIN3_PORT (PIO06CFG)
#define ADC_AIN4_PORT (PIO05CFG)
#define ADC_AIN5_PORT (PIO04CFG)
#define ADC_AIN6_PORT (PIO03CFG)
#define ADC_AIN7_PORT (PIO02CFG)
/**@} */

/**@name ADC control register ADCCON0
 * @{
 */
#define ADC_ADCCON0_ADCEN_POS           (7U)
#define ADC_ADCCON0_ADCEN_MSK           (0x01U << ADC_ADCCON0_ADCEN_POS)
#define ADC_ADCCON0_ADCEN               ADC_ADCCON0_ADCEN_MSK
#define ADC_ADCCON0_ADCIF_POS           (6U)
#define ADC_ADCCON0_ADCIF_MSK           (0x01U << ADC_ADCCON0_ADCIF_POS)
#define ADC_ADCCON0_ADCIF               ADC_ADCCON0_ADCIF_MSK
#define ADC_ADCCON0_ADCSC_POS           (5U)
#define ADC_ADCCON0_ADCSC_MSK           (0x01U << ADC_ADCCON0_ADCSC_POS)
#define ADC_ADCCON0_ADCSC               ADC_ADCCON0_ADCSC_MSK
#define ADC_ADCCON0_ADCSWS_POS          (4U)
#define ADC_ADCCON0_ADCSWS_MSK          (0x01U << ADC_ADCCON0_ADCSWS_POS)
#define ADC_ADCCON0_ADCSWS              ADC_ADCCON0_ADCSWS_MSK
#define ADC_ADCCON0_ADDLY_POS           (2U)
#define ADC_ADCCON0_ADDLY_MSK           (0x03U << ADC_ADCCON0_ADDLY_POS)
#define ADC_ADCCON0_ADDLY               ADC_ADCCON0_ADDLY_MSK
#define ADC_ADCCON0_ADCMPPS_POS         (1U)
#define ADC_ADCCON0_ADCMPPS_MSK         (0x01U << ADC_ADCCON0_ADCMPPS_POS)
#define ADC_ADCCON0_ADCMPPS             ADC_ADCCON0_ADCMPPS_MSK
#define ADC_ADCCON0_ADCMPO_POS          (0U)
#define ADC_ADCCON0_ADCMPO_MSK          (0x01U << ADC_ADCCON0_ADCMPO_POS)
#define ADC_ADCCON0_ADCMPO              ADC_ADCCON0_ADCMPO_MSK


#define ENABLE_ADC                      (ADCCON0 |= ADC_ADCCON0_ADCEN)      /*!< Enable ADC conversion circuit */
#define DISABLE_ADC                     (ADCCON0 &= ~ADC_ADCCON0_ADCEN)     /*!< Disable ADC conversion circuit */

/**
 * ADC flag
 * @return 1: ADC conversion complete, at this time the current ADC conversion result can be read\n
 *         0: ADC conversion not complete
 * @note This bit must be cleared by writing 0, and the next conversion can start only after this bit is cleared
 */
#define IS_ADC_IF_FLAG                  ((ADCCON0 & ADC_ADCCON0_ADCIF) ? 1 : 0)
#define CLR_ADC_IF_FLAG                 (ADCCON0 &= ~ADC_ADCCON0_ADCIF)

#define ADC_SW_CVT_MODE                 (0)
#define ADC_HW_CVT_MODE                 (1)
/**
 * ADC conversion start signal selection bit
 * @param[in] status:
 * -# ADC_SW_CVT_MODE: Start ADC conversion through software configuration
 * -# ADC_HW_CVT_MODE: Start ADC conversion triggered by hardware
 */
#define ADC_ADCCON0_SC_SET(status)                                                  \
    ADCCON0 = (ADCCON0 & ~ADC_ADCCON0_ADCSC) | ((status) << ADC_ADCCON0_ADCSC_POS)

#define ENABLE_ADC_SOFT_CVT             (ADCCON0 |= ADC_ADCCON0_ADCSWS)     /*!< Start ADC software conversion */
/**
 * Software configuration trigger start ADC conversion control bit (read)
 * @return 1: ADC module is working, regardless of the trigger start condition, once the ADC conversion is over, the bit
 * read value is always 1\n 0: ADC module is idle
 * @note When the ADC module is not idle, configuring AD conversion start is invalid
 */
#define GET_ADC_ADCCON0_SWS             ((ADCCON0 & ADC_ADCCON0_ADCSWS) ? 1 : 0)

#define ADC_CR_GREATER_CMP_1         (0) /*!< If ADRH, ADCRL >= ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0 */
#define ADC_CR_LESS_CMP_1            (1) /*!< If ADRH, ADCRL < ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0 */
/**
 * ADC comparator output polarity selection bit
 * @param[in] status:
 * -# ADC_CR_GREATER_CMP_1: If ADRH, ADCRL >= ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0
 * -# ADC_CR_LESS_CMP_1:    If ADRH, ADCRL < ADCMP, then ADCMPO = 1, otherwise ADCMPO = 0
 */
#define ADC_ADCCON0_PPS_SET(status)                                                 \
    ADCCON0 = (ADCCON0 & ~ADC_ADCCON0_ADCMPPS) | ((status) << ADC_ADCCON0_ADCMPPS_POS)

/**
 * ADC comparator output bit
 * @return 1: Comparison result is high\n
 *         0: Comparison result is low
 * @note This bit outputs the result of the ADC comparator and is updated after each ADC conversion
 */
#define GET_ADC_ADCMPO                                                              \
    ((ADCCON0 & ADC_ADCCON0_ADCMPO) ? 1 : 0)
/**@} */

/**@name ADC controller register ADCCON1
 * @{
 */
#define ADC_ADCCON1_ADFBEN_POS          (7U)
#define ADC_ADCCON1_ADFBEN_MSK          (0x1 << ADC_ADCCON1_ADFBEN_POS)
#define ADC_ADCCON1_ADFBEN              ADC_ADCCON1_ADFBEN_MSK
#define ADC_ADCCON1_HWSSEL_POS          (5U)
#define ADC_ADCCON1_HWSSEL_MSK          (0x3 << ADC_ADCCON1_HWSSEL_POS)
#define ADC_ADCCON1_HWSSEL              ADC_ADCCON1_HWSSEL_MSK
#define ADC_ADCCON1_HWTSEL_POS          (3U)
#define ADC_ADCCON1_HWTSEL_MSK          (0x3 << ADC_ADCCON1_HWTSEL_POS)
#define ADC_ADCCON1_HWTSEL              ADC_ADCCON1_HWTSEL_MSK
#define ADC_ADCCON1_VREFSEL_POS         (0)
#define ADC_ADCCON1_VREFSEL_MSK         (0x1 << ADC_ADCCON1_VREFSEL_POS)
#define ADC_ADCCON1_VREFSEL             ADC_ADCCON1_VREFSEL_MSK


#define ADC_ENABLE_PWMFB                (1)
#define ADC_DISABLE_PWMFB               (0)
/**
 * ADC comparator result controls PWM brake enable bit
 * @param[in] status:
 * -# ADC_DISABLE_PWMFB: Disable
 * -# ADC_ENABLE_PWMFB: Enable
 */
#define ADC_ADCCON0_FBEN_SET(status)                                                \
    ADCCON1 = (ADCCON1 & ~ADC_ADCCON1_ADFBEN) | ((status) << ADC_ADCCON1_ADFBEN_POS)

#define ADC_PWM0                        (0x00)
#define ADC_PWM2                        (0x01)
#define ADC_STADC                       (0x03)
/**
 * Hardware source selection for triggering ADC conversion
 * @param[in] mode:
 * -# ADC_PWM0
 * -# ADC_PWM2
 * -# ADC_PWM4
 * -# ADC_STADC
 */
#define ADC_ADCCON1_HWSSEL_SEL(mode)                                                \
    ADCCON1 = ((ADCCON1 & (~ADC_ADCCON1_HWSSEL_MSK)) | ((mode) << ADC_ADCCON1_HWSSEL_POS))

#define ADC_PWMSTA_RISING               (0x00)
#define ADC_PWMSTA_FALLING              (0x01)
#define ADC_PWM_MIDPOINT                (0x02)
#define ADC_PWM_ENDPOINT                (0x03)
/**
 * Hardware signal type selection for triggering ADC conversion
 * @param[in] mode:
 * -# ADC_PWM_RISING :    Rising edge of PWM0/2/4 or STADC pin
 * -# ADC_PWM_FALLING:    Falling edge of PWM0/2/4 or STADC pin
 * -# ADC_PWM_MIDPOINT  : Midpoint of the PWM0/2/4 cycle
 * -# ADC_PWM_ENDPOINT  : Endpoint of the PWM0/2/4 cycle
 */
#define ADC_ADCCON1_HWTSEL_SEL(mode)                                                \
    ADCCON1 = ((ADCCON1 & (~ADC_ADCCON1_HWTSEL_MSK)) | ((mode) << ADC_ADCCON1_HWTSEL_POS))

#define ADC_INPUT_VREF_AVDD             (0x00)
#define ADC_INPUT_VREF_2V5              (0x01)
/**
 * ADC reference voltage selection bit
 * @param[in] mode:
 * -# ADC_INPUT_VREF_AVDD: Select AVDD as input
 * -# ADC_INPUT_VREF_2V5: Select 2.5V as input
 */
#define ADC_ADCCON1_VREF_SEL(mode)                                                  \
    ADCCON1 = ((ADCCON1 & (~ADC_ADCCON1_VREFSEL)) | ((mode) << ADC_ADCCON1_VREFSEL_POS))

/**@} */

/**@name ADC controller register ADCCON2
 * @{
 */
#define ADC_ADCCON2_ADCCKS_POS          (4)
#define ADC_ADCCON2_ADCCKS_MSK          (0xF << ADC_ADCCON2_ADCCKS_POS)
#define ADC_ADCCON2_ADCCKS              ADC_ADCCON2_ADCCKS_MSK
#define ADC_ADCCON2_ADCCHS_POS          (0)
#define ADC_ADCCON2_ADCCHS_MSK          (0xF << ADC_ADCCON2_ADCCHS_POS)
#define ADC_ADCCON2_ADCCHS              ADC_ADCCON2_ADCCHS_MSK

#define ADC_DIV_1                       (0x08)
#define ADC_DIV_2                       (0x00)
#define ADC_DIV_4                       (0x01)
#define ADC_DIV_8                       (0x02)
#define ADC_DIV_16                      (0x03)
#define ADC_DIV_32                      (0x04)
#define ADC_DIV_64                      (0x05)
#define ADC_DIV_128                     (0x06)
#define ADC_DIV_256                     (0x07)
/**
 * ADC conversion clock division control
 * @param[in] mode:
 * -# ADC_DIV_1  : Fsys
 * -# ADC_DIV_2  : Fsys/2
 * -# ADC_DIV_4  : Fsys/4
 * -# ADC_DIV_8  : Fsys/8
 * -# ADC_DIV_16 : Fsys/16
 * -# ADC_DIV_32 : Fsys/32
 * -# ADC_DIV_64 : Fsys/64
 * -# ADC_DIV_128: Fsys/128
 * -# ADC_DIV_256: Fsys/256
 */
#define ADC_ADCCON1_CKS_SEL(mode)                                                   \
    ADCCON2 = ((ADCCON2 & (~ADC_ADCCON2_ADCCKS)) | ((mode) << ADC_ADCCON2_ADCCKS_POS))

#define ADC_AIN0                        (0x00)
#define ADC_AIN1                        (0x01)
#define ADC_AIN2                        (0x02)
#define ADC_AIN3                        (0x03)
#define ADC_AIN4                        (0x04)
#define ADC_AIN5                        (0x05)
#define ADC_AIN6                        (0x06)
#define ADC_AIN7                        (0x07)
#define ADC_INTERNAL_CH                 (0x08)
/**
 * ADC conversion channel selection bit
 * @param[in] mode:
 * -# ADC_AIN0----ADC_AIN7 correspond to channels 0-7
 * -# ADC_INTERNAL_CH internal channel
 */
#define ADC_ADCCON2_CHS_SEL(mode)                                                   \
    ADCCON2 = ((ADCCON2 & (~ADC_ADCCON2_ADCCHS)) | ((mode) << ADC_ADCCON2_ADCCHS_POS))

/**@} */

/**@name ADC sampling time control register
 * @{
 */
#define ADC_ADCSMP_SMP_POS              (0U)
#define ADC_ADCSMP_SMP_MSK              (0xFU << ADC_ADCSMP_SMP_POS)
#define ADC_ADCSMP_SMP                  ADC_ADCSMP_SMP_MSK

#define ADC_CLKP_4                      (0x00)
#define ADC_CLKP_5                      (0x01)
#define ADC_CLKP_6                      (0x02)
#define ADC_CLKP_7                      (0x03)
#define ADC_CLKP_8                      (0x04)
#define ADC_CLKP_9                      (0x05)
#define ADC_CLKP_10                     (0x06)
#define ADC_CLKP_11                     (0x07)
#define ADC_CLKP_12                     (0x08)
#define ADC_CLKP_13                     (0x09)
#define ADC_CLKP_14                     (0x10)
#define ADC_CLKP_15                     (0x11)
/**
 * ADC sampling time control
 * @param[in] mode:
 * ADC_CLKP_4  : The sampling time is 4  CLK_P
 * ADC_CLKP_5  : The sampling time is 5  CLK_P
 * ADC_CLKP_6  : The sampling time is 6  CLK_P
 * ADC_CLKP_7  : The sampling time is 7  CLK_P
 * ADC_CLKP_8  : The sampling time is 8  CLK_P
 * ADC_CLKP_9  : The sampling time is 9  CLK_P
 * ADC_CLKP_10 : The sampling time is 10 CLK_P
 * ADC_CLKP_11 : The sampling time is 11 CLK_P
 * ADC_CLKP_12 : The sampling time is 12 CLK_P
 * ADC_CLKP_13 : The sampling time is 13 CLK_P
 * ADC_CLKP_14 : The sampling time is 14 CLK_P
 * ADC_CLKP_15 : The sampling time is 15 CLK_P
 */
#define ADC_SMP_SEL(mode)               ADCSMP = (mode)

/**@} */


/**@name ADC hardware trigger delay data register
 * @{
 */
/**
 * Configure hardware trigger delay
 * @param[in] u16Data: Hardware trigger delay time
 * @note The hardware delay is a total of 10 bits. ADCCON2[1:0] are the high two bits and ADDLYL[7:0] are the low 8
 * bits.
 */
#define ADC_ADDLY_DATA(u16Data)                                                                                         \
    ADCCON0 = ((ADCCON0 & ~ADC_ADCCON0_ADDLY) | ((((u16Data) >> 8) & 0x03) << ADC_ADCCON0_ADDLY_POS));                  \
    ADDLYL  = (u16Data) & 0xFF;
/**@} */

/**@name ADC conversion result register
 * @{
 */
/**
 * Get ADC conversion result
 * @return 12-bit conversion result {ADCRH[7:0] ADCRL[3:0]}
 */
#define GET_ADC_CVT_12BIT ((ADCRH << 4) | (ADCRL & 0x0F))
/**@} */

/**@name ADC comparison value register
 * @{
 */
/**
 * Configure ADC comparison value
 * @param[in] u16Data: ADC comparison value
 * @note The 12-bit comparison value comprises 12 bits {ADCMPH[7:0] ADCMPL[3:0]}
 */
#define ADC_CMP_12BIT_SET(u16Data)                                                                                     \
    ADCMPH = ((u16Data) >> 4) & 0xFF;                                                                                  \
    ADCMPL = (u16Data) & 0x0F;
/**@} */

/**@name External functions
 * @{
 */
void     ADC_ConfigChannel(uint8_t u8channel, uint8_t u8div);
void     ADC_ConfigCMP(uint8_t u8FBStatus, uint8_t u8cmpSel);
void     ADC_ConfigHWCVT(uint8_t u8HWsource, uint8_t u8trigger, uint16_t u16delay);
void     ADC_ConfigSWCVT(void);
void     ADC_StartSWCVT(void);
uint16_t ADC_GetResultQueryMode(void);

/**@} */

#endif /* __ADC_H__ */
