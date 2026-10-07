/**
 * @file      common.h
 * @brief     Common driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __COMMON_H__
#define __COMMON_H__

#include "WY8S8002xx.h"

#define SET_BIT     (1U) /*!< Set BIT to 1 */
#define CLR_BIT     (0U) /*!< Clear BIT to 0 */

#define OUTPUT_HIGH (1)  /*!< Output high level */
#define OUTPUT_LOW  (0)  /*!< Output low level */

#define BIT0        (0x01U)
#define BIT1        (0x02U)
#define BIT2        (0x04U)
#define BIT3        (0x08U)
#define BIT4        (0x10U)
#define BIT5        (0x20U)
#define BIT6        (0x40U)
#define BIT7        (0x80U)

/**@name Interrupt Vector Number Definitions
 * @{
 */
#define INT0_VECTOR   0  /*!< INT0 interrupt number */
#define BOD_VECTOR    1  /*!< Brown-out Detection interrupt number */
#define INT1_VECTOR   2  /*!< INT1 interrupt number */
#define TIMER0_VECTOR 3  /*!< TIMER0 interrupt number */
#define UART0_VECTOR  4  /*!< UART0 interrupt number */
#define TIMER1_VECTOR 5  /*!< TIMER1 interrupt number */
#define UART1_VECTOR  6  /*!< UART1 interrupt number */
#define WDT_VECTOR    7  /*!< Watchdog Timer interrupt number */
#define TIMER2_VECTOR 8  /*!< TIMER2 interrupt number */
#define TIMER3_VECTOR 9  /*!< TIMER3 interrupt number */
#define SPI_VECTOR    10 /*!< SPI interrupt number */
#define GPIO_VECTOR   11 /*!< GPIO interrupt number */
#define ADC_VECTOR    12 /*!< ADC interrupt number */
#define PWM_VECTOR    13 /*!< PWM interrupt number */
#define FB_VECTOR     14 /*!< Brake interrupt number */
#define SWT_VECTOR    16 /*!< SWT Self-Wake-up interrupt number */
#define IR_VECTOR   	17 /*!< IR interrupt number */
/**@} */

/**@name Interrupt Mask Registers
 * @{
 */
#define ENABLE_ALL_INT    (EA = 1)       /*!< Enable global interrupts */
#define DISABLE_ALL_INT   (EA = 0)       /*!< Disable global interrupts */
#define ENABLE_UART1_INT  (ET6 = 1)      /*!< Enable UART1 interrupt */
#define DISABLE_UART1_INT (ET6 = 0)      /*!< Disable UART1 interrupt */
#define ENABLE_TIME1_INT  (ET5 = 1)      /*!< Enable TIMER1 interrupt */
#define DISABLE_TIME1_INT (ET5 = 0)      /*!< Disable TIMER1 interrupt */
#define ENABLE_UART0_INT  (ET4 = 1)      /*!< Enable UART0 interrupt */
#define DISABLE_UART0_INT (ET4 = 0)      /*!< Disable UART0 interrupt */
#define ENABLE_TIME0_INT  (ET3 = 1)      /*!< Enable TIMER0 interrupt */
#define DISABLE_TIME0_INT (ET3 = 0)      /*!< Disable TIMER0 interrupt */
#define ENABLE_INT1_INT   (ET2 = 1)      /*!< Enable INT1 interrupt */
#define DISABLE_INT1_INT  (ET2 = 0)      /*!< Disable INT1 interrupt */
#define ENABLE_BOD_INT    (ET1 = 1)      /*!< Enable BOD interrupt */
#define DISABLE_BOD_INT   (ET1 = 0)      /*!< Disable BOD interrupt */
#define ENABLE_INT0_INT   (ET0 = 1)      /*!< Enable INT0 interrupt */
#define DISABLE_INT0_INT  (ET0 = 0)      /*!< Disable INT0 interrupt */

