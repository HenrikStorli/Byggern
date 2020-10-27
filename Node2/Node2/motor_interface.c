/*
 * motor_controll.c
 *
 * Created: 26.10.2020 14:01:11
 *  Author: henri
 */ 

#include "motor_interface.h"


void motor_init_DAC(){
	// Set clock for DACC peripheral
	REG_PMC_PCER1 |= (1<<6);
	
	//Set DACC MODE REGISTER, free running mode
	REG_DACC_MR = 0x05012000; //0x050012000
	
	//Set DAC channel to channel 1
	REG_DACC_CHER = 0b10;
	
	//Enable output on port D's pins: 0, 1, 2, 9, 10
	REG_PIOD_PER |= 0b11000000111; //Enable IO 
	REG_PIOD_OER |= 0b11000000111;; //Enable output
	
	//Enable input on port D's pins: 0-7
	REG_PIOD_PER |= 0b11111111;
	
}

void motor_set_position(int position){
	int register_value = (4095.0/255.0)* position; // 4095 for motor reselution (12 bits), and 255 for max slider value.
	
	REG_DACC_CDR = register_value;
}

void motor_select_direction(MOTOR_DIRECTION direction){

	if(direction == MOTOR_LEFT){
		REG_PIOD_SODR =  (1<<10); //ANTAR DIR = 1 gir venstre
	}
	else if (direction == MOTOR_RIGHT){
		REG_PIOD_CODR = (1<<10); //ANTAR DIR = 1 gir høyre
	}
}


void motor_enable(void){
	
	REG_PIOD_SODR |= (1<<9); //Set PD9 high	
}

void motor_reset_counter(void){
	
}

void motor_activate_counter_output(void){
	REG_PIOD_CODR |= (1<<0); //Set PD0 low
}


void motor_select_encoder_byte(ENCODER_BYTE byte){
	
	if(byte == ENCODER_HIGHER_BYTE){
		REG_PIOD_CODR = (1<<2); //Set PD2 low
	}
	else if(byte == ENCODER_LOWER_BYTE){
		REG_PIOD_SODR = (1<<2); //Set PD2 high
	}
}

//Funksjon skal muligens fjernes
uint8_t motor_read_counter(uint8_t lower_higher_byte){
	motor_activate_counter_output();
	
}


uint16_t motor_read_counter(){
	
	//Enable output for encoder
	motor_activate_counter_output();
	
	//Select higher encoder byte
	motor_select_encoder_byte(ENCODER_HIGHER_BYTE);
	
	//DELAY ABOUT 20us
	sadasdasdsd
	
	//Read MSB
	asdsdasdasd
	REG_PIOD_PDSR
	
	//Select lower encoder byte
	motor_select_encoder_byte(ENCODER_LOWER_BYTE);
	
	//DELAY ABOUT 20us
	sadasdasdsd	
	
	//Read LSB
	asdasdasdas
	REG_PIOD_PDSR
	
	//Toggle !RST to reset counter
	qweqweqweqwe
	
	//Disable output of encoder
	asdasdasdasd
	
}
