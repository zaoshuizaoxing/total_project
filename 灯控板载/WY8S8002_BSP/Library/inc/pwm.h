/**
 * @file      pwm.h
 * @brief     PWM Driver Configuration
 * @version   V1.0.0
 * @date      2023-07
 * @copyright WAYON
 */

#ifndef __PWM_H__
#define __PWM_H__

#include "WY8S8002xx.h"

#define PWM_0 (0)
#define PWM_1 (1)
#define PWM_2 (2)
#define PWM_3 (3)

/**@name PWM Control Register - PWMCON
 * @{
 */
#define PWM_PWMCON_PWMRUN_POS       (7)
#define PWM_PWMCON_PWMRUN_MSK       (0x1 << PWM_PWMCON_PWMRUN_POS)
#define PWM_PWMCON_PWMRUN           PWM_PWMCON_PWMRUN_MSK

#define PWM_PWMCON_PWMMODE_POS      (5)
#define PWM_PWMCON_PWMMODE_MSK      (0x3 << PWM_PWMCON_PWMMODE_POS)
#define PWM_PWMCON_INDEPENDENT      (0x0 << PWM_PWMCON_PWMMODE_POS)
#define PWM_PWMCON_COMPLEMENTARY    (0x1 << PWM_PWMCON_PWMMODE_POS)
#define PWM_PWMCON_SYNC             (0x2 << PWM_PWMCON_PWMMODE_POS)

#define PWM_PWMCON_CNTTYPE_POS      (4)
#define PWM_PWMCON_CNTTYPE_MSK      (0x1 << PWM_PWMCON_CNTTYPE_POS)
#define PWM_PWMCON_CNTTYPE          PWM_PWMCON_CNTTYPE_MSK

#define PWM_PWMCON_PWM1SOEN_POS     (2)
#define PWM_PWMCON_PWM1SOEN_MSK     (0x1 << PWM_PWMCON_PWM1SOEN_POS)
#define PWM_PWMCON_PWM1SOEN         PWM_PWMCON_PWM1SOEN_MSK

#define PWM_PWMCON_PWM0SOEN_POS     (1)
#define PWM_PWMCON_PWM0SOEN_MSK     (0x1 << PWM_PWMCON_PWM0SOEN_POS)
#define PWM_PWMCON_PWM0SOEN         PWM_PWMCON_PWM0SOEN_MSK

#define PWM_PWMCON_PWMSEL_POS       (0)
#define PWM_PWMCON_PWMSEL_MSK       (0x1 << PWM_PWMCON_PWMSEL_POS)
#define PWM_PWMCON_PWMSEL           PWM_PWMCON_PWMSEL_MSK

#define ENABLE_PWM                  (PWMCON |= PWM_PWMCON_PWMRUN)       /*!< Enable PWM */
#define DISABLE_PWM                 (PWMCON &= ~PWM_PWMCON_PWMRUN)      /*!< Disable PWM */

#define PWM_INDEPENDENT_MODE        (PWM_PWMCON_INDEPENDENT)            /*!< Independent Mode */
#define PWM_COMPLEMENTARY_MODE      (PWM_PWMCON_COMPLEMENTARY)          /*!< Complementary Mode */
#define PWM_SYNC_MODE               (PWM_PWMCON_SYNC)                   /*!< Synchronous Mode */
/**
 * PWM Mode Configuration
 * @param[in] mode
 * -# PWM_INDEPENDENT_MODE    Independent Mode
 * -# PWM_COMPLEMENTARY_MODE  Complementary Mode
 * -# PWM_SYNC_MODE           Synchronous Mode
 */
#define PWM_PWMCON_PWMMODE_SET(mode)                                                        \
    PWMCON = ((PWMCON & (~PWM_PWMCON_PWMMODE_MSK)) | (mode))

#define PWM_EDGE_ALIGN_MODE         (0x00)
#define PWM_Mid_ALIGN_MODE          (0x01)
/**
 * PWM Counter Alignment Mode Selection
 * @param[in] mode
 * -# PWM_EDGE_ALIGN_MODE: Edge Aligned
 * -# PWM_Mid_ALIGN_MODE: Center Aligned
 */
#define PWM_CNTTYPE_SET(mode)                                                               \
    PWMCON = ((PWMCON & (~PWM_PWMCON_CNTTYPE)) | ((mode) << PWM_PWMCON_CNTTYPE_POS))


#define PWM_FUNC_PWM                (0x00)
#define PWM_FUNC_SERIAL             (0x01)
/**
 * PWM_1 function selection
 * @param[in] mode
 * -# PWM_FUNC_PWM: function - pwm output
 * -# PWM_FUNC_SERIAL: function - serial output
 */
#define PWM1_FUNCTION_SELECTION(mode)                                                        \
    PWMCON = ((PWMCON & (~PWM_PWMCON_PWM1SOEN)) | ((mode) << PWM_PWMCON_PWM1SOEN_POS))
/**
 * PWM_0 function selection
 * @param[in] mode
 * -# PWM_FUNC_PWM: function - pwm output
 * -# PWM_FUNC_SERIAL: function - serial output
 */
#define PWM0_FUNCTION_SELECTION(mode)                                                        \
    PWMCON = ((PWMCON & (~PWM_PWMCON_PWM0SOEN)) | ((mode) << PWM_PWMCON_PWM0SOEN_POS))

#define PWM_CLK_PSC                 (0x00)
#define PWM_CLK_TIMER1              (0x01)
/**
 * PWM Channel Clock Selection
 * @param[in] status
 * -# PWM_CLK_PSC: CLK_pwm equals CLK_pwmpsc
 * -# PWM_CLK_TIMER1: CLK_pwm equals Timer1_out
 */