#define ENABLE_FB_INT     (EI1 |= BIT7)  /*!< Enable Brake interrupt */
#define DISABLE_FB_INT    (EI1 &= ~BIT7) /*!< Disable Brake interrupt */
#define ENABLE_PWM_INT    (EI1 |= BIT6)  /*!< Enable PWM interrupt */
#define DISABLE_PWM_INT   (EI1 &= ~BIT6) /*!< Disable PWM interrupt */
#define ENABLE_ADC_INT    (EI1 |= BIT5)  /*!< Enable ADC interrupt */
#define DISABLE_ADC_INT   (EI1 &= ~BIT5) /*!< Disable ADC interrupt */
#define ENABLE_GPIO_INT   (EI1 |= BIT4)  /*!< Enable GPIO interrupt */
#define DISABLE_GPIO_INT  (EI1 &= ~BIT4) /*!< Disable GPIO interrupt */
#define ENABLE_SPI_INT    (EI1 |= BIT3)  /*!< Enable SPI interrupt */
#define DISABLE_SPI_INT   (EI1 &= ~BIT3) /*!< Disable SPI interrupt */
#define ENABLE_TIME3_INT  (EI1 |= BIT2)  /*!< Enable TIMER3 interrupt */
#define DISABLE_TIME3_INT (EI1 &= ~BIT2) /*!< Disable TIMER3 interrupt */
#define ENABLE_TIME2_INT  (EI1 |= BIT1)  /*!< Enable TIMER2 interrupt */
#define DISABLE_TIME2_INT (EI1 &= ~BIT1) /*!< Disable TIMER2 interrupt */
#define ENABLE_WDT_INT    (EI1 |= BIT0)  /*!< Enable Watchdog Timer interrupt */
#define DISABLE_WDT_INT   (EI1 &= ~BIT0) /*!< Disable Watchdog Timer interrupt */

#define ENABLE_IR_INT   	(EI2 |= BIT2)  /*!< Enable IR interrupt */
#define DISABLE_IR_INT  	(EI2 &= ~BIT2) /*!< Disable IR interrupt */
#define ENABLE_SWT_INT    (EI2 |= BIT1)  /*!< Enable SWT interrupt */
#define DISABLE_SWT_INT   (EI2 &= ~BIT1) /*!< Disable SWT interrupt */

/**@} */
/**@name Interrupt Priority Control Registers
 * @{
 */
#define UART1_PRIORITY_H  (IP |= BIT6)   /*!< High priority for UART1 */
#define UART1_PRIORITY_L  (IP &= ~BIT6)  /*!< Low priority for UART1 */
#define TIME1_PRIORITY_H  (IP |= BIT5)   /*!< High priority for TIMER1 */
#define TIME1_PRIORITY_L  (IP &= ~BIT5)  /*!< Low priority for TIMER1 */
#define UART0_PRIORITY_H  (IP |= BIT4)   /*!< High priority for UART0 */
#define UART0_PRIORITY_L  (IP &= ~BIT4)  /*!< Low priority for UART0 */
#define TIME0_PRIORITY_H  (IP |= BIT3)   /*!< High priority for TIMER0 */
#define TIME0_PRIORITY_L  (IP &= ~BIT3)  /*!< Low priority for TIMER0 */
#define INT1_PRIORITY_H   (IP |= BIT2)   /*!< High priority for INT1 */
#define INT1_PRIORITY_L   (IP &= ~BIT2)  /*!< Low priority for INT1 */
#define BOD_PRIORITY_H    (IP |= BIT1)   /*!< High priority for BOD */
#define BOD_PRIORITY_L    (IP &= ~BIT1)  /*!< Low priority for BOD */
#define INT0_PRIORITY_H   (IP |= BIT0)   /*!< High priority for INT0 */
#define INT0_PRIORITY_L   (IP &= ~BIT0)  /*!< Low priority for INT0 */

