/*
 * Node2.c
 *
 * Created: 12.10.2020 15:10:31
 * Author : Herbe
 */ 

#include <sam3x8e.h>
//#include <>
#include "sam.h"

#include "uart.h"
#include "printf-stdarg.h"
//#include "wdt.h"
#include "can_controller.h"
#include "can_interrupt.h"
#include "ADC.h"
#include "Timer.h"

#define F_CPU 84E6

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    configure_uart();
    IR_init();
    timer_init();
      //init can config     
    uint32_t can_msk = 0x00143555;
    uint8_t can_status = can_init(can_msk, 1, 1);
    
    WDT->WDT_MR = WDT_MR_WDDIS; // Dissable watchdog      

  //  REG_PIOA_PER |= (1 << 19) | (1 << 20); // set as gpio on pin 19 and 20
  //  REG_PIOA_OER |= (1 << 19) | (1 << 20); // output enable
  //  REG_PIOA_SODR = (1 << 19) | (1 << 20); // set output data   

    CAN_MESSAGE test_message;
    
    test_message.id = 2;
    test_message.data[0] = 'H';
    test_message.data[1] = 'E';
    test_message.data[2] = 'I';
    test_message.data_length = 3;
    
    Start_Timer(1);  

    while (1) 
    {
       // uint8_t mm = can_send(&test_message, 1);
        
        //if(mm){
        //    printf("Mailbox budy");
        //}
        
      
        //printf("clock state is: %d \n\r" , highscore);
        
        
        
        //uint16_t IR = IR_read();
        //printf("data is: %d \n\r", IR);
        //
        //uint8_t score = IR_check(IR);
        //if(score == 1){
        //    //check if game over and send highscore by can            
        //    
        //    CAN_MESSAGE game_over;
        //    game_over.id = 1;
        //    game_over.data_length = 1;
        //    game_over.data[1] = timer_count;
        //    can_send(&game_over, 0);    // 0 for mailbox transmit 
        //    printf("Game Over! \n\r");
        //    while(1);
        //}



//        printf("X = %d Y = %d, joybutton = %d, joydirection = %d \n\r", received_joystick_data.posX, received_joystick_data.posY, received_joystick_data.button_pushed, received_joystick_data.joystick_direction);

   // CAN_MESSAGE can_msg;    
   // uint8_t mailbox_status = can_receive(&can_msg, 1);
   // if(can_msg.id > 0){
   // printf("Lengden er : %d\n Dataen er: %d\n ID'en er: %d", can_msg.data_length, can_msg.data[0], can_msg.data_length);    
   // }
    
//    printf("Halla jeg funker yolo lel derp  \n\r");
    }
}
