/**
 * @file      ir.h
 * @brief     ir driver configuration
 * @author    Software Team
 * @date      2025-04
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __IR_H__
#define __IR_H__

#include "WY8S8002xx.h"

/************************************************************/
/*                  bit definition                          */
/************************************************************/
/* bit definition for IRCON */
#define IR_CON_EN_Pos                   (7U)
#define IR_CON_EN_Msk                   (0x1U << IR_CON_EN_Pos)
#define IR_CON_EN                       IR_CON_EN_Msk
#define IR_CON_IE_Pos                   (6U)
#define IR_CON_IE_Msk                   (0x1U << IR_CON_IE_Pos)
#define IR_CON_IE                       IR_CON_IE_Msk
#define IR_CON_LCODEEN_Pos              (5U)
#define IR_CON_LCODEEN_Msk              (0x1U << IR_CON_LCODEEN_Pos)
#define IR_CON_LCODEEN                  IR_CON_LCODEEN_Msk
#define IR_CON_RXTX_Pos                 (4U)
#define IR_CON_RXTX_Msk                 (0x1U << IR_CON_RXTX_Pos)
#define IR_CON_RXTX                     IR_CON_RXTX_Msk
#define IR_CON_LCODE1_Pos               (3U)
#define IR_CON_LCODE1_Msk               (0x1U << IR_CON_LCODE1_Pos)
#define IR_CON_LCODE1                   IR_CON_LCODE1_Msk
#define IR_CON_LCODE0_Pos               (2U)
#define IR_CON_LCODE0_Msk               (0x1U << IR_CON_LCODE0_Pos)
#define IR_CON_LCODE0                   IR_CON_LCODE0_Msk
#define IR_CON_CODE1_Pos                (1U)
#define IR_CON_CODE1_Msk                (0x1U << IR_CON_CODE1_Pos)
#define IR_CON_CODE1                    IR_CON_CODE1_Msk
#define IR_CON_CODE0_Pos                (0U)
#define IR_CON_CODE0_Msk                (0x1U << IR_CON_CODE0_Pos)
#define IR_CON_CODE0                    IR_CON_CODE0_Msk

/* bit definition for IRRCFG */
#define IR_RCFG_IRRT_Pos                (5U)
#define IR_RCFG_IRRT_Msk                (0x3U << IR_RCFG_IRRT_Pos)
#define IR_RCFG_IRRT_12_5K              (0x0U << IR_RCFG_IRRT_Pos)
#define IR_RCFG_IRRT_25K                (0x1U << IR_RCFG_IRRT_Pos)
#define IR_RCFG_IRRT_50K                (0x2U << IR_RCFG_IRRT_Pos)
#define IR_RCFG_IRRT_100K               (0x3U << IR_RCFG_IRRT_Pos)
#define IR_RCFG_VREF_SEL_Pos            (0U)
#define IR_RCFG_VREF_SEL_Msk            (0x1FU << IR_RCFG_VREF_SEL_Pos)
#define IR_RCFG_VREF_SEL                IR_RCFG_VREF_SEL_Msk

/* bit definition for IRTWORDLO */
#define IR_IRTWORDLO_BITLO_Pos          (6U)
#define IR_IRTWORDLO_BITLO_Msk          (0x3U << IR_IRTWORDLO_BITLO_Pos)
#define IR_IRTWORDLO_BITLO_0            (0x0U << IR_IRTWORDLO_BITLO_Pos)
#define IR_IRTWORDLO_BITLO_1            (0x1U << IR_IRTWORDLO_BITLO_Pos)
#define IR_IRTWORDLO_BITLO_2            (0x2U << IR_IRTWORDLO_BITLO_Pos)
#define IR_IRTWORDLO_BITLO_3            (0x3U << IR_IRTWORDLO_BITLO_Pos)
#define IR_IRTWORDLO_IRTWORDLO_Pos      (0U)
#define IR_IRTWORDLO_IRTWORDLO_Msk      (0x3U << IR_IRTWORDLO_IRTWORDLO_Pos)
#define IR_IRTWORDLO_IRTWORDLO          IR_IRTWORDLO_IRTWORDLO_Msk

