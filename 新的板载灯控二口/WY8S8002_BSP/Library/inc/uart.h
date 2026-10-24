/**
 * @file      uart.h
 * @brief     UART Driver Configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __UART_H__
#define __UART_H__

#include "WY8S8002xx.h"

#define UART_0 (0)
#define UART_1 (1)

/**@name UART Control Registers - SCON, SCON_1
 * @{
 */
#define UART_SCON_SM01_POS  (6)
#define UART_SCON_SM01_MSK  (0x3 << UART_SCON_SM01_POS)

#define UART_8BIT_SYN_MODE  (0x00) /*!< 8-bit Master Synchronous Mode, CLK_P/2 */
#define UART_8BIT_ASY_MODE  (0x01) /*!< 8-bit Asynchronous Mode, Variable Baud Rate */
#define UART_9BIT_ASY_SMODE (0x02) /*!< 9-bit Asynchronous Mode, Baud Rate is CLK_P/32 or CLK_P/64 */
#define UART_9BIT_ASY_CMODE (0x03) /*!< 9-bit Asynchronous Mode, Variable Baud Rate */
/**
 * UART0 Mode Selection
 * @param[in] mode
 * -# UART_8BIT_SYN_MODE:  8-bit Master Synchronous Mode, CLK_P/2
 * -# UART_8BIT_ASY_MODE:  8-bit Asynchronous Mode, Variable Baud Rate
 * -# UART_9BIT_ASY_SMODE: 9-bit Asynchronous Mode, Baud Rate is CLK_P/32 or CLK_P/64
 * -# UART_9BIT_ASY_CMODE: 9-bit Asynchronous Mode, Variable Baud Rate
 */
#define UART0_SCON_MODE_SET(mode) (SCON = ((SCON & (~UART_SCON_SM01_MSK)) | ((mode) << UART_SCON_SM01_POS)))

#define ENABLE_UART0_SM2          (SM2 = 1) /*!< Enable UART0 Multi-processor Communication Mode */
#define DISABLE_UART0_SM2         (SM2 = 0) /*!< Disable UART0 Multi-processor Communication Mode */

#define ENABLE_UART0_REN          (REN = 1) /*!< Enable UART0 Reception */
#define DISABLE_UART0_REN         (REN = 0) /*!< Disable UART0 Reception */

/**
 * UART0 Transmit Interrupt Flag
 * @return 1: Byte transmission completed, must be cleared by software\n
 *         0: Byte is being transmitted or no data has been transmitted
 */
#define IS_UART0_TI_FLAG  (TI)
#define CLR_UART0_TI_FLAG (TI = 0) /*!< Clear Transmit Interrupt Flag */

/**
 * UART0 Receive Interrupt Flag
 * @return 1: Byte reception completed, must be cleared by software\n
 *         0: Byte is being received or no data has been received
 */
#define IS_UART0_RI_FLAG  (RI)
#define CLR_UART0_RI_FLAG (RI = 0) /*!< Clear Receive Interrupt Flag */
/**
 * UART1 Mode Selection
 * @param[in] mode
 * -# UART_8BIT_SYN_MODE: 8-bit Master Synchronous Mode, CLK_P/2
 * -# UART_8BIT_ASY_MODE:  8-bit Asynchronous Mode, Variable Baud Rate
 * -# UART_9BIT_ASY_SMODE: 9-bit Asynchronous Mode, Baud Rate is CLK_P/32 or CLK_P/64
 * -# UART_9BIT_ASY_CMODE: 9-bit Asynchronous Mode, Variable Baud Rate
 */
#define UART1_SCON_MODE_SET(mode) (SCON_1 = ((SCON_1 & (~UART_SCON_SM01_MSK)) | ((mode) << UART_SCON_SM01_POS)))

#define ENABLE_UART1_SM2          (SM2_1 = 1) /*!< Enable UART1 Multi-processor Communication Mode */
#define DISABLE_UART1_SM2         (SM2_1 = 0) /*!< Disable UART1 Multi-processor Communication Mode */

#define ENABLE_UART1_REN          (REN_1 = 1) /*!< Enable UART1 Reception */
#define DISABLE_UART1_REN         (REN_1 = 0) /*!< Disable UART1 Reception */

/**
 * UART1 Receive Interrupt Flag
 * @return 1: Byte reception completed, must be cleared by software\n
 *         0: Byte is being received or no data has been received
 */
#define IS_UART1_RI_FLAG  (RI_1)
#define CLR_UART1_RI_FLAG (RI_1 = 0) /*!< Clear Receive Interrupt Flag */
/**
 * UART1 Transmit Interrupt Flag
 * @return 1: Byte transmission completed, must be cleared by software\n
 *         0: Byte is being transmitted or no data has been transmitted
 */
