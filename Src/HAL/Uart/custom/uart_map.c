/*
 * uart_map.c
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */


#include "common.h"
#include "uart.h"
#include "uart_map.h"

#ifdef IS_UART1
    uint8_t usart1TxBuffer[USART1_TX_BUFFER];
    uint8_t usart1RxBuffer[USART1_RX_BUFFER];
#endif
#ifdef IS_UART2
    uint8_t usart2TxBuffer[USART2_TX_BUFFER];
    uint8_t usart2RxBuffer[USART2_RX_BUFFER];
#endif

const sUartInstanceMap UARTInstanceMap[NUM_OF_UART] =  {

#ifdef IS_UART1
    {
        USART1,
        115200,
        UART_WORDLENGTH_8B,
        UART_STOPBITS_1,
        UART_PARITY_NONE,
        USART1_TX_BUFFER,
        usart1TxBuffer,
        USART1_RX_BUFFER,
        usart1RxBuffer,
        NULL, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif
#ifdef IS_UART2
    {
        USART2,
        115200,
        UART_WORDLENGTH_8B,
        UART_STOPBITS_1,
        UART_PARITY_NONE,
        USART2_TX_BUFFER,
        usart2TxBuffer,
        USART2_RX_BUFFER,
        usart2RxBuffer,
        NULL, //modificable, mirar ejemplo MTG
        NULL,
    },
#endif

};
