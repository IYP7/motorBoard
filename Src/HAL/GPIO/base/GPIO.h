


#ifndef HAL_GPIO_BASE_H_
#define HAL_GPIO_BASE_H_

#include "common.h"
#include "GPIO_map.h"


#define GPIO_AF_NONE		0xFF


typedef enum
{
	GPIO_LOW,
	GPIO_HIGH,
	GPIO_TOGGLE,
} eGPIOValue;

typedef struct
{
	GPIO_TypeDef*	  	port;
	uint16_t 			pin;
	uint32_t 			mode;
	uint8_t				speed;
	uint8_t    			pupd;
	uint8_t				alternate;
	eGPIOValue			initialValue;
} sGPIOInstanceMap;


void GPIOInit( void );
void GPIOWrite(eGPIO port, eGPIOValue value);
eGPIOValue GPIORead(eGPIO port);


#endif /* HAL_GPIO_BASE_H_ */

