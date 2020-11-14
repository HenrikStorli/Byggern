/*
 * pos_read.c
 *
 * Created: 16.09.2020 13:43:36
 *  Author: Herbe
 */


#include <avr/io.h>
#include <stdio.h>
#include "pos_read.h"


void pos_read(position* pos){

    int ADC_Y = ADC_read(0);
    int ADC_X = ADC_read(1);

    // X read

    if((ADC_X >= (P_cal.center_X - 20)) && (ADC_X <= (P_cal.center_X + 20))){ //Deadspace for joystick
        ADC_X = 0;
    }
    else if(ADC_X > (P_cal.center_X + 20)){
        ADC_X = (ADC_X - P_cal.center_X) * 100.0 / (255.0 - P_cal.center_X);  //
    }

    else if (ADC_X < (P_cal.center_X - 20)){
        ADC_X = (ADC_X / ((float)P_cal.center_X)) * 100 - 100;   // // Scaling when value is larger then center value
    }

    // Y read

    if(ADC_Y >= (P_cal.center_Y - 80) && ADC_Y <= (P_cal.center_Y + 80)){  //Deadspace for joystick
        ADC_Y = 0;
    }
    else if(ADC_Y > (P_cal.center_Y + 80)){
        ADC_Y = (ADC_Y - (P_cal.center_Y)) * 100.0 / (255.0 - P_cal.center_Y);  // Scaling when value is larger then center value
    }

    else if (ADC_Y < (P_cal.center_Y - 80)){
        ADC_Y = (ADC_Y / ((float)P_cal.center_Y)) * 100 - 100;   // Scaling when value is smaller then center value
    }

    pos -> posX = ADC_X;
    pos -> posY = ADC_Y;
}

DIRECTION joystick_direction(void){

    pos_read(&P_pos);

    int angle = atan2(P_pos.posY, P_pos.posX);

    if(!P_pos.posY & !P_pos.posX){
        return NEUTRAL;
    }

    else if(angle >= -PI / 4.0 & angle <= PI/4.0){
        return RIGHT;
    }

    else if(angle >= -3 * PI/4.0 & angle <= -PI / 4.0){
        return DOWN;
    }

    else if(angle >= 3 * PI/4 | angle <= -3* PI / 4.0){
        return LEFT;
    }

    else if(angle >= PI / 4 & angle <= 3*PI / 4.0){
        return UP;
    }
}

void pos_readSettings(void){
	
	DDRB &= ~(1 << PB1);
	DDRD &= ~(1 << PD4);
	DDRD &= ~(1 << PD5);

	PORTB |= (1 << PB1); // internal pull up enable
}


uint8_t usb_button_pushed(USB_BUTTON BUTTON){

    uint8_t pressed;

    if(BUTTON == LEFT_BUTTON){
        pressed = (PIND & (1 << PD4) );

		}

    if(BUTTON == RIGHT_BUTTON){
        pressed =  (PIND & (1 << PD5) );
		}

    if(BUTTON == JOYSTICK_BUTTON){
        pressed =  (PINB & (1 << PB1) );
        return !pressed;
		}

    return pressed;
}
