/*
 * BridgeMode.h
 *
 *  Created on: 23 feb. 2018
 *      Author: Iván
 */

#ifndef MIDDLEWARE_BRIDGEMODE_H_
#define MIDDLEWARE_BRIDGEMODE_H_

tBool enterBridgeMode(char *RxBuffer, uint8_t Rxlength, char TxBuffer[], uint8_t TxLength);
uint8_t searchChar(char *searchedbuffer, uint8_t length, char character);
void initStructs(void);
void initString(char * buffer, uint8_t length);

typedef struct
{
	char drone[10];
	char right[1];
	char left[1];
	char fw[1];
	char bw[1];
}sLed;

typedef struct
{
	char controller[10];
	char drone[10];
}sMuerto;

typedef struct
{
	char controller[10];
	char weapon[10];
}sDisparo;




#endif /* MIDDLEWARE_BRIDGEMODE_H_ */
