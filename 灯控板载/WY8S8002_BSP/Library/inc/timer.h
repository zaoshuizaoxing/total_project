/**
 * @file      timer.h
 * @brief     Timer driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "WY8S8002xx.h"

/**@name TIMER0/1 Mode Register - TMOD
 * @{
 */
#define TIMER1_TMOD_GATE1_POS (7)
#define TIMER1_TMOD_GATE1_MSK (0x1 << TIMER1_TMOD_GATE1_POS)
#define TIMER1_TMOD_CNT1_POS  (6)
#define TIMER1_TMOD_CNT1_MSK  (0x1 << TIMER1_TMOD_CNT1_POS)
#define TIMER1_TMOD_MODE_POS  (4)
#define TIMER1_TMOD_MODE_MSK  (0x3 << TIMER1_TMOD_MODE_POS)
#define TIMER0_TMOD_GATE0_POS (3)
#define TIMER0_TMOD_GATE0_MSK (0x1 << TIMER0_TMOD_GATE0_POS)
#define TIMER0_TMOD_CNT0_POS  (2)
#define TIMER0_TMOD_CNT0_MSK  (0x1 << TIMER0_TMOD_CNT0_POS)
#define TIMER0_TMOD_MODE_POS  (0)
#define TIMER0_TMOD_MODE_MSK  (0x3 << TIMER0_TMOD_MODE_POS)

#define TIMER01_MODE0         (0x00) /*!< Mode 0, 13-bit timer/counter */
#define TIMER01_MODE1         (0x01) /*!< Mode 1, 16-bit timer/counter */
#define TIMER01_MODE2         (0x02) /*!< Mode 2, 8-bit timer/counter, TL reloads automatically from TH on overflow */
#define TIMER01_MODE3                                                                                                  \
    (0x03) /*!< Mode 3, TL0 is configured as an 8-bit timer/counter (controlled by TIMER0), TH0 is configured as an    \
              8-bit timer/counter (controlled by TIMER1) */

#define TIMER01_TR_GATE     (0)
#define TIMER01_INT_TR_GATE (1)

#define TIMER01_ICLK        (0)
#define TIMER01_TCLK        (1)

/**
 * TIMER1 Gate Control
 * @param[in] status
 * -# TIMER01_TR_GATE: Start counting when TCON.TR1 is set to 1
 * -# TIMER01_INT_TR_GATE: Start counting when INT1 is 1 and TR1 is 1
 */
#define TIMER1_TMOD_GATE1_SET(status) (TMOD = ((TMOD & (~TIMER1_TMOD_GATE1_MSK)) | ((status) << TIMER1_TMOD_GATE1_POS)))
/**
 * TIMER1 Counter/Timer Selection
 * @param[in] status
 * -# TIMER01_ICLK: As timer1, select the clock from internal clock input
 * -# TIMER01_TCLK: As counter1, select the clock from pin T1 input
 */
#define TIMER1_TMOD_CNT1_SET(status) (TMOD = ((TMOD & (~TIMER1_TMOD_CNT1_MSK)) | ((status) << TIMER1_TMOD_CNT1_POS)))
/**
 * TIMER1 Mode Selection
 * @param[in] mode
 * -# TIMER01_MODE0: Mode 0, 13-bit timer/counter
 * -# TIMER01_MODE1: Mode 1, 16-bit timer/counter
 * -# TIMER01_MODE2: Mode 2, 8-bit timer/counter, TH1 reloads automatically to TL1 on overflow
 * -# TIMER01_MODE3: Mode 3, timer1 stops
 */
#define TIMER1_TMOD_MODE_SET(mode) (TMOD = ((TMOD & (~TIMER1_TMOD_MODE_MSK)) | ((mode) << TIMER1_TMOD_MODE_POS)))
/**
 * TIMER0 Gate Control
 * @param[in] status
 * -# TIMER01_TR_GATE: Start counting when TCON.TR0 is set to 1
 * -# TIMER01_INT_TR_GATE: Start counting when INT0 is 1 and TR0 is 1
 */
