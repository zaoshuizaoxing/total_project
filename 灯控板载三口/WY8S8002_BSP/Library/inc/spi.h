/**
 * @file      spi.h
 * @brief     SPI driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __SPI_H__
#define __SPI_H__

#include "WY8S8002xx.h"

/**@name SPI Configuration Register - SPICFG
 * @{
 */
#define SPI_SPICFG_EN_POS      (7)
#define SPI_SPICFG_EN_MSK      (0x1 << SPI_SPICFG_EN_POS)
#define SPI_SPICFG_MS_POS      (6)
#define SPI_SPICFG_MS_MSK      (0x1 << SPI_SPICFG_MS_POS)
#define SPI_SPICFG_OENMST_POS  (5)
#define SPI_SPICFG_OENMST_MSK  (0x1 << SPI_SPICFG_OENMST_POS)
#define SPI_SPICFG_MSB_POS     (4)
#define SPI_SPICFG_MSB_MSK     (0x1 << SPI_SPICFG_MSB_POS)

#define ENABLE_SPI             (SPICFG |= SPI_SPICFG_EN_MSK)  /*!< Enable SPI */
#define DISABLE_SPI            (SPICFG &= ~SPI_SPICFG_EN_MSK) /*!< Disable SPI */

#define SPI_SLAVE_NSSI         (0) /*!< Set SPI as slave, NSS pin as input, used as slave chip select signal */
#define SPI_MULTI_MASTER_NSSI  (2) /*!< Set SPI as master and multi-master, NSS pin as input */
#define SPI_SINGLE_MASTER_NSSO (3) /*!< Set SPI as single master, NSS pin as output */
/**
 * SPI Working Mode Selection
 * @param[in] status High bit of SPI_SLAVE_NSSI, SPI_MULTI_MASTER_NSSI, SPI_SINGLE_MASTER_NSSO
 */
#define SPI_SPICFG_MS_SET(status) (SPICFG = ((SPICFG & (~SPI_SPICFG_MS_MSK)) | ((status) << SPI_SPICFG_MS_POS)))
/**
 * SPI Working Mode Configuration
 * @param[in] status Low bit of SPI_SLAVE_NSSI, SPI_MULTI_MASTER_NSSI, SPI_SINGLE_MASTER_NSSO
 */
#define SPI_SPICFG_OENMST_SET(status)                                                                                  \
    (SPICFG = ((SPICFG & (~SPI_SPICFG_OENMST_MSK)) | ((status) << SPI_SPICFG_OENMST_POS)))

#define SPI_LSB_MODE (1)
#define SPI_MSB_MODE (0)
/**
 * Transfer Start Bit Configuration
 * @param[in] status
 * -# SPI_MSB_MODE: Transfer starts from the most significant bit
 * -# SPI_LSB_MODE: Transfer starts from the least significant bit
 */
#define SPI_SPICFG_MSB_SET(status) (SPICFG = ((SPICFG & (~SPI_SPICFG_MSB_MSK)) | ((status) << SPI_SPICFG_MSB_POS)))
/**@} */

/**@name SPI Mode Register - SPIMOD
 * @{
 */
#define SPI_SPIMOD_CPOL_POS (5)
#define SPI_SPIMOD_CPOL_MSK (0x1 << SPI_SPIMOD_CPOL_POS)
#define SPI_SPIMOD_CPHA_POS (4)
#define SPI_SPIMOD_CPHA_MSK (0x1 << SPI_SPIMOD_CPHA_POS)
#define SPI_SPIMOD_PM_POS   (0)
#define SPI_SPIMOD_PM_MSK   (0x7 << SPI_SPIMOD_PM_POS)

#define SPI_MODE0           (0)
#define SPI_MODE1           (1)
#define SPI_MODE2           (2)
#define SPI_MODE3           (3)
/**
 * SPI Working Mode Configuration Bit, works with CPHA
 * @param[in] status High bit of SPI_MODE0, SPI_MODE1, SPI_MODE2, SPI_MODE3
 */
#define SPI_SPIMOD_CPOL_SET(status) (SPIMOD = ((SPIMOD & (~SPI_SPIMOD_CPOL_MSK)) | ((status) << SPI_SPIMOD_CPOL_POS)))
/**
 * SPI Working Mode Configuration Bit, works with CPOL
 * @param[in] status Low bit of SPI_MODE0, SPI_MODE1, SPI_MODE2, SPI_MODE3
 */
