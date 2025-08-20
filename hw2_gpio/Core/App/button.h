/*
 * button.h
 *
 *  Created on: Aug 15, 2025
 *      Author: master
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"

void init_btn(GPIO_TypeDef*, uint16_t);
void HAL_GPIO_EXTI_Callback(uint16_t);

#endif /* BUTTON_H_ */
