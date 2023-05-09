/*  USART_Lib.c
**  Purpose:    	Serial p-t-p asynchronous communication for AVR
**  Chip:       	Hardware dependencies in low level library.
**                  Macro FOSC must be set to system frequency.
**			        Tested on Atmega328p running at 16MHz (GCC compiler)
**  Version:    	1.0  2020-05-15
**  Author:     	Anita Enmark
**
**  Uses:		    USART_LowLib, stdio.h
**
*/

#include "USART_Lib.h"
#include "USART_LowLib.h"    /*initLowUSART, putchLowUSART, getchLowUSART*/
#include <stdio.h>           /*sprintf*/


/*
********************************************************************************
**  Enable USART transmitter and receiver, disable interrupts
**  Sets USART baud rate. Protocol is set to
**    		- 8 data bits
**    		- 1 start bit
**    		- 1 stop bit
**
**  Input: 	baudrate – max baudrate dependent on clock frequency
**  Uses:      initLowUSART, macro FOSC for CPU frequency
**
*/
void initUSART(uint64_t baudrate)
{
	uint32_t countUBRR;
	/*Assignment 2 Part II: Can this be moved to LowLib to improve code?*/
	countUBRR=(uint32_t)((FOSC/16UL)/baudrate-1);    /*see Atmega328p Data Sheet Table 52 p.132*/
	initLowUSART(countUBRR);

}

/********************************************************************************
**  putchUSART: Write a single character to USART
**
**  Input:      ch - 8 bit character
**  Return:	    --
**  Uses:      putchLowUSART
*/
void putchUSART(uint8_t ch)
{
    putchLowUSART(ch);
}


/* ********************************************************************************
**  getchUSART: Read a single character from USART. No error checking.
**
**  Input:	   --
**  Return:    8 bit character
**  Uses:      getchUSART
*/
uint8_t getchUSART(void)
{
    return getchLowUSART();
}


/* ********************************************************************************
**  putStringUSART: Writes a null-terminated string of arbitrary length to USART,
**  null termination not included
**
**  Uses:      putchUSART
*/
void putStringUSART(char *str)
{
    uint32_t i = 0;
	
    while(str[i] != '\0')
    {
        putchUSART(str[i]);
        i++;
    }
}


/* ********************************************************************************
**  getStringUSART: Reads a NULL-terminated string of arbitrary length from USART
**
**
**  Input:     str -  Pointer to string
**  Output:    str -  NULL-terminated string
**  Uses:      getchUSART
**
**  Application must ensure that incoming data do not exceed string buffer size
*/
void getStringUSART(char *str)
{
    uint32_t i = 0;
	
    do
    {
    str[i]=getchUSART();
    i++;    
    } while(str[i-1] != 0x00);
}


/* ********************************************************************************
**  printNum8USART: ASCCI-codes an 8 bit unsigned integer number and writes
**  the string to USART
**
**  Input:     num  -  8 bit unsigned integer number
**  Uses:      putchUSART, sprintf
*/
void printNum8USART(uint8_t num)
{
    char buf[4]={0};    
    int i = 0;
	
    sprintf(buf,"%d", (int)num);
    while(buf[i] != '\0')
    {
        putchUSART(buf[i]);
        i++;
    }
}


/* ********************************************************************************
**  printNum32USART: ASCCI-codes a 32 bit unsigned integer number and writes
**  the string to USART
**
**  Input: 	   num  -  32 bit unsigned integer number
**  Uses:      putchUSART, sprintf
*/
void printNum32USART(uint32_t num)
{
    int i = 0;
    char buf[9]={0};
	
    sprintf(buf,"%lu", num);
    while(buf[i] != '\0')
    {
        putchUSART(buf[i]);
        i++;
    }
}


