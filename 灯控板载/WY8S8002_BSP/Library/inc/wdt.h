/**
 * @file      wdt.h
 * @brief     WDT Driver Configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __WDT_H__
#define __WDT_H__

#include "WY8S8002xx.h"

/**@name WDT Control Register - WDTCON
 * @{
 */
#define WDT_WDTCON_WDTEN_POS  (7)
#define WDT_WDTCON_WDTEN_MSK  (0x1 << WDT_WDTCON_WDTEN_POS)
#define WDT_WDTCON_WDTEN      WDT_WDTCON_WDTEN_MSK
#define WDT_WDTCON_WDTCLR_POS (6)
#define WDT_WDTCON_WDTCLR_MSK (0x1 << WDT_WDTCON_WDTCLR_POS)
#define WDT_WDTCON_WDTCLR     WDT_WDTCON_WDTCLR_MSK
#define WDT_WDTCON_WDTF_POS   (5)
#define WDT_WDTCON_WDTF_MSK   (0x1 << WDT_WDTCON_WDTF_POS)
#define WDT_WDTCON_WDTF       WDT_WDTCON_WDTF_MSK
#define WDT_WDTCON_WDTPS_POS  (0)
#define WDT_WDTCON_WDTPS_MSK  (0xF << WDT_WDTCON_WDTPS_POS)
#define WDT_WDTCON_WDTPS      WDT_WDTCON_WDTPS_MSK

#define WDT_WDTCLRED          (WDT_WDTCON_WDTEN|WDT_WDTCON_WDTCLR) /*!< WDT counter cleared */
#define WDT_WDTCLRING         (WDT_WDTCON_WDTEN) /*!< WDT counter clearing */
/**
 * Get WDT clear status
 * @param[in] status
 * @return WDT_WDTCLRED: WDT counter clear
 *         WDT_WDTCLRING: WDT counter clearing
 *         Other: WDT disabled		 		
 */
#define GET_WDT_WDTCLR_STATUS() (WDTCON & (WDT_WDTCON_WDTEN|WDT_WDTCON_WDTCLR))

/**
 * Waiting for the WDT counter clear to complete
 */
#define WAITING_WDT_WDTCLR() while(GET_WDT_WDTCLR_STATUS() == WDT_WDTCLRING){} 
	
#define ENABLE_WDT            1 /*!< Enable WDT */
#define DISABLE_WDT           0 /*!< Disable WDT */
/**
 * WDT Run Enable Bit
 * @param[in] status
 * -# DISABLE_WDT: WDT run disabled
 * -# ENABLE_WDT: WDT run enabled
 */
#define WDT_WDTCON_WDTEN_SET(status)                                                                                   \
    (WDTCON = ((WDTCON & (~WDT_WDTCON_WDTEN_MSK)) | ((status) << WDT_WDTCON_WDTEN_POS)))

/**
 * WDT Timeout Flag
 * @return 1: WDT timer overflow
 *         0: WDT timer has not overflowed
 */
#define IS_WDT_TF_FLAG ((WDTCON & WDT_WDTCON_WDTF_MSK) >> WDT_WDTCON_WDTF_POS)

#define WDT_DIV_2      (0x00)
#define WDT_DIV_4      (0x01)
#define WDT_DIV_8      (0x02)
#define WDT_DIV_16     (0x03)
#define WDT_DIV_32     (0x04)
#define WDT_DIV_64     (0x05)
#define WDT_DIV_128    (0x06)
#define WDT_DIV_256    (0x07)
#define WDT_DIV_512    (0x08)
#define WDT_DIV_1024   (0x0F)
/**
 * WDT Clock Prescaler Selection Bit
 * @param[in] div
 * -# WDT_DIV_2:    WDT count clock is CLK_LRC divided by 2
 * -# WDT_DIV_4:    WDT count clock is CLK_LRC divided by 4
 * -# WDT_DIV_8:    WDT count clock is CLK_LRC divided by 8
 * -# WDT_DIV_16:   WDT count clock is CLK_LRC divided by 16
 * -# WDT_DIV_32:   WDT count clock is CLK_LRC divided by 32
 * -# WDT_DIV_64:   WDT count clock is CLK_LRC divided by 64
 * -# WDT_DIV_128:  WDT count clock is CLK_LRC divided by 128
 * -# WDT_DIV_256:  WDT count clock is CLK_LRC divided by 256
 * -# WDT_DIV_512:  WDT count clock is CLK_LRC divided by 512
 * -# WDT_DIV_1024: WDT count clock is CLK_LRC divided by 1024
 */
#define WDT_WDTCON_PSDIV_SET(div) (WDTCON = ((WDTCON & (~WDT_WDTCON_WDTPS_MSK)) | ((div) << WDT_WDTCON_WDTPS_POS)))
/**@} */

/**@name WDT Mode Register - WDTMOD
 * @{
 */
#define WDT_WDTMOD_WDTRST_POS (7)
#define WDT_WDTMOD_WDTRST_MSK (0x1 << WDT_WDTMOD_WDTRST_POS)
#define WDT_WDTMOD_WDTMOD_POS (5)
#define WDT_WDTMOD_WDTMOD_MSK (0x3 << WDT_WDTMOD_WDTMOD_POS)

#define ENABLE_OVER_RST       (1)
#define DISABLE_OVER_RST      (0)

/**
 * WDT Overflow Reset Control
 * @param[in] status
 * -# DISABLE_OVER_RST: Disable reset on overflow
 * -# ENABLE_OVER_RST:  Enable reset on overflow
 */
#define WDT_WDTMOD_WDTRST_SET(status)                                                                                  \
    (WDTMOD = ((WDTMOD & (~WDT_WDTMOD_WDTRST_MSK)) | ((status) << WDT_WDTMOD_WDTRST_POS)))

#define WDT_IDLE_SLEEP_MODE 0x00
#define WDT_IDLE_MODE       0x01
#define WDT_NONE_MODE       0x03
/**
 * WDT Operation Mode Configuration
 * @param[in] mode
 * -# WDT_IDLE_SLEEP_MODE: WDT runs in both Idle and Sleep modes
 * -# WDT_IDLE_MODE:       WDT runs in Idle mode, stops in Sleep mode
 * -# WDT_NONE_MODE:       WDT stops in both Idle and Sleep modes
 */
#define WDT_WDTMOD_WDTMOD_SET(mode) (WDTMOD = ((WDTMOD & (~WDT_WDTMOD_WDTMOD_MSK)) | ((mode) << WDT_WDTMOD_WDTMOD_POS)))
/**@} */

/**@name External Functions
 * @{
 */
void WDT_ConfigMode(uint8_t u8div, uint8_t u8overRstFlag, uint8_t u8Mode);
void WDT_Run(uint8_t u8WDTFlag);
void WDT_ClearWDT(void);
void WDT_ClearTF(void);
/**@} */

#endif /* __WDT_H__ */
