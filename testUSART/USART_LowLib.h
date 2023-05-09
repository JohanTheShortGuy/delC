
#ifndef USART_LOWLIB_H_
#define USART_LOWLIB_H_

void initLowUSART(uint32_t);
uint8_t getchLowUSART(void);
void putchLowUSART(uint8_t);

#endif /* USART_LOWLIB_H_ */