#define TIMER0_TMOD_GATE0_SET(status) (TMOD = ((TMOD & (~TIMER0_TMOD_GATE0_MSK)) | ((status) << TIMER0_TMOD_GATE0_POS)))
/**
 * TIMER0 Counter/Timer Selection
 * @param[in] status
 * -# TIMER01_ICLK: As timer0, select the clock from internal clock input
 * -# TIMER01_TCLK: As counter0, select the clock from pin T0 input
 */
#define TIMER0_TMOD_CNT0_SET(status) (TMOD = ((TMOD & (~TIMER0_TMOD_CNT0_MSK)) | ((status) << TIMER0_TMOD_CNT0_POS)))
/**
 * TIMER0 Mode Selection
 * @param[in] mode
 * -# TIMER01_MODE0: Mode 0, 13-bit timer/counter
 * -# TIMER01_MODE1: Mode 1, 16-bit timer/counter
 * -# TIMER01_MODE2: Mode 2, 8-bit timer/counter, TH0 reloads automatically to TL0 on overflow
 * -# TIMER01_MODE3: Mode 3, TL0 is configured as an 8-bit timer/counter (controlled by TIMER0), TH0 is configured as an
 * 8-bit timer/counter (controlled by TIMER1)
 */
#define TIMER0_TMOD_MODE_SET(mode) (TMOD = ((TMOD & (~TIMER0_TMOD_MODE_MSK)) | ((mode) << TIMER0_TMOD_MODE_POS)))
/**@} */

/**@name TIMER0/1 Control Register - TCON
 * @{
 */
/**
 * TIMER1 Overflow Flag
 * @return 0: TIMER1 not overflowed\n
 *         1: TIMER1 overflowed, set by hardware on overflow, cleared by hardware
 */
#define IS_TIME1_OVER_FLAG  (TF1)
#define CLR_TIME1_OVER_FLAG (TF1 = 0) /*!< Clear the flag */

#define ENABLE_TIMER1       (TR1 = 1) /*!< Start TIMER1 */
#define DISABLE_TIMER1      (TR1 = 0) /*!< Stop TIMER1 */

/**
 * TIMER0 Overflow Flag
 * @return 0: TIMER0 not overflowed\n
 *         1: TIMER0 overflowed, set by hardware on overflow, cleared by hardware
 */
#define IS_TIME0_OVER_FLAG  (TF0)
#define CLR_TIME0_OVER_FLAG (TF0 = 0) /*!< Clear the flag */

#define ENABLE_TIMER0       (TR0 = 1) /*!< Start TIMER0 */
#define DISABLE_TIMER0      (TR0 = 0) /*!< Stop TIMER0 */

/**@} */

/**@name TIMER0/1 Data Register - THx TLx
 * @{
 */
/**
 * TIMER0 Data Register
 * @param[in] dataH  High byte of data register
 * @param[in] dataL  Low byte of data register
 */
#define TIMER0_DATA_REG(dataH, dataL)                                                                                  \
    TH0 = (dataH);                                                                                                     \
    TL0 = (dataL);
/**
 * TIMER1 Data Register
 * @param[in] dataH  High byte of data register
 * @param[in] dataL  Low byte of data register
 */
#define TIMER1_DATA_REG(dataH, dataL)                                                                                  \
    TH1 = (dataH);                                                                                                     \
    TL1 = (dataL);
/**@} */

/**@name TIMER2 Data Register - T2RH T2RL
 * @{
 */
/**
 * TIMER2 Data Register
 * @param[in] dataH  High byte of data register
 * @param[in] dataL  Low byte of data register
 */
#define TIMER2_DATA_REG(dataH, dataL)                                                                                  \
    T2RH = (dataH);                                                                                                    \
    T2RL = (dataL);
/**@} */

/**@name TIMER2 Reload/Compare Data Register - RCMP2H RCMP2L
 * @{
 */
/**
 * TIMER2 Reload/Compare Data Register
 * @param[in] dataH  High byte of data register
 * @param[in] dataL  Low byte of data register
 */
