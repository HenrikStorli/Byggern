#ifndef CAN_COMMUNICATION_H_
#define CAN_COMMUNICATION_H_

#include "mcp2515.h"
#include "mcp2515_driver.h"
#include <avr/interrupt.h>

typedef struct CAN_message{
    unsigned int identifier;
    uint8_t data_length;
    uint8_t data[8];
}CAN_message_t;

uint8_t CAN_init(uint8_t mode);

uint8_t CAN_message_transmission(CAN_message_t* can_message);

CAN_message_t CAN_meessage_reception();

void CAN_communication_test();

#endif /* CAN_COMMUNICATION_H_ */
