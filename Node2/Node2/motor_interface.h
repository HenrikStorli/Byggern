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

//MULIG DETTE ER FEIL RETNING I FORHOLD TIL DIR = 0/1
typedef enum{MOTOR_RIGHT, MOTOR_LEFT}MOTOR_DIRECTION;
typedef enum{ENCODER_HIGHER_BYTE, ENCODER_LOWER_BYTE} ENCODER_BYTE;

void motor_init_DAC(void);

void motor_set_input(int input);

void motor_select_direction(MOTOR_DIRECTION direction);

void motor_enable(void);

void motor_reset_counter(void);

void motor_activate_counter_output(uint8_t on);

void motor_select_encoder_byte(ENCODER_BYTE byte);

uint16_t motor_read_counter(void);

#endif /* MOTOR_CONTROLL_H_ */