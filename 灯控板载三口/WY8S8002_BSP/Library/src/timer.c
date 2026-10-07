/**
 * @file      timer.c
 * @brief     TIMER Module Driver
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "timer.h"

/**
 * Configures TIMER0 mode
 * @param[in] u8mode  Mode selection
 * -# TIMER01_MODE0  Mode 0, 13-bit Timer/Counter
 * -# TIMER01_MODE1  Mode 1, 16-bit Timer/Counter
 * -# TIMER01_MODE2  Mode 2, 8-bit Timer/Counter, reloads value from TH on TL overflow
 * -# TIMER01_MODE3  Mode 3, TL0 as 8-bit Timer/Counter (controlled by TIMER0), TH0 as 8-bit Timer/Counter (controlled
 * by TIMER1)
 * @param[in] u8gate Gate control
 * -# TIMER01_TR_GATE:    Starts counting when TCON.TR0 is set to 1
 * -# TIMER01_INT_TR_GATE:Starts counting when both INT0 and TR0 are set to 1
 * @param[in] u8cnt Clock source selection
 * -# TIMER01_ICLK: As Timer0, the driving clock is from the internal clock input
 * -# TIMER01_TCLK: As Counter0, the driving clock is from the T0 pin input
 */
void TIMER0_ConfigMode(uint8_t u8mode, uint8_t u8gate, uint8_t u8cnt)
{
    TIMER0_TMOD_MODE_SET(u8mode);  /* Mode selection */
    TIMER0_TMOD_GATE0_SET(u8gate); /* Gate control */
    TIMER0_TMOD_CNT0_SET(u8cnt);   /* Clock source selection */
}

/**
 * Configures TIMER1 mode
 * @param[in] u8mode  Mode selection
 * -# TIMER01_MODE0  Mode 0, 13-bit Timer/Counter
 * -# TIMER01_MODE1  Mode 1, 16-bit Timer/Counter
 * -# TIMER01_MODE2  Mode 2, 8-bit Timer/Counter, reloads value from TH on TL overflow
 * -# TIMER01_MODE3  Mode 3, TL0 as 8-bit Timer/Counter (controlled by TIMER0), TH0 as 8-bit Timer/Counter (controlled
 * by TIMER1)
 * @param[in] u8gate Gate control
 * -# TIMER01_TR_GATE:    Starts counting when TCON.TR1 is set to 1
 * -# TIMER01_INT_TR_GATE:Starts counting when both INT1 and TR1 are set to 1
 * @param[in] u8cnt Clock source selection
 * -# TIMER01_ICLK: As Timer1, the driving clock is from the internal clock input
 * -# TIMER01_TCLK: As Counter1, the driving clock is from the T1 pin input
 */
void TIMER1_ConfigMode(uint8_t u8mode, uint8_t u8gate, uint8_t u8cnt)
{
    TIMER1_TMOD_MODE_SET(u8mode);  /* Mode selection */
    TIMER1_TMOD_GATE1_SET(u8gate); /* Gate control */
    TIMER1_TMOD_CNT1_SET(u8cnt);   /* Clock source selection */
}

/**
 * Configures TIMER2 capture channel 0
 * @param[in] u8trigger Capture trigger mode
 * -# TIMER2_CAPLS_FALLING: Falling edge
 * -# TIMER2_CAPLS_RISING: Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Both rising and falling edges
 * @param[in] u8filter Enable/disable noise filter
 * -# DISABLE_CAP_FILTER: Disable noise filter on the capture channel
 * -# ENABLE_CAP_FILTER: Enable noise filter on the capture channel
 */
void TIMER2_ConfigCap0Mode(uint8_t u8trigger, uint8_t u8filter)
{
    TIMER2_CAPCON1_CAP0LS_SET(u8trigger);
    TIMER2_CAPCON0_CAPFEN0_SET(u8filter);
}

/**
 * Configures TIMER2 capture channel 1
 * @param[in] u8trigger Capture trigger mode
 * -# TIMER2_CAPLS_FALLING: Falling edge
 * -# TIMER2_CAPLS_RISING: Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Both rising and falling edges
 * @param[in] u8filter Enable/disable noise filter
 * -# DISABLE_CAP_FILTER: Disable noise filter on the capture channel
 * -# ENABLE_CAP_FILTER: Enable noise filter on the capture channel
 */
void TIMER2_ConfigCap1Mode(uint8_t u8trigger, uint8_t u8filter)
{
    TIMER2_CAPCON1_CAP1LS_SET(u8trigger);
    TIMER2_CAPCON0_CAPFEN1_SET(u8filter);
}

/**
 * Configures TIMER2 capture channel 2
 * @param[in] u8trigger Capture trigger mode
 * -# TIMER2_CAPLS_FALLING: Falling edge
 * -# TIMER2_CAPLS_RISING: Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Both rising and falling edges
 * @param[in] u8filter Enable/disable noise filter
 * -# DISABLE_CAP_FILTER: Disable noise filter on the capture channel
 * -# ENABLE_CAP_FILTER: Enable noise filter on the capture channel
 */
void TIMER2_ConfigCap2Mode(uint8_t u8trigger, uint8_t u8filter)
{
    TIMER2_CAPCON1_CAP2LS_SET(u8trigger);
    TIMER2_CAPCON0_CAPFEN2_SET(u8filter);
}

/**
 * Configures TIMER2 capture channel 3
 * @param[in] u8trigger Capture trigger mode
 * -# TIMER2_CAPLS_FALLING: Falling edge
 * -# TIMER2_CAPLS_RISING: Rising edge
 * -# TIMER2_CAPLS_RISING_FALLING: Both rising and falling edges
 * @param[in] u8filter Enable/disable noise filter
 * -# DISABLE_CAP_FILTER: Disable noise filter on the capture channel
 * -# ENABLE_CAP_FILTER: Enable noise filter on the capture channel
 */
void TIMER2_ConfigCap3Mode(uint8_t u8trigger, uint8_t u8filter)
{
    TIMER2_CAPCON1_CAP3LS_SET(u8trigger);
    TIMER2_CAPCON0_CAPFEN3_SET(u8filter);
}
