/*
 * adcLib.h
 *
 * Created: 2023-05-07 22:15:21
 *  Author: Anita
 */ 


#ifndef ADCLIB_H_
#define ADCLIB_H_
#include <stdint.h>

void initADC(uint8_t muxChannel);
uint8_t readADC(void);





#endif /* ADCLIB_H_ */