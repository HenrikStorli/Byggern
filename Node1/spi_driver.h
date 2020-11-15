/*
 * spi_driver.h
 *
 * Created: 30.09.2020 14:04:07
 *  Author: Herbe
 */


/**
* @file
* @brief Library for using SPI
*/


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "iom162.h"


#define DDR_SPI DDRB
#define MOSI PB5
#define SCK PB7
#define SS PB4

#define PORT_SPI PORTB

#define DUMMY 0b01010110

/**
 * @brief Writes data on the spi for the atmega162
 *
 * @param data The data to be sent trough spi
 */
void spi_write(char data);

/**
 * @brief Reads the data contained in the SPI Data Register
 *
 * @return the data contained in SPI Data Register
 */
char spi_read(void);

/**
 * @brief Initializes the spi module
 */
void spi_init(void);

#endif /* SPI_DRIVER_H_ */
