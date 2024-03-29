/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_FAN_Pin GPIO_PIN_0
#define ADC_FAN_GPIO_Port GPIOA
#define ADC_NTC_Pin GPIO_PIN_1
#define ADC_NTC_GPIO_Port GPIOA
#define VOICE_TX_Pin GPIO_PIN_2
#define VOICE_TX_GPIO_Port GPIOA
#define VOICE_RX_Pin GPIO_PIN_3
#define VOICE_RX_GPIO_Port GPIOA
#define SPI_NSS_Pin GPIO_PIN_4
#define SPI_NSS_GPIO_Port GPIOA

#define TFT_BACKLIGHT_Pin 				GPIO_PIN_0
#define TFT_BACKLIGHT_GPIO_Port 		GPIOB


#define TFT_DCX_Pin GPIO_PIN_1
#define TFT_DCX_GPIO_Port GPIOB

#define TFT_RESET_Pin 				GPIO_PIN_2
#define TFT_RESET_GPIO_Port 		GPIOB

#define LED_WIFI_Pin GPIO_PIN_12
#define LED_WIFI_GPIO_Port GPIOB
#define LED_KILL_Pin GPIO_PIN_13
#define LED_KILL_GPIO_Port GPIOB
#define LED_KEY_TIM_Pin GPIO_PIN_14
#define LED_KEY_TIM_GPIO_Port GPIOB
#define LED_POWER_Pin GPIO_PIN_8
#define LED_POWER_GPIO_Port GPIOA
#define KEY_POWER_Pin GPIO_PIN_9
#define KEY_POWER_GPIO_Port GPIOA
#define KEY_POWER_EXTI_IRQn EXTI9_5_IRQn
#define KEY_MODE_Pin GPIO_PIN_10
#define KEY_MODE_GPIO_Port GPIOA
#define KEY_MODE_EXTI_IRQn EXTI15_10_IRQn

///
#define KEY_ADD_Pin GPIO_PIN_11

#define KEY_ADD_GPIO_Port GPIOA
#define KEY_ADD_EXTI_IRQn EXTI15_10_IRQn
//
#define KEY_DEC_Pin GPIO_PIN_12
#define KEY_DEC_GPIO_Port GPIOA
#define KEY_DEC_EXTI_IRQn EXTI15_10_IRQn
//
#define LED_PTC_Pin GPIO_PIN_8
#define LED_PTC_GPIO_Port GPIOB
#define LED_RAT_Pin GPIO_PIN_9
#define LED_RAT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
