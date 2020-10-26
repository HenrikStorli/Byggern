/*
 * CAN_messages.h
 *
 * Created: 14.10.2020 16:05:04
 *  Author: Herbe
 */ 


#ifndef CAN_MESSAGES_H_
#define CAN_MESSAGES_H_

#include "CAN_communication.h"
#include "pos_read.h"


/**
 * @brief Sends information about the joystick as a CAN message
 */
void joyStick_Can_Message();

#endif /* CAN_MESSAGES_H_ */