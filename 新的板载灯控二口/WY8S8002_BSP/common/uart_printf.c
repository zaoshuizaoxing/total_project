/**
 * @file      uart_printf.c
 * @brief     Implementation of printf function construction
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "timer.h"
#include "uart.h"
#include "uart_printf.h"

/**
 * UART0 initialization configuration
 * @note This UART0 is used for print testing of various modules.
 * @note Calling the printf function will increase the code size (about 2KB); it is recommended to use it only during
 * the debugging phase.
 */
void UART0_Test(void)
{
    PORT_SET_MUX(PIO04CFG, UART0_RXD_MUX_MODE); /* Configure P04 pin as UART0_RX */
    PORT_SET_MUX(PIO05CFG, UART0_TXD_MUX_MODE); /* Configure P05 pin as UART0_TX */

    UART0_SCON_MODE_SET(UART_8BIT_ASY_MODE);
    ENABLE_UART0_SM2;
    UART0_SCKS_SET(UART_TIMER3);
    TIMER3_T3CON_DIV_SET(TIMER3_DIV_2);
    ENABLE_UART0_SMOD;
    /* Baud rate configured to 9600bps */
    T3RH = 0xFF; /* 65536 - (2 * g_u32SystemClock) / (32 * 2 * 9600) */
    T3RL = 0xCB;
    ENABLE_TIMER3;
}

/**
 * Builds the printf function using the "stdio.h" library
 * @param[in] c  Data to be sent
 * @return Data sent over the serial port
 */
char putchar(char c)
{
    TI   = 0;
    SBUF = c;
    while(!TI)
        ;
    TI = 0;
    return c;
}
