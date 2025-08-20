/*
 * display_7seg.c
 *
 *  Created on: Aug 15, 2025
 *      Author: master
 */
#include "display_7seg.h"



static const uint8_t  digit_code_ca[] = {
		0b11000000,
		0b11111001,
		0b10100100,
		0b10110000,
		0b10011001,
		0b10010010,
		0b10000010,
		0b11111000,
		0b10000000,
		0b10010000
		};

static void init_pin(GPIO_TypeDef* port, uint16_t pin)
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
	else
		Error_Handler();

	HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(port, &GPIO_InitStruct);
}



void display_7seg_init(display_7seg_t *display)
{
	for(uint8_t i = 0; i < NUM_DIGITS; i++)
		init_pin(display->digit[i].port, display->digit[i].pin);
	for(uint8_t i = 0; i < 8; i++)
		init_pin(display->segment[i].port, display->segment[i].pin);
	display_7seg_update(display, 0);
}
void display_7seg_update(display_7seg_t *display, uint32_t number)
{
	for(uint8_t i = 0; i < NUM_DIGITS; i++)
	{
		display -> data[i] = digit_code_ca[number % 10];
		number /=10;
	}
}

void display_7seg_show(display_7seg_t *display)
{
	static uint8_t cur_digit = 0;

	HAL_GPIO_WritePin(display->digit[cur_digit].port, display->digit[cur_digit].pin, GPIO_PIN_SET);

	cur_digit = (cur_digit + 1) % NUM_DIGITS;

	for(uint8_t i = 0; i < 8; i++)
	{
		GPIO_PinState  pinstate = ((display->data[cur_digit]) >> i) & 0x0001 ? GPIO_PIN_SET : GPIO_PIN_RESET;
		HAL_GPIO_WritePin(display->segment[i].port, display->segment[i].pin, pinstate);
	}
	HAL_GPIO_WritePin(display->digit[cur_digit].port, display->digit[cur_digit].pin, GPIO_PIN_RESET);

}

