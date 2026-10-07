/**
 * @file      delay.c
 * @brief     Precise delay functions
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "delay.h"
#include "timer.h"

/**定时器0延时函数
 * Generate a 1ms delay using Timer0
 * @param[in] u8Xms: Delay time in milliseconds (ms)
 * @note The parameter is of type uint8_t, thus the maximum support is a 255ms delay
 */
void Timer0_Delay_ms(uint8_t u8Xms)
{
    TIMER0_TMOD_MODE_SET(TIMER01_MODE1);
    ENABLE_TIMER0;
    while(u8Xms != 0) /* One loop equals 1ms */
    {
        TH0 = 0xE0;
        TL0 = 0xC0;
        while(IS_TIME0_OVER_FLAG != 1)
            ;
        CLR_TIME0_OVER_FLAG;
        u8Xms--;
    }
    DISABLE_TIMER0;
}
