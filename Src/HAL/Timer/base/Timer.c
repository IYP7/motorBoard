/*
 * Timer.c
 *
 *  Created on: 3 dic. 2019
 *      Author: Ivan
 */

#include "Timer.h"


void TimerInit(eTimer instance)
{
	sTimerMap *map = &timerMap[instance];
	TIM_HandleTypeDef *handler = &timerHandler[instance];
	uint32_t timerClock;

	getTimerClock(&timerClock);

	map->enableClock(handler);

	handler->Instance = map->instance;
	handler->Init.CounterMode = map->counterMode;
	handler->Init.ClockDivision = map->clockDivision;
	handler->Init.RepetitionCounter = map->repetitionCounter;
	handler->Init.AutoReloadPreload = map->autoReloadPreload;

	if (map->calcPrescAndPeriod)
	{
		map->calcPrescAndPeriod(timerClock, map->period, &handler->Init.Prescaler, &handler->Init.Period);
	}
	else
	{
		handler->Init.Period = map->period;
		handler->Init.Prescaler = map->prescaler;
	}

	map->enableTimerExternalClock(handler);

	map->initTimerByType(handler);
}

void TimerStart(eTimer instance)
{
	sTimerMap *map = &timerMap[instance];
	TIM_HandleTypeDef *handler = &timerHandler[instance];

	map->startTimer(handler);
}

void TimerSetDuty(eTimer instance, uint16_t duty)
{
	uint32_t pulse;
	sTimerMap *map = &timerMap[instance];
	TIM_HandleTypeDef *handler = &timerHandler[instance];

	if (map->typeMap.reset)
	{
		__HAL_TIM_SET_COUNTER(handler,0);
	}

	//map->typeMap.duty = duty;

	/********************************************/
	/* Pulse calculation:  						*/
	/*				(Period + 1) * Duty    		*/
	/*		Pulse =	 ------------------ 		*/
	/* 				     Resolution       		*/
	/*__________________________________________*/

	pulse = ((handler->Instance->ARR + 1) * duty) / map->typeMap.resolution;

	switch (map->typeMap.channel)
	{
	case TIM_CHANNEL_1:
		handler->Instance->CCR1 = pulse;
		break;
	case TIM_CHANNEL_2:
		handler->Instance->CCR2 = pulse;
		break;
	case TIM_CHANNEL_3:
		handler->Instance->CCR3 = pulse;
		break;
	case TIM_CHANNEL_4:
		handler->Instance->CCR4 = pulse;
		break;
	default:
		break;
	}
}

