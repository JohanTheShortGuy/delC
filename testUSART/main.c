 /*
 * testUSART.c
 * Use of code is explained during demo lecture 
 *
 * Version: 1.0
 * Created: 2020-05-15 11:12:46
 * Author: Anita Enmark
 * System: System set in USART library. Tested on Arduino Uno board with 16 MHz Atmega328p, GCC
 */ 
//#include <stdint.h>
#include "USART_Lib.h"
#define F_CPU 16000000UL
#define BAUD 9600UL


int main(void)
{
	uint8_t dummyChar;
	uint8_t dummyStr[20];
	uint8_t outDAC;

	initUSART(BAUD);
	
	//dummyChar=getchUSART();
	putchUSART('\n');
	putchUSART('\n');
	putStringUSART("Demo on sending uint64_t in ASCII:  ");
	printNum32USART(123456UL);
	putchUSART('\n');
	
	/*while(1)
	{
		putStringUSART("Send a NULL-terminated string:");
		putchUSART('\n');
		getStringUSART(dummyStr);
		putStringUSART(dummyStr);
		putchUSART('\n');
		putchUSART('\n');
	}*/
	putStringUSART("Start Sawtooth by sending one byte:");
	putchUSART('\n');
	//dummyChar=getchUSART();
	while(1)
	{	
		
		for (outDAC=0; outDAC<=255;outDAC++)
		{
			putchUSART(outDAC);
			_delay_ms(100);
		}
	}
	
}



