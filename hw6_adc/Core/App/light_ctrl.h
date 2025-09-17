/*
 * light_ctrl.h
 *
 *  Created on: Sep 17, 2025
 *      Author: master
 */

#ifndef LIGHT_CTRL_H_
#define LIGHT_CTRL_H_

#include "stm32g4xx_hal.h"
//

typedef struct {
        GPIO_TypeDef *port;
        uint16_t pin;
        uint8_t state;
    } led_t;
typedef struct {
    ADC_HandleTypeDef *hadc;
    uint32_t AWDy;
    uint16_t value;
    uint16_t high_threshold;
    uint16_t low_threshold;
}sensor_t;
typedef struct{
    sensor_t sensor;
    led_t led;
    uint16_t threshold;
    uint16_t hyster;
}light_t;


void light_toggle(light_t *light, uint16_t new_value);
void light_update_threshold(light_t *light, uint16_t new_threshold);
void light_send_state(light_t *light);

#endif /* LIGHT_CTRL_H_ */
