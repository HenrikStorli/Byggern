#include "CAN_communication.h"

volatile int flag = 0;

uint8_t CAN_init(uint8_t mode){
    // Enable interrupt on PIN PE0 (INT0).

    cli(); // Disable global interrupts
    
    
    MCUCR |= (1 << ISC01);
    MCUCR &= ~(1 << ISC00);
    GICR |= (1 << INT0);   

    sei(); // Enable global interrupts
   
    mcp_init(MODE_CONFIG); 
    
    mcp_write(MCP_CANINTE, MCP_RX_INT); // Enable both buffers
    
	//Bit timing and synchronization
    mcp_write(MCP_CNF1, 0b10000001);
    mcp_write(MCP_CNF2, 0b10101101);
    mcp_write(MCP_CNF3, 0b00000101);

	//Set given mode
    mcp_set_mode(mode);
    
}

ISR(INT0_vect){
    flag = 1;
}


uint8_t CAN_check_interrupt(){
    if(flag){
        return 1;
    }
	return 0;
}


uint8_t CAN_message_transmission(CAN_message_t* can_message){

    //Splitting up the identifier into two bytes
    uint8_t identifier_low = ((can_message -> identifier) << 5);
    uint8_t identifier_high = ((can_message -> identifier) >> 3);

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

    // Request to send to given buffer
    mcp_request_to_send(0);
}


CAN_message_t CAN_meessage_reception(){
    CAN_message_t message;

    uint8_t byte_mask = 0xE0; // Mask for lower part of identifier
    uint8_t length_mask = 0x0F; // Mask for message length register

    // Reading the identifier higher byte
    unsigned int identifier_high = mcp_read(MCP_RXB0SIDH);
    identifier_high = (identifier_high << 8 );

    // Reading the identifier lower byte
    uint8_t identifier_low = mcp_read(MCP_RXB0SIDL);
    identifier_low &= byte_mask;

    message.identifier = identifier_low + identifier_high;

    // Reading the message length
    message.data_length = mcp_read(MCP_RXB0DLC)&length_mask;

    // Reading the data in the message
    for(uint8_t i = 0; i < message.data_length; i++){
        (message.data)[i] = mcp_read(MCP_RXB0DM +i);
    }
    
    return message;
}

CAN_message_t CAN_meessage_reception2(){
    CAN_message_t message;

    uint8_t byte_mask = 0xE0;   // Mask for lower part of identifier
    uint8_t length_mask = 0x0F; // Mask for message length register

    // Reading the identifier higher byte
    unsigned int identifier_high = mcp_read(MCP_RXB1SIDH);
    identifier_high = (identifier_high << 8 );

    // Reading the identifier lower byte
    uint8_t identifier_low = mcp_read(MCP_RXB0SIDL + 16);
    identifier_low &= byte_mask;

    message.identifier = identifier_low + identifier_high;

    // Reading the message length
    message.data_length = mcp_read(MCP_RXB0DLC + 16)&length_mask;

    // Reading the data in the message
    for(uint8_t i = 0; i < message.data_length; i++){
        (message.data)[i] = mcp_read(MCP_RXB0DM +i + 16);
    }
    
    return message;
}

CAN_message_t message_handler(){
    CAN_message_t message;
    
    // Checks if buffer 1 is full
    if(mcp_read(MCP_CANINTF) && 0x01){
        message = CAN_meessage_reception(); //reads buffer 2 register
        printf("i reception nr1 \r\n");

        mcp_bit_modify(MCP_CANINTF, 1, 0);  // resets can interrupt flag bit for buffer 1
        if(!(mcp_read(MCP_CANINTF) && 2)   ){
            printf("er i if nr1 \r\n");
            flag = 0;
        }
    }
    
    // Checks if buffer 2 is full
    else if(mcp_read(MCP_CANINTF) && 0x02){
        message = CAN_meessage_reception2();  //reads buffer 2 register
         printf("i reception nr2 \r\n");

        mcp_bit_modify(MCP_CANINTF, 2, 0);    // resets can interrupt flag bit for buffer 2
        if(!(mcp_read(MCP_CANINTF) && 1)   ){ 
            printf("er i if nr2 \r\n");
            flag = 0; 
        }
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
    _delay_ms(10);
    if(CAN_check_interrupt()){
        printf("Interrupt fungerer\n\r");
        message_recieve = message_handler();
        printf("DATAEN er: %d\n\r",message_recieve.data[0]);
        printf("identifier : %d \r\n", message.identifier); 
        printf("data length : %d \r\n", message.data_length);
    }
    else{
        printf("IKKE Interrupt \r\n");

    }
}


void CAN_communication_test2(){ 
    CAN_message_t message;
    CAN_message_t message_recieve;

    message.identifier = 0x44;
    message.data_length = 2;
    (message.data)[0] = 0x22;
    (message.data)[1] = 0x22;

    CAN_message_transmission(&message);

    if(CAN_check_interrupt()){
        printf("Interrupt fungerer\n\r");
        message_recieve = message_handler();
        printf("DATAEN2 er: %d\n\r",message_recieve.data[0]);
        printf("identifier2 : %d \r\n", message.identifier); 
        printf("data length2 : %d \r\n", message.data_length);
    }
    else{
        printf("IKKE Interrupt2 \r\n");

    }
}
