/*
 * interrupts.c
 *
 *  Created on: 29 oct. 2017
 *      Author: Iván
 */

#include "common.h"
#include "interrupts.h"
#include "interrupts_map.h"

extern sInterruptsInstanceMap interruptsInstanceMap[NUM_OF_IRQS];

void interruptsInit( void )
{
	uint8_t i;

	for(i = 0; i < NUM_OF_IRQS; i++)
	{
		if (SVCall_IRQn <= (interruptsInstanceMap[i].IRQn))
		{
			HAL_NVIC_SetPriority(interruptsInstanceMap[i].IRQn, (uint32_t)interruptsInstanceMap[i].PreemptPriority, (uint32_t)interruptsInstanceMap[i].SubPriority);
		}
	}

}

void interruptsStart( void )
{
	uint8_t i;

	for(i = 0; i < NUM_OF_IRQS; i++)
	{
		if (interruptsInstanceMap[i].State == IRQ_ENABLE)
		{
			if (IS_NVIC_DEVICE_IRQ(interruptsInstanceMap[i].IRQn))
			{
				HAL_NVIC_EnableIRQ(interruptsInstanceMap[i].IRQn);
			}

		}
	}

}

void interruptsStop( void )
{
	uint8_t i;

	for(i = 0; i < NUM_OF_IRQS; i++)
	{
		if (IS_NVIC_DEVICE_IRQ(interruptsInstanceMap[i].IRQn))
		{
			HAL_NVIC_DisableIRQ(interruptsInstanceMap[i].IRQn);
		}
	}

}