#define FB_PRIORITY_H     (IP1 |= BIT7)  /*!< High priority for Brake */
#define FB_PRIORITY_L     (IP1 &= ~BIT7) /*!< Low priority for Brake */
#define PWM_PRIORITY_H    (IP1 |= BIT6)  /*!< High priority for PWM */
#define PWM_PRIORITY_L    (IP1 &= ~BIT6) /*!< Low priority for PWM */
#define ADC_PRIORITY_H    (IP1 |= BIT5)  /*!< High priority for ADC */
#define ADC_PRIORITY_L    (IP1 &= ~BIT5) /*!< Low priority for ADC */
#define GPIO_PRIORITY_H   (IP1 |= BIT4)  /*!< High priority for GPIO */
#define GPIO_PRIORITY_L   (IP1 &= ~BIT4) /*!< Low priority for GPIO */
#define SPI_PRIORITY_H    (IP1 |= BIT3)  /*!< High priority for SPI */
#define SPI_PRIORITY_L    (IP1 &= ~BIT3) /*!< Low priority for SPI */
#define TIMER3_PRIORITY_H (IP1 |= BIT2)  /*!< High priority for TIMER3 */
#define TIMER3_PRIORITY_L (IP1 &= ~BIT2) /*!< Low priority for TIMER3 */
#define TIMER2_PRIORITY_H (IP1 |= BIT1)  /*!< High priority for TIMER2 */
#define TIMER2_PRIORITY_L (IP1 &= ~BIT1) /*!< Low priority for TIMER2 */
#define WDT_PRIORITY_H    (IP1 |= BIT0)  /*!< High priority for WDT */
#define WDT_PRIORITY_L    (IP1 &= ~BIT0) /*!< Low priority for WDT */

#define IR_PRIORITY_H   (IP2 |= BIT2)  /*!< High priority for IR */
#define IR_PRIORITY_L   (IP2 &= ~BIT2) /*!< Low priority for IR */
#define SWT_PRIORITY_H    (IP2 |= BIT1)  /*!< High priority for SWT */
#define SWT_PRIORITY_L    (IP2 &= ~BIT1) /*!< Low priority for SWT */

/**@} */
/**@name Multiplexing Pin Configuration Table
 * @{
 */
#define GPIO_MUX_MODE      (0)  /*!< Pin multiplexing mode as GPIO */
#define SCK_MUX_MOD        (1)  /*!< Pin multiplexing mode for SPI_SCK */
#define MOSI_MUX_MOD       (2)  /*!< Pin multiplexing mode for SPI_MOSI */
#define MISO_MUX_MOD       (3)  /*!< Pin multiplexing mode for SPI_MISO */
#define NSS_MUX_MOD        (4)  /*!< Pin multiplexing mode for SPI_NSS */
#define UART0_RXD_MUX_MODE (5)  /*!< Pin multiplexing mode for UART0_RX */
#define UART1_RXD_MUX_MODE (6)  /*!< Pin multiplexing mode for UART1_RX */
#define UART0_TXD_MUX_MODE (9)  /*!< Pin multiplexing mode for UART0_TX */
#define UART1_TXD_MUX_MODE (10) /*!< Pin multiplexing mode for UART1_TX */
#define PWM0_MUX_MODE      (11) /*!< Pin multiplexing mode for PWM0 */
#define PWM1_MUX_MODE      (12) /*!< Pin multiplexing mode for PWM1 */
#define PWM2_MUX_MODE      (13) /*!< Pin multiplexing mode for PWM2 */
#define PWM3_MUX_MODE      (14) /*!< Pin multiplexing mode for PWM3 */
#define CAP0_MUX_MODE      (17) /*!< Pin multiplexing mode for CAP0 */
#define CAP1_MUX_MODE      (18) /*!< Pin multiplexing mode for CAP1 */
#define CAP2_MUX_MODE      (19) /*!< Pin multiplexing mode for CAP2 */
#define CAP3_MUX_MODE      (20) /*!< Pin multiplexing mode for CAP3 */
#define STADC_MUX_MODE     (21) /*!< Pin multiplexing mode for STADC */
#define FB_MUX_MODE        (22) /*!< Pin multiplexing mode for Brake */
#define INT0_MUX_MODE      (23) /*!< Pin multiplexing mode for INT0 */
#define INT1_MUX_MODE      (24) /*!< Pin multiplexing mode for INT1 */
#define TIME0_T0_MUX_MODE  (25) /*!< Pin multiplexing mode for T0 */
#define TIME1_T1_MUX_MODE  (26) /*!< Pin multiplexing mode for T1 */
#define IRTX_MUX_MODE  		 (27) /*!< Pin multiplexing mode for IRTX  */
#define ANALOG_MUX_MODE    (31) /*!< Pin multiplexing mode for Analog functions */

