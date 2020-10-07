

#include "CAN_communication.h"

uint8_t CAN_init(){
    //Enable interrupt on PIN PE0 (INT2).

    cli();

    EMCUCR |= (1<<ISC2);

    GICR |= (1<<INT2);

    sei();

    MCP_CANINTE |= MCP_RX_INT; //Enable buffer 1 and 0 interrupt.
}

ISR(INT2_vect){
    CAN_meessage_reception();
}

uint8_t CAN_message_transmission(CAN_message_t* can_message){

    //Splitting up the identifier into two bytes
    uint8_t identifier_low = (can_message -> identifier) % 8;
    uint8_t identifier_high = (can_message -> identifier) / 8;

    //Writing the identifier
    mcp_write(MCP_TXB0SIDL, identifier_low);
    mcp_write(MCP_TXB0SIDH, identifier_high);

    //Writing the length of the data message
    mcp_write(MCP_TXB0DLC, can_message -> data_length);

    //Writing the data Message
    uint8_t data_byte;
    for(uint8_t i = 0; i < (can_message -> data_length); i++){
        data_byte = (can_message -> data)[i];
        mcp_write(MCP_TXB0D0 + i, data_byte);
    }

    mcp_request_to_send(0); // Litt usikker
}

CAN_message_t CAN_meessage_reception(){

    CAN_message_t.identifier = 


}