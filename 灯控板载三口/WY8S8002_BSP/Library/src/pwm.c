/**
 * @file      pwm.c
 * @brief     PWM Driver Configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "pwm.h"

/**
 * Configures PWM interrupt
 * @param[in] u8pwmNum  PWM channel
 * -# PWM_0 - PWM_5
 * @param[in] u8trigger Interrupt trigger mode
 * -# PWM_FALLING_MODE    Falling edge on PWM0/1/2/3/4/5 pin
 * -# PWM_RISING_MODE     Rising edge on PWM0/1/2/3/4/5 pin
 * -# PWM_MIDPOINT_MODE   Midpoint of each PWM cycle
 * -# PWM_ENDPOINT_MODE   Endpoint of each PWM cycle
 * @note Midpoint or endpoint interrupt modes are only applicable in PWM center-aligned mode
 */
void PWM_ConfigINT(uint8_t u8pwmNum, uint8_t u8trigger)
{
    switch(u8pwmNum)
    {
        case PWM_0:
            PWM_PWM0_INTTY_SET(u8trigger);
            break;
        case PWM_1:
            PWM_PWM1_INTTY_SET(u8trigger);
            break;
        case PWM_2:
            PWM_PWM2_INTTY_SET(u8trigger);
            break;
        case PWM_3:
            PWM_PWM3_INTTY_SET(u8trigger);
            break;
        default:
            break;
    }
}

/**
 * Configures output level after PWM channel fault
 * @param[in] u8pwmNum  PWM channel
 * -# PWM_0 - PWM_5
 * @param[in] u8pwmLevel Output level
 * -# OUTPUT_HIGH
 * -# OUTPUT_LOW
 */
void PWM_ConfigFBOutputLevel(uint8_t u8pwmNum, uint8_t u8pwmLevel)
{
    switch(u8pwmNum)
    {
        case PWM_0:
            PWM_PWMOUTD_FBKD0_SET(u8pwmLevel);
            break;
        case PWM_1:
            PWM_PWMOUTD_FBKD1_SET(u8pwmLevel);
            break;
        case PWM_2:
            PWM_PWMOUTD_FBKD2_SET(u8pwmLevel);
            break;
        case PWM_3:
            PWM_PWMOUTD_FBKD3_SET(u8pwmLevel);
            break;
        default:
            break;
    }
}

/**
 * Configures masked output level for PWM
 * @param[in] u8pwmNum  PWM channel
 * -# PWM_0 - PWM_5
 * @param[in] u8pwmLevel  Output level
 * -# OUTPUT_HIGH
 * -# OUTPUT_LOW
 */
void PWM_ConfigMASKOutputLevel(uint8_t u8pwmNum, uint8_t u8pwmLevel)
{
    switch(u8pwmNum)
    {
        case PWM_0:
            PWM_PWMOUTD_MASKD0_SET(u8pwmLevel);
            break;
        case PWM_1:
            PWM_PWMOUTD_MASKD1_SET(u8pwmLevel);
            break;
        case PWM_2:
            PWM_PWMOUTD_MASKD2_SET(u8pwmLevel);
            break;
        case PWM_3:
            PWM_PWMOUTD_MASKD3_SET(u8pwmLevel);
            break;
        default:
            break;
    }
}

/**
 * Starts loading PWM configuration
 * @param[in] u8pwmNum  PWM channel
 * -# PWM_0 - PWM_5
 * @note
 * Writing 1 to this bit automatically loads new configuration values at the end of the current PWM cycle. Changed
 * configuration values, such as period, duty cycle, dead time, and mode, will take effect in the next cycle.
 */
void PWM_StartLoad(uint8_t u8pwmNum)
{
    switch(u8pwmNum)
    {
        case PWM_0:
            ENABLE_PWM0_LOAD;
            /* Wait for load to complete */
            while(1 == IS_PWM0_LOAD_FLAG)
                ;
            break;
        case PWM_1:
            ENABLE_PWM1_LOAD;
            /* Wait for load to complete */
            while(1 == IS_PWM1_LOAD_FLAG)
                ;
            break;
        case PWM_2:
            ENABLE_PWM2_LOAD;
            /* Wait for load to complete */
            while(1 == IS_PWM2_LOAD_FLAG)
                ;
            break;
        case PWM_3:
            ENABLE_PWM3_LOAD;
            /* Wait for load to complete */
            while(1 == IS_PWM3_LOAD_FLAG)
                ;
            break;
        default:
            break;
    }
}
