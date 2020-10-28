/*
 * Timer.c
 *
 * Created: 21.10.2020 15:01:05
 *  Author: Herbe
 */ 
#include "Timer.h"

volatile uint32_t highscore = 0;
volatile uint16_t status = 0;


uint32_t timer_init(void){
    REG_PMC_PCER0 |= (1 << ID_PIOB) | (1 << ID_TC0); //enable timer in power controller

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
//pmc
//interrupt vect
//nvic

//void GAME_OVER(void){
//  SetTimer(0);  
//  CAN_MESSAGE score;
//  score.data = highscore;
//  score.data_length = 4;
//  score.id = 0;
//}

void SetTimer(uint8_t state){
    if(state == 1){
        TC0->TC_CHANNEL[0].TC_CCR |= TC_CCR_SWTRG
                                   | TC_CCR_CLKEN;         
    }
    else if(state == 0) {
        TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKDIS;         
    }
}
 