/* bit definition for IRTWORDHI */
#define IR_IRTWORDHI_BITHI_Pos          (6U)
#define IR_IRTWORDHI_BITHI_Msk          (0x3U << IR_IRTWORDHI_BITHI_Pos)
#define IR_IRTWORDHI_BITHI_0            (0x0U << IR_IRTWORDHI_BITHI_Pos)
#define IR_IRTWORDHI_BITHI_1            (0x1U << IR_IRTWORDHI_BITHI_Pos)
#define IR_IRTWORDHI_BITHI_2            (0x2U << IR_IRTWORDHI_BITHI_Pos)
#define IR_IRTWORDHI_BITHI_3            (0x3U << IR_IRTWORDHI_BITHI_Pos)
#define IR_IRTWORDHI_IRTWORDHI_Pos      (0U)
#define IR_IRTWORDHI_IRTWORDHI_Msk      (0x3U << IR_IRTWORDHI_IRTWORDHI_Pos)
#define IR_IRTWORDHI_IRTWORDHI          IR_IRTWORDHI_IRTWORDHI_Msk

/* bit definition for IRSTA */
#define IR_STA_RCODE1_Pos               (5U)
#define IR_STA_RCODE1_Msk               (0x1U << IR_STA_RCODE1_Pos)
#define IR_STA_RCODE1                   IR_STA_RCODE1_Msk
#define IR_STA_RCODE0_Pos               (4U)
#define IR_STA_RCODE0_Msk               (0x1U << IR_STA_RCODE0_Pos)
#define IR_STA_RCODE0                   IR_STA_RCODE0_Msk
#define IR_STA_TDONEHI_Pos              (2U)
#define IR_STA_TDONEHI_Msk              (0x1U << IR_STA_TDONEHI_Pos)
#define IR_STA_TDONEHI                  IR_STA_TDONEHI_Msk
#define IR_STA_TDONELO_Pos              (1U)
#define IR_STA_TDONELO_Msk              (0x1U << IR_STA_TDONELO_Pos)
#define IR_STA_TDONELO                  IR_STA_TDONELO_Msk
#define IR_STA_TDONELC_Pos              (0U)
#define IR_STA_TDONELC_Msk              (0x1U << IR_STA_TDONELC_Pos)
#define IR_STA_TDONELC                  IR_STA_TDONELC_Msk


/** @defgroup IR_lcode_Signal_Type ir signal type
 * @{
 */
#define IR_LCODE_LOW_LEVEL                  (0x0U)      /*!< lcode signal type is low level signal */
#define IR_LCODE_CARRIER                    (0x1U)      /*!< lcode signal type is carrier signal */
/**
 * @}
 */

/** @defgroup IR_Logic_Signal_Type ir signal type
 * @{
 */
#define IR_LOGIC_SEC0_CARRIER_SEC1_LEVEL    (0x0U)      /*!< Logic signal type is : section0-carrier_signal; section1-level_signal*/
#define IR_LOGIC_SEC0_LEVEL_SEC1_CARRIER    (0x1U)      /*!< Logic signal type is : section0-level_signal; section1-carrier_signal */
/**
 * @}
 */

/** @defgroup IR_Function_Sel ir signal type
 * @{
 */
#define IR_RECEIVE_FUNCTION                 (0x0U)      /*!< ir receive function*/
#define IR_TRANSMISSION_FUNCTION            (0x1U)      /*!< ir_transmission_function */
/**
 * @}
 */

/** @defgroup IR_interrupt_flag ir signal type
 * @{
 */
#define IR_IFLAG_RCODE1                     IR_STA_RCODE1   /* flag of received carrier signal */
#define IR_IFLAG_RCODE0                     IR_STA_RCODE0   /* flag of received low_level signal */
#define IR_IFLAG_TDONEHI                    IR_STA_TDONEHI  /* flag of TDONEHI transmission completion*/
#define IR_IFLAG_TDONELO                    IR_STA_TDONELO  /* flag of TDONELO transmission completion */
#define IR_IFLAG_TDONELC                    IR_STA_TDONELC  /* flag of LCODE transmission completion */
/**
 * @}
 */


/**
 * @brief IR lcode0 signal type set.
 * @param SigType: signal type
 *        This parameter can be one of the following values:
 *          @arg @ref IR_LCODE_LOW_LEVEL signal type is low level signal
 *          @arg @ref IR_LCODE_CARRIER  signal type is carrier signal
 */
#define IR_LCODE0_TYPE_SET(SigType)       \
    IRCON = IRCON & (~IR_CON_LCODE0) | (SigType << IR_CON_LCODE0_Pos)

/**
 * @brief IR lcode0 signal length set.
 * @param u16Len: signal length
 *        This parameter can be one of the following values:
 *          @arg @ref u16Len <= 0x3FF  
 */
#define IR_LCODE0_LENGTH_SET(u16Len)        \
    do {                                    \
        IRL0PRD1 = (u16Len);                \
        IRL0PRD2 = ((uint16_t)u16Len)>>8;   \
    } while(0);

/**
 * @brief IR lcode0 signal length get.
 */
