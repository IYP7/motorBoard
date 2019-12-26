/*
 * Timer_map.c
 *
 *  Created on: 3 dic. 2019
 *      Author: Ivan
 */

#include "Timer.h"

sTimerMap timerMap[NUM_OF_TIMERS] =
{
	{
		.instance = TIM1,
		.prescaler = 0,
		.counterMode = TIM_COUNTERMODE_UP,
		.period = 0,
		.clockDivision = TIM_CLOCKDIVISION_DIV1,
		.repetitionCounter = 0,
		.autoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE,
		.typemap =
		&initTimerPwm,
		&startTimerPwm,
		&enableTimerClockPwm,
		NULL,
		&calculatePrescAndPeriod,
	},
};

sTimerPWMOutMap TimerPwmOutMap[] =  {

		/*TIMER_PWM_1	*/	{	TIM_CHANNEL_3, 	0,    TIMER_PWM_OUTPUT_DUTY_RESOLUTION	, 	FALSE, 	TIM_OCPOLARITY_HIGH, TRUE, TIMER_PWM_COMPLEMENT_DIRECTED },

};

