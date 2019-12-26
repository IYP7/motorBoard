/*
 * TimerPrivate.h
 *
 *  Created on: 8 dic. 2019
 *      Author: Ivan
 */

#ifndef HAL_TIMER_BASE_TIMERPRIVATE_H_
#define HAL_TIMER_BASE_TIMERPRIVATE_H_

/*********************************************
 * 			Pwm callback functions			 *
 *********************************************/
void initTimerPwm(TIM_HandleTypeDef *handler);
void startTimerPwm(TIM_HandleTypeDef *handler);
void enableTimerClockPwm(TIM_HandleTypeDef *handler);

void getTimerClock (uint32_t *timerClock);
void calculatePrescAndPeriod(uint32_t clockFreq,  uint32_t period, uint32_t *prescaler, uint32_t *arr);

#endif /* HAL_TIMER_BASE_TIMERPRIVATE_H_ */
