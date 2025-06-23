/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HSI_IN_Pin GPIO_PIN_0
#define HSI_IN_GPIO_Port GPIOH
#define HSI_OUT_Pin GPIO_PIN_1
#define HSI_OUT_GPIO_Port GPIOH
#define USB3_BLUE_Pin GPIO_PIN_1
#define USB3_BLUE_GPIO_Port GPIOA
#define USB3_GREEN_Pin GPIO_PIN_2
#define USB3_GREEN_GPIO_Port GPIOA
#define USB3_RED_Pin GPIO_PIN_5
#define USB3_RED_GPIO_Port GPIOA
#define USB2_BLUE_Pin GPIO_PIN_6
#define USB2_BLUE_GPIO_Port GPIOA
#define USB2_GREEN_Pin GPIO_PIN_7
#define USB2_GREEN_GPIO_Port GPIOA
#define USB2_RED_Pin GPIO_PIN_0
#define USB2_RED_GPIO_Port GPIOB
#define USB1_OC_Pin GPIO_PIN_2
#define USB1_OC_GPIO_Port GPIOB
#define USB2_OC_Pin GPIO_PIN_10
#define USB2_OC_GPIO_Port GPIOB
#define USB3_OC_Pin GPIO_PIN_11
#define USB3_OC_GPIO_Port GPIOB
#define USB1_BLUE_Pin GPIO_PIN_8
#define USB1_BLUE_GPIO_Port GPIOA
#define USB1_GREEN_Pin GPIO_PIN_9
#define USB1_GREEN_GPIO_Port GPIOA
#define USB1_RED_Pin GPIO_PIN_10
#define USB1_RED_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define LED_EN_BUTTON_Pin GPIO_PIN_15
#define LED_EN_BUTTON_GPIO_Port GPIOA
#define BOOT_BUTTON_Pin GPIO_PIN_3
#define BOOT_BUTTON_GPIO_Port GPIOH
#define LED_USB_Pin GPIO_PIN_8
#define LED_USB_GPIO_Port GPIOB
#define LED_PWR_Pin GPIO_PIN_9
#define LED_PWR_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
