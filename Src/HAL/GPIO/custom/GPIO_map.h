/*
 * GPIO_map.h
 *
 *  Created on: 15 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_GPIO_CUSTOM_GPIO_MAP_H_
#define HAL_GPIO_CUSTOM_GPIO_MAP_H_


#include "common.h"

typedef enum
{

	GPIO_USART1_TX,
	GPIO_USART1_RX,

	GPIO_USART2_TX,
	GPIO_USART2_RX,

	GPIO_TIM1_CH1,


    NUM_OF_GPIO
} eGPIO;

#endif /* HAL_GPIO_CUSTOM_GPIO_MAP_H_ */