#define TIMER2_RCMP_DATA_REG(dataH, dataL)                                                                             \
    RCMP2H = (dataH);                                                                                                  \
    RCMP2L = (dataL);
/**@} */

/**@name TIMER2 Control Register - T2CON
 * @{
 */
#define TIMER2_T2CON_TR2_POS   (1)
#define TIMER2_T2CON_TR2_MSK   (0x1 << TIMER2_T2CON_TR2_POS)
#define TIMER2_T2CON_CMRL_POS  (0)
#define TIMER2_T2CON_CMRL_MSK  (0x1 << TIMER2_T2CON_CMRL_POS)
#define TIMER2_T2CON_CMPCR_POS (2)
#define TIMER2_T2CON_CMPCR_MSK (0x1 << TIMER2_T2CON_CMPCR_POS)

#define ENABLE_TIMER2          (T2CON |= TIMER2_T2CON_TR2_MSK)    /*!< Start TIMER2 */
#define DISABLE_TIMER2         (T2CON &= ~TIMER2_T2CON_TR2_MSK)   /*!< Stop TIMER2 */

#define TIMER2_SET_COMP_MODE   (T2CON |= TIMER2_T2CON_CMRL_MSK)   /*!< Set TIMER2 to compare mode */
#define TIMER2_SET_RELOAD_MODE (T2CON &= ~TIMER2_T2CON_CMRL_MSK)  /*!< Set TIMER2 to reload mode */

#define ENABLE_TIMER2_CMPCR    (T2CON |= TIMER2_T2CON_CMPCR_MSK)  /*!< Clear TIMER2 counter value on compare match */
#define DISABLE_TIMER2_CMPCR   (T2CON &= ~TIMER2_T2CON_CMPCR_MSK) /*!< Continue counting after compare match */

/**
 * Check TIMER2 Overflow Flag
 * @return 1: CPU executes TIMER2 interrupt service function
 * @note This bit is not automatically cleared by hardware, it needs to be cleared by software writing 0
 */
#define IS_TIME2_TF2_FLAG  (T2CON & (1 << 5))
#define CLR_TIME2_TF2_FLAG (T2CON &= ~(1 << 5)) /*!< Clear TIMER2 overflow flag */
/**
 * Check TIMER2 Compare Match Flag
 * @return 1: CPU executes TIMER2 interrupt service function
 * @note This bit is not automatically cleared by hardware, it needs to be cleared by software writing 0
 */
#define IS_TIME2_TC2_FLAG  (T2CON & (1 << 4))
#define CLR_TIME2_TC2_FLAG (T2CON &= ~(1 << 4)) /*!< Clear TIMER2 compare match flag */
/**@} */

/**@name TIMER2 Mode Selection Register - T2MOD
 * @{
 */
#define TIMER2_T2MOD_LDEN_POS  (7)
#define TIMER2_T2MOD_LDEN_MSK  (0x1 << TIMER2_T2MOD_LDEN_POS)
#define TIMER2_T2MOD_T2DIV_POS (4)
#define TIMER2_T2MOD_T2DIV_MSK (0x7 << TIMER2_T2MOD_T2DIV_POS)
#define TIMER2_T2MOD_CAPCR_POS (3)
#define TIMER2_T2MOD_CAPCR_MSK (0x1 << TIMER2_T2MOD_CAPCR_POS)
#define TIMER2_T2MOD_LDTS_POS  (0)
#define TIMER2_T2MOD_LDTS_MSK  (0x7 << TIMER2_T2MOD_LDTS_POS)

#define ENABLE_TIMER2_RELOAD                                                                                           \
    (T2MOD |= TIMER2_T2MOD_LDEN_MSK)  /*!< Enable automatic reload of RCMP2H and RCMP2L to TH2 and TL2 */
#define DISABLE_TIMER2_RELOAD                                                                                          \
    (T2MOD &= ~TIMER2_T2MOD_LDEN_MSK) /*!< Disable automatic reload of RCMP2H and RCMP2L to TH2 and TL2 */

