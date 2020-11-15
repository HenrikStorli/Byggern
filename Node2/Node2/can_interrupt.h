/*
 * can_interrupt.h
 *
 * Author: Gustav O. Often and Eivind H. Jølsgard
 *
 * For use in TTK4155 Embedded and Industrial Computer Systems Design
 * NTNU - Norwegian University of Science and Technology
 *
 */ 


#ifndef CAN_INTERRUPT_H_
#define CAN_INTERRUPT_H_

#include <stdio.h>

typedef struct joystick_data{
    int posX;
    int posY;
    uint8_t button_pushed;
    uint8_t joystick_direction;
	uint8_t sliderRight;
}joystick_data_t;

joystick_data_t received_joystick_data;

int start_game;


void CAN0_Handler       ( void );


#endif /* CAN_INTERRUPT_H_ */