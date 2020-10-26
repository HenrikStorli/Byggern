/*
 * motor_controll.c
 *
 * Created: 26.10.2020 14:01:11
 *  Author: henri
 */ 

#include "motor_controll.h"


void motor_init_DAC(){
	// Set clock for DACC peripheral
	REG_PMC_PCER1 |= (1<<6);
	
	//Set DACC MODE REGISTER, free running mode
	REG_DACC_MR = 0x05012000; //0x050012000
	
	//Set DAC channel to channel 1
	REG_DACC_CHER = 0b10;
}

void motor_set_position(int position){
	int register_value = (4095.0/255.0)* position; // 4095 for motor reselution (12 bits), and 255 for max slider value.
	
	REG_DACC_CDR = register_value;
}