#define TIMER2_T2DIV_1DIV   (0x00)
#define TIMER2_T2DIV_4DIV   (0x01)
#define TIMER2_T2DIV_16DIV  (0x02)
#define TIMER2_T2DIV_32DIV  (0x03)
#define TIMER2_T2DIV_64DIV  (0x04)
#define TIMER2_T2DIV_128DIV (0x05)
#define TIMER2_T2DIV_256DIV (0x06)
#define TIMER2_T2DIV_512DIV (0x07)
/**
 * TIMER2 Clock Division Value
 * @param[in] mode
 * -# TIMER2_T2DIV_1DIV:  TIMER2 clock divided by 1
 * -# TIMER2_T2DIV_4DIV:  TIMER2 clock divided by 4
 * -# TIMER2_T2DIV_16DIV: TIMER2 clock divided by 16
 * -# TIMER2_T2DIV_32DIV: TIMER2 clock divided by 32
 * -# TIMER2_T2DIV_64DIV: TIMER2 clock divided by 64
 * -# TIMER2_T2DIV_128DIV:TIMER2 clock divided by 128
 * -# TIMER2_T2DIV_256DIV:TIMER2 clock divided by 256
 * -# TIMER2_T2DIV_512DIV:TIMER2 clock divided by 512
 */
#define TIMER2_T2MOD_T2DIV_SET(mode)                                                                                   \
    (T2MOD = ((T2MOD & (~TIMER2_T2MOD_T2DIV_MSK)) | ((mode) << TIMER2_T2MOD_T2DIV_POS)))

#define ENABLE_TIMER2_CAPCR  (T2MOD |= TIMER2_T2MOD_CAPCR_MSK)  /*!< Clear TIMER2 counter value on capture event */
#define DISABLE_TIMER2_CAPCR (T2MOD &= ~TIMER2_T2MOD_CAPCR_MSK) /*!< Continue counting after capture event */

#define TIMER2_LDTS_CAP0     (0x00)
#define TIMER2_LDTS_CAP1     (0x01)
#define TIMER2_LDTS_CAP2     (0x02)
#define TIMER2_LDTS_CAP3     (0x03)
#define TIMER2_LDTS_OVER     (0x04)
/**
 * TIMER2 Auto-reload Trigger Selection
 * @param[in] mode
 * -# TIMER2_LDTS_CAP0: Auto-reload on capture channel 0 event
 * -# TIMER2_LDTS_CAP1: Auto-reload on capture channel 1 event
 * -# TIMER2_LDTS_CAP2: Auto-reload on capture channel 2 event
 * -# TIMER2_LDTS_CAP3: Auto-reload on capture channel 3 event
 * -# TIMER2_LDTS_OVER: Auto-reload on TIMER2 overflow
 */
#define TIMER2_T2MOD_LDTS_SET(mode) (T2MOD = ((T2MOD & (~TIMER2_T2MOD_LDTS_MSK)) | ((mode) << TIMER2_T2MOD_LDTS_POS)))
/**@} */

/**@name Input Capture Control Register 0 - CAPCON0
 * @{
 */
#define TIMER2_CAPCON0_CAPEN3_POS  (7)
#define TIMER2_CAPCON0_CAPEN3_MSK  (0x1 << TIMER2_CAPCON0_CAPEN3_POS)
#define TIMER2_CAPCON0_CAPEN2_POS  (6)
#define TIMER2_CAPCON0_CAPEN2_MSK  (0x1 << TIMER2_CAPCON0_CAPEN2_POS)
#define TIMER2_CAPCON0_CAPEN1_POS  (5)
#define TIMER2_CAPCON0_CAPEN1_MSK  (0x1 << TIMER2_CAPCON0_CAPEN1_POS)
#define TIMER2_CAPCON0_CAPEN0_POS  (4)
#define TIMER2_CAPCON0_CAPEN0_MSK  (0x1 << TIMER2_CAPCON0_CAPEN0_POS)
#define TIMER2_CAPCON0_CAPFEN3_POS (3)
#define TIMER2_CAPCON0_CAPFEN3_MSK (0x1 << TIMER2_CAPCON0_CAPFEN3_POS)
#define TIMER2_CAPCON0_CAPFEN2_POS (2)
#define TIMER2_CAPCON0_CAPFEN2_MSK (0x1 << TIMER2_CAPCON0_CAPFEN2_POS)
#define TIMER2_CAPCON0_CAPFEN1_POS (1)
#define TIMER2_CAPCON0_CAPFEN1_MSK (0x1 << TIMER2_CAPCON0_CAPFEN1_POS)
#define TIMER2_CAPCON0_CAPFEN0_POS (0)
#define TIMER2_CAPCON0_CAPFEN0_MSK (0x1 << TIMER2_CAPCON0_CAPFEN0_POS)

