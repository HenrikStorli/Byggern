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
#include "motor_controller.h"


uint32_t timer_init(void);

void TC0_Handler(void);

void TC1_Handler(void);

//void GAME_OVER(void);

void SetTimer(uint8_t state);

uint32_t count_value(void);

void reset_count(void);

#endif /* TIMER_H_ */