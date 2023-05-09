/*
	Filename:Main.c
	Version: 2.0
	Created: 2020-05-15 11:12:46
	Author: Anita Enmark
	System: Arduino Uno with ATmega328
 */

#define F_CPU 16000000UL
#define BAUD 9600UL

#include "USART_Lib.h"
#include "adcLib.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>


int main(void)
{
	
	
	initUSART(BAUD);
	initADC(0);
	
	while(1)
	{
		
	   putchUSART(readADC());
	   _delay_ms(20);
		
	}
			
}


