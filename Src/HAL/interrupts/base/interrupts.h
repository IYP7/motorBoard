/*
 * interrupts.h
 *
 *  Created on: 29 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_INTERRUPTS_BASE_INTERRUPTS_H_
#define HAL_INTERRUPTS_BASE_INTERRUPTS_H_

#include "common.h"
#include "interrupts_map.h"

#define IRQ_PRIORITY_0      	0x00
#define IRQ_PRIORITY_1      	0x01
#define IRQ_PRIORITY_2      	0x02

#define IRQ_SUBPRIORITY_0       0x00


typedef enum
{
	IRQ_DISABLE=0,
	IRQ_ENABLE,

} eIRQState;

typedef struct
{
	IRQn_Type  IRQn;
	uint8_t   PreemptPriority;
	uint8_t   SubPriority;
	eIRQState  State;

}sInterruptsInstanceMap;

void interruptsInit( void );
void interruptsStart( void );
void interruptsStop( void );


#endif /* HAL_INTERRUPTS_BASE_INTERRUPTS_H_ */
