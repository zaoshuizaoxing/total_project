/**
 * @file      common.c
 * @brief     Common utility functions
 * @author    Software Team
 * @date      2025-04
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "wdt.h"
uint32_t g_u32SystemClock = HRC_VALUE; /*!< Global variable for system clock */
/**
 * Configure system clock
 * @param[in] u8clkSel Clock source selection
 * -# SYSCLK_HRC
 * -# SYSCLK_LRC
 * -# SYSCLK_OSC
 * @param[in] u8divSel Clock division coefficient
 * -# CLK_DIV_NOT
 * -# CLK_DIV_2
 * -# CLK_DIV_4
 * -# CLK_DIV_8
 * -# CLK_DIV_16
 * -# CLK_DIV_32
 * -# CLK_DIV_64
 * -# CLK_DIV_128
 * @param[in] u8waits Flash access wait cycles
 * -# VDD >= 3.6V
 * -# WAITS_INST_VDD_GE3600MV_CLK_LT10M 				Configuration for main frequency < 10MHz
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE10_LT20M   	Configuration for main frequency >= 10 and < 20MHz 
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE20_LT30M   	Configuration for main frequency >= 20 and < 30MHz 
 * -# WAITS_INST_VDD_GE3600MV_CLK_GE30_LT32M   	Configuration for main frequency >= 30 and =< 32MHz 
 * -# VDD < 3.6V
 * -# WAITS_INST_VDD_LT3600MV_CLK_LT5M  				Configuration for main frequency < 5MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE5_LT10M    	Configuration for main frequency >= 5 and < 10MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE10_LT15M    Configuration for main frequency >= 10 and < 15MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE15_LT20M    Configuration for main frequency >= 15 and < 20MHz
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE20_LT25M    Configuration for main frequency >= 20 and < 25MHz  
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE25_LT30M    Configuration for main frequency >= 25 and < 30MHz 
 * -# WAITS_INST_VDD_LT3600MV_CLK_GE30_LT32M    Configuration for main frequency >= 30 and =< 32MHz  
 *
 * @note When u8divSel = 0, CLK_sys is the clock source frequency
 * @note When u8divSel != 0, CLK_sys = clock source frequency / (2 * u8divSel)
 * @note If CLKSEL_OSC mode is selected, you need to change the external clock frequency in OSC_VALUE
 * @note If switching from a high frequency to a lower one, configure CLKCON before WAITSTS; if from low to high,
 * configure WAITSTS before CLKCON
 */
void System_ConfigCLK(sysclk_t u8clkSel, uint8_t u8divSel, uint8_t u8waits)
{

    if(u8waits > GET_SYS_CLK_WAITS)
    {
        SYS_CLK_WAITS(u8waits);
    }

    switch(u8clkSel)
    {
        case SYSCLK_HRC:
            SYS_CLK_SEL(CLKSEL_HRC);
						DISABLE_HSE_CLK;
            g_u32SystemClock = HRC_VALUE;
            break;
        case SYSCLK_LRC:
            SYS_CLK_SEL(CLKSEL_LRC);
            g_u32SystemClock = LRC_VALUE;
            break;
        case SYSCLK_OSC:
						ENABLE_HSE_CLK;
            SYS_CLK_SEL(CLKSEL_OSC);
            g_u32SystemClock = OSC_VALUE;
            break;
    }

    SYS_CLK_DIV(u8divSel); /* Configure the division coefficient */

    if(u8waits < GET_SYS_CLK_WAITS)
    {
        SYS_CLK_WAITS(u8waits);
    }

    g_u32SystemClock >>= u8divSel; /* Update g_u32SystemClock */
}

/**
* Enter standby
* @return 0:Fail to enter 1:Success to enter
* @note Enter standby mode when PCON.SYSD is 1.
*/ 
uint8_t System_EnterStandby(void)
{
    if(0x00 == IS_SYSD_FLAG)
    {
        return 0;
    }
    _nop_();
    PCON |= BIT4;
    _nop_();
    _nop_();
    _nop_();
    return 1;
}

/**
 * Enter sleep mode
 * @return 0: Failure, 1: Success
 * @note Sleep mode can only be entered when PCON.SYSD is set to 1
 */
uint8_t System_EnterSleep(void)
{
		WAITING_WDT_WDTCLR();
    if(0x00 == IS_SYSD_FLAG)
    {
        return 0;
    }
    _nop_();
    PCON |= BIT1;
    _nop_();
    _nop_();
    _nop_();
    return 1;
}

/**
 * Enter idle mode
 */
void System_EnterIdle(void)
{
    _nop_();
    PCON |= BIT0;
    _nop_();
}

/**
 * Software reset
 */
uint8_t System_SoftReset(void)
{
    if(0x00 == IS_SYSD_FLAG)
    {
        return 0;
    }
    SYSRST |= BIT1;

    return 1;
}

/**
 * Fine-Tuning of HRC
 * @param[in] dir:
 * -# DIR_FREQ_UP: Fine-Tuning HRC frequency up
 * -# DIR_FREQ_DOWM: Fine-Tuning HRC frequency dowm
 * @param[in] step: Fine-Tuning step size
 * @not step range:0-1023
 * @return 0: Failure, 1: Success
 */
uint8_t HRC_FineTuning(uint8_t dir, uint16_t step)
{
	uint16_t fine_tune =  HRCFTUNE16 & 0x03FF;
	
	if(dir == DIR_FREQ_UP){ 
		fine_tune += step; 
		if(fine_tune > 0x03FF){
			return 0;
		}else{
			HRCFTUNE16 = (HRCFTUNE16 & 0xFC00) | fine_tune;
		}
	}else{ 
		if(fine_tune < step){
			return 0;
		}else{
			fine_tune -= step; 
			HRCFTUNE16 = (HRCFTUNE16 & 0xFC00) | fine_tune;
		}
	}
	return 1;
}
