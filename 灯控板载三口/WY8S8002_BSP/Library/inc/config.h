/**
 * @file      config.h
 * @brief     CONFIG driver configuration
 * @author    Software Team
 * @date      2023-07
 * @version   V1.0.0
 * @copyright WAYON
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

/**
 * @brief Enable debugging features
 * @return 0: Execution successful
 *         1: Execution failed
 * @note If you need to disable debugging features, you can configure it in the Keil's settings interface
 */
uint8_t CONFIG_Enable_OCD(void);

#define OCD_ENABLE CONFIG_Enable_OCD()

#endif /* __CONFIG_H__ */
