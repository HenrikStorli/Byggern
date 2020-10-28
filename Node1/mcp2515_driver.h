/*
 * mcp2515_driver.h
 *
 * Created: 30.09.2020 17:07:47
 *  Author: Herbe
 */


#ifndef MCP2515_DRIVER_H_
#define MCP2515_DRIVER_H_

#define F_CPU  4915200

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "spi_driver.h"
#include "mcp2515.h"

#define DDR_SPI DDRB
#define PORT_SPI PORTB
#define SS PB4
#define CAN_SS PB2

/**
 * @brief Initializes the mcp with the given mode
 *
 * @param mode The mode that should be set
 *
 * @return 1 If something went wrong, 0 if initialized correctly.
 */
uint8_t mcp_init(uint8_t mode);

/**
 * @brief Sets the given mode for the mcp
 *
 * @param mode The mode that should be set
 */
void mcp_set_mode(uint8_t mode);

/**
 * @brief Writes to the mcp controller
 *
 * @param adrs The adress that should be written to
 * @param value The value that it written
 */
void mcp_write(uint8_t adrs, uint8_t value);

/**
 * @brief Reads a given adrs in the mcp
 *
 * @param adrsThe adress that should be read
 *
 * @return The message contained in the adress
 */
uint8_t mcp_read(uint8_t adrs);

/**
 * @brief Chip select for the mcp
 *
 * @param state 0 if chips should be selected, 1 if not
 */
void spi_master_CS(unsigned char state);

/**
 * @brief Resets the mcp
 */
void mcp_reset();

/**
 * @brief Modifies one or more bits in a register in the mcp
 *
 * @param adrs The adres that should be modified
 * @param mask_byte Byte that decides which bits can be modified
 * @param data_byte A byte containing the new data.
 */
void mcp_bit_modify(uint8_t adrs, uint8_t mask_byte, uint8_t data_byte);

/**
 * @brief Reads the mcp's status
 *
 * @return Byte containing the status of the mcp
 */
uint8_t mcp_read_status();

/**
 * @brief Sends a request to the mcp, that a message should be sent
 * Input "3" if all TX's should be requested
 *
 * @param buffer The buffer that is requested to send
 */
void mcp_request_to_send(uint8_t buffer); //Input "3" if all TX's should be requested

#endif /* MCP2515_DRIVER_H_ */
