/**
 * @file      gpio.h
 * @brief     General Purpose IO (GPIO) interface driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */
#ifndef __GPIO_H__
#define __GPIO_H__

#include "WY8S8002xx.h"

#define GPIO_PIN_0    (0x00)
#define GPIO_PIN_1    (0x01)
#define GPIO_PIN_2    (0x02)
#define GPIO_PIN_3    (0x03)
#define GPIO_PIN_4    (0x04)
#define GPIO_PIN_5    (0x05)
#define GPIO_PIN_6    (0x06)
#define GPIO_PIN_7    (0x07)

#define GPIO_PULLUP   (0x0001) /*!< Pull-up mode */
#define GPIO_PULLDOWN (0x0100) /*!< Pull-down mode */
#define GPIO_NOPULL   (0x0000) /*!< No pull-up or pull-down */

#define GPIO_PP       (0x00)   /*!< Push-pull output mode */
#define GPIO_OD       (0x01)   /*!< Open-drain output mode */

#define CURRENT_00    (0x00)   /*!< Output drive capability mode 0 */
#define CURRENT_01    (0x01)   /*!< Output drive capability mode 1 */
#define CURRENT_10    (0x02)   /*!< Output drive capability mode 2 */
#define CURRENT_11    (0x03)   /*!< Output drive capability mode 3 */
/**@} */
/**@name Interrupt Mode Configuration
 * @{
 */
#define GPIO_INT_NONE           (0x00) /*!< Disable interrupt */
#define GPIO_INT_RISING         (0x01) /*!< Input rising edge interrupt */
#define GPIO_INT_FALLING        (0x02) /*!< Input falling edge interrupt */
#define GPIO_INT_RISING_FALLING (0x03) /*!< Input both edges interrupt */

/**
 * Check if GPIO has an interrupt flag
 * @param[in] PinNum GPIO_PIN_0 - GPIO_PIN_7
 */
#define IS_GPIO0_FLAG(PinNum) (PIO0IF & (1 << (PinNum)))
#define IS_GPIO1_FLAG(PinNum) (PIO1IF & (1 << (PinNum)))

/**
 * Clear GPIO interrupt flag
 * @param[in] PinNum GPIO_PIN_0 - GPIO_PIN_7
 */
#define CLR_GPIO0_FLAG(PinNum) (PIO0IF &= ~(1 << (PinNum)))
#define CLR_GPIO1_FLAG(PinNum) (PIO1IF &= ~(1 << (PinNum)))
/**@} */

/**@name External Functions
 * @{
 */
void GPIO0_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode);
void GPIO1_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode);
void GPIO2_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode);
void GPIO_ConfigOutput(uint8_t u8PinNum, uint8_t u8opMode, uint16_t u16udMode, uint8_t u8crtMode);
void GPIO0_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode);
void GPIO1_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode);
void GPIO2_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode);
void GPIO_ConfigInput(uint8_t u8PinNum, uint16_t u16udMode);
void GPIO0_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode);
void GPIO1_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode);
void GPIO_ConfigINT(uint8_t u8PinNum, uint8_t u8PinIntMode);

/**@} */

#endif /* __GPIO_H__ */
