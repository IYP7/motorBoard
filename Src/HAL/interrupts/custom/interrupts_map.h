/*
 * interrupts_map.h
 *
 *  Created on: 29 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_H_
#define HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_H_

#include "common.h"

typedef enum
{
	IRQ_SYSTICK = 0,
	IRQ_USART1,
	IRQ_USART2,
//	IRQ_B1,
	NUM_OF_IRQS

} eInterrupts;


void HAL_UART1_IRQ(void);
void HAL_UART2_IRQ(void);
//void EXTI0_1_IRQHandler(void);


#endif /* HAL_INTERRUPTS_CUSTOM_INTERRUPTS_MAP_H_ */