#define PWM_CLKSEL_SET(status)                                                              \
    PWMCON = ((PWMCON & (~PWM_PWMCON_PWMSEL_MSK)) | ((status) << PWM_PWMCON_PWMSEL_POS))
/**@} */

/**@name PWM Clock Prescaler Control Register - PWMPSC01,PWMPSC23
 * @{
 */
/**
 * PWM Channel Prescaler Clock Output Control
 * @param[in] u8data
 * -# 00 = Stop Prescaler Clock
 * -# Others = System Clock CLK_sys divided by (PWMPSC + 1)
 */
#define PWM_PWMPSC01_DATA(u8data)                                                           \
    PWMPSC01 = (u8data)

#define PWM_PWMPSC23_DATA(u8data)                                                           \
    PWMPSC23 = (u8data)
/**@} */

/**@name PWM Counter Mode Control Register - PWMCNTM
 * @{
 */
#define PWM_PWMCNTM_CNTE3_POS       (0x07)
#define PWM_PWMCNTM_CNTE3_MSK       (0x1 << PWM_PWMCNTM_CNTE3_POS)
#define PWM_PWMCNTM_CNTE3           PWM_PWMCNTM_CNTE3_MSK

#define PWM_PWMCNTM_CNTE2_POS       (0x06)
#define PWM_PWMCNTM_CNTE2_MSK       (0x1 << PWM_PWMCNTM_CNTE2_POS)
#define PWM_PWMCNTM_CNTE2           PWM_PWMCNTM_CNTE2_MSK

#define PWM_PWMCNTM_CNTE1_POS       (0x05)
#define PWM_PWMCNTM_CNTE1_MSK       (0x1 << PWM_PWMCNTM_CNTE1_POS)
#define PWM_PWMCNTM_CNTE1           PWM_PWMCNTM_CNTE1_MSK

#define PWM_PWMCNTM_CNTE0_POS       (0x04)
#define PWM_PWMCNTM_CNTE0_MSK       (0x1 << PWM_PWMCNTM_CNTE0_POS)
#define PWM_PWMCNTM_CNTE0           PWM_PWMCNTM_CNTE0_MSK

#define PWM_PWMCNTM_CNTM3_POS       (0x03)
#define PWM_PWMCNTM_CNTM3_MSK       (0x1 << PWM_PWMCNTM_CNTM3_POS)
#define PWM_PWMCNTM_CNTM3           PWM_PWMCNTM_CNTM3_MSK

#define PWM_PWMCNTM_CNTM2_POS       (0x02)
#define PWM_PWMCNTM_CNTM2_MSK       (0x1 << PWM_PWMCNTM_CNTM2_POS)
#define PWM_PWMCNTM_CNTM2           PWM_PWMCNTM_CNTM2_MSK

#define PWM_PWMCNTM_CNTM1_POS       (0x01)
#define PWM_PWMCNTM_CNTM1_MSK       (0x1 << PWM_PWMCNTM_CNTM1_POS)
#define PWM_PWMCNTM_CNTM1           PWM_PWMCNTM_CNTM1_MSK

#define PWM_PWMCNTM_CNTM0_POS       (0x00)
#define PWM_PWMCNTM_CNTM0_MSK       (0x1 << PWM_PWMCNTM_CNTM0_POS)
#define PWM_PWMCNTM_CNTM0           PWM_PWMCNTM_CNTM0_MSK

#define ENABLE_PWM0_CNT             (PWMCNTM |= PWM_PWMCNTM_CNTE0)      /*!< Enable PWM0 Counter */
#define DISABLE_PWM0_CNT            (PWMCNTM &= ~PWM_PWMCNTM_CNTE0)     /*!< Disable PWM0 Counter */
#define ENABLE_PWM1_CNT             (PWMCNTM |= PWM_PWMCNTM_CNTE1)      /*!< Enable PWM1 Counter */
#define DISABLE_PWM1_CNT            (PWMCNTM &= ~PWM_PWMCNTM_CNTE1)     /*!< Disable PWM1 Counter */
#define ENABLE_PWM2_CNT             (PWMCNTM |= PWM_PWMCNTM_CNTE2)      /*!< Enable PWM2 Counter */
#define DISABLE_PWM2_CNT            (PWMCNTM &= ~PWM_PWMCNTM_CNTE2)     /*!< Disable PWM2 Counter */
#define ENABLE_PWM3_CNT             (PWMCNTM |= PWM_PWMCNTM_CNTE3)      /*!< Enable PWM3 Counter */
#define DISABLE_PWM3_CNT            (PWMCNTM &= ~PWM_PWMCNTM_CNTE3)     /*!< Disable PWM3 Counter */

#define ONESHOT_MODE                (0)
#define AUTOLOAD_MODE               (1)
/**
 * PWM Channel 3 Counter Mode Control
 * @param[in] status
 * -# ONESHOT_MODE: One-shot Mode
 * -# AUTOLOAD_MODE: Auto-load Mode
 */
#define PWM3_CNT_MODE_SET(status)                                                           \
    PWMCNTM = ((PWMCNTM & (~PWM_PWMCNTM_CNTM3)) | ((status) << PWM_PWMCNTM_CNTM3_POS))

/**
 * PWM Channel 2 Counter Mode Control
 * @param[in] status
 * -# ONESHOT_MODE: One-shot Mode
 * -# AUTOLOAD_MODE: Auto-load Mode
 */
#define PWM2_CNT_MODE_SET(status)                                                           \
    PWMCNTM = ((PWMCNTM & (~PWM_PWMCNTM_CNTM2)) | ((status) << PWM_PWMCNTM_CNTM2_POS))

/**
 * PWM Channel 1 Counter Mode Control
 * @param[in] status
 * -# ONESHOT_MODE: One-shot Mode
 * -# AUTOLOAD_MODE: Auto-load Mode
 */
