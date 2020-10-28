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
	
	//Enable pmc for port C and port D
	PMC->PMC_PCER0 |= (1 << ID_PIOC);
	PMC->PMC_PCER0 |= (1 << ID_PIOC);
	
	//Enable output on port D's pins: 0, 1, 2, 9, 10
	REG_PIOD_PER |= 0b11000000111; //Enable IO 
	REG_PIOD_OER |= 0b11000000111; //Enable output
	
	//Enable input on port C's pins: 0-7
	REG_PIOC_PER |= 0b11111111;
	
}

void motor_set_input(int input){
	int register_value = (4095.0/255.0)* input; // 4095 for motor reselution (12 bits), and 255 for max slider value.
	
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
	
	motor_reset_counter();
}

void motor_reset_counter(void){
	//Reset pin low
	REG_PIOD_CODR = (1 << 1);
	
	//Delay
	
	for(int i = 0; i < 400; i++);
	
	//Reset pin high
	REG_PIOD_SODR = (1 << 1);
	
}

void motor_activate_counter_output(uint8_t on){
	
	if(on){
		REG_PIOD_CODR |= (1<<0); //Set PD0 low
	}
	else if(!on){
		REG_PIOD_SODR |=(1<<0);
	}
}


void motor_select_encoder_byte(ENCODER_BYTE byte){
	
	if(byte == ENCODER_HIGHER_BYTE){
		REG_PIOD_CODR = (1<<2); //Set PD2 low
	}
	else if(byte == ENCODER_LOWER_BYTE){
		REG_PIOD_SODR = (1<<2); //Set PD2 high
	}
}


uint16_t motor_read_counter(){
	
	//Enable output for encoder
	motor_activate_counter_output(1);
	
	//Select higher encoder byte
	motor_select_encoder_byte(ENCODER_HIGHER_BYTE);
	
	//DELAY ABOUT 20us
	for(int i = 0; i < 400; i++);
	
	//Read MSB
	volatile uint16_t most_significant_byte = REG_PIOC_PDSR;
	most_significant_byte &= 0x000000FF;  //Masking out the uninteresting bits
	most_significant_byte = (most_significant_byte << 8);
	
	
	//Select lower encoder byte
	motor_select_encoder_byte(ENCODER_LOWER_BYTE);
	
	//DELAY ABOUT 20us
	for(int i = 0; i < 400; i++);

	//Read LSB
	volatile uint16_t least_significant_byte = REG_PIOC_PDSR;
	least_significant_byte &= 0x000000FF; //Masking out the uninteresting bits
	
	//Set !RST low to reset counter

	//Delay 20 ms

	//Set !RST high 

	//Disable output of encoder
	motor_activate_counter_output(0);
	
	return most_significant_byte + least_significant_byte;
	
}
