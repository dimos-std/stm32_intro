/*
 * blink.c
 *
 *  Created on: Aug 11, 2025
 *      Author: master
 */

#include "blink.h"


void blink_led_om_board()
{
	static uint32_t pin_state = GPIO_PIN_RESET;

	HAL_GPIO_WritePin(LED_ON_BOARD_GPIO_Port, LED_ON_BOARD_Pin, pin_state);
	HAL_Delay(2000);
	pin_state = !pin_state;
}
