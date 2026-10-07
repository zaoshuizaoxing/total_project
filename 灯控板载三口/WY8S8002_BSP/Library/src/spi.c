/**
 * @file      spi.c
 * @brief     SPI Module Driver
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#include "spi.h"

/**
 * Configures the SPI mode
 * @param[in] u8MSmode Master/Slave mode
 * -# SPI_SLAVE_NSSI         Configure SPI as a slave, with NSS pin as input, acting as a slave select signal
 * -# SPI_MULTI_MASTER_NSSI  Configure SPI as a master in multi-master mode, with NSS pin as input
 * -# SPI_SINGLE_MASTER_NSSO Configure SPI as a single master, with NSS pin as output
 * @param[in] u8mlsb Data transfer start bit configuration
 * -# SPI_MSB_MODE: Transfer starts from the most significant bit
 * -# SPI_LSB_MODE: Transfer starts from the least significant bit
 * @param[in] u8workMode Working mode configuration
 * -# SPI_MODE0
 * -# SPI_MODE1
 * -# SPI_MODE2
 * -# SPI_MODE3
 * @note Configure the SPI mode using CPOL and CPHA \n
@verbatim
  CPOL  CPHA  MODE
  0      0    mode0
  0      1    mode1
  1      0    mode2
  1      1    mode3
@endverbatim
 */
void SPI_ConfigMode(uint8_t u8MSmode, uint8_t u8mlsb, uint8_t u8workMode)
{
    SPI_SPICFG_MS_SET((u8MSmode >> 1) & 0x01); /* Mode selection */
    SPI_SPICFG_OENMST_SET(u8MSmode & 0x01);
    SPI_SPICFG_MSB_SET(u8mlsb);
    SPI_SPIMOD_CPOL_SET((u8workMode >> 1) & 0x01); /* Mode selection */
    SPI_SPIMOD_CPHA_SET(u8workMode & 0x01);
}
