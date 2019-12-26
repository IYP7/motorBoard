/*
 * BridgeMode.c
 *
 *  Created on: 23 feb. 2018
 *      Author: Iván
 */

#include "common.h"
#include "BridgeMode.h"
#include "GPIO.h"

#define MAX_CHARS 5

static sLed Led;
static sMuerto Muerto;
static sDisparo Disparo;

char tag[10];



void initStructs(void)
{
	initString(Disparo.controller, strlen(Disparo.controller));
	initString(Disparo.weapon, strlen(Disparo.weapon));
	initString(Led.drone, strlen(Led.drone));
	initString(Led.right, strlen(Led.right));
	initString(Led.left, strlen(Led.left));
	initString(Led.fw, strlen(Led.fw));
	initString(Led.bw, strlen(Led.bw));
	initString(Muerto.controller, strlen(Muerto.controller));
	initString(Muerto.drone, strlen(Muerto.drone));
}
