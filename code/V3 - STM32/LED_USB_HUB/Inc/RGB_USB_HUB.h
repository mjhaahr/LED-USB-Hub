/**
 *****************************************************************************
 *
 * @file        RGB_USB_HUB.h
 *
 * @module      RGB USB Hub Module (HUB)
 *
 * @brief       Handles the operating logic for the RGB USB Hub
 *
 * @author      Matthew Haahr
 *****************************************************************************
 */

#ifndef __HUB_H__
#define __HUB_H__
// ------------------------------------------------------------------------ //
// Includes
// ------------------------------------------------------------------------ //
#include "main.h"
#include "stm32l5xx_hal.h"

// ------------------------------------------------------------------------ //
// Public Macros/Defines
// ------------------------------------------------------------------------ //

// ------------------------------------------------------------------------ //
// Public Typedefs
// ------------------------------------------------------------------------ //

// ------------------------------------------------------------------------ //
// Public Method Definitions
// Public Methods:
// ------------------------------------------------------------------------ //
/**
 * Initializes the RGB USB Hub  Module
 * @param TIM_HandleTypeDef* htim1 - HAL Timer Handle 1
 * @param TIM_HandleTypeDef* htim2 - HAL Timer Handle 2
 * @param TIM_HandleTypeDef* htim3 - HAL Timer Handle 3
 * @param PCD_HandleTypeDef* hpcd_USB_FS - HAL USB Handle
 */
void HUB_Init(TIM_HandleTypeDef* htim1, TIM_HandleTypeDef* htim2, TIM_HandleTypeDef* htim3, PCD_HandleTypeDef* hpcd_USB_FS);

/**
 * Runs the main task of the RGB USB Hub  Module
 */
void HUB_Task(void);

#endif /* __HUB_H__ */