#define PWM1_CNT_MODE_SET(status)                                                           \
    PWMCNTM = ((PWMCNTM & (~PWM_PWMCNTM_CNTM1)) | ((status) << PWM_PWMCNTM_CNTM1_POS))

/**
 * PWM Channel 0 Counter Mode Control
 * @param[in] status
 * -# ONESHOT_MODE: One-shot Mode
 * -# AUTOLOAD_MODE: Auto-load Mode
 */
#define PWM0_CNT_MODE_SET(status)                                                           \
    PWMCNTM = ((PWMCNTM & (~PWM_PWMCNTM_CNTM0)) | ((status) << PWM_PWMCNTM_CNTM0_POS))

/**@name PWM load control register - PWMLOAD
 * @{
 */
#define PWM_PWMLOAD_LOAD3_POS       (0x07)
#define PWM_PWMLOAD_LOAD3_MSK       (0x1 << PWM_PWMLOAD_LOAD3_POS)
#define PWM_PWMLOAD_LOAD3           PWM_PWMLOAD_LOAD3_MSK

#define PWM_PWMLOAD_LOAD2_POS       (0x06)
#define PWM_PWMLOAD_LOAD2_MSK       (0x1 << PWM_PWMLOAD_LOAD2_POS)
#define PWM_PWMLOAD_LOAD2           PWM_PWMLOAD_LOAD2_MSK

#define PWM_PWMLOAD_LOAD1_POS       (0x05)
#define PWM_PWMLOAD_LOAD1_MSK       (0x1 << PWM_PWMLOAD_LOAD1_POS)
#define PWM_PWMLOAD_LOAD1           PWM_PWMLOAD_LOAD1_MSK

#define PWM_PWMLOAD_LOAD0_POS       (0x04)
#define PWM_PWMLOAD_LOAD0_MSK       (0x1 << PWM_PWMLOAD_LOAD0_POS)
#define PWM_PWMLOAD_LOAD0           PWM_PWMLOAD_LOAD0_MSK

#define PWM_PWMLOAD_ALL             (0xF << PWM_PWMLOAD_LOAD0_POS)

/**
 * PWM Load Configuration
 * @note
 * Write 1 to this bit to automatically load new configuration values at the end of the current PWM cycle.
 * Updated configuration values, such as period, duty cycle, dead time, and mode, will take effect in the next cycle.
 * The hardware will automatically clear the LOAD bit to 0 after the load is complete.
 */
#define ENABLE_PWM0_LOAD            (PWMLOAD |= PWM_PWMLOAD_LOAD0)      /* PWM0 load */
#define ENABLE_PWM1_LOAD            (PWMLOAD |= PWM_PWMLOAD_LOAD1)      /* PWM1 load */
#define ENABLE_PWM2_LOAD            (PWMLOAD |= PWM_PWMLOAD_LOAD2)      /* PWM2 load */
#define ENABLE_PWM3_LOAD            (PWMLOAD |= PWM_PWMLOAD_LOAD3)      /* PWM3 load */
#define ENABLE_PWM_ALL_LOAD         (PWMLOAD = PWM_PWMLOAD_ALL)         /* PWM all load */

/**
 * Return Load Execution Status
 * @return  Return Load Execution Status
 * -# 0: The last configuration value has been loaded
 * -# 1: The last configuration value is still not completed
 * @note LOAD should be used after the internal counter is enabled, i.e., when PWMCNTE is non-zero
 */
#define IS_PWM0_LOAD_FLAG           ((PWMLOAD & PWM_PWMLOAD_LOAD0) >> PWM_PWMLOAD_LOAD0_POS)
#define IS_PWM1_LOAD_FLAG           ((PWMLOAD & PWM_PWMLOAD_LOAD1) >> PWM_PWMLOAD_LOAD1_POS)
#define IS_PWM2_LOAD_FLAG           ((PWMLOAD & PWM_PWMLOAD_LOAD2) >> PWM_PWMLOAD_LOAD2_POS)
#define IS_PWM3_LOAD_FLAG           ((PWMLOAD & PWM_PWMLOAD_LOAD3) >> PWM_PWMLOAD_LOAD3_POS)
/**@} */


/**@name PWM Period Data Register - PWMPxL PWMPxH
 * @{
 */
/**
 * PWM Channel Period Data Register
 * @param[in] dataH High 8 bits of the PWM channel period data register
 * @param[in] dataL Low 8 bits of the PWM channel period data register
 */
#define PWM_PWMP0HL_DATA(dataH, dataL)                                                                                  \
    PWMP0H = (dataH);                                                                                                   \
    PWMP0L = (dataL);
/**
 * PWM Channel Period Data Register
 * @param[in] dataH High 8 bits of the PWM channel period data register
 * @param[in] dataL Low 8 bits of the PWM channel period data register
 */
#define PWM_PWMP1HL_DATA(dataH, dataL)                                                                                  \
    PWMP1H = (dataH);                                                                                                   \
    PWMP1L = (dataL);
/**
 * PWM Channel Period Data Register
 * @param[in] dataH High 8 bits of the PWM channel period data register
 * @param[in] dataL Low 8 bits of the PWM channel period data register
 */
#define PWM_PWMP2HL_DATA(dataH, dataL)                                                                                  \
    PWMP2H = (dataH);                                                                                                   \
    PWMP2L = (dataL);
/**
 * PWM Channel Period Data Register
 * @param[in] dataH High 8 bits of the PWM channel period data register
 * @param[in] dataL Low 8 bits of the PWM channel period data register
 */
#define PWM_PWMP3HL_DATA(dataH, dataL)                                                                                  \
    PWMP3H = (dataH);                                                                                                   \
    PWMP3L = (dataL);
