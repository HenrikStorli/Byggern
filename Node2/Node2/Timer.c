/*
 * Timer.c
 *
 * Created: 21.10.2020 15:01:05
 *  Author: Herbe
 */ 
#include "Timer.h"
#include "can_controller.h"
#include "can_interrupt.h"
//#include "printf-stdarg.h"

volatile uint32_t highscore = 0;
volatile uint16_t status = 0;

#define F_CPU 84E6
 
uint32_t timer_init(void){
    REG_PMC_PCER0 |= 
                   (1 << ID_PIOB)
                  | (1 << ID_TC0)
                  | (1 << ID_TC1)
                  | (1 << ID_TC2); //enable timer in power controller

    TC2->TC_CHANNEL[2].TC_IER |= TC_IER_CPCS
                               | TC_IER_CPAS;                              
    TC2->TC_CHANNEL[2].TC_CCR |= TC_CCR_CLKEN;
    uint16_t RC_count_100hz = 6563; // to have 100hz ish intervals
    TC2->TC_CHANNEL[2].TC_RC = RC_count_100hz; // Set Compare RC
    TC2->TC_CHANNEL[2].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK4  // prescale of 128
                               | TC_CMR_WAVE                // waveform mode
                               | TC_CMR_WAVSEL_UP_RC        // compare rising edge on RC
                               | TC_CMR_ACPC_SET;           //
    NVIC_EnableIRQ(ID_TC2);
    
    // DAC TIMING SETUP //
    TC1->TC_CHANNEL[1].TC_IER |= TC_IER_CPCS
                              | TC_IER_CPAS;
                              
    //TC1->TC_CHANNEL[1].TC_CCR |= TC_CCR_CLKEN;
    uint16_t RC_count_DAC = 21; // to have 2us intervals
    TC1->TC_CHANNEL[1].TC_RC = RC_count_DAC; // Set Compare RC
    TC1->TC_CHANNEL[1].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK2  // prescale of 8
                               | TC_CMR_WAVE                // waveform mode
                               | TC_CMR_WAVSEL_UP_RC        // compare rising edge on RC
                               | TC_CMR_ACPC_SET;           //
    NVIC_EnableIRQ(ID_TC1); 
       
    // HIGHSCORE TIMING SETUP //    
    
    TC0->TC_CHANNEL[0].TC_IER |= TC_IER_CPCS
                              | TC_IER_CPAS;
    TC0->TC_CHANNEL[0].TC_CCR |= TC_CCR_CLKEN;    
    uint16_t RC_count = 39400; // to have ish 1000 points per min (~16,67Hz)
    TC0->TC_CHANNEL[0].TC_RC = RC_count; // Set Compare RA        
    TC0->TC_CHANNEL[0].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK4  // prescale of 128
                               | TC_CMR_WAVE                // waveform mode
                               | TC_CMR_WAVSEL_UP_RC        // compare rising edge on RC
                               | TC_CMR_ACPC_SET;           //     
    NVIC_EnableIRQ(ID_TC0); 
}
void TC0_Handler(void){
    uint16_t status =  TC0->TC_CHANNEL[0].TC_SR;
    //if(TC0->TC_CHANNEL[0].TC_SR == TC_SR_COVFS){
    highscore++;
    //}
    //if (!(highscore %1000)) {
    printf("highscore is: %d \n\r", highscore);   
    //}
     //return status;
    //TC_SR_CLKSTA
    

    NVIC_ClearPendingIRQ(ID_TC0);
}
void TC1_Handler(void){
    uint16_t status = TC1->TC_CHANNEL[1].TC_SR;
     
    NVIC_ClearPendingIRQ(ID_TC1);
}

void TC2_Handler(void){
    uint16_t status = TC2->TC_CHANNEL[1].TC_SR;
    printf("interrupt TC2");
    NVIC_ClearPendingIRQ(ID_TC2);
}    
void delay_2us(uint32_t delay){    
    for(uint8_t i = 0; i <= delay; i++) {         
        SetTimer(3);    
        //asm("nop");
    }
}

void GAME_OVER(void){
  //SetTimer(0);  
  CAN_MESSAGE score;
  score.data[0] = 100;

//  score.data[1] = 8 >> highscore;
//  score.data[2] = 16 >> highscore;
//  score.data[3] = 24 >> highscore;
  score.data_length = 1;    //4
  score.id = 0;
  printf("Game over!\n\r");
}

void SetTimer(uint8_t state){
    if(state == 1) {
        TC0->TC_CHANNEL[0].TC_CCR |= TC_CCR_SWTRG
                                   | TC_CCR_CLKEN;         
    }
    else if(state == 0) {
        TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKDIS;         
    }
    else if(state == 3) {
        TC1->TC_CHANNEL[1].TC_CCR |= TC_CCR_SWTRG
                                   | TC_CCR_CLKEN;       
    }
    else if(state == 4) {
        TC1->TC_CHANNEL[1].TC_CCR |= TC_CCR_CLKDIS;        
    }
    else if(state == 5) {
        TC2->TC_CHANNEL[2].TC_CCR |= TC_CCR_SWTRG
                                   | TC_CCR_CLKEN;       
    }
    else if(state == 6) {
        TC2->TC_CHANNEL[2].TC_CCR |= TC_CCR_CLKDIS;        
    }
}
 