#define SPI_SPIMOD_CPHA_SET(status) (SPIMOD = ((SPIMOD & (~SPI_SPIMOD_CPHA_MSK)) | ((status) << SPI_SPIMOD_CPHA_POS)))

#define SPI_DIV_2                   (0x00)
#define SPI_DIV_4                   (0x01)
#define SPI_DIV_8                   (0x02)
#define SPI_DIV_16                  (0x03)
#define SPI_DIV_32                  (0x04)
#define SPI_DIV_64                  (0x05)
#define SPI_DIV_128                 (0x06)
#define SPI_DIV_256                 (0x07)
/**
 * PWM SCK Frequency Division Factor
 * @param[in] mode
 * -# SPI_DIV_2   System clock CLK_P/2 division
 * -# SPI_DIV_4   System clock CLK_P/4 division
 * -# SPI_DIV_8   System clock CLK_P/8 division
 * -# SPI_DIV_32  System clock CLK_P/32 division
 * -# SPI_DIV_64  System clock CLK_P/64 division
 * -# SPI_DIV_128 System clock CLK_P/128 division
 * -# SPI_DIV_256 System clock CLK_P/256 division
 */
#define SPI_DIV_SET(div) (SPIMOD = ((SPIMOD & (~SPI_SPIMOD_PM_MSK)) | ((div) << SPI_SPIMOD_PM_POS)))
/**@} */

/**@name SPI Status Register - SPISR
 * @{
 */
#define SPI_SPISR_IF_POS  (7)
#define SPI_SPISR_IF_MSK  (0x1 << SPI_SPISR_IF_POS)
#define SPI_SPISR_MME_POS (6)
#define SPI_SPISR_MME_MSK (0x1 << SPI_SPISR_MME_POS)
#define SPI_SPISR_WOL_POS (5)
#define SPI_SPISR_WOL_MSK (0x1 << SPI_SPISR_WOL_POS)
#define SPI_SPISR_OVF_POS (4)
#define SPI_SPISR_OVF_MSK (0x1 << SPI_SPISR_OVF_POS)
/**
 * Transfer Completion Flag
 * @return 1: SPI transfer completed
 *         0: SPI transfer not completed
 * @note This bit is automatically set by hardware
 */
#define IS_SPI_IF_FLAG ((SPISR & SPI_SPISR_IF_MSK) >> SPI_SPISR_IF_POS)
/**
 * Clear Transfer Completion Flag
 */
#define CLR_SPI_IF_FLAG (SPISR &= ~SPI_SPISR_IF_MSK)
/**
 * Mode Fault Flag
 * @return 1: Mode fault occurred
 *         0: No mode fault occurred
 * @note This bit is automatically set by hardware
 */
#define IS_SPI_MME_FLAG ((SPISR & SPI_SPISR_MME_MSK) >> SPI_SPISR_MME_POS)
/**
 * Clear Mode Fault Flag
 */
#define CLR_SPI_MME_FLAG (SPISR &= ~SPI_SPISR_MME_MSK)
/**
 * Write Collision Flag
 * @return 1: Write collision occurred
 *         0: No write collision occurred
 * @note This bit is automatically set by hardware
 */
#define IS_SPI_WOL_FLAG ((SPISR & SPI_SPISR_WOL_MSK) >> SPI_SPISR_WOL_POS)
/**
 * Clear Write Collision Flag
 */
#define CLR_SPI_WOL_FLAG (SPISR &= ~SPI_SPISR_WOL_MSK)
/**
 * Buffer Overflow Flag
 * @return 1: Buffer overflow occurred
 *         0: No buffer overflow occurred
 * @note This bit is automatically set by hardware
 */
#define IS_SPI_OVF_FLAG ((SPISR & SPI_SPISR_OVF_MSK) >> SPI_SPISR_OVF_POS)
/**
 * Clear Buffer Overflow Flag
 */
#define CLR_SPI_OVF_FLAG (SPISR &= ~SPI_SPISR_OVF_MSK)
/**@} */

/**
 * Write Data to SPITDR
 * @param[in] u8data Data to be written
 */
#define SPI_WRITE_SPITDR(u8data) (SPITDR = (u8data))
/**
 * Read Data from SPIRDR
 * @return Data read from SPIRDR
 */
#define SPI_RAED_SPIRDR (SPIRDR)

/**@name External Functions
 * @{
 */
void SPI_ConfigMode(uint8_t u8MSmode, uint8_t u8mlsb, uint8_t u8workMode);

/**@} */
#endif /* __SPI_H__ */