#define IS_UART1_TI_FLAG  (TI_1)
#define CLR_UART1_TI_FLAG (TI_1 = 0) /*!< Clear Transmit Interrupt Flag */
/**@} */

/**@name UART0/1 Baud Rate Selection Register - SCKS
 * @{
 */
#define UART_SCKS_SMOD1_POS (7)
#define UART_SCKS_SMOD1_MSK (0x1 << UART_SCKS_SMOD1_POS)
#define UART_SCKS_SCKS1_POS (6)
#define UART_SCKS_SCKS1_MSK (0x1 << UART_SCKS_SCKS1_POS)
#define UART_SCKS_SCKS0_POS (5)
#define UART_SCKS_SCKS0_MSK (0x1 << UART_SCKS_SCKS0_POS)

#define ENABLE_UART1_SMOD   (SCKS |= UART_SCKS_SMOD1_MSK)  /*!< Enable UART1 Baud Rate Double */
#define DISABLE_UART1_SMOD  (SCKS &= ~UART_SCKS_SMOD1_MSK) /*!< Disable UART1 Baud Rate Double */

#define UART_TIMER3         (0)
#define UART_TIMER1         (1)
/**
 * UART1 Baud Rate Clock Source Selection
 * @param[in] status
 * -# UART_TIMER1: Baud rate clock source TIMER1
 * -# UART_TIMER3: Baud rate clock source TIMER3
 */
#define UART1_SCKS_SET(status) (SCKS = ((SCKS & (~UART_SCKS_SCKS1_MSK)) | ((status) << UART_SCKS_SCKS1_POS)))

/**
 * UART0 Baud Rate Clock Source Selection
 * @param[in] status
 * -# UART_TIMER1: Baud rate clock source TIMER1
 * -# UART_TIMER3: Baud rate clock source TIMER3
 */
#define UART0_SCKS_SET(status) (SCKS = ((SCKS & (~UART_SCKS_SCKS0_MSK)) | ((status) << UART_SCKS_SCKS0_POS)))
/**@} */

/**@name UART0 Baud Rate Double Enable Configuration
 * @{
 */
#define POWER_PCON_SMOD0_POS (7)
#define POWER_PCON_SMOD0_MSK (0x1 << POWER_PCON_SMOD0_POS)

#define ENABLE_UART0_SMOD    (PCON |= POWER_PCON_SMOD0_MSK)  /*!< Enable UART0 Baud Rate Double */
#define DISABLE_UART0_SMOD   (PCON &= ~POWER_PCON_SMOD0_MSK) /*!< Disable UART0 Baud Rate Double */
/**@} */
#define ENABLE_DOUBLE_BRT  (1) /*!< Enable UART Baud Rate Double */
#define DISABLE_DOUBLE_BRT (0) /*!< Disable UART Baud Rate Double */

/**
 * Write Data to UART0 SBUF
 * @param[in] u8data Data to be written
 */
#define UART0_WRITE_SBUF(u8data) (SBUF = (u8data))
/**
 * Read Data from UART0 SBUF
 * @return Data read from SBUF
 */
#define UART0_READ_SBUF (SBUF)
/**
 * Write Data to UART1 SBUF_1
 * @param[in] u8data Data to be written
 */
#define UART1_WRITE_SBUF(u8data) (SBUF_1 = (u8data))
/**
 * Read Data from UART1 SBUF_1
 * @return Data read from SBUF_1
 */
#define UART1_READ_SBUF (SBUF_1)

/**
 * Write Data to UART0 TB8
 * @param[in] bdata Data to be written (1-bit width)
 */
#define UART0_WRITE_TB8(bdata) (TB8 = (bdata))
/**
 * Read Data from UART0 RB8
 * @return Data read from RB8 (1-bit width)
 */
#define UART0_READ_RB8 (RB8)
/**
 * Write Data to UART1 TB8_1
 * @param[in] bdata Data to be written (1-bit width)
 */
#define UART1_WRITE_TB8(bdata) (TB8_1 = (bdata))
/**
 * Read Data from UART1 RB8_1
 * @return Data read from RB8_1 (1-bit width)
 */
#define UART1_READ_RB8 (RB8_1)

/**@name External Functions
 * @{
 */
void UART_ConfigBaudRate(uint8_t u8UartNum, uint8_t u8Timer, uint32_t u32BaudRate, uint8_t u8Double);
/**@} */

#endif /* __UART_H__ */
