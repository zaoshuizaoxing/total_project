/**
 * @file      iap_aprom.c
 * @brief     Implement IAP Functionality
 * @author    Software Team
 * @date      2025-04
 * @version   V1.0.0
 * @copyright WAYON
 */
#include "common.h"
#include "flash.h"

/**
 * Enable the flash write function
 * @return 0: Success
 *         1: Failure
 */
uint8_t Program_Flash_Init()
{
    IAPCON = BYTE_PROGRAM_APP;
    if(IAPCON == BYTE_PROGRAM_APP)
        return 1;
    else
        return 0;
}

/**
 * Disable the flash write function
 * @return 0: Success
 *         1: Failure
 */
uint8_t Program_Flash_UnInit()
{
    IAPCON = BYTE_DIS_COMMAND;
    if(IAPCON == BYTE_DIS_COMMAND)
        return 1;
    else
        return 0;
}

/**
 * Write data to FLASH
 * @param[in] u16Addr: Write address (16-bit width)
 * @param[in] u8DataBuf: Data to be written
 * @param[in] u16size: Data length
 */
void Program_Flash(uint16_t u16Addr, uint8_t *u8DataBuf, uint16_t u16size)
{
    uint16_t u16DataLen = 0;
    u16size             = (u16size + 1) & ~1; // Adjust size for half Words

    while(u16size)
    {
        IAPAL = LOBYTE(u16Addr / 2);
        IAPAH = HIBYTE(u16Addr / 2);

        IAPFD0 = u8DataBuf[u16DataLen];
        IAPFD1 = u8DataBuf[u16DataLen + 1];

        while(IAPCON & 0x04)
            ;

        u16DataLen += 2;
        u16Addr += 2;
        u16size -= 2;
    }
}

/**
 * Read data to FLASH
 * @param[in] u16Addr: Read address (16-bit width)
 * @param[in] u8DataBuf: Data to be read out
 * @param[in] u16size: Data length
 */
void Read_Flash(uint16_t u16Addr, uint8_t *u8DataBuf, uint16_t u16size)
{
    uint16_t u16DataLen = 0;
    u16size             = (u16size + 1) & ~1; // Adjust size for half Words
    while(u16size)
    {
        IAPAL = LOBYTE(u16Addr / 2);
        IAPAH = HIBYTE(u16Addr / 2);

        IAPCON = BYTE_READ_APP;

        while(IAPCON & 0x20)
            ;

        u8DataBuf[u16DataLen]     = IAPFD0;
        u8DataBuf[u16DataLen + 1] = IAPFD1;

        u16Addr += 2;
        u16size -= 2;
        u16DataLen += 2;
    }
}

/**
 * Write data to config
 * @param[in] u8Addr: Write address
 * @param[in] u8DataBuf: Data to be written
 * @param[in] u8size: Data length
 * @note
 */
void Program_Config(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size)
{
    uint8_t u8DataAddr = 0;
    u8size             = (u8size + 1) & ~1; // Adjust size for half Words

    while(u8size)
    {
        IAPCON = BYTE_PROGRAM_CONFIG;

        IAPAL = LOBYTE(u8Addr / 2);

        IAPFD0 = u8DataBuf[u8DataAddr];
        IAPFD1 = u8DataBuf[u8DataAddr + 1];

        while(IAPCON & 0x04)
            ;

        u8Addr += 2;
        u8size -= 2;
        u8DataAddr += 2;
    }
}

/**
 * Read data to config
 * @param[in] u8Addr: Read address
 * @param[in] u8DataBuf: Data to be read out
 * @param[in] u8size: Data length
 */
void Read_Config(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size)
{
    uint8_t u8DataLen = 0;
    u8size            = (u8size + 1) & ~1; // Adjust size for half Words
    while(u8size)
    {
        IAPAL = LOBYTE(u8Addr / 2);

        IAPCON = BYTE_READ_CONFIG;

        while(IAPCON & 0x10)
            ;

        u8DataBuf[u8DataLen]     = IAPFD0;
        u8DataBuf[u8DataLen + 1] = IAPFD1;

        u8Addr += 2;
        u8size -= 2;
        u8DataLen += 2;
    }
}

/**
 * Write data to EEPROM
 * @param[in] u8Addr: Write address
 * @param[in] u8DataBuf: Data to be written
 * @param[in] u8size: Data length
 * @note
 */
void Program_EEPROM(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size)
{
    uint8_t u8DataAddr = 0;

    while(u8size)
    {
        IAPCON = BYTE_WRITE_EEPROM;

        IAPAL = LOBYTE(u8Addr);

        IAPFD1 = u8DataBuf[u8DataAddr];

        while(IAPCON & 0x04)
            ;

        u8Addr += 1;
        u8size -= 1;
        u8DataAddr += 1;
    }
}

/**
 * Read data to EEPROM
 * @param[in] u8Addr: Read address
 * @param[in] u8DataBuf: Data to be read out
 * @param[in] u8size: Data length
 * @note
 */
void Read_EEPROM(uint8_t u8Addr, uint8_t *u8DataBuf, uint8_t u8size)
{
    uint8_t u8DataAddr = 0;

    while(u8size)
    {
        IAPAL = LOBYTE(u8Addr);

        IAPCON = BYTE_READ_EEPROM;

        while(IAPCON & 0x80)
            ;
        u8DataBuf[u8DataAddr] = IAPFD1;

        u8Addr += 1;
        u8size -= 1;
        u8DataAddr += 1;
    }
}

/**
 * Get internal bandgap voltage value stored at chip manufacturing
 * @return ADC bandgap voltage value in mV
 */
uint16_t IAP_GetChipBandGap(void)
{
	uint16_t tmp = 0;
	IAPAL = BAND_GAP_1200MV_FT_ADDR;
	IAPCON = 0x10;
	while(IAPCON & 0x10);
	tmp = (IAPFD1<<8)|IAPFD0;
	if((tmp == 0x0000)||(tmp == 0xFFFF)){               
		IAPAL = BAND_GAP_1200MV_CP_ADDR;
		IAPCON = 0x10;
		while(IAPCON & 0x10);
		tmp = (IAPFD1<<8)|IAPFD0;
	}
  return tmp;
}
/**
 * Get the internal 2.5V reference voltage value of ADC in memory chip
 * @return ADC internal 2.5V reference voltage value in mV
 */
uint16_t IAP_GetReferenceVoltage2_5V(void)
{
	uint16_t tmp = 0;
	IAPAL = ADC_VREF_2500MV_FT_ADDR;
	IAPCON = 0x10;
	while(IAPCON & 0x10);
	tmp = (IAPFD1<<8)|IAPFD0;
	if((tmp == 0x0000)||(tmp == 0xFFFF)){               
		IAPAL = ADC_VREF_2500MV_CP_ADDR;
		IAPCON = 0x10;
		while(IAPCON & 0x10);
		tmp = (IAPFD1<<8)|IAPFD0;
	}
  return tmp;
}