#define ENABLE_TIMER2_CAP3         (CAPCON0 |= TIMER2_CAPCON0_CAPEN3_MSK)  /*!< Enable TIMER2 input capture channel 3 */
#define DISABLE_TIMER2_CAP3        (CAPCON0 &= ~TIMER2_CAPCON0_CAPEN3_MSK) /*!< Disable TIMER2 input capture channel 3 */
#define ENABLE_TIMER2_CAP2         (CAPCON0 |= TIMER2_CAPCON0_CAPEN2_MSK)  /*!< Enable TIMER2 input capture channel 2 */
#define DISABLE_TIMER2_CAP2        (CAPCON0 &= ~TIMER2_CAPCON0_CAPEN2_MSK) /*!< Disable TIMER2 input capture channel 2 */
#define ENABLE_TIMER2_CAP1         (CAPCON0 |= TIMER2_CAPCON0_CAPEN1_MSK)  /*!< Enable TIMER2 input capture channel 1 */
#define DISABLE_TIMER2_CAP1        (CAPCON0 &= ~TIMER2_CAPCON0_CAPEN1_MSK) /*!< Disable TIMER2 input capture channel 1 */
#define ENABLE_TIMER2_CAP0         (CAPCON0 |= TIMER2_CAPCON0_CAPEN0_MSK)  /*!< Enable TIMER2 input capture channel 0 */
#define DISABLE_TIMER2_CAP0        (CAPCON0 &= ~TIMER2_CAPCON0_CAPEN0_MSK) /*!< Disable TIMER2 input capture channel 0 */

#define DISABLE_CAP_FILTER         (0)                                     /*!< Disable noise filter */
#define ENABLE_CAP_FILTER          (1)                                     /*!< Enable noise filter */
/**
 * TIMER2 Input Capture Channel 3 Noise Filter Enable
 * @param[in] status
 * -# DISABLE_CAP_FILTER: Disable noise filter on input capture channel 3
 * -# ENABLE_CAP_FILTER:  Enable noise filter on input capture channel 3
 */
#define TIMER2_CAPCON0_CAPFEN3_SET(status)                                                                             \
    (CAPCON0 = ((CAPCON0 & (~TIMER2_CAPCON0_CAPFEN3_MSK)) | ((status) << TIMER2_CAPCON0_CAPFEN3_POS)))
/**
 * TIMER2 Input Capture Channel 2 Noise Filter Enable
 * @param[in] status
 * -# DISABLE_CAP_FILTER: Disable noise filter on input capture channel 2
 * -# ENABLE_CAP_FILTER:  Enable noise filter on input capture channel 2
 */
#define TIMER2_CAPCON0_CAPFEN2_SET(status)                                                                             \
    (CAPCON0 = ((CAPCON0 & (~TIMER2_CAPCON0_CAPFEN2_MSK)) | ((status) << TIMER2_CAPCON0_CAPFEN2_POS)))
/**
 * TIMER2 Input Capture Channel 1 Noise Filter Enable
 * @param[in] status
 * -# DISABLE_CAP_FILTER: Disable noise filter on input capture channel 1
 * -# ENABLE_CAP_FILTER:  Enable noise filter on input capture channel 1
 */
#define TIMER2_CAPCON0_CAPFEN1_SET(status)                                                                             \
    (CAPCON0 = ((CAPCON0 & (~TIMER2_CAPCON0_CAPFEN1_MSK)) | ((status) << TIMER2_CAPCON0_CAPFEN1_POS)))

