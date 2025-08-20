/*
 * button.c
 *
 *  Created on: Aug 15, 2025
 *      Author: master
 */
#include "button.h"

volatile uint8_t btn_flag = 0;

void init_btn(GPIO_TypeDef* port, uint16_t pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	IRQn_Type IRQn = 0;

	if(!pin)
		Error_Handler();

	if(port == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(port == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(port == GPIOC)
		__HAL_RCC_GPIOC_CLK_ENABLE();
	else Error_Handler();

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;

	HAL_GPIO_Init(port, &GPIO_InitStruct);

	switch(pin)
	{
		case GPIO_PIN_0:
			IRQn = EXTI0_IRQn;
			break;
		case GPIO_PIN_1:
			IRQn = EXTI1_IRQn;
			break;
		case GPIO_PIN_2:
			IRQn = EXTI2_IRQn;
			break;
		case GPIO_PIN_3:
			IRQn = EXTI3_IRQn;
			break;
		case GPIO_PIN_4:
			IRQn = EXTI4_IRQn;
			break;
		case GPIO_PIN_5:
		case GPIO_PIN_6:
		case GPIO_PIN_7:
		case GPIO_PIN_8:
		case GPIO_PIN_9:
			IRQn = EXTI9_5_IRQn;
			break;
		case GPIO_PIN_10:
		case GPIO_PIN_11:
		case GPIO_PIN_12:
		case GPIO_PIN_13:
		case GPIO_PIN_14:
		case GPIO_PIN_15:
			IRQn = EXTI15_10_IRQn;
			break;
	}

	HAL_NVIC_SetPriority(IRQn, 8, 0);
	HAL_NVIC_EnableIRQ(IRQn);

}
void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
	if(BTN_ON_BOARD_Pin == pin)
		btn_flag = 1;
}


