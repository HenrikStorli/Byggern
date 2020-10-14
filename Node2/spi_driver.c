/*
 * spi_driver.c
 *
 * Created: 30.09.2020 14:03:40
 *  Author: Herbe
 */
#include "spi_driver.h"


void spi_write(char data){

    SPDR = data;
    while( !(SPSR & (1<<SPIF)) );

}

char spi_read(void){

    spi_write(DUMMY);
    //printf("SPI data sent is");
    return SPDR;
}

void spi_init(void){
    DDR_SPI |= (1 << SCK) | (1 << MOSI) | (1 << SS);

    SPCR |= (1 << SPE) | (1 << MSTR) |(1<<SPR0);  // Enable SPI and set as master

    // // mode 0 with CPHA = 0 and CPOL = 0
    // SPCR &= ~(1<<CPOL);
    // SPCR &= ~(1<<CPHA);

    //SPSR |= (1 << SPI2X);  // clock divider set to F_CPU/2 for highest speed
}
