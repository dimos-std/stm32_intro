/*
 * blink.c
 *
 *  Created on: Aug 11, 2025
 *      Author: master
 */

#include "led.h"

void init_led(GPIO_TypeDef* port, uint16_t pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	if(!pin)
		Error_Handler();
	if(port == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(port == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(port == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else Error_Handler();

	HAL_GPIO_WritePin(LED_ON_BOARD_GPIO_Port, LED_ON_BOARD_Pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(port, &GPIO_InitStruct);

}
