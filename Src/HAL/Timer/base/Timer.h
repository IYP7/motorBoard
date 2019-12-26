/*
 * Timer.h
 *
 *  Created on: 3 dic. 2019
 *      Author: Ivan
 */

#ifndef HAL_TIMER_BASE_TIMER_H_
#define HAL_TIMER_BASE_TIMER_H_

#include "common.h"
#include "Timer_map.h"
#include "TimerPrivate.h"

#define MON_TIMER_US		1000000
#define TIMER_PWM_INPUT_DUTY_RESOLUTION 100
#define TIMER_PWM_OUTPUT_DUTY_RESOLUTION 10000

TIM_HandleTypeDef timerHandler[NUM_OF_TIMERS];
extern sTimerMap timerMap[NUM_OF_TIMERS];

void TimerInit(eTimer instance);
void TimerStart(eTimer instance);

#endif /* HAL_TIMER_BASE_TIMER_H_ */
