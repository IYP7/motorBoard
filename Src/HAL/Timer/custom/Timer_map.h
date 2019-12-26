/*
 * Timer_map.h
 *
 *  Created on: 3 dic. 2019
 *      Author: Ivan
 */

#ifndef HAL_TIMER_CUSTOM_TIMER_MAP_H_
#define HAL_TIMER_CUSTOM_TIMER_MAP_H_

typedef enum
{
	TIMER_PWM_1,

	NUM_OF_TIMERS,
}eTimer;

typedef enum eTimerPwmComplement{
	TIMER_PWM_COMPLEMENT_NOT_USED,
	TIMER_PWM_COMPLEMENT_DIRECTED,
	TIMER_PWM_COMPLEMENT_INVERTED,
} tTimerPwmComplement;

typedef struct
{
	TIM_TypeDef* instance;
	uint32_t prescaler;
	uint32_t counterMode;
	uint32_t period;
	uint32_t clockDivision;
	uint32_t repetitionCounter;
	uint32_t autoReloadPreload;
	void (*initTimerByType)(TIM_HandleTypeDef*);
	void (*startTimer)(TIM_HandleTypeDef*);
	void (*enableClock)(TIM_HandleTypeDef*);
	void (*enableTimerExternalClock)(TIM_HandleTypeDef*);
	void (*calcPrescAndPeriod)(uint32_t clockFreq, uint32_t period, uint32_t *prescaler, uint32_t *arr);
}sTimerMap;

typedef struct {
	uint32_t	channel;
	uint16_t	duty;
	uint32_t	resolution;
	tBool		reset;
	uint32_t 	polarity;
	tBool		preload;
	tTimerPwmComplement complement;

} sTimerPWMOutMap;

#endif /* HAL_TIMER_CUSTOM_TIMER_MAP_H_ */
