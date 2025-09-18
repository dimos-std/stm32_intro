/*
 * light_ctrl.c
 *
 *  Created on: Sep 17, 2025
 *      Author: master
 */

#include "../App/light_ctrl.h"

#include "usbd_cdc_if.h"
#include "stm32g4xx_hal_adc.h"

void light_toggle(light_t *light, uint16_t new_value)
{
  if(light == NULL)
    return;

  light->sensor.value = new_value;

  if(!(light->led.state) && ((light->sensor.value) <= (light->sensor.low_threshold)))
  {
    HAL_GPIO_WritePin(light -> led.port, light -> led.pin, GPIO_PIN_SET);
    light ->led.state = 0xFF;
  }
  else if(light->led.state && (light->sensor.value >= light->sensor.high_threshold))
  {
    HAL_GPIO_WritePin(light -> led.port, light -> led.pin, GPIO_PIN_RESET);
    light -> led.state = 0;
  }
}

void light_update_threshold(light_t *light, uint16_t new_threshold)
{

  if(light == NULL)
      return;
  if(light->threshold == new_threshold)
    return;

  uint32_t tmp_awd_high_threshold_shifted = 0;
  uint32_t tmp_awd_low_threshold_shifted = 0;
  uint32_t ADC_MAX_VALUE =  0x0FFFU >> (light->sensor.hadc->Init.Resolution >> 2);

  light->threshold = new_threshold;

  if(new_threshold + light->hyster / 2 >= ADC_MAX_VALUE)
  {
    light->sensor.high_threshold = ADC_MAX_VALUE;
    light->sensor.low_threshold = ADC_MAX_VALUE - light->hyster;
  } else if (new_threshold - light->hyster / 2 >= ADC_MAX_VALUE)
  {
    light->sensor.high_threshold = light->hyster;
    light->sensor.low_threshold = 0;
  }
  else
  {
    light->sensor.high_threshold = light->threshold + light->hyster / 2;
    light->sensor.low_threshold = light->threshold - light->hyster / 2;
  }


  if (light->sensor.AWDx == ADC_ANALOGWATCHDOG_1)
  {
    tmp_awd_high_threshold_shifted = ADC_AWD1THRESHOLD_SHIFT_RESOLUTION(light->sensor.hadc, light->sensor.high_threshold);
    tmp_awd_low_threshold_shifted  = ADC_AWD1THRESHOLD_SHIFT_RESOLUTION(light->sensor.hadc, light->sensor.low_threshold);
  }
  else
  {
    tmp_awd_high_threshold_shifted = ADC_AWD23THRESHOLD_SHIFT_RESOLUTION(light->sensor.hadc, light->sensor.high_threshold);
    tmp_awd_low_threshold_shifted  = ADC_AWD23THRESHOLD_SHIFT_RESOLUTION(light->sensor.hadc, light->sensor.low_threshold);
  }
  LL_ADC_ConfigAnalogWDThresholds(light->sensor.hadc->Instance, light->sensor.AWDx, tmp_awd_high_threshold_shifted,
                                  tmp_awd_low_threshold_shifted);
}

void light_send_state(light_t *light)
{
  uint32_t length = 0;
  uint8_t str_out_buf[64] = {0};
  length = sprintf((char*)str_out_buf, "%5d %5d %5d %5d\n", light->sensor.value,
      light->sensor.high_threshold, light->sensor.low_threshold, light->led.state);
  CDC_Transmit_FS(str_out_buf, length);
}