/**@} */

/**@name PWM Compare Data Register - PWMDxL PWMDxH
 * @{
 */
/**
 * PWM Compare Data Register
 * @param[in] dataH High 8 bits of the PWM channel 0 compare data (duty cycle data) register
 * @param[in] dataL Low 8 bits of the PWM channel 0 compare data (duty cycle data) register
 */
#define PWM_PWMD0HL_DATA(dataH, dataL)                                                                                 \
    PWMD0H = (dataH);                                                                                                  \
    PWMD0L = (dataL);
/**
 * PWM Compare Data Register
 * @param[in] dataH High 8 bits of PWM channel 1 compare data (duty cycle data) CMP1 register
 * @param[in] dataL Low 8 bits of PWM channel 1 compare data (duty cycle data) CMP1 register
 */
#define PWM_PWMD1HL_DATA(dataH, dataL)                                                                                 \
    PWMD1H = (dataH);                                                                                                  \
    PWMD1L = (dataL);
/**
 * PWM Compare Data Register
 * @param[in] dataH High 8 bits of PWM channel 2 compare data (duty cycle data) CMP2 register
 * @param[in] dataL Low 8 bits of PWM channel 2 compare data (duty cycle data) CMP2 register
 */
#define PWM_PWMD2HL_DATA(dataH, dataL)                                                                                 \
    PWMD2H = (dataH);                                                                                                  \
    PWMD2L = (dataL);
/**
 * PWM Compare Data Register
 * @param[in] dataH High 8 bits of PWM channel 3 compare data (duty cycle data) CMP3 register
 * @param[in] dataL Low 8 bits of PWM channel 3 compare data (duty cycle data) CMP3 register
 */
#define PWM_PWMD3HL_DATA(dataH, dataL)                                                                                 \
    PWMD3H = (dataH);                                                                                                  \
    PWMD3L = (dataL);
/**@} */

/**@name PWM Dead Time Data Register - PWM01DT PWM23DT
 * @{
 */
/**
 * PWM Channel 0/1 Dead Time Data Register
 * @param[in] u8data PWM Channel 0/1 Dead Time Data Register
 */
#define PWM_PWM01DT_DATA(u8data)                                                                                    \
    PWM01DT = (u8data)
/**
 * PWM Channel 2/3 Dead Time Data Register
 * @param[in] u8data PWM Channel 2/3 Dead Time Data Register
 */
#define PWM_PWM23DT_DATA(u8data)                                                                                    \
    PWM23DT = (u8data)
/**@} */

/**@name PWM configuration control - PWMDTFBC
 * @{
 */
#define PWM_PWMDTFBC_PWMIE3_POS     (0x07)
#define PWM_PWMDTFBC_PWMIE3_MSK     (0x1 << PWM_PWMDTFBC_PWMIE3_POS)
#define PWM_PWMDTFBC_PWMIE3         PWM_PWMDTFBC_PWMIE3_MSK

#define PWM_PWMDTFBC_PWMIE2_POS     (0x06)
#define PWM_PWMDTFBC_PWMIE2_MSK     (0x1 << PWM_PWMDTFBC_PWMIE2_POS)
#define PWM_PWMDTFBC_PWMIE2         PWM_PWMDTFBC_PWMIE2_MSK

#define PWM_PWMDTFBC_PWMIE1_POS     (0x05)
#define PWM_PWMDTFBC_PWMIE1_MSK     (0x1 << PWM_PWMDTFBC_PWMIE1_POS)
#define PWM_PWMDTFBC_PWMIE1         PWM_PWMDTFBC_PWMIE1_MSK

#define PWM_PWMDTFBC_PWMIE0_POS     (0x04)
#define PWM_PWMDTFBC_PWMIE0_MSK     (0x1 << PWM_PWMDTFBC_PWMIE0_POS)
#define PWM_PWMDTFBC_PWMIE0         PWM_PWMDTFBC_PWMIE0_MSK

#define PWM_PWMDTFBC_PWM23DTE_POS   (0x03)
#define PWM_PWMDTFBC_PWM23DTE_MSK   (0x1 << PWM_PWMDTFBC_PWM23DTE_POS)
#define PWM_PWMDTFBC_PWM23DTE       PWM_PWMDTFBC_PWM23DTE_MSK

#define PWM_PWMDTFBC_PWM01DTE_POS   (0x02)
#define PWM_PWMDTFBC_PWM01DTE_MSK   (0x1 << PWM_PWMDTFBC_PWM01DTE_POS)
#define PWM_PWMDTFBC_PWM01DTE       PWM_PWMDTFBC_PWM01DTE_MSK

#define PWM_PWMDTFBC_FBINLS_POS     (0x01)
#define PWM_PWMDTFBC_FBINLS_MSK     (0x1 << PWM_PWMDTFBC_FBINLS_POS)
#define PWM_PWMDTFBC_FBINLS         PWM_PWMDTFBC_FBINLS_MSK

#define PWM_PWMDTFBC_FBINEN_POS     (0x00)
#define PWM_PWMDTFBC_FBINEN_MSK     (0x1 << PWM_PWMDTFBC_FBINEN_POS)
#define PWM_PWMDTFBC_FBINEN         PWM_PWMDTFBC_FBINEN_MSK

