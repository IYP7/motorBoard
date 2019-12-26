/*
 * uart.c
 *
 *  Created on: 20 oct. 2017
 *      Author: Iván
 */


#include "uart.h"
#include "common.h"


extern const sUartInstanceMap UARTInstanceMap[NUM_OF_UART];
UART_HandleTypeDef uartHandlers[NUM_OF_UART];
sUartContext uartCircularBuffers[NUM_OF_UART];
uint8_t RxByte;
static eUart uartPortIRQ;


void uartInterruptHandler(eUart uartPort)
{
    UART_HandleTypeDef* uart_instance; //HAL Uart
    //en caso de usar las callbacks, revisar el código de MTG
    uart_instance = &uartHandlers[uartPort];
    uartPortIRQ = uartPort;
    HAL_UART_IRQHandler(uart_instance);
}


void uartInit(void)
{
    UART_HandleTypeDef* uart_handler;
    const sUartInstanceMap* uart_instance;
    uint8_t i;


	#ifdef IS_UART1
        __HAL_RCC_USART1_CLK_ENABLE();
	#endif
	#ifdef IS_UART2
        __HAL_RCC_USART2_CLK_ENABLE();
	#endif

    for(i=0; i<NUM_OF_UART; i++) {
        uart_handler = &uartHandlers[i];
        uart_instance = &UARTInstanceMap[i];
        uart_handler->Instance        = uart_instance->port;
        uart_handler->Init.BaudRate   = uart_instance->baudRate;
        uart_handler->Init.WordLength = uart_instance->dataSize;
        uart_handler->Init.StopBits   = uart_instance->stopBits;
        uart_handler->Init.Parity     = uart_instance->parity;
        uart_handler->Init.HwFlowCtl  = UART_HWCONTROL_NONE;
        uart_handler->Init.Mode       = UART_MODE_TX_RX;
        //se pueden añadir los parámetros Init.CLKPolarity, Init.CLKPhase e Init.CLKLastBit

        __HAL_UART_ENABLE_IT(uart_handler, UART_IT_RXNE);

		CreateFIFO(&uartCircularBuffers[i].rxBuffer,
                UARTInstanceMap[i].rxBufferPtr,
                UARTInstanceMap[i].rxBufferSize);

		CreateFIFO(&uartCircularBuffers[i].txBuffer,
                UARTInstanceMap[i].txBufferPtr,
                UARTInstanceMap[i].txBufferSize);
    }
}

HAL_StatusTypeDef uartStop(void)
{
    uint8_t i;
    UART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];

        if(uart_handler->Instance == USART1){
            __HAL_RCC_USART1_FORCE_RESET();
            __HAL_RCC_USART1_RELEASE_RESET();
        }
        else if (uart_handler->Instance == USART2){
            __HAL_RCC_USART2_FORCE_RESET();
            __HAL_RCC_USART2_RELEASE_RESET();
        }
        if(HAL_UART_DeInit(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
    }

    return HAL_OK;
}

HAL_StatusTypeDef uartStart(void)
{
    uint8_t i;
    UART_HandleTypeDef* uart_handler;

    for(i=0; i<NUM_OF_UART; i++){
        uart_handler = &uartHandlers[i];
        if(HAL_UART_DeInit(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        if(HAL_UART_Init(uart_handler) != HAL_OK)
        {
            return HAL_ERROR;
        }
        HAL_UART_Receive_IT(uart_handler, &RxByte, 1 );
    }
    return HAL_OK;
}

HAL_StatusTypeDef uartRead(eUart uartPort, char* buffer, uint8_t lastChar)
{
    uint32_t i=0;
    uint8_t byte=0;
    uint32_t bufferSize = 30;
    uint8_t result;

    if(GetFIFOPendingBytes(&uartCircularBuffers[uartPort].rxBuffer) < 5 ){
		initString(buffer,bufferSize);
		result = HAL_ERROR;
    }else{
        while((byte != lastChar) && (i<bufferSize) )
        {
            byte = GetFIFOByte(&uartCircularBuffers[uartPort].rxBuffer);
            buffer[i] = byte;
            i++;
        }
        ResetFIFO(&uartCircularBuffers[uartPort].rxBuffer);
        result = HAL_OK;
    }

    return result;
}

HAL_StatusTypeDef uartWrite(eUart uartPort, char* buffer)
{
    HAL_StatusTypeDef error;
    error = HAL_UART_Transmit_IT(&uartHandlers[uartPort], (uint8_t*)buffer, strlen(buffer));
    while (HAL_UART_GetState(&uartHandlers[uartPort]) == HAL_UART_STATE_BUSY_TX ||
    HAL_UART_GetState(&uartHandlers[uartPort]) == HAL_UART_STATE_BUSY_TX_RX);
    return error;

}

HAL_StatusTypeDef uartDriverWritePolling(eUart uartPort, char* buffer)
{
    return HAL_UART_Transmit(&uartHandlers[uartPort], (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart_handler)
{

	if(GetFIFOFreeBytes(&uartCircularBuffers[uartPortIRQ].rxBuffer) > 0){
		AddFIFOByte(&uartCircularBuffers[uartPortIRQ].rxBuffer, RxByte);
	}

	 HAL_UART_Receive_IT(uart_handler, &RxByte, 1 );

}




