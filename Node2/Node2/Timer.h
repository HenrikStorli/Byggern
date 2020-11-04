/*
 * Timer.h
 *
 * Created: 21.10.2020 15:01:40
 *  Author: Herbe
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "sam.h"
#include "printf-stdarg.h"



uint32_t timer_init(void);
void TC0_Handler(void);
void TC1_Handler(void);
void TC2_Handler(void);
void delay_2us(uint32_t delay);
void GAME_OVER(void);
void SetTimer(uint8_t state);

#endif /* TIMER_H_ */