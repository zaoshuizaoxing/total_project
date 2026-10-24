/**
 * @file      flash.h
 * @brief     FLASH Driver Configuration
 * @author    Software Team
 * @date      2025-04
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __FLASH_H__
#define __FLASH_H__

#include "WY8S8002xx.h"

#define     BYTE_READ_CONFIG        0x10
#define     BYTE_PROGRAM_CONFIG     0x01
#define     BYTE_READ_APP           0x20
#define     BYTE_PROGRAM_APP        0x02
#define     BYTE_DIS_COMMAND        0x00
#define     BYTE_READ_EEPROM        0x80
#define     BYTE_WRITE_EEPROM       0x40
#define     HIBYTE(v1)              ((unsigned char)((v1)>>8))                   
#define     LOBYTE(v1)              ((unsigned char)((v1)&0xFF))

#define BAND_GAP_1200MV_FT_ADDR				0x11
#define BAND_GAP_1200MV_CP_ADDR				0x13
#define ADC_VREF_2500MV_FT_ADDR				0x12
#define ADC_VREF_2500MV_CP_ADDR				0x14

#define 	FLASH_END_ADDR   (8 * 1024 - 1)         /*!< The end address of FLASH */

/**@name External Functions
 * @{
 */
uint8_t Program_Flash_Init(void);
uint8_t Program_Flash_UnInit(void);
void Program_Flash(uint16_t u16Addr,uint8_t *u8DataBuf,uint16_t u16size);
void Read_Flash(uint16_t u16Addr,uint8_t *u8DataBuf,uint16_t u16size);
void Program_Config(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size);
void Read_Config(uint8_t u8Addr,uint8_t *u8DataBuf,uint8_t u8size);
void Program_EEPROM(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size);
void Read_EEPROM(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size);
uint16_t IAP_GetChipBandGap(void);
uint16_t IAP_GetReferenceVoltage2_5V(void);
/**@} */

#endif /* __FLASH_H__ */
