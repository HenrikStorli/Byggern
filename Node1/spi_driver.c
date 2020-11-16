/*
 * spi_driver.c
 *
 * Created: 30.09.2020 14:03:40
 *  Author: Herbe
 */

/**
* @file
* @brief Implementation file for spi_driver
*/


#include "spi_driver.h"


void spi_write(char data){

    SPDR = data;
    while( !(SPSR & (1<<SPIF)) );

}

char spi_read(void){

    spi_write(DUMMY);
	
    return SPDR;
}

void spi_init(void){
    DDR_SPI |= (1 << SCK) | (1 << MOSI) | (1 << SS);

    SPCR |= (1 << SPE) | (1 << MSTR) | (1<<SPR0);  // Enable SPI and set as master
}