/**
 * TIMER2 Input Capture Channel 0 Noise Filter Enable
 * @param[in] status
 * -# DISABLE_CAP_FILTER: Disable noise filter on input capture channel 0
 * -# ENABLE_CAP_FILTER:  Enable noise filter on input capture channel 0
 */
#define TIMER2_CAPCON0_CAPFEN0_SET(status)                                                                             \
    (CAPCON0 = ((CAPCON0 & (~TIMER2_CAPCON0_CAPFEN0_MSK)) | ((status) << TIMER2_CAPCON0_CAPFEN0_POS)))

/**@} */

/**@name Input Capture Control Register 1 - CAPCON1
 * @{
 */
#define TIMER2_CAPCON1_CAP3LS_POS   (6)
#define TIMER2_CAPCON1_CAP3LS_MSK   (0x3 << TIMER2_CAPCON1_CAP3LS_POS)
#define TIMER2_CAPCON1_CAP2LS_POS   (4)
#define TIMER2_CAPCON1_CAP2LS_MSK   (0x3 << TIMER2_CAPCON1_CAP2LS_POS)
#define TIMER2_CAPCON1_CAP1LS_POS   (2)
#define TIMER2_CAPCON1_CAP1LS_MSK   (0x3 << TIMER2_CAPCON1_CAP1LS_POS)
#define TIMER2_CAPCON1_CAP0LS_POS   (0)
#define TIMER2_CAPCON1_CAP0LS_MSK   (0x3 << TIMER2_CAPCON1_CAP0LS_POS)

#define TIMER2_CAPLS_FALLING        (0x00)
#define TIMER2_CAPLS_RISING         (0x01)
#define TIMER2_CAPLS_RISING_FALLING (0x02)
/**
 * TIMER2 Input Capture Channel 3 Condition Selection
 * @param[in] mode
 * -# TIMER2_CAPLS_FALLING:        Falling edge
 * -# TIMER2_CAPLS_RISING:         Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Rising or falling edge
 */
#define TIMER2_CAPCON1_CAP3LS_SET(mode)                                                                                \
    (CAPCON1 = ((CAPCON1 & (~TIMER2_CAPCON1_CAP3LS_MSK)) | ((mode) << TIMER2_CAPCON1_CAP3LS_POS)))
#define GET_TIMER2_CAP3LS                                                                                              \
    ((CAPCON1 & TIMER2_CAPCON1_CAP3LS_MSK)                                                                             \
     >> TIMER2_CAPCON1_CAP3LS_POS) /*!< Get capture channel 3 trigger condition status */
/**
 * TIMER2 Input Capture Channel 2 Condition Selection
 * @param[in] mode
 * -# TIMER2_CAPLS_FALLING:        Falling edge
 * -# TIMER2_CAPLS_RISING:         Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Rising or falling edge
 */
#define TIMER2_CAPCON1_CAP2LS_SET(mode)                                                                                \
    (CAPCON1 = ((CAPCON1 & (~TIMER2_CAPCON1_CAP2LS_MSK)) | ((mode) << TIMER2_CAPCON1_CAP2LS_POS)))
#define GET_TIMER2_CAP2LS                                                                                              \
    ((CAPCON1 & TIMER2_CAPCON1_CAP2LS_MSK)                                                                             \
     >> TIMER2_CAPCON1_CAP2LS_POS) /*!< Get capture channel 2 trigger condition status */
/**
 * TIMER2 Input Capture Channel 1 Condition Selection
 * @param[in] mode
 * -# TIMER2_CAPLS_FALLING:        Falling edge
 * -# TIMER2_CAPLS_RISING:         Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Rising or falling edge
 */
#define TIMER2_CAPCON1_CAP1LS_SET(mode)                                                                                \
    (CAPCON1 = ((CAPCON1 & (~TIMER2_CAPCON1_CAP1LS_MSK)) | ((mode) << TIMER2_CAPCON1_CAP1LS_POS)))
