/*
 * CircularBuffer.c
 *
 *  Created on: 26 oct. 2017
 *      Author: Iván
 */

#include "CircularBuffer.h"

#include "common.h"
//#include "interrupts.h"


void CreateFIFO(CircularBuffer* buffer, uint8_t* bufferPtr, uint16_t size)
{
	buffer->bufferPtr = bufferPtr;
	buffer->bufferLen = size;
	buffer->rxPtr = 0;
	buffer->txPtr = 0;
    buffer->numOfBytes = 0;
}

void ResetFIFO(CircularBuffer* buffer)
{
	buffer->rxPtr = 0;
	buffer->txPtr = 0;
    buffer->numOfBytes = 0;
}

uint8_t GetFIFOByte(CircularBuffer* buffer)
{
    uint8_t result;
	//interruptsDisable();
    result = buffer->bufferPtr[buffer->rxPtr];
    buffer->numOfBytes--;
    buffer->rxPtr++;
    buffer->rxPtr %= buffer->bufferLen;
    //interruptsEnable();
    return result;
}

void AddFIFOByte(CircularBuffer* buffer, uint8_t data)
{
	//interruptsDisable();
    buffer->bufferPtr[buffer->txPtr]= data;
    buffer->numOfBytes++;
    buffer->txPtr++;
    buffer->txPtr %= buffer->bufferLen;
	//interruptsEnable();
}



uint16_t GetFIFOPendingBytes(CircularBuffer* buffer)
{
    return buffer->numOfBytes;
}

uint16_t GetFIFOFreeBytes(CircularBuffer* buffer)
{
    return (buffer->bufferLen)-(buffer->numOfBytes);
}