#define ENABLE_PWM_CH0_INT          (PWMDTFBC |= PWM_PWMDTFBC_PWMIE0)       /* Enable pwm channel 0 interrupt */
#define DISABLE_PWM_CH0_INT         (PWMDTFBC &= ~PWM_PWMDTFBC_PWMIE0)      /* Disable pwm channel 0 interrupt */
#define ENABLE_PWM_CH1_INT          (PWMDTFBC |= PWM_PWMDTFBC_PWMIE1)       /* Enable pwm channel 1 interrupt */
#define DISABLE_PWM_CH1_INT         (PWMDTFBC &= ~PWM_PWMDTFBC_PWMIE1)      /* Disable pwm channel 1 interrupt */
#define ENABLE_PWM_CH2_INT          (PWMDTFBC |= PWM_PWMDTFBC_PWMIE2)       /* Enable pwm channel 2 interrupt */
#define DISABLE_PWM_CH2_INT         (PWMDTFBC &= ~PWM_PWMDTFBC_PWMIE2)      /* Disable pwm channel 2 interrupt */
#define ENABLE_PWM_CH3_INT          (PWMDTFBC |= PWM_PWMDTFBC_PWMIE3)       /* Enable pwm channel 3 interrupt */
#define DISABLE_PWM_CH3_INT         (PWMDTFBC &= ~PWM_PWMDTFBC_PWMIE3)      /* Disable pwm channel 3 interrupt */

#define ENABLE_PWM01_DTE            (PWMDTFBC |= PWM_PWMDTFBC_PWM01DTE)     /*!< Enable PWM0/1 Channel Dead Time */
#define DISABLE_PWM01_DTE           (PWMDTFBC &= ~PWM_PWMDTFBC_PWM01DTE)    /*!< Disable PWM0/1 Channel Dead Time */
#define ENABLE_PWM23_DTE            (PWMDTFBC |= PWM_PWMDTFBC_PWM23DTE)     /*!< Enable PWM0/1 Channel Dead Time */
#define DISABLE_PWM23_DTE           (PWMDTFBC &= ~PWM_PWMDTFBC_PWM23DTE)    /*!< Disable PWM0/1 Channel Dead Time */

#define FB_RISING                   (0x01)
#define FB_FALLING                  (0x00)
/**
 * FB Pin Input Selection
 * @param[in] status
 * -# FB_FALLING: Falling Edge
 * -# FB_RISING: Rising Edge
 */
#define PWM_FBINLS_SET(status)                                                                                      \
    (PWMDTFBC = ((PWMDTFBC & (~PWM_PWMDTFBC_FBINLS)) | ((status) << PWM_PWMDTFBC_FBINLS_POS)))

#define ENABLE_PWM_FB               (PWMDTFBC |= PWM_PWMDTFBC_FBINEN)       /*!< Enable PWM Fault Brake via FB Pin */
#define DISABLE_PWM_FB              (PWMDTFBC &= ~PWM_PWMDTFBC_FBINEN)      /*!< Disable PWM Fault Brake via FB Pin */
/**@} */

/**@name PWM Interrupt Type Register - PWMINTY
 * @{
 */
#define PWM_PWMINTY_INTTY3_POS      (0x06)
#define PWM_PWMINTY_INTTY3_MSK      (0x03 << PWM_PWMINTY_INTTY3_POS)
#define PWM_PWMINTY_INTTY3          PWM_PWMINTY_INTTY3_MSK

#define PWM_PWMINTY_INTTY2_POS      (0x04)
#define PWM_PWMINTY_INTTY2_MSK      (0x03 << PWM_PWMINTY_INTTY2_POS)
#define PWM_PWMINTY_INTTY2          PWM_PWMINTY_INTTY2_MSK

#define PWM_PWMINTY_INTTY1_POS      (0x02)
#define PWM_PWMINTY_INTTY1_MSK      (0x03 << PWM_PWMINTY_INTTY1_POS)
#define PWM_PWMINTY_INTTY1          PWM_PWMINTY_INTTY1_MSK

#define PWM_PWMINTY_INTTY0_POS      (0x00)
#define PWM_PWMINTY_INTTY0_MSK      (0x03 << PWM_PWMINTY_INTTY0_POS)
#define PWM_PWMINTY_INTTY0          PWM_PWMINTY_INTTY0_MSK

#define PWM_FALLING_MODE            (0x00)
#define PWM_RISING_MODE             (0x01)
#define PWM_MIDPOINT_MODE           (0x02)
#define PWM_ENDPOINT_MODE           (0x03)
#define PWM_INT_MODE_MASK           (0x03)
/**
 * PWM Interrupt Type Selection
 * @param[in] mode
 * -# PWM_FALLING_MODE    Falling Edge of PWM0/1/2/3/4/5 Pins
 * -# PWM_RISING_MODE     Rising Edge of PWM0/1/2/3/4/5 Pins
 * -# PWM_MIDPOINT_MODE   Midpoint of Each PWM Cycle
 * -# PWM_ENDPOINT_MODE   Endpoint of Each PWM Cycle
 * @note Midpoint or Endpoint Interrupt Mode Only Applicable to PWM Center Aligned Mode
 */
#define PWM_PWM0_INTTY_SET(status)                                                                               \
    (PWMINTY = ((PWMINTY & (~PWM_PWMINTY_INTTY0)) | ((status) << PWM_PWMINTY_INTTY0_POS)))

#define PWM_PWM1_INTTY_SET(status)                                                                               \
    (PWMINTY = ((PWMINTY & (~PWM_PWMINTY_INTTY1)) | ((status) << PWM_PWMINTY_INTTY1_POS)))

#define PWM_PWM2_INTTY_SET(status)                                                                               \
    (PWMINTY = ((PWMINTY & (~PWM_PWMINTY_INTTY2)) | ((status) << PWM_PWMINTY_INTTY2_POS)))

#define PWM_PWM3_INTTY_SET(status)                                                                               \
    (PWMINTY = ((PWMINTY & (~PWM_PWMINTY_INTTY3)) | ((status) << PWM_PWMINTY_INTTY3_POS)))
/**@} */

/**@name PWM Interrupt Flag Register - PWMINTF
 * @{
 */
