/*
 * uart_map.h
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_UART_CUSTOM_UART_MAP_H_
#define HAL_UART_CUSTOM_UART_MAP_H_


#include "common.h"
#include "config.h"


#ifdef IS_UART1
#define USART1_TX_BUFFER          256
#endif
#ifdef IS_UART2
#define USART2_TX_BUFFER          1028
#endif


#ifdef IS_UART1
#define USART1_RX_BUFFER          100
#endif
#ifdef IS_UART2
#define USART2_RX_BUFFER          100
#endif


typedef enum
{
#ifdef IS_UART1
    //UART_1,
#endif
#ifdef IS_UART2
    //UART_2,
#endif
    NUM_OF_UART
} eUart;



#endif /* HAL_UART_CUSTOM_UART_MAP_H_ */
