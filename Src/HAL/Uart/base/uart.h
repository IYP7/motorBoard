/*
 * uart.h
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */

#ifndef HAL_UART_BASE_UART_H_
#define HAL_UART_BASE_UART_H_

#include "common.h"
#include "UART_map.h"
#include "GPIO.h"
#include "../../../Tools/CircularBuffer/CircularBuffer.h"



#define MAX_UART_BUFFER_SIZE    256


/**
 * Generic callback for a defined UART. It expects an uint8_t parameter
 * and returns eError.
 */



typedef HAL_StatusTypeDef (*uartRxCallback)(uint8_t);
typedef HAL_StatusTypeDef (*uartTxCallback)(uint8_t);

typedef struct
{
	CircularBuffer rxBuffer;
	CircularBuffer txBuffer;
} sUartContext;

typedef struct
{
    USART_TypeDef*  port;           /**< @brief ST HAL UART port structure */
    uint32_t        baudRate;       /**< @brief speed of the UART port */
    uint8_t         dataSize;       /**< @brief Word Length of the sent data */
    uint8_t         parity;         /**< @brief Activate or deactivate Parity */
    uint8_t         stopBits;       /**< @brief Activate or deactivate stop bits*/

    //Read/Write Buffers
    uint16_t        txBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        txBufferPtr;    /**< @brief Pointer of the tx buffer */
    uint16_t        rxBufferSize;   /**< @brief Size of the tx buffer */
    uint8_t*        rxBufferPtr;    /**< @brief Pointer of the tx buffer */

    //Callbacks
    uartRxCallback  rxCallback;     /**< @brief Callback for RX interruption */
    uartTxCallback  txCallback;     /**< @brief Callback for TX interruption */
} sUartInstanceMap;


void uartInterruptHandler(eUart uartPort);
void uartInit(void);
HAL_StatusTypeDef uartStop(void);
HAL_StatusTypeDef uartStart(void);
HAL_StatusTypeDef uartWrite(eUart  uartPort, char* buffer);
HAL_StatusTypeDef uartDriverWritePolling(eUart uartPort, char* buffer);
HAL_StatusTypeDef uartRead(eUart  uartPort, char* buffer, uint8_t lastChar);

#endif // HAL_UART_BASE_UART_H_
