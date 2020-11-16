/*
 * CAN_messages.c
 *
 * Created: 14.10.2020 16:04:06
 *  Author: Herbe
 */ 


/**
* @file
* @brief Implementation file for CAN_joystick_message
*/


#include "CAN_joystick_messages.h"


void joyStick_Can_Message(){
	
pos_read(&P_pos); //Reads the current position of the joystick

uint8_t sendSliderRight = ADC_read(2);  
uint8_t sendPosX = 128 + P_pos.posX;  //Adding 128 to not have negative a number
uint8_t sendPosY = 128 + P_pos.posY;  //Adding 128 to not have negative a number
uint8_t sendJoyButton = usb_button_pushed(JOYSTICK_BUTTON);
uint8_t sendJoyDirection = (joystick_direction()) << 1; //shift right to not disturb rest of message

uint8_t sendJoyData = sendJoyDirection + sendJoyButton;  //Combining button-bushed and joystick-direction in one byte.

CAN_message_t joyStickData;
joyStickData.identifier = 0b11111111;
joyStickData.data[0] = sendPosX;
joyStickData.data[1] = sendPosY;
joyStickData.data[2] = sendJoyData;
joyStickData.data[3] = sendSliderRight;
joyStickData.data_length = 4;

CAN_message_transmission(&joyStickData);
}