/**
 * Pin multiplexing function configuration
 * @param[in] PioCFG:
 * -# PIO00CFG - PIO07CFG
 * -# PIO10CFG - PIO17CFG
 * -# PIO20CFG - PIO21CFG
 * @param[in] MUXMode: See Multiplexing Pin Configuration Table from
 * GPIO_MUX_MODE......ANALOG_MUX_MODE
 */
#define PORT_SET_MUX(PioCFG, MUXMode) ((PioCFG) = (MUXMode))
/**@} */

/**@name System Clock Configuration
 * @{
 */
#define HRC_VALUE     		(32000000) /* HRC clock frequency 32MHz */
#define OSC_VALUE         (8000000)  /* External oscillator frequency if external clock mode is selected */
#define LRC_VALUE         (32000)    /* LRC clock frequency */

#define CLKSEL_HRC        (0x00)     /*!< Internal high-speed clock: 32MHz */
#define CLKSEL_LRC        (0x01)     /*!< Internal low-frequency clock: 32KHz */
#define CLKSEL_OSC        (0x02)     /*!< External clock: 1MHz~24MHz */

#define CLK_DIV_NOT       (0)        /* System clock not divided */
#define CLK_DIV_2         (1)        /* System clock divided by 2 */
#define CLK_DIV_4         (2)        /* System clock divided by 4 */
#define CLK_DIV_8         (3)        /* System clock divided by 8 */
#define CLK_DIV_16        (4)        /* System clock divided by 16 */
#define CLK_DIV_32        (5)        /* System clock divided by 32 */
#define CLK_DIV_64        (6)        /* System clock divided by 64 */
#define CLK_DIV_128       (7)        /* System clock divided by 128 */

#define DIR_FREQ_UP       (1)        /* Fine-Tuning HRC frequency up */
#define DIR_FREQ_DOWM     (0)        /* Fine-Tuning HRC frequency down */

#define CLKCON_SEL_POS    (6)
#define CLKCON_SEL_MSK    (0x3 << CLKCON_SEL_POS)
#define CLKCON_HSEEN_POS 	(3)
#define CLKCON_HSEEN_MSK 	(0x1 << CLKCON_HSEEN_POS)
#define CLKCON_DIV_POS    (0)
#define CLKCON_DIV_MSK    (0x7 << CLKCON_DIV_POS)
/**
 * System clock source setting
 * @param[in] mode:
 * -# CLKSEL_HRC Internal high-speed clock: 32MHz
 * -# CLKSEL_LRC Internal low-speed clock: 32KHz
 * -# CLKSEL_OSC External high-speed crystal oscillator: (1MHz~32MHz)
 */
#define SYS_CLK_SEL(mode) (CLKCON = ((CLKCON & (~CLKCON_SEL_MSK)) | ((mode) << CLKCON_SEL_POS)))
/**
 * Enable HSE and configure p00 as clock input pin
 */
#define ENABLE_HSE_CLK  	(CLKCON |= CLKCON_HSEEN_MSK)
/**
 * Disable HSE and configure p00 as GPIO
 */
#define DISABLE_HSE_CLK  	(CLKCON &= ~CLKCON_HSEEN_MSK)	
/**
 * System clock division control
 * @param[in] divData System clock division factor, values range from 0 to 7
 * -# CLK_DIV_NOT
 * -# CLK_DIV_2
 * -# CLK_DIV_4
 * -# CLK_DIV_8
 * -# CLK_DIV_16
 * -# CLK_DIV_32
 * -# CLK_DIV_64
 * -# CLK_DIV_128
 */
#define SYS_CLK_DIV(divData) (CLKCON = ((CLKCON & (~CLKCON_DIV_MSK)) | ((divData) << CLKCON_DIV_POS)))

#define WAITSTS_INSTWS_POS  (0)
#define WAITSTS_INSTWS_MSK  (0xF << WAITSTS_INSTWS_POS)

