/*
 * mcp2515_driver.c
 *
 * Created: 30.09.2020 17:07:30
 *  Author: Herbe
 */

#include "mcp2515_driver.h"


uint8_t mcp_init(uint8_t mode){
    uint8_t value;

    spi_init();
    
    mcp_reset();
    mcp_set_mode(MODE_CONFIG);
    _delay_ms(30);
    value = mcp_read(MCP_CANSTAT);
    printf("value is %d", value);
    if((value & MODE_MASK) != MODE_CONFIG){
        printf("MCP2515 is NOT in configuration mode after reset!\n");
        return 1;
    }

    mcp_set_mode(mode);

    value = mcp_read(MCP_CANSTAT);
    if((value & MODE_MASK) != mode){
        printf("MCP2515 is NOT in the specified mode after initialization!\n");
        return 1;
    }

    return 0;
}

void mcp_set_mode(uint8_t mode){
    mcp_write(MCP_CANCTRL, mode);
}

void mcp_write(uint8_t adrs, uint8_t value){

    spi_master_CS(0); //Select CAN controller

    spi_write(MCP_WRITE); // Instruction
    spi_write(adrs);    //Adress
    spi_write(value);   // Data

    spi_master_CS(1); //Deselect CAN controller
}


uint8_t mcp_read(uint8_t adrs){
   uint8_t result;

   spi_master_CS(0);

   spi_write(MCP_READ); //Instruction
   spi_write(adrs); // Adress
   result =  spi_read(); //Read return value

   spi_master_CS(1);

   return result;
}


void spi_master_CS(unsigned char state){

    //DDR_SPI |= (1 << SS);

    if(!state) {
        //Lower CS pin
        PORT_SPI &= ~(1 << SS);
        //_delay_us(40);
        }
    else {
        // Set CS pin
        PORT_SPI |= (1 << SS);
        }
}

void mcp_reset(){

    spi_master_CS(0);
    spi_write(MCP_RESET);
    
    spi_master_CS(1);
}


void mcp_bit_modify(uint8_t adrs, uint8_t mask_byte, uint8_t data_byte){
    spi_master_CS(0);

    // Not all registers can be accessed with this command
    spi_write(MCP_BITMOD);
    spi_write(adrs);
    spi_write(mask_byte);
    spi_write(data_byte);

    spi_master_CS(1);

}

uint8_t mcp_read_status(){
    uint8_t status_value;
    spi_master_CS(0);

    spi_write(MCP_READ_STATUS);
    status_value = spi_read();

    spi_master_CS(1);

    return status_value;
}

void mcp_request_to_send(uint8_t buffer){
    spi_master_CS(0);

    switch (buffer) {
      case 0:
          spi_write(MCP_RTS_TX0);
          break;
      case 1:
          spi_write(MCP_RTS_TX1);
          break;
      case 2:
          spi_write(MCP_RTS_TX2);
          break;
      default:
        spi_write(MCP_RTS_ALL);
    }

    spi_master_CS(1);
}
