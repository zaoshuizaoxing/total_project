/**
 * @file      uart.c
 * @brief     UART Module Driver
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "timer.h"
#include "uart.h"

/**
 * Configures UART Baud Rate
 * @param[in] u8UartNum  UART number
 * -# UART_0
 * -# UART_1
 * @param[in] u8Timer Timer selection
 * -# UART_TIMER1
 * -# UART_TIMER3
 * @param[in] u32BaudRate UART Baud Rate
 * @param[in] u8Double Baud rate doubling enable
 * -# ENABLE_DOUBLE_BRT   Enable doubling
 * -# DISABLE_DOUBLE_BRT  Disable doubling
 */
void UART_ConfigBaudRate(uint8_t u8UartNum, uint8_t u8Timer, uint32_t u32BaudRate, uint8_t u8Double)
{
    uint16_t u16Timer3PS;
    uint8_t  u8UartDouble; /* UART doubling enable variable */

    if(u8Double == DISABLE_DOUBLE_BRT)
    {
        if(UART_0 == u8UartNum)
        {
            DISABLE_UART0_SMOD; /* Disable UART0 doubling */
        }
        else
        {
            DISABLE_UART1_SMOD; /* Disable UART1 doubling */
        }
        u8UartDouble = 0;
    }
    else
    {
        if(UART_0 == u8UartNum)
        {
            ENABLE_UART0_SMOD; /* Enable UART0 doubling */
        }
        else
        {
            ENABLE_UART1_SMOD; /* Enable UART1 doubling */
        }
        u8UartDouble = 1;
    }

    switch(u8Timer)
    {
        case UART_TIMER1:
            if(UART_0 == u8UartNum)
            {
                UART0_SCKS_SET(UART_TIMER1); /* Set UART0 to use TIMER1 as clock source */
            }
            else
            {
                UART1_SCKS_SET(UART_TIMER1);     /* Set UART1 to use TIMER1 as clock source */
            }
            TIMER1_TMOD_CNT1_SET(CLR_BIT);       /* Set clock source to internal clock */
            TIMER1_TMOD_GATE1_SET(CLR_BIT);      /* Start counting when TCON.TR1 is set to 1 */
            TIMER1_TMOD_MODE_SET(TIMER01_MODE2); /* 8-bit auto-reload timer/counter */
            TH1 = 256 - ((1 + u8UartDouble) * g_u32SystemClock) / (32 * 2 * u32BaudRate); /* Configure baud rate */
            ENABLE_TIMER1;                                                                /* Start TIMER1 */
            break;
        case UART_TIMER3:
            if(UART_0 == u8UartNum)
            {
                UART0_SCKS_SET(UART_TIMER3); /* Set UART0 to use TIMER3 as clock source */
            }
            else
            {
                UART1_SCKS_SET(UART_TIMER3);           /* Set UART1 to use TIMER3 as clock source */
            }
            TIMER3_T3CON_DIV_SET(UART_TIMER3_DIV_SLE); /* Set TIMER3 prescaler */
            u16Timer3PS
                = 65536 - ((1 + u8UartDouble) * g_u32SystemClock) / (32 * (1 << UART_TIMER3_DIV_SLE) * u32BaudRate);
            T3RH = (u16Timer3PS >> 8) & 0xFF;
            T3RL = (u16Timer3PS >> 0) & 0xFF;
            ENABLE_TIMER3; /* Start TIMER3 */
            break;
        default:
            break;
    }
}
