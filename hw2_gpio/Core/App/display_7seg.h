/*
 * display_7seg.h
 *
 *  Created on: Aug 15, 2025
 *      Author: master
 */

#ifndef DISPLAY_7SEG_H_
#define DISPLAY_7SEG_H_

#include "main.h"

#define NUM_DIGITS 3

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
} pin_t;

typedef struct
{
	pin_t digit[NUM_DIGITS];
	pin_t segment[8];
	uint8_t data[NUM_DIGITS]; // format static const uint8_t  digit_code_ca[]
} display_7seg_t;

void display_7seg_init(display_7seg_t*);
void display_7seg_update(display_7seg_t *, uint32_t);
void display_7seg_show(display_7seg_t *);

#endif /* DISPLAY_7SEG_H_ */
