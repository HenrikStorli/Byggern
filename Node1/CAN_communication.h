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

/**
 * @brief Initializes the CAN-controller with the given mode
 *
 * @param mode The mode that should be set
 *
 * @return 1 If something went wrong, 0 if initialized correctly.
 */
uint8_t CAN_init(uint8_t mode);

/**
 * @brief Sends can message
 *
 * @param can_message A pointer to the message.
 *
 * @return 1 if something went wrong, 0 otherwise
 */
uint8_t CAN_message_transmission(CAN_message_t* can_message);

/**
 * @brief Receives message on buffer 0
 *
 * @return The received message
 */
CAN_message_t CAN_meessage_reception();

/**
 * @brief Receives message on buffer 1
 *
 * @return The received message
 */
CAN_message_t CAN_meessage_reception2();

/**
 * @brief Checks both buffers for a message
 *
 * @return The received message
 */
CAN_message_t message_handler();

/**
 * @brief Tests the CAN controller
 */
void CAN_communication_test();

/**
 * @brief Tests the CAN controller
 */
void CAN_communication_test2();

#endif /* CAN_COMMUNICATION_H_ */
