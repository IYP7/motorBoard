/*
 * TimerPrivate.c
 *
 *  Created on: 8 dic. 2019
 *      Author: Ivan
 */

#include "Timer.h"

void initTimerPwm(TIM_HandleTypeDef *handler)
{
	HAL_TIM_PWM_Init(handler);
}

void startTimerPwm(TIM_HandleTypeDef *handler)
{
	HAL_TIM_PWM_Start(handler, TIM_CHANNEL_1);
}

void enableTimerClockPwm(TIM_HandleTypeDef *handler)
{
	__HAL_RCC_TIM2_CLK_ENABLE();
}

/*************************************************************************//**
 * @brief  Get timer clock
 *
 * @param	instance.
 *
 * @return  None.
 *
 ****************************************************************************/
void getTimerClock (uint32_t *timerClock)
{
	uint32_t HCLK_Prescaler = RCC->CFGR & RCC_CFGR_HPRE;
	uint32_t APB1_Prescaler = RCC->CFGR & RCC_CFGR_PPRE1;

	switch(HCLK_Prescaler)
	{
		case RCC_CFGR_HPRE_DIV1:
			*timerClock = SystemCoreClock;
			break;
		case RCC_CFGR_HPRE_DIV2:
			*timerClock = SystemCoreClock/2;
			break;
		case RCC_CFGR_HPRE_DIV4:
			*timerClock = SystemCoreClock/4;
			break;
		case RCC_CFGR_HPRE_DIV8:
			*timerClock = SystemCoreClock/8;
			break;
		case RCC_CFGR_HPRE_DIV16:
			*timerClock = SystemCoreClock/16;
			break;
		case RCC_CFGR_HPRE_DIV64:
			*timerClock = SystemCoreClock/64;
			break;
		case RCC_CFGR_HPRE_DIV128:
			*timerClock = SystemCoreClock/128;
			break;
		case RCC_CFGR_HPRE_DIV256:
			*timerClock = SystemCoreClock/256;
			break;
		case RCC_CFGR_HPRE_DIV512:
			*timerClock = SystemCoreClock/512;
			break;
		default:
			break;
	}

	switch(APB1_Prescaler)
	{
		case RCC_CFGR_PPRE1_DIV4:
			*timerClock = *timerClock/2;
			break;
		case RCC_CFGR_PPRE1_DIV8:
			*timerClock = *timerClock/4;
			break;
		case RCC_CFGR_PPRE1_DIV16:
			*timerClock = *timerClock/8;
			break;
		default:
			break;
	}

}

/*************************************************************************//**
 * @brief  Calculates the ARR and prescaler for a period determined
 *  		 ______________________________________________
 * 	 	 	*            ( ClockFreq * PERIOD )        	*
 *	 	 	* 	ARR =   ---------------------------   -  1	*
 *      	*   	   	   	 (Prescaler + 1)           		*
 *			*_______________________________________________*

 * @return  int32_t calculated value.
 ****************************************************************************/
void calculatePrescAndPeriod(uint32_t clockFreq,  uint32_t period, uint32_t *prescaler, uint32_t *arr)
{
	uint32_t calcRes = 0;

	if (period != 0)
	{
		/* MON_TIMER_US is used to convert us to sec */
		calcRes = (clockFreq / MON_TIMER_US) * period;

		/* Period is higher than FFFF -> PSC it's different than 0, then we need to calculate the prescaler*/
		if ( calcRes > 0xFFFF )
		{
			*prescaler = calcRes / 0xFFFF;
		}

		*arr = (calcRes / (*prescaler + 1)) - 1;
	}

}
