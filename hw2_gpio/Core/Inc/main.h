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
#include "stm32g4xx_hal.h"

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
void MX_GPIO_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_ON_BOARD_Pin GPIO_PIN_13
#define BTN_ON_BOARD_GPIO_Port GPIOC
#define BTN_ON_BOARD_EXTI_IRQn EXTI15_10_IRQn
#define DIGIT1_Pin GPIO_PIN_1
#define DIGIT1_GPIO_Port GPIOA
#define DIGIT2_Pin GPIO_PIN_2
#define DIGIT2_GPIO_Port GPIOA
#define DIGIT3_Pin GPIO_PIN_3
#define DIGIT3_GPIO_Port GPIOA
#define SEG_DP_Pin GPIO_PIN_4
#define SEG_DP_GPIO_Port GPIOA
#define SEG_G_Pin GPIO_PIN_5
#define SEG_G_GPIO_Port GPIOA
#define SEG_F_Pin GPIO_PIN_6
#define SEG_F_GPIO_Port GPIOA
#define SEG_E_Pin GPIO_PIN_7
#define SEG_E_GPIO_Port GPIOA
#define SEG_D_Pin GPIO_PIN_4
#define SEG_D_GPIO_Port GPIOC
#define SEG_C_Pin GPIO_PIN_0
#define SEG_C_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_1
#define SEG_B_GPIO_Port GPIOB
#define SEG_A_Pin GPIO_PIN_2
#define SEG_A_GPIO_Port GPIOB
#define LED_ON_BOARD_Pin GPIO_PIN_6
#define LED_ON_BOARD_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
