/*
 * motor_controll.h
 *
 * Created: 26.10.2020 14:01:21
 *  Author: henri
 */ 

//////////////// MJ1 ///////////
//NOT_OE - PD0
//NOT_RST - PD1
//SEL - PD2
//EN - PD9
//DIR - PD10
//////////////// MJ2 ////////////
//DO0 - PC1
//DO1 - PC2
//.
//.
//.
//DO7 - PC8

//DAC1 - PB16


#ifndef MOTOR_CONTROLL_H_
#define MOTOR_CONTROLL_H_

#include <sam.h>
#include "can_interrupt.h"


void motor_init_DAC();

void motor_set_position(int position);

#endif /* MOTOR_CONTROLL_H_ */