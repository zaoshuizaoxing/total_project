/**
 * @file      wdt.c
 * @brief     WDT Driver
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "wdt.h"

/**
 * Initializes WDT configuration
 * @param[in] u8div  WDT overflow duration
 * -# WDT_DIV_2     WDT clock divided by 2
 * -# WDT_DIV_4     WDT clock divided by 4
 * -# WDT_DIV_8     WDT clock divided by 8
 * -# WDT_DIV_16    WDT clock divided by 16
 * -# WDT_DIV_32    WDT clock divided by 32
 * -# WDT_DIV_64    WDT clock divided by 64
 * -# WDT_DIV_128   WDT clock divided by 128
 * -# WDT_DIV_256   WDT clock divided by 256
 * -# WDT_DIV_512   WDT clock divided by 512
 * -# WDT_DIV_1024  WDT clock divided by 1024
 * @param[in] u8overRstFlag Overflow reset control
 * -# DISABLE_OVER_RST: Disable reset on overflow
 * -# ENABLE_OVER_RST: Enable reset on overflow
 * @param[in] u8Mode WDT operating mode configuration
 * -# WDT_IDLE_SLEEP_MODE    WDT runs in both Idle and Sleep modes
 * -# WDT_IDLE_MODE          WDT runs in Idle mode, stops in Sleep mode
 * -# WDT_NONE_MODE          WDT stops in both Idle and Sleep modes
 */
void WDT_ConfigMode(uint8_t u8div, uint8_t u8overRstFlag, uint8_t u8Mode)
{
    WDT_WDTCON_PSDIV_SET(u8div); /* Configure overflow time */
    WDT_WDTMOD_WDTRST_SET(u8overRstFlag); /* Configure overflow reset control */
    WDT_WDTMOD_WDTMOD_SET(u8Mode); /* Configure WDT operating mode */
}

/**
 * Enables or disables WDT
 * @param[in] u8WDTFlag
 * -# DISABLE_WDT: Disable WDT operation
 * -# ENABLE_WDT: Enable WDT operation
 */
void WDT_Run(uint8_t u8WDTFlag)
{
    WDT_WDTCON_WDTEN_SET(u8WDTFlag);
}

/**
 * Clears WDT counter
 * @note Protected by TA sequence
 * @note After clearing the watchdog counter, you need to wait for the watchdog timer to reset
 */
void WDT_ClearWDT(void)
{
	if(GET_WDT_WDTCLR_STATUS() == WDT_WDTCLRED)
	{
		WDTCON &= ~WDT_WDTCON_WDTCLR;
	}
}

/**
 * Clears WDT timeout flag
 * @note Protected by TA sequence
 */
void WDT_ClearTF(void)
{
    WDTCON &= ~BIT5;
}