#define WAITS_INST_VDD_GE3600MV_CLK_LT10M     				(0U)  /* Wait state configuration for VDD >= 3.6V, main frequency < 10MHz */
#define WAITS_INST_VDD_GE3600MV_CLK_GE10_LT20M      	(1U)	/* Wait state configuration for VDD >= 3.6V, main frequency >= 10 and < 20MHz */
#define WAITS_INST_VDD_GE3600MV_CLK_GE20_LT30M      	(2U)	/* Wait state configuration for VDD >= 3.6V, main frequency >= 20 and < 30MHz */
#define WAITS_INST_VDD_GE3600MV_CLK_GE30_LE32M      	(3U)	/* Wait state configuration for VDD >= 3.6V, main frequency >= 30 and =< 32MHz */

#define WAITS_INST_VDD_LT3600MV_CLK_LT5M    					(0U)	/* Wait state configuration for VDD < 3.6V, main frequency < 5MHz  */  
#define WAITS_INST_VDD_LT3600MV_CLK_GE5_LT10M    			(1U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 5 and < 10MHz */ 	 
#define WAITS_INST_VDD_LT3600MV_CLK_GE10_LT15M    		(2U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 10 and < 15MHz */  
#define WAITS_INST_VDD_LT3600MV_CLK_GE15_LT20M    		(3U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 15 and < 20MHz */  
#define WAITS_INST_VDD_LT3600MV_CLK_GE20_LT25M    		(4U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 20 and < 25MHz */  
#define WAITS_INST_VDD_LT3600MV_CLK_GE25_LT30M    		(5U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 25 and < 30MHz */  
#define WAITS_INST_VDD_LT3600MV_CLK_GE30_LE32M    		(6U)	/* Wait state configuration for VDD < 3.6V, main frequency >= 30 and =< 32MHz */  
/**
 * Flash memory fetch instruction access cycle configuration
 * @param[in] wait:
 * -# WAITS_INST_VDD_GE3600MV_CLK_LT10M 				Configuration for VDD >= 3.6V, main frequency < 10MHz
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE10_LT20M   	Configuration for VDD >= 3.6V, main frequency >= 10 and < 20MHz 
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE20_LT30M   	Configuration for VDD >= 3.6V, main frequency >= 20 and < 30MHz 
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE30_LT32M   	Configuration for VDD >= 3.6V, main frequency >= 30 and =< 32MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_LT5M  				Configuration for VDD < 3.6V, main frequency < 5MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE5_LT10M    	Configuration for VDD < 3.6V, main frequency >= 5 and < 10MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE10_LT15M    Configuration for VDD < 3.6V, main frequency >= 10 and < 15MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE15_LT20M    Configuration for VDD < 3.6V, main frequency >= 15 and < 20MHz
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE20_LT25M    Configuration for VDD < 3.6V, main frequency >= 20 and < 25MHz  
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE25_LT30M    Configuration for VDD < 3.6V, main frequency >= 25 and < 30MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE30_LT32M    Configuration for VDD < 3.6V, main frequency >= 30 and =< 32MHz 
 */
#define SYS_CLK_WAITS(waits) (WAITSTS = ((WAITSTS & (~WAITSTS_INSTWS_MSK)) | ((waits) << WAITSTS_INSTWS_POS)))

/**
 * Get flash memory fetch instruction access cycle configuration
 * @return VDD >= 3.6V
 *         0: Configuration for main frequency < 10MHz
 *         1: Configuration for main frequency >= 10 and < 20MHz
 *         2: Configuration for main frequency >= 20 and < 30MHz 
 *         3: Configuration for main frequency >= 30 and =< 32MHz 
 *         VDD < 3.6V
 *         0: Configuration for VDD < 3.6V, main frequency < 5MHz 
 *         1: Configuration for VDD < 3.6V, main frequency >= 5 and < 10MHz 
 *         2: Configuration for VDD < 3.6V, main frequency >= 10 and < 15MHz 
 *         3: Configuration for VDD < 3.6V, main frequency >= 15 and < 20MHz 
 *         4: Configuration for VDD < 3.6V, main frequency >= 20 and < 25MHz 
 *         5: Configuration for VDD < 3.6V, main frequency >= 25 and < 30MHz 
 *         6: Configuration for VDD < 3.6V, main frequency >= 30 and =< 32MHz  
 */
#define GET_SYS_CLK_WAITS ((WAITSTS & WAITSTS_INSTWS_MSK) >> WAITSTS_INSTWS_POS)

