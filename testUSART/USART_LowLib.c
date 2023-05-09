#include <avr/io.h>
#include "USART_LowLib.h"


void initLowUSART(uint32_t baudCount)
{
    UCSR0B=((1<<TXEN0)|(1<<RXEN0)); // Enable receiver and transmitter 0b00011000
    //UCSR0C= 0b00000110; Already initialised 
    UBRR0L = baudCount & 0x00FF; // Bitmask last byte
}

void putchLowUSART(uint8_t ch)
{
    while(! ((UCSR0A & (1<<UDRE0)) == (1<<UDRE0) )) // Wait until transmit buffer is redy to transmit
	{} // 0b00100000 ------ 0b00100000
    UDR0=ch;
}

uint8_t getchLowUSART(void)
{
    while(!((UCSR0A & (1<<RXC0)) == (1<<RXC0) )) // Wait until data to read
	{} //0b10000000 ----- 0b10000000
    return (UDR0);
}


/*
void putchLowUSART(uint8_t ch)
{
	while(!((UCSR0A&(0b00100000))==0b00100000));
	UDR0=ch;
}

uint8_t getchLowUSART(void)
{
	while(!((UCSR0A&0b10000000)==0b10000000));
	return (UDR0);
}
*/