/*
 * Strings.c
 *
 *  Created on: 25 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "Strings.h"

void initString(char * buffer, uint8_t length)
{
	uint8_t i;
	for(i=0;i<length;i++)
	{
		buffer[i] = 0;
	}
}