/**@name Reset Management
 * @{
 */
#define SYSRST_SWRST_POS 			(1)
#define SYSRST_SWRST_MSK 			(0x1 <<  SYSRST_SWRST_POS)
#define SYSRST_EXRSTEN_POS    (0)
#define SYSRST_EXRSTEN_MSK    (0x1 <<  SYSRST_EXRSTEN_POS)
/**
 * Get the system reset reason
 * @return Bit 7: 0 - No software reset occurred; 1 - Software reset occurred. This bit is set by
 * hardware and must be cleared by software writing 0.\n Bit 6: 0 - No external reset occurred; 1 -
 * External reset occurred. This bit is set by hardware and must be cleared by software writing 0.\n
 * Bit 5: 0 - No BOD reset occurred; 1 - BOD reset occurred. This bit is set by hardware and must be
 * cleared by software writing 0.\n Bit 4: 0 - No WDT reset occurred; 1 - WDT reset occurred. This
 * bit is set by hardware and must be cleared by software writing 0.
 */
#define GET_SYS_RST_REASON (SYSRST)

/**
 * Clear all reset reasons
 */
#define CLR_ALL_RST_REASON (SYSRST &= 0x0F)
/**
 *  Configure p00 as GPIO
 */
#define CONFIG_P20_IO  	(SYSRST &= SYSRST_EXRSTEN_MSK)	  
/**
 * Configure p00 as reset pin
 */
#define CONFIG_P20_RST  	(SYSRST |= SYSRST_EXRSTEN_MSK)	 
/**@} */

/**@name Power Management
 * @{
 */
#define POWER_PCON_SLEEPWPP_POS (5)
#define POWER_PCON_SLEEPWPP_MSK (0x1 << POWER_PCON_SLEEPWPP_POS)
#define POWER_PCON_GF1_POS      (3)
#define POWER_PCON_GF1_MSK      (0x1 << POWER_PCON_GF1_POS)
#define POWER_PCON_GF0_POS      (2)
#define POWER_PCON_GF0_MSK      (0x1 << POWER_PCON_GF0_POS)

#define ENABLE_PORTINT_WAKE_SLEEP                                                                                      \
    (PCON |= POWER_PCON_SLEEPWPP_MSK)  /*!< Enable waking from Sleep mode through pin interrupt */
#define DISABLE_PORTINT_WAKE_SLEEP                                                                                     \
    (PCON &= ~POWER_PCON_SLEEPWPP_MSK) /*!< Disable waking from Sleep mode through pin interrupt                       \
                                        */

/**
 * General Flag 1
 * @param[in] status:
 * -# CLR_BIT: Clear general flag
 * -# SET_BIT: Set general flag
 */
#define POWER_PCON_GF1_SET(status) (PCON = ((PCON & (~POWER_PCON_GF1_MSK)) | ((status) << POWER_PCON_GF1_POS)))
/**
 * General Flag 0
 * @param[in] status:
 * -# CLR_BIT: Clear general flag
 * -# SET_BIT: Set general flag
 */
#define POWER_PCON_GF0_SET(status) (PCON = ((PCON & (~POWER_PCON_GF0_MSK)) | ((status) << POWER_PCON_GF0_POS)))

/**
 * SYSD System Flag
 * @return 1: System can be configured to enter Sleep \n
 *         0: System cannot be configured to enter Sleep
 */
#define IS_SYSD_FLAG            ((PCON & BIT6) >> 6)

#define POWER_BODCON_BODEN_POS  (7)
#define POWER_BODCON_BODEN_MSK  (0x1 << POWER_BODCON_BODEN_POS)
#define POWER_BODCON_BODF_POS   (6)
#define POWER_BODCON_BODF_MSK   (0x1 << POWER_BODCON_BODF_POS)
#define POWER_BODCON_BODRST_POS (5)
#define POWER_BODCON_BODRST_MSK (0x1 << POWER_BODCON_BODRST_POS)
#define POWER_BODCON_BODV_POS   (2)
#define POWER_BODCON_BODV_MSK   (0x7 << POWER_BODCON_BODV_POS)
#define POWER_BODCON_V1P2EN_POS (1)
#define POWER_BODCON_V1P2EN_MSK (0x1 << POWER_BODCON_V1P2EN_POS)

