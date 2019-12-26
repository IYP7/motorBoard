/*
 * GPIO.c
 *
 *  Created on: 15 oct. 2017
 *      Author: Iván
 */

#include "common.h"
#include "GPIO.h"
#include "GPIO_map.h"

extern const sGPIOInstanceMap GPIOInstanceMap[NUM_OF_GPIO];


void InitGPIOClock(eGPIO port)
{
	/* Enable the GPIO Clock */
	if ( GPIOInstanceMap[port].port == GPIOA ){
		__GPIOA_CLK_ENABLE();
	}

	if( GPIOInstanceMap[port].port == GPIOB ){
		__GPIOB_CLK_ENABLE();
	}

	if( GPIOInstanceMap[port].port == GPIOC ){
		__GPIOC_CLK_ENABLE();
	}

	if( GPIOInstanceMap[port].port == GPIOD ){
		__GPIOD_CLK_ENABLE();
	}

	if( GPIOInstanceMap[port].port == GPIOF ){
		__GPIOF_CLK_ENABLE();
	}

}


void GPIOInit( void )
{
	uint8_t 			port;
	GPIO_InitTypeDef  	GPIO_InitStructure;

	for (port = 0; port < NUM_OF_GPIO; port++)
	{
		/* Enable GPIO clock of corresponding port */
		InitGPIOClock(port);

		/* Configure the GPIO parameters */
        GPIO_InitStructure.Pin =  	(uint32_t)GPIOInstanceMap[port].pin;
		GPIO_InitStructure.Mode = 	(uint32_t)GPIOInstanceMap[port].mode;
		GPIO_InitStructure.Speed = 	(uint32_t)GPIOInstanceMap[port].speed;
		GPIO_InitStructure.Pull = 	(uint32_t)GPIOInstanceMap[port].pupd;
		GPIO_InitStructure.Alternate = (uint32_t)GPIOInstanceMap[port].alternate;

		HAL_GPIO_Init(GPIOInstanceMap[port].port, &GPIO_InitStructure);

		/* Set GPIO initial value */

		GPIOWrite(port, GPIOInstanceMap[port].initialValue);

	}
}

void GPIOWrite(eGPIO port, eGPIOValue value)
{
		if ( value != GPIO_TOGGLE )
		{
			HAL_GPIO_WritePin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin, value);
		}
		else
		{
			HAL_GPIO_TogglePin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin);
			HAL_Delay(100);
		}
}

eGPIOValue GPIORead(eGPIO port)
{
	return HAL_GPIO_ReadPin(GPIOInstanceMap[port].port, GPIOInstanceMap[port].pin);
}

//void buttonInterruptHandler(uint16_t GPIO_Pin)
//{
//	HAL_GPIO_EXTI_IRQHandler(GPIO_Pin);
//}


