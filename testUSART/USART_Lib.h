/*  USART_Lib.h
**
**  Purpose:    	Serial p-t-p asynchronous communication for AVR 
**  Chip:       	Hardware dependencies in low level library.
					Macro FOSC must be set to system frequency.
**					Tested on Atmega328p running at 16MHz (GCC compiler)
**  Version:    	1.0  2020-05-15
**  Author:     	Anita Enmark
**
*/


#ifndef USART_LIB_H_
#define USART_LIB_H_
#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

#define FOSC 16000000UL /*Atmega328p CPU frequency*/

/*
********************************************************************************
**	Enable USART transmitter and receiver, disable interrupts
**	Sets USART baud rate. Protocol is set to (see Atmega8 Datasheet pp. 148 -156):
**    		- 8 data bits
**    		- 1 start bit
**    		- 1 stop bit
**
**	Input: 	   baudrate – max baudrate dependent on clock frequency
**  Uses:      initLowUSART, macro FOSC for CPU frequency must be defined
**
*/
void initUSART(uint64_t baudrate);

/********************************************************************************
**	putchUSART: Write a single character to USART
**
**	Input:      ch - 8 bit character
**  Return:	    --
**  Uses:       putchLowUSART
*/
void putchUSART(uint8_t ch);


/* ********************************************************************************
**	getchUSART: Read a single character from USART. No error checking.
**
**	Input:	   --
**  Return:    8 bit character
**  Uses:      getchUSART
*/
uint8_t getchUSART(void);


/* ********************************************************************************
**	putStringUSART: Writes a null-terminated string of arbitrary length to USART,
**	null termination not included
**
**	Input:     str -  NULL-terminated string
**  Uses:      putchUSART
*/
void putStringUSART(char *str);


/* ********************************************************************************
**	getStringUSART: Reads a NULL-terminated string of arbitrary length from USART
**
**
**	Input:     str -  Pointer to string
**	Output:    str -  NULL-terminated string
**  Uses:      getchUSART
**
**  Application must ensure that incoming data do not exceed string buffer size
*/
void getStringUSART(char *str);


/* ********************************************************************************
**	printNum8USART: ASCCI-codes an 8 bit unsigned integer number and writes
**	the string to USART
**
**	Input:     num  -  8 bit unsigned integer number
**  Uses:      putchUSART, sprintf
*/
void printNum8USART(uint8_t num);


/* ********************************************************************************
**	printNum32USART: ASCCI-codes a 32 bit unsigned integer number and writes
**	the string to USART
**
**	Input: 	   num  -  32 bit unsigned integer number
**  Uses:      putchUSART, sprintf
*/
void printNum32USART(uint32_t num);


#endif /* USART_LIB_H_ */
