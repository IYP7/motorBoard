/*
 * CircularBuffer.h
 *
 *  Created on: 26 oct. 2017
 *      Author: Iván
 */

#ifndef TOOLS_CIRCULARBUFFER_CIRCULARBUFFER_H_
#define TOOLS_CIRCULARBUFFER_CIRCULARBUFFER_H_

#include "common.h"

typedef struct
{
    uint16_t rxPtr;
    uint16_t txPtr;
    uint8_t *bufferPtr;
    uint16_t bufferLen;
    uint16_t numOfBytes;
}CircularBuffer;


void CreateFIFO(CircularBuffer* buffer, uint8_t* bufferPtr, uint16_t size);
void ResetFIFO(CircularBuffer* buffer);
void ClearFIFO(CircularBuffer* buffer);
void AddFIFOByte(CircularBuffer* buffer, uint8_t data);
uint8_t GetFIFOByte(CircularBuffer* buffer);
uint16_t GetFIFOPendingBytes(CircularBuffer* buffer);
uint16_t GetFIFOFreeBytes(CircularBuffer* buffer);


#endif /* TOOLS_CIRCULARBUFFER_CIRCULARBUFFER_H_ */