#define PWM_PWMINTF_FBF_POS         (0x04)
#define PWM_PWMINTF_FBF_MSK         (0x1 << PWM_PWMINTF_FBF_POS)
#define PWM_PWMINTF_FBF             PWM_PWMINTF_FBF_MSK

#define PWM_PWMINTF_3IF_POS         (0x03)
#define PWM_PWMINTF_3IF_MSK         (0x1 << PWM_PWMINTF_3IF_POS)
#define PWM_PWMINTF_3IF             PWM_PWMINTF_3IF_MSK

#define PWM_PWMINTF_2IF_POS         (0x02)
#define PWM_PWMINTF_2IF_MSK         (0x1 << PWM_PWMINTF_2IF_POS)
#define PWM_PWMINTF_2IF             PWM_PWMINTF_2IF_MSK

#define PWM_PWMINTF_1IF_POS         (0x01)
#define PWM_PWMINTF_1IF_MSK         (0x1 << PWM_PWMINTF_1IF_POS)
#define PWM_PWMINTF_1IF             PWM_PWMINTF_1IF_MSK

#define PWM_PWMINTF_0IF_POS         (0x00)
#define PWM_PWMINTF_0IF_MSK         (0x1 << PWM_PWMINTF_0IF_POS)
#define PWM_PWMINTF_0IF             PWM_PWMINTF_0IF_MSK

/**
 * Fault Brake Interrupt Flag
 * @return 1: Interrupt Occurred
 *         0: No Interrupt Occurred
 * @note Cleared by software
 */
#define IS_PWM_FBF_FLAG                                                                                     \
    (PWMFBF)

#define CLR_PWM_FBF_FLAG                                                                                         \ 
    (PWMFBF = 0)

/**
 * PWM Channel 3 Interrupt Flag
 * @return 1: Interrupt Occurred
 *         0: No Interrupt Occurred
 * @note Cleared by software
 */
#define IS_PWM3IF_FLAG                                                                                          \
    (PWMIF3)

#define CLR_PWM3IF_FLAG                                                                                         \ 
    (PWMIF3 = 0)
/**
 * PWM Channel 2 Interrupt Flag
 * @return 1: Interrupt Occurred
 *         0: No Interrupt Occurred
 * @note Cleared by software
 */
#define IS_PWM2IF_FLAG                                                                                          \
    (PWMIF2)

#define CLR_PWM2IF_FLAG                                                                                         \ 
    (PWMIF2 = 0)
/**
 * PWM Channel 1 Interrupt Flag
 * @return 1: Interrupt Occurred
 *         0: No Interrupt Occurred
 * @note Cleared by software
 */
#define IS_PWM1IF_FLAG                                                                                          \
    (PWMIF1)

#define CLR_PWM1IF_FLAG                                                                                         \ 
    (PWMIF1 = 0)
/**
 * PWM Channel 0 Interrupt Flag
 * @return 1: Interrupt Occurred\n
 *         0: No Interrupt Occurred
 * @note Cleared by software
 */
#define IS_PWM0IF_FLAG                                                                                          \
    (PWMIF0)

#define CLR_PWM0IF_FLAG                                                                                         \ 
    (PWMIF0 = 0)
/**@} */

/**@name PWM Output Data Register - PWMOUTD
 * @{
 */
#define PWM_PWMOUTD_FBKD3_POS       (7)
#define PWM_PWMOUTD_FBKD3_MSK       (0x1 << PWM_PWMOUTD_FBKD3_POS)
#define PWM_PWMOUTD_FBKD3           PWM_PWMOUTD_FBKD3_MSK

#define PWM_PWMOUTD_FBKD2_POS       (6)
#define PWM_PWMOUTD_FBKD2_MSK       (0x1 << PWM_PWMOUTD_FBKD2_POS)
#define PWM_PWMOUTD_FBKD2           PWM_PWMOUTD_FBKD2_MSK

#define PWM_PWMOUTD_FBKD1_POS       (5)
#define PWM_PWMOUTD_FBKD1_MSK       (0x1 << PWM_PWMOUTD_FBKD1_POS)
#define PWM_PWMOUTD_FBKD1           PWM_PWMOUTD_FBKD1_MSK

#define PWM_PWMOUTD_FBKD0_POS       (4)
#define PWM_PWMOUTD_FBKD0_MSK       (0x1 << PWM_PWMOUTD_FBKD0_POS)
#define PWM_PWMOUTD_FBKD0           PWM_PWMOUTD_FBKD0_MSK

#define PWM_PWMOUTD_MASKD3_POS      (3)
#define PWM_PWMOUTD_MASKD3_MSK      (0x1 << PWM_PWMOUTD_MASKD3_POS)
#define PWM_PWMOUTD_MASKD3          PWM_PWMOUTD_MASKD3_MSK

#define PWM_PWMOUTD_MASKD2_POS      (2)
#define PWM_PWMOUTD_MASKD2_MSK      (0x1 << PWM_PWMOUTD_MASKD2_POS)
#define PWM_PWMOUTD_MASKD2          PWM_PWMOUTD_MASKD2_MSK

#define PWM_PWMOUTD_MASKD1_POS      (1)
#define PWM_PWMOUTD_MASKD1_MSK      (0x1 << PWM_PWMOUTD_MASKD1_POS)
#define PWM_PWMOUTD_MASKD1          PWM_PWMOUTD_MASKD1_MSK

#define PWM_PWMOUTD_MASKD0_POS      (0)
#define PWM_PWMOUTD_MASKD0_MSK      (0x1 << PWM_PWMOUTD_MASKD0_POS)
#define PWM_PWMOUTD_MASKD0          PWM_PWMOUTD_MASKD0_MSK

