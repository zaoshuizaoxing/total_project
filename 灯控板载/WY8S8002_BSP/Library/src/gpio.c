/**
 * @file      gpio.c
 * @brief     GPIO Driver Configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "common.h"
#include "gpio.h"

/**
 * Configure PORT0 Output Mode
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u8opMode Push-pull or open-drain mode
 * -# GPIO_PP
 * -# GPIO_OD
 * @param[in] u16udMode Configure pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 * @param[in] u8crtMode Current drive capability
 * -# CURRENT_00
 * -# CURRENT_01
 */
void GPIO0_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode)
{
    if(u8crtMode > CURRENT_01) {
        u8crtMode = CURRENT_01;
    }
    P0OD  = (P0OD & (~(1 << u8PinNum))) | (u8opMode << u8PinNum);
    P0UP  = (P0UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P0RD  = (P0RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P0DR = 	(P0DR & (~(0x01 << u8PinNum))) | (u8crtMode << u8PinNum);
    P0DIR |= (1 << u8PinNum);
}

/**
 * Configure PORT1 Output Mode
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u8opMode Push-pull or open-drain mode
 * -# GPIO_PP
 * -# GPIO_OD
 * @param[in] u16udMode Configure pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 * @param[in] u8crtMode Current drive capability
 * Pin number GPIO_PIN_0 and GPIO_PIN_1��
 * -# CURRENT_00
 * -# CURRENT_01
 * -# CURRENT_02
 * -# CURRENT_03
 * Pin number GPIO_PIN_2 - GPIO_PIN_7��
 * -# CURRENT_00
 * -# CURRENT_01
 */
void GPIO1_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode)
{
    if((u8PinNum > GPIO_PIN_1) && (u8crtMode > CURRENT_01)){
        u8crtMode = CURRENT_01;
    }

    if(u8PinNum > GPIO_PIN_1){
        P1DRL = (P1DRL & (~(0x01 << u8PinNum))) | (u8crtMode << u8PinNum);
    }else{
        P1DRH = (P1DRH & (~(0x03 << (u8PinNum<<1)))) | (u8crtMode << (u8PinNum<<1));
    }

    P1OD  = (P1OD & (~(1 << u8PinNum))) | (u8opMode << u8PinNum);
    P1UP  = (P1UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P1RD  = (P1RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P1DIR |= (1 << u8PinNum);
}

/**
 * Configure PORT2 Output Mode
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_5
 * @param[in] u8opMode Push-pull or open-drain mode
 * -# GPIO_PP
 * -# GPIO_OD
 * @param[in] u16udMode Configure pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 * @param[in] u8crtMode Current drive capability
 * -# CURRENT_00
 * -# CURRENT_01
 */
void GPIO2_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode)
{
    P2OD  = (P2OD & (~(1 << u8PinNum))) | (u8opMode << u8PinNum);
    P2UP  = (P2UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P2RD  = (P2RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P2DR 	= (P2DR & (~(0x01 << u8PinNum))) | ((u8crtMode << u8PinNum));
    P2DIR |= (1 << u8PinNum);
}

/**
 * Configure PORT Output Mode
 * @param[in] u8PinNum Pin number: 0~7, 10~17, 20~21
 * @param[in] u8opMode Push-pull or open-drain mode
 * -# GPIO_PP
 * -# GPIO_OD
 * @param[in] u16udMode Configure pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 * @param[in] u8crtMode Current drive capability
 * -# CURRENT_00
 * -# CURRENT_01
 */
void GPIO_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode)
{
    uint8_t group = u8PinNum / 10;
    uint8_t pin   = u8PinNum % 10;
    switch(group)
    {
        case 0:
            GPIO0_ConfigOutput(pin, u8opMode, u16udMode, u8crtMode);
            break;
        case 1:
            GPIO1_ConfigOutput(pin, u8opMode, u16udMode, u8crtMode);
            break;
        case 2:
            GPIO2_ConfigOutput(pin, u8opMode, u16udMode, u8crtMode);
            break;
        default:
            break;
    }
}

/**
 * Configure PORT0 as Input Mode with Pull-up or Pull-down Resistors
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u16udMode Pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 */
void GPIO0_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode)
{
    P0UP = (P0UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P0RD = (P0RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P0DIR &= ~(1 << u8PinNum);
}

/**
 * Configure PORT1 as Input Mode with Pull-up or Pull-down Resistors
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u16udMode Pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 */
void GPIO1_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode)
{
    P1UP = (P1UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P1RD = (P1RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P1DIR &= ~(1 << u8PinNum);
}

/**
 * Configure PORT2 as Input Mode with Pull-up or Pull-down Resistors
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_5
 * @param[in] u16udMode Pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 */
void GPIO2_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode)
{
    P2UP = (P2UP & (~(1 << u8PinNum))) | (u16udMode << u8PinNum);
    P2RD = (P2RD & (~(1 << u8PinNum))) | ((u16udMode >> 8) << u8PinNum);
    P2DIR &= ~(1 << u8PinNum);
}

/**
 * Configure PORT as Input Mode with Pull-up or Pull-down Resistors
 * @param[in] u8PinNum Pin number: 0~7, 10~17, 20~25
 * @param[in] u16udMode Pull-up or pull-down resistors
 * -# GPIO_PULLUP
 * -# GPIO_PULLDOWN
 * -# GPIO_NOPULL
 */
void GPIO_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode)
{
    uint8_t group = u8PinNum / 10;
    uint8_t pin   = u8PinNum % 10;
    switch(group)
    {
        case 0:
            GPIO0_ConfigInput(pin, u16udMode);
            break;
        case 1:
            GPIO1_ConfigInput(pin, u16udMode);
            break;
        case 2:
            GPIO2_ConfigInput(pin, u16udMode);
            break;
        default:
            break;
    }
}

/**
 * Configure PORT0 Interrupt Mode
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u8PinIntMode Interrupt trigger mode
 * -# GPIO_INT_NONE
 * -# GPIO_INT_RISING
 * -# GPIO_INT_FALLING
 * -# GPIO_INT_RISING_FALLING
 */
void GPIO0_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode)
{
    PIO0EICFGL = (PIO0EICFGL & (~(0x03 << (u8PinNum * 2)))) | ((u8PinIntMode << (u8PinNum * 2)) & 0xFF);
    PIO0EICFGH = (PIO0EICFGH & (~((0x03 * (u8PinNum / 4)) << ((u8PinNum % 4) * 2))))
                 | (((u8PinIntMode * (u8PinNum / 4)) << ((u8PinNum % 4) * 2)));
}

/**
 * Configure PORT1 Interrupt Mode
 * @param[in] u8PinNum Pin number: GPIO_PIN_0 - GPIO_PIN_7
 * @param[in] u8PinIntMode Interrupt trigger mode
 * -# GPIO_INT_NONE
 * -# GPIO_INT_RISING
 * -# GPIO_INT_FALLING
 * -# GPIO_INT_RISING_FALLING
 */
void GPIO1_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode)
{
    PIO1EICFGL = (PIO1EICFGL & (~(0x03 << (u8PinNum * 2)))) | ((u8PinIntMode << (u8PinNum * 2)) & 0xFF);
    PIO1EICFGH = (PIO1EICFGH & (~((0x03 * (u8PinNum / 4)) << ((u8PinNum % 4) * 2))))
                 | (((u8PinIntMode * (u8PinNum / 4)) << ((u8PinNum % 4) * 2)));
}

/**
 * Configure PORT Interrupt Mode
 * @param[in] u8PinNum Pin number: 0~7, 10~17
 * @param[in] u8PinIntMode Interrupt trigger mode
 * -# GPIO_INT_NONE
 * -# GPIO_INT_RISING
 * -# GPIO_INT_FALLING
 * -# GPIO_INT_RISING_FALLING
 */
void GPIO_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode)
{
    uint8_t group = u8PinNum / 10;
    uint8_t pin   = u8PinNum % 10;

    switch(group)
    {
        case 0:
            GPIO0_ConfigINT(pin, u8PinIntMode);
            break;
        case 1:
            GPIO1_ConfigINT(pin, u8PinIntMode);
            break;
        default:
            break;
    }
}