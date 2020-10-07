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

uint8_t mcp_init(uint8_t mode);

void mcp_set_mode(uint8_t mode);

void mcp_write(uint8_t adrs, uint8_t value);

uint8_t mcp_read(uint8_t adrs);

void spi_master_CS(unsigned char state);

void mcp_reset();

void mcp_bit_modify(uint8_t adrs, uint8_t mask_byte, uint8_t data_byte);

uint8_t mcp_read_status();

void mcp_request_to_send(uint8_t buffer); //Input "3" if all TX's should be requested

#endif /* MCP2515_DRIVER_H_ */