#define GET_TIMER2_CAP1LS                                                                                              \
    ((CAPCON1 & TIMER2_CAPCON1_CAP1LS_MSK)                                                                             \
     >> TIMER2_CAPCON1_CAP1LS_POS) /*!< Get capture channel 1 trigger condition status */

/**
 * TIMER2 Input Capture Channel 0 Condition Selection
 * @param[in] mode
 * -# TIMER2_CAPLS_FALLING:        Falling edge
 * -# TIMER2_CAPLS_RISING:         Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Rising or falling edge
 */
#define TIMER2_CAPCON1_CAP0LS_SET(mode)                                                                                \
    (CAPCON1 = ((CAPCON1 & (~TIMER2_CAPCON1_CAP0LS_MSK)) | ((mode) << TIMER2_CAPCON1_CAP0LS_POS)))
#define GET_TIMER2_CAP0LS                                                                                              \
    ((CAPCON1 & TIMER2_CAPCON1_CAP0LS_MSK)                                                                             \
     >> TIMER2_CAPCON1_CAP0LS_POS) /*!< Get capture channel 0 trigger condition status */

/**@} */

/**@name Input Capture Control Register 2 - CAPCON2
 * @{
 */
#define TIMER2_CAPCON2_CAPF3_POS (3)
#define TIMER2_CAPCON2_CAPF3_MSK (0x1 << TIMER2_CAPCON2_CAPF3_POS)
#define TIMER2_CAPCON2_CAPF2_POS (2)
#define TIMER2_CAPCON2_CAPF2_MSK (0x1 << TIMER2_CAPCON2_CAPF2_POS)
#define TIMER2_CAPCON2_CAPF1_POS (1)
#define TIMER2_CAPCON2_CAPF1_MSK (0x1 << TIMER2_CAPCON2_CAPF1_POS)
#define TIMER2_CAPCON2_CAPF0_POS (0)
#define TIMER2_CAPCON2_CAPF0_MSK (0x1 << TIMER2_CAPCON2_CAPF0_POS)

/**
 * Input Capture Channel 0 Flag
 * @return 1: Input capture channel 0 detected an edge trigger event
 * @note   This bit is set by hardware and cleared by software writing 0
 */
#define IS_TIME2_CAPF0_FLAG  ((CAPCON2 & TIMER2_CAPCON2_CAPF0_MSK) >> TIMER2_CAPCON2_CAPF0_POS)
#define CLR_TIME2_CAPF0_FLAG (CAPCON2 &= ~TIMER2_CAPCON2_CAPF0_MSK) /*!< Clear input capture channel 0 flag */
/**
 * Input Capture Channel 1 Flag
 * @return 1: Input capture channel 1 detected an edge trigger event
 * @note   This bit is set by hardware and cleared by software writing 0
 */
#define IS_TIME2_CAPF1_FLAG  ((CAPCON2 & TIMER2_CAPCON2_CAPF1_MSK) >> TIMER2_CAPCON2_CAPF1_POS)
#define CLR_TIME2_CAPF1_FLAG (CAPCON2 &= ~TIMER2_CAPCON2_CAPF1_MSK) /*!< Clear input capture channel 1 flag */
/**
 * Input Capture Channel 2 Flag
 * @return 1: Input capture channel 2 detected an edge trigger event
 * @note   This bit is set by hardware and cleared by software writing 0
 */
#define IS_TIME2_CAPF2_FLAG  ((CAPCON2 & TIMER2_CAPCON2_CAPF2_MSK) >> TIMER2_CAPCON2_CAPF2_POS)
#define CLR_TIME2_CAPF2_FLAG (CAPCON2 &= ~TIMER2_CAPCON2_CAPF2_MSK) /*!< Clear input capture channel 2 flag */
/**
 * Input Capture Channel 3 Flag
 * @return 1: Input capture channel 3 detected an edge trigger event
 * @note   This bit is set by hardware and cleared by software writing 0
 */
