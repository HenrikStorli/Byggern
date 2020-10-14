/*
 * CAN_messages.c
 *
 * Created: 14.10.2020 16:04:06
 *  Author: Herbe
 */ 
#include "CAN_messages.h"


void joyStick_Can_Message(){
pos_read(&P_pos);
uint8_t sendPosX = 128 + P_pos.posX;
uint8_t sendPosY = 128 + P_pos.posY;
uint8_t sendJoyButton = usb_button_pushed(JOYSTICK_BUTTON);
uint8_t sendJoyDirection = (joystick_direction()) << 1; //shift right to not disturb rest of message

uint8_t sendJoyData = sendJoyDirection + sendJoyButton;

CAN_message_t joyStickData;
joyStickData.identifier = 0;
joyStickData.data[0] = sendPosX;
joyStickData.data[1] = sendPosY;
joyStickData.data[2] = sendJoyData;
joyStickData.data_length = 3;

CAN_message_transmission(&joyStickData);
}