/**
 * PWM Channel 3 Fault Output Data
 * @param[in] status
 * -# OUTPUT_LOW: When a fault occurs, the PWM signal output is 0
 * -# OUTPUT_HIGH: When a fault occurs, the PWM signal output is 1
 */
#define PWM_PWMOUTD_FBKD3_SET(status)                                                                           \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_FBKD3)) | ((status) << PWM_PWMOUTD_FBKD3_POS))

/**
 * PWM Channel 2 Fault Output Data
 * @param[in] status
 * -# OUTPUT_LOW: When a fault occurs, the PWM signal output is 0
 * -# OUTPUT_HIGH: When a fault occurs, the PWM signal output is 1
 */
#define PWM_PWMOUTD_FBKD2_SET(status)                                                                           \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_FBKD2)) | ((status) << PWM_PWMOUTD_FBKD2_POS))

/**
 * PWM Channel 1 Fault Output Data
 * @param[in] status
 * -# OUTPUT_LOW: When a fault occurs, the PWM signal output is 0
 * -# OUTPUT_HIGH: When a fault occurs, the PWM signal output is 1
 */
#define PWM_PWMOUTD_FBKD1_SET(status)                                                                           \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_FBKD1)) | ((status) << PWM_PWMOUTD_FBKD1_POS))

/**
 * PWM Channel 0 Fault Output Data
 * @param[in] status
 * -# OUTPUT_LOW: When a fault occurs, the PWM signal output is 0
 * -# OUTPUT_HIGH: When a fault occurs, the PWM signal output is 1
 */
#define PWM_PWMOUTD_FBKD0_SET(status)                                                                           \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_FBKD0)) | ((status) << PWM_PWMOUTD_FBKD0_POS))

/**
 * PWM Channel 3 Mask Data Bit
 * @param[in] status
 * -# OUTPUT_LOW: Channel Output Low
 * -# OUTPUT_HIGH: Channel Output High
 */
#define PWM_PWMOUTD_MASKD3_SET(status)                                                                          \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_MASKD3)) | ((status) << PWM_PWMOUTD_MASKD3_POS))

/**
 * PWM Channel 2 Mask Data Bit
 * @param[in] status
 * -# OUTPUT_LOW: Channel Output Low
 * -# OUTPUT_HIGH: Channel Output High
 */
#define PWM_PWMOUTD_MASKD2_SET(status)                                                                          \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_MASKD2)) | ((status) << PWM_PWMOUTD_MASKD2_POS))

/**
 * PWM Channel 1 Mask Data Bit
 * @param[in] status
 * -# OUTPUT_LOW: Channel Output Low
 * -# OUTPUT_HIGH: Channel Output High
 */
#define PWM_PWMOUTD_MASKD1_SET(status)                                                                          \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_MASKD1)) | ((status) << PWM_PWMOUTD_MASKD1_POS))

/**
 * PWM Channel 0 Mask Data Bit
 * @param[in] status
 * -# OUTPUT_LOW: Channel Output Low
 * -# OUTPUT_HIGH: Channel Output High
 */
#define PWM_PWMOUTD_MASKD0_SET(status)                                                                          \
    PWMOUTD = ((PWMOUTD & (~PWM_PWMOUTD_MASKD0)) | ((status) << PWM_PWMOUTD_MASKD0_POS))
/**@} */

/**@name PWM Output Control Register - PWMOUTC
 * @{
 */
#define PWM_PWMOUTC_INV3_POS        (7)
#define PWM_PWMOUTC_INV3_MSK        (0x1 << PWM_PWMOUTC_INV3_POS)
#define PWM_PWMOUTC_INV3            PWM_PWMOUTC_INV3_MSK

#define PWM_PWMOUTC_INV2_POS        (6)
#define PWM_PWMOUTC_INV2_MSK        (0x1 << PWM_PWMOUTC_INV2_POS)
#define PWM_PWMOUTC_INV2            PWM_PWMOUTC_INV2_MSK

#define PWM_PWMOUTC_INV1_POS        (5)
#define PWM_PWMOUTC_INV1_MSK        (0x1 << PWM_PWMOUTC_INV1_POS)
#define PWM_PWMOUTC_INV1            PWM_PWMOUTC_INV1_MSK

#define PWM_PWMOUTC_INV0_POS        (4)
#define PWM_PWMOUTC_INV0_MSK        (0x1 << PWM_PWMOUTC_INV0_POS)
#define PWM_PWMOUTC_INV0            PWM_PWMOUTC_INV0_MSK

#define PWM_PWMOUTC_MASKEN3_POS     (3)
#define PWM_PWMOUTC_MASKEN3_MSK     (0x1 << PWM_PWMOUTC_MASKEN3_POS)
#define PWM_PWMOUTC_MASKEN3         PWM_PWMOUTC_MASKEN3_MSK

#define PWM_PWMOUTC_MASKEN2_POS     (2)
#define PWM_PWMOUTC_MASKEN2_MSK     (0x1 << PWM_PWMOUTC_MASKEN2_POS)
#define PWM_PWMOUTC_MASKEN2         PWM_PWMOUTC_MASKEN2_MSK

#define PWM_PWMOUTC_MASKEN1_POS     (1)
#define PWM_PWMOUTC_MASKEN1_MSK     (0x1 << PWM_PWMOUTC_MASKEN1_POS)
#define PWM_PWMOUTC_MASKEN1         PWM_PWMOUTC_MASKEN1_MSK

#define PWM_PWMOUTC_MASKEN0_POS     (0)
#define PWM_PWMOUTC_MASKEN0_MSK     (0x1 << PWM_PWMOUTC_MASKEN0_POS)
#define PWM_PWMOUTC_MASKEN0         PWM_PWMOUTC_MASKEN0_MSK


