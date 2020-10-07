#ifndef CAN_COMMUNICATION_H_
#define CAN_COMMUNICATION_H_

#include "mcp2515.h"
#include "mcp2515_driver.h"
#include <avr/interrupt.h>


/*Message Transmission registers*/
#define MCP_TXRTSCTRL	0x0D		// TXnRTS Pin control and status register - Is this necessary?

#define MCP_TXB0CTRL	0x30		// Transmit buffer 0 control register
#define MCP_TXB0SIDH	0x31		// Transmit buffer 0 standard identifier high
#define MCP_TXB0SIDL	0x32		// Transmit buffer 0 standard identifier low
#define MCP_TXB0DLC		0x35		// Transmit buffer 0 data length code
#define MCP_TXB0D0		0x36		// Transmit buffer 0 Data Byte m. From 0x36 to 0x3D

#define MCP_RXB0CTRL	0x60

#define MCP_RXB0SIDH	0x61		// Receive buffer 0 standard identifier high
#define MCP_RXB0SIDL	0x62		// Receive buffer 0 standard identifier low
#define MCP_RXB0DLC		0x65		// Receive buffer 0 data length code
#define MCP_RXB0DM		0x66		// Receive buffer 0 Data Byte m. From 0x66 to 0x6D

#define MCP_RXB1CTRL	0x70
#define MCP_RXB1SIDH	0x71

typedef struct CAN_message{
    unsigned int identifier;
    uint8_t data_length;
    uint8_t data[8];
}CAN_message_t;

void CAN_init(uint8_t mode);

void CAN_message_transmission(CAN_message_t* can_message);

CAN_message_t CAN_meessage_reception();

void CAN_message_interrupt();

void CAN_communication_test();


#endif /* CAN_COMMUNICATION_H_ */
