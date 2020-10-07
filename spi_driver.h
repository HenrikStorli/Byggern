/*
 * spi_driver.h
 *
 * Created: 30.09.2020 14:04:07
 *  Author: Herbe
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <avr/io.h>
#include <stdio.h>
#include "iom162.h"


#define DDR_SPI DDRB
#define MOSI PB5
#define SCK PB7
#define SS PB4

#define PORT_SPI PORTB

#define DUMMY 0b01010110

void spi_write(char data);

char spi_read(void);

void spi_init(void);

#endif /* SPI_DRIVER_H_ */