#define IR_LCODE0_LENGTH_GET()              \
    (((uint16_t)IRL0PRD2 << 8) | IRL0PRD1)

/**
 * @brief IR lcode0 signal type set.
 * @param SigType: signal type
 *        This parameter can be one of the following values:
 *          @arg @ref IR_LCODE_LOW_LEVEL signal type is low level signal
 *          @arg @ref IR_LCODE_CARRIER  signal type is carrier signal * 
 */
#define IR_LCODE1_TYPE_SET(SigType)       \
    IRCON = IRCON & (~IR_CON_LCODE1) | (SigType << IR_CON_LCODE1_Pos)

/**
 * @brief IR lcode1 signal length set.
 * @param u16Len: signal length
 *        This parameter can be one of the following values:
 *          @arg @ref u16Len <= 0x3FF  
 */
#define IR_LCODE1_LENGTH_SET(u16Len)        \
    do {                                    \
        IRL1PRD1 = (u16Len);                \
        IRL1PRD2 = ((uint16_t)u16Len)>>8;   \
    } while(0);

/**
 * @brief IR lcode1 signal length get.
 */
#define IR_LCODE1_LENGTH_GET()              \
    (((uint16_t)IRL1PRD2 << 8) | IRL1PRD1)

/**
 * @brief IR lcode sendenable.
 */
#define IR_LCODE_SEND_ENABLE()              \
    IRCON |= IR_CON_LCODEEN

/**
 * @brief IR lcode sendenable.
 */
#define IS_LCODE_SEND_ENABLE()              \
    (IRCON & IR_CON_LCODEEN)

/**
 * @brief IR logic0 signal type set.
 * @param SigType: logic0 signal type
 *        This parameter can be one of the following values:
 *          @arg @ref IR_LOGIC_SEC0_CARRIER_SEC1_LEVEL Logic signal type is : section0-carrier_signal; section1-level_signal
 *          @arg @ref IR_LOGIC_SEC0_LEVEL_SEC1_CARRIER Logic signal type is : section0-level_signal; section1-carrier_signal
 */
#define IR_LOGIC0_TYPE_SET(SigType)           \
    IRCON = IRCON & (~IR_CON_CODE0) | (SigType<<IR_CON_CODE0_Pos)

/**
 * @brief IR logic0 signal length set.
 * @param u8Sec0: logic0 section 0 length
 * @param u8SeRL1PRD1c1: logic0 section 1 length
 *        This parameter can be one of the following values:
 *          @arg @ref u8Sec0 <= 0xFF; u8Sec1 <= 0xFF
 */
#define IR_LOGIC0_LENGTH_SET(u8Sec0, u8Sec1)    \
    do {                                        \
        IRL0PRD1 = (u8Sec0);                    \
        IRL0PRD2 = (u8Sec1);                    \
    } while(0);

/**
 * @brief IR logic1 signal type set.
 * @param SigType: logic1 signal type
 *        This parameter can be one of the following values:
 *          @arg @ref IR_LOGIC_SEC0_CARRIER_SEC1_LEVEL Logic signal type is : section0-carrier_signal; section1-level_signal
 *          @arg @ref IR_LOGIC_SEC0_LEVEL_SEC1_CARRIER Logic signal type is : section0-level_signal; section1-carrier_signal
 */
#define IR_LOGIC1_TYPE_SET(SigType)           \
    IRCON = IRCON & (~IR_CON_CODE1) | (SigType<<IR_CON_CODE1_Pos)

/**
 * @brief IR logic1 signal length set.
 * @param u8Sec0: logic1 section 0 length
 * @param u8Sec1: logic1 section 1 length
 *        This parameter can be one of the following values:
 *          @arg @ref u8Sec0 <= 0xFF; u8Sec1 <= 0xFF
 */
#define IR_LOGIC1_LENGTH_SET(u8Sec0, u8Sec1)    \
    do {                                        \
        IRL1PRD1 = (u8Sec0);                    \
        IRL1PRD2 = (u8Sec1);                    \
    } while(0);

/**
 * @brief IR function selection
 * @param func: IR function
 * @param u8Sec1: logic1 section 1 length
 *        This parameter can be one of the following values:
 *          @arg @ref IR_RECEIVE_FUNCTION
 *          @arg @ref IR_TRANSMISSION_FUNCTION
 */
#define IR_FUNC_SEL(func)                       \
    IRCON = IRCON & (~IR_CON_RXTX) | ((func)<<IR_CON_RXTX_Pos);

/**
 * @brief IR enable
 */
#define IR_ENABLE()                             \
    IRCON |= IR_CON_EN

/**
 * @brief IR disable
 */
#define IR_DISABLE()                            \
    IRCON &= ~IR_CON_EN