#define ENABLE_BOD              (BODCON |= POWER_BODCON_BODEN_MSK) /*!< Enable Brown-Out Detection circuit */
#define DISABLE_BOD                                                                                                    \
    (BODCON &= ~POWER_BODCON_BODEN_MSK)                            /*!< Disable Brown-Out Detection circuit            \
                                                                    */
/**
 * Brown-Out Detection interrupt flag
 * @return 0: VDD above VBOD\n
 *         1: VDD dropped below VBOD
 * @note This bit is set by hardware and must be cleared by software writing 0
 */
#define IS_BODCON_BOD_FLAG  ((BODCON & POWER_BODCON_BODF_MSK) >> POWER_BODCON_BODF_POS)
#define CLR_BODCON_BOD_FLAG (BODCON &= ~POWER_BODCON_BODF_MSK)

#define ENABLE_BODRST       (BODCON |= POWER_BODCON_BODRST_MSK)  /*!< Enable Brown-Out Detection reset */
#define DISABLE_BODRST      (BODCON &= ~POWER_BODCON_BODRST_MSK) /*!< Disable Brown-Out Detection reset */

#define BODV_SEL2V20        (0x00)
#define BODV_SEL2V55        (0x01)
#define BODV_SEL2V90        (0x02)
#define BODV_SEL3V25        (0x03)
#define BODV_SEL3V60        (0x04)
#define BODV_SEL3V95        (0x05)
#define BODV_SEL4V30        (0x06)
#define BODV_SEL4V65        (0x07)
/**
 * Brown-Out Detection voltage selection
 * @param[in] mode:
 * -# BODV_SEL2V20: VBOD voltage 2.20V 
 * -# BODV_SEL2V55: VBOD voltage 2.55V
 * -# BODV_SEL2V90: VBOD voltage 2.90V
 * -# BODV_SEL3V25: VBOD voltage 3.25V
 * -# BODV_SEL3V60: VBOD voltage 3.60V
 * -# BODV_SEL3V95: VBOD voltage 3.95V
 * -# BODV_SEL4V30: VBOD voltage 4.30V
 * -# BODV_SEL4V65: VBOD voltage 4.65V
 */
#define POWER_BODCON_BODV_SET(mode) (BODCON = ((BODCON & (~POWER_BODCON_BODV_MSK)) | ((mode) << POWER_BODCON_BODV_POS)))

#define ENABLE_V1P2EN       (BODCON |= POWER_BODCON_V1P2EN_MSK)  /*!< Enable 1.2V OUTPUT */
#define DISABLE_V1P2EN      (BODCON &= ~POWER_BODCON_V1P2EN_MSK) /*!< Disable 1.2V OUTPUT */

/**@} */

/**@name SWT Counter
 * @{
 */
#define SWT_SWTCON_SWTIF_POS (4)
#define SWT_SWTCON_SWTIF_MSK (0x1 << SWT_SWTCON_SWTIF_POS)
#define SWT_SWTCON_SWTR_POS  (3)
#define SWT_SWTCON_SWTR_MSK  (0x1 << SWT_SWTCON_SWTR_POS)
#define SWT_SWTCON_SWTPS_POS (0)
#define SWT_SWTCON_SWTPS_MSK (0x7 << SWT_SWTCON_SWTPS_POS)

/**
 * SWT Overflow Flag
 * @return 1: SWT counter overflow\n
 *         0: SWT counter did not overflow
 */
#define IS_SWT_SWTIF_FLAG  ((SWTCON & SWT_SWTCON_SWTIF_MSK) >> SWT_SWTCON_SWTIF_POS)
#define CLR_SWT_SWTIF_FLAG (SWTCON &= ~SWT_SWTCON_SWTIF_MSK)