#define IS_TIME2_CAPF3_FLAG  ((CAPCON2 & TIMER2_CAPCON2_CAPF3_MSK) >> TIMER2_CAPCON2_CAPF3_POS)
#define CLR_TIME2_CAPF3_FLAG (CAPCON2 &= ~TIMER2_CAPCON2_CAPF3_MSK) /*!< Clear input capture channel 3 flag */
/**@} */

/**@name TIMER3 Control Register - T3CON
 * @{
 */
#define TIMER3_DIV_REV        (0x0) /*!< Reserved */
#define TIMER3_DIV_2          (0x1) /*!< Divide by 2, TIMER3 clock is CLK_P/2 */
#define TIMER3_DIV_4          (0x2) /*!< Divide by 4, TIMER3 clock is CLK_P/4 */
#define TIMER3_DIV_8          (0x3) /*!< Divide by 8, TIMER3 clock is CLK_P/8 */
#define TIMER3_DIV_16         (0x4) /*!< Divide by 16, TIMER3 clock is CLK_P/16 */
#define TIMER3_DIV_32         (0x5) /*!< Divide by 32, TIMER3 clock is CLK_P/32 */
#define TIMER3_DIV_64         (0x6) /*!< Divide by 64, TIMER3 clock is CLK_P/64 */
#define TIMER3_DIV_128        (0x7) /*!< Divide by 128, TIMER3 clock is CLK_P/128 */
#define TIMER3_DIV_SLE        TIMER3_DIV_2

#define UART_TIMER3_DIV_SLE   TIMER3_DIV_2 /*!< UART TIMER3 clock division selection */

#define TIMER3_T3CON_TR3_POS  (6)
#define TIMER3_T3CON_TR3_MSK  (0x1 << TIMER3_T3CON_TR3_POS)
#define TIMER3_T3CON_T3PS_POS (0)
#define TIMER3_T3CON_T3PS_MSK (0x7 << TIMER3_T3CON_T3PS_POS)

#define ENABLE_TIMER3         (T3CON |= TIMER3_T3CON_TR3_MSK)  /*!< Start TIMER3 */
#define DISABLE_TIMER3        (T3CON &= ~TIMER3_T3CON_TR3_MSK) /*!< Stop TIMER3 */

/**
 * TIMER3 Division Selection
 * @param[in] mode
 * -# TIMER3_DIV_2: Divide by 2, TIMER3 clock is CLK_P/2
 * -# TIMER3_DIV_4: Divide by 4, TIMER3 clock is CLK_P/4
 * -# TIMER3_DIV_8: Divide by 8, TIMER3 clock is CLK_P/8
 * -# TIMER3_DIV_16: Divide by 16, TIMER3 clock is CLK_P/16
 * -# TIMER3_DIV_REV: Reserved
 */
#define TIMER3_T3CON_DIV_SET(mode) (T3CON = ((T3CON & (~TIMER3_T3CON_T3PS_MSK)) | ((mode) << TIMER3_T3CON_T3PS_POS)))
/**@} */

/**@name TIMER3 Data Register - T3RH T3RL
 * @{
 */
/**
 * TIMER3 Data Register
 * @param[in] dataH  High byte of Timer3 data register
 * @param[in] dataL  Low byte of Timer3 data register
 */
#define TIMER3_DATA_REG(dataH, dataL)                                                                                  \
    T3RH = (dataH);                                                                                                    \
    T3RL = (dataL);
/**@} */

/**@name External Functions
 * @{
 */
void TIMER0_ConfigMode(uint8_t u8mode, uint8_t u8gate, uint8_t u8cnt);
void TIMER1_ConfigMode(uint8_t u8mode, uint8_t u8gate, uint8_t u8cnt);
void TIMER2_ConfigCap0Mode(uint8_t u8trigger, uint8_t u8filter);
void TIMER2_ConfigCap1Mode(uint8_t u8trigger, uint8_t u8filter);
void TIMER2_ConfigCap2Mode(uint8_t u8trigger, uint8_t u8filter);
void TIMER2_ConfigCap3Mode(uint8_t u8trigger, uint8_t u8filter);
/**@} */

#endif /* __TIMER_H__ */