/**
 * @brief IR interrupt enable
 */
#define IR_INTERRUPT_ENABLE()                   \
    IRCON |= IR_CON_IE

/**
 * @brief IR interrupt disable
 */
#define IR_INTERRUPT_DISABLE()                   \
    IRCON &= ~IR_CON_IE



/**
 * @brief IR write send data register high 4 bit
 * @param active: effective bit
 *        This parameter can be one of the following values: active <= 0x3
 * @param val: send data
 *        This parameter can be one of the following values: val <= 0xF
 */
#define IR_WRITE_DATA_HIGH(active, val)          \
    IRTWORDHI = ((active) << IR_IRTWORDHI_BITHI_Pos) | ((val) << IR_IRTWORDHI_IRTWORDHI_Pos)

/**
 * @brief IR write send data register low 4 bit
 * @param active: effective bit
 *        This parameter can be one of the following values: active <= 0x3
 * @param val: send data
 *        This parameter can be one of the following values: val <= 0xF
 */
#define IR_WRITE_DATA_LOW(active, val)          \
    IRTWORDLO = ((active) << IR_IRTWORDLO_BITLO_Pos) | ((val) << IR_IRTWORDLO_IRTWORDLO_Pos)

/** @brief  Clear ir flag.
 * @param  __FLAG__ specifies the flag to clear.
 *          This parameter can be any combination of the following values:
 *            @arg @ref IR_IFLAG_RCODE1   flag of received carrier signal
 *            @arg @ref IR_IFLAG_RCODE0   flag of received low_level signal
 *            @arg @ref IR_IFLAG_TDONEHI  flag of TDONEHI transmission completion
 *            @arg @ref IR_IFLAG_TDONELO  flag of TDONELO transmission completion
 *            @arg @ref IR_IFLAG_TDONELO  flag of LCODE transmission completion
 *
 * @retval None
 */
#define IR_CLEAR_FLAG(__FLAG__) (IRSTA &= ~(__FLAG__))

/** @brief  Get ir flag.
 * @param  __FLAG__ specifies the flag to clear.
 *          This parameter can be any combination of the following values:
 *            @arg @ref IR_IFLAG_RCODE1   flag of received carrier signal
 *            @arg @ref IR_IFLAG_RCODE0   flag of received low_level signal
 *            @arg @ref IR_IFLAG_TDONEHI  flag of TDONEHI transmission completion
 *            @arg @ref IR_IFLAG_TDONELO  flag of TDONELO transmission completion
 *            @arg @ref IR_IFLAG_TDONELO  flag of LCODE transmission completion
 *
 * @retval None
 */
#define IR_GET_FLAG(__FLAG__) ((IRSTA & (__FLAG__)) ? 1 : 0)

/** @brief  selection of receiving resistance.
 * @param  RESIS receiving resistance.
 *          This parameter can be any combination of the following values:
 *            @arg @ref IR_RCFG_IRRT_12_5K
 *            @arg @ref IR_RCFG_IRRT_25K
 *            @arg @ref IR_RCFG_IRRT_50K
 *            @arg @ref IR_RCFG_IRRT_100K
 *
 * @retval None
 */
#define IR_RECE_RESIS_SEL(RESIS)                          \
    IRRCFG = (IRRCFG & ~IR_RCFG_IRRT_Msk) | ((RESIS) << IR_RCFG_IRRT_Pos)

/** @brief  receiving reference voltage.
 * reference voltage = (VOLT + 32) / 64 * AVDD
 * @retval None
 */
#define IR_RECE_REF_VOLT_SEL(VOLT)                          \
    IRRCFG = (IRRCFG & ~IR_RCFG_VREF_SEL) | ((VOLT) << IR_RCFG_VREF_SEL_Pos)



typedef struct {
    uint8_t CarrierFreq;        /*!< Carrier Frequency, range: 30 - 60 */
    uint8_t CarrierDuty;        /*!< Carrier duty cycle, range: 0 - 100 */
    uint8_t Function;           /*!< transmission or receive, range:IR_Function_Sel */

    uint8_t Lcode0SignalType;   /*!< Lcode0 signal type, range:IR_lcode_Signal_Type */
    uint8_t Lcode1SignalType;   /*!< Lcode1 signal type, range:IR_lcode_Signal_Type */
    
    uint8_t Logic0SignalType;   /*!< Logic0 signal type, range:IR_Logic_Signal_Type */
    uint8_t Logic1SignalType;   /*!< Logic1 signal type, range:IR_Logic_Signal_Type */
} IR_Init_t;


void IR_Init (const IR_Init_t* Init);

#endif /* __IR_H__ */
