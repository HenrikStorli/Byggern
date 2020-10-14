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
 * @brief Updates the screen according to the given node.
 *
 * @param mode A pointer to the current node.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

uint8_t CAN_init(uint8_t mode);

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

uint8_t CAN_message_transmission(CAN_message_t* can_message);

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

CAN_message_t CAN_meessage_reception();

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

CAN_message_t CAN_meessage_reception2();

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

CAN_message_t message_handler();

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

void CAN_communication_test();

/**
 * @brief Updates the screen according to the given node.
 *
 * @param current_node A pointer to the current node.
 * @param child Index for the current nodes child.
 *
 * @return True if one of the buttons are pushed, False otherwise.
 */

void CAN_communication_test2();

#endif /* CAN_COMMUNICATION_H_ */