#define ENABLE_PWM0_INV_OUTPUT      (PWMOUTC |= PWM_PWMOUTC_INV0)       /*!< Enable Inverted Output for Channel 0 */
#define DISABLE_PWM0_INV_OUTPUT     (PWMOUTC &= ~PWM_PWMOUTC_INV0)      /*!< Disable Inverted Output for Channel 0 */
#define ENABLE_PWM1_INV_OUTPUT      (PWMOUTC |= PWM_PWMOUTC_INV1)       /*!< Enable Inverted Output for Channel 1 */
#define DISABLE_PWM1_INV_OUTPUT     (PWMOUTC &= ~PWM_PWMOUTC_INV1)      /*!< Disable Inverted Output for Channel 1 */
#define ENABLE_PWM2_INV_OUTPUT      (PWMOUTC |= PWM_PWMOUTC_INV2)       /*!< Enable Inverted Output for Channel 2 */
#define DISABLE_PWM2_INV_OUTPUT     (PWMOUTC &= ~PWM_PWMOUTC_INV2)      /*!< Disable Inverted Output for Channel 2 */
#define ENABLE_PWM3_INV_OUTPUT      (PWMOUTC |= PWM_PWMOUTC_INV3)       /*!< Enable Inverted Output for Channel 3 */
#define DISABLE_PWM3_INV_OUTPUT     (PWMOUTC &= ~PWM_PWMOUTC_INV3)      /*!< Disable Inverted Output for Channel 3 */


#define ENABLE_PWM0_MASK            (PWMOUTC |= PWM_PWMOUTC_MASKEN0)    /*!< Enable Channel 0 Mask Data Output */
#define DISABLE_PWM0_MASK           (PWMOUTC &= ~PWM_PWMOUTC_MASKEN0)   /*!< Disable Channel 0 Mask Data Output, Normal PWM Waveform Output */
#define ENABLE_PWM1_MASK            (PWMOUTC |= PWM_PWMOUTC_MASKEN1)    /*!< Enable Channel 1 Mask Data Output */
#define DISABLE_PWM1_MASK           (PWMOUTC &= ~PWM_PWMOUTC_MASKEN1)   /*!< Disable Channel 1 Mask Data Output, Normal PWM Waveform Output */
#define ENABLE_PWM2_MASK            (PWMOUTC |= PWM_PWMOUTC_MASKEN2)    /*!< Enable Channel 2 Mask Data Output */
#define DISABLE_PWM2_MASK           (PWMOUTC &= ~PWM_PWMOUTC_MASKEN2)   /*!< Disable Channel 2 Mask Data Output, Normal PWM Waveform Output */
#define ENABLE_PWM3_MASK            (PWMOUTC |= PWM_PWMOUTC_MASKEN3)    /*!< Enable Channel 3 Mask Data Output */
#define DISABLE_PWM3_MASK           (PWMOUTC &= ~PWM_PWMOUTC_MASKEN3)   /*!< Disable Channel 3 Mask Data Output, Normal PWM Waveform Output */

/**@} */

/**@name PWM Serial Output Duty Cycle Register - PWMSODW
 * @{
 */
/**
 * PWM0 logic0 Serial Output Duty Cycle Set
 * @param[in] duty PWM Serial Output Duty Cycle
 */
#define PWM0_LOGIC0_SERIAL_OUTPUT_DUTY_SET(duty)                                                                \
    PWM01DT = (PWM01DT & ~0x0F) | ((duty) >> 8);                                                                \
    PWMD0L = (duty)
/**
 * PWM0 logic1 Serial Output Duty Cycle Set
 * @param[in] duty PWM Serial Output Duty Cycle
 */
#define PWM0_LOGIC1_SERIAL_OUTPUT_DUTY_SET(duty)                                                                \
    PWMSODW = (PWMSODW & ~0x0F) | ((duty) >> 8);                                                                \
    PWMD0H = (duty)
/**
 * PWM1 logic0 Serial Output Duty Cycle Set
 * @param[in] duty PWM Serial Output Duty Cycle
 */
#define PWM1_LOGIC0_SERIAL_OUTPUT_DUTY_SET(duty)                                                                \
    PWM01DT = (PWM01DT & 0x0F) | (((duty) >> 4) & 0xF0);                                                        \
    PWMD1L = (duty)
/**
 * PWM1 logic1 Serial Output Duty Cycle Set
 * @param[in] duty PWM Serial Output Duty Cycle
 */
#define PWM1_LOGIC1_SERIAL_OUTPUT_DUTY_SET(duty)                                                                \
    PWMSODW = (PWMSODW & 0x0F) | (((duty) >> 4) & 0xF0);                                                        \
    PWMD1H = (duty)
/**@} */


/**@name PWM Serial Output Data 0 Register - PWMSO0_DATA
 * @{
 */
/**
 * PWM Serial Output Data 0 Set
 * @param[in] val PWM Serial Output Data 0
 */
#define PWM_PWMSO0_DATA_SET(val)                                                                                \
    PWMSO0DATA = (val);
/**@} */


/**@name PWM Serial Output Data 1 Register - PWMSO1_DATA
 * @{
 */
/**
 * PWM Serial Output Data 1 Set
 * @param[in] val PWM Serial Output Data 1
 */
#define PWM_PWMSO1_DATA_SET(val)                                                                                \
    PWMSO1DATA = (val);
/**@} */

/**@name External Functions
 * @{
 */

void PWM_ConfigINT(uint8_t u8pwmNum, uint8_t u8trigger);
void PWM_ConfigFBOutputLevel(uint8_t u8pwmNum, uint8_t u8pwmLevel);
void PWM_ConfigMASKOutputLevel(uint8_t u8pwmNum, uint8_t u8pwmLevel);
void PWM_StartLoad(uint8_t u8pwmNum);

/**@} */

#endif /* __PWM_H__ */
