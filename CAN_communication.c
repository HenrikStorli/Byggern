

#include "CAN_communication.h"

volatile uint8_t flag = 0;

void CAN_init(uint8_t mode){

    mcp_init(mode);

    // Enable interrupt on PIN PE0 (INT2).

    // Disable  global  interrupts
    cli();

    // Falling edge interrupt
    EMCUCR &= ~(1<<ISC2);

    // Enable  interrupt  on PE0 
    GICR |= (1<<INT2);

    // Enable  global  interrupts
    sei();

    // Enable receive interrupts (RXB 0 and 1).
    mcp_write(MCP_CANINTE, MCP_RX_INT); //Enable buffer 1 and 0 interrupt.
}

ISR(INT2_vect){
    flag = 1;
}

uint8_t CAN_check_interrupt(){
    if(flag){
        flag = 0;
        return 1;
    }
    
    return 0;
}

void CAN_message_transmission(CAN_message_t* can_message){

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
    CAN_message_t message;
    uint8_t byte_mask = 0xE0;

    unsigned int identifier_high = mcp_read(MCP_RXB0SIDH);
    identifier_high = (identifier_high << 8 );
    uint8_t identifier_low = mcp_read(MCP_RXB0SIDL);
    identifier_low &= byte_mask;

    message.identifier = identifier_low + identifier_high;

    message.data_length = mcp_read(MCP_RXB0DLC);

    for(uint8_t i = 0; i < message.data_length; i++){
        (message.data)[i] = mcp_read(MCP_RXB0DM +1);
    }

    return message;
}

void CAN_communication_test(){
    CAN_message_t message;
    CAN_message_t message_recieve;

    message.identifier = 0xff;
    message.data_length = 2;
    (message.data)[0] = 0x11;
    (message.data)[1] = 0x11;

    CAN_message_transmission(&message);

    if(CAN_check_interrupt()){
        printf("Interrupt fungerer\n\r");
        message_recieve = CAN_meessage_reception();
        printf("DATAEN er: %d\n\r",message_recieve.data[0]);
        //printf("IDENTIFIER er: %d\n\r",message_recieve.identifier);
       // printf("LENGDEN er: %d\n\r",message_recieve.data_length);

    }
    else{
        printf("IKKE Interrupt ");

    }
}