#define SWT_PSDIV_2        0x00
#define SWT_PSDIV_4        0x01
#define SWT_PSDIV_16       0x02
#define SWT_PSDIV_64       0x03
#define SWT_PSDIV_256      0x04
#define SWT_PSDIV_512      0x05
#define SWT_PSDIV_1024     0x06
#define SWT_PSDIV_2048     0x07
/**
 * Enable and configure SWT clock
 * @param[in] psdiv:
 * -# SWT_PSDIV_2     SWT count clock is CLK_LRC divided by 2;
 * -# SWT_PSDIV_4     SWT count clock is CLK_LRC divided by 4;
 * -# SWT_PSDIV_16    SWT count clock is CLK_LRC divided by 16;
 * -# SWT_PSDIV_64    SWT count clock is CLK_LRC divided by 64;
 * -# SWT_PSDIV_256   SWT count clock is CLK_LRC divided by 256;
 * -# SWT_PSDIV_512   SWT count clock is CLK_LRC divided by 512;
 * -# SWT_PSDIV_1024  SWT count clock is CLK_LRC divided by 1024;
 * -# SWT_PSDIV_2048  SWT count clock is CLK_LRC divided by 2048.
 */
#define SWT_ENABLE(psdiv)                                                                                              \
    (SWTCON = ((SWTCON & (~SWT_SWTCON_SWTPS_MSK)) | ((psdiv) << SWT_SWTCON_SWTPS_POS)) | SWT_SWTCON_SWTR_MSK)
#define SWT_DISABLE (SWTCON &= ~(SWT_SWTCON_SWTR_MSK | SWT_SWTCON_SWTIF_MSK)) /*!< Disable SWT */
/**
 * SWT Data Register
 * @param[in] data 8-bit SWT count value
 * @note SWT_OVERFLOW = CLK_LRC/((256 - SWTR)*SWTPS)
 */
#define SWT_SWTR_SET(data) (SWTR = (data))
/**
 * Get SWT count value
 */
#define GET_SWTR_CNT   SWTRCNT
/**@} */

/**@name External Interrupts INT0/INT1
 * @{
 */
#define INT_FALLING  (1)
#define INT_LOWLEVEL (0)

/**
 * External Interrupt 1 Flag
 * @return 0: External interrupt 1 did not occur \n
 *         1: External interrupt 1 occurred
 */
#define IS_INT1_FLAG (IE1)
/**
 * External Interrupt 1 trigger mode control bit:
 * @param[in] mode:
 * -# INT_FALLING: Falling edge triggered
 * -# INT_LOWLEVEL: Low level triggered
 */
#define INT1_TRIGGER_MODE_SET(status) (IT1 = (status))
/**
 * External Interrupt 0 Flag
 * @return 0: External interrupt 0 did not occur \n
 *         1: External interrupt 0 occurred
 */
#define IS_INT0_FLAG (IE0)
/**
 * External Interrupt 0 trigger mode control bit:
 * @param[in] mode:
 * -# INT_FALLING: Falling edge triggered
 * -# INT_LOWLEVEL: Low level triggered
 */
#define INT0_TRIGGER_MODE_SET(status) (IT0 = (status))
/**@} */

/**@name OCD Configuration
 * @{
 */
#define OCD_OCDEN_OCDEN_POS (0)
#define OCD_OCDEN_OCDEN_MSK (0x1 << OCD_OCDEN_OCDEN_POS) 
#define OCD_ENABLE   (OCDEN |= OCD_OCDEN_OCDEN_MSK)
#define OCD_DISABLE  (OCDEN &= ~OCD_OCDEN_OCDEN_MSK)
/**@} */ 

typedef enum {
    SYSCLK_HRC	= 0U, /*!< Internal high-speed clock: 32MHz */
    SYSCLK_LRC  = 1U, /*!< Internal low-frequency clock: 32KHz */
    SYSCLK_OSC  = 2U  /*!< External clock: 1MHz~32MHz */
} sysclk_t;

extern uint32_t g_u32SystemClock;

/**@name External Functions
 * @{
 */
void    System_ConfigCLK(sysclk_t u8clkSel, uint8_t u8divSel, uint8_t u8waits);
uint8_t System_EnterStandby(void);
uint8_t System_EnterSleep(void);
void    System_EnterIdle(void);
uint8_t System_SoftReset(void);
uint8_t HRC_FineTuning(uint8_t dir, uint16_t step);
/**@} */
#endif /*_COMMON_H_*/
