/*
 * music.c
 *
 * Created: 13.11.2020 20:31:04
 *  Author: Herbe
 */ 
#include <avr/io.h>
#include "music.h"
#include "notes.h"
#define  F_CPU 4915200 
#include <util/delay.h>

#define DEFAULT_VOLUME 100

void InitMusic()
{
	// Configure OC1B pin as output

	DDRE |= (1 << PE2); //OC1B as output

	// timer1 configuration (for pWM)
    TCCR1A = (1 << COM1B1);  // Clear OC1A/OC1B on compare match

	
	TCCR1B = (1 << WGM13) 	//mode 8, pWM, phase and Frequency Correct (TOp value is ICR1)
		   | (1 << CS11); 		//prescaler(8)
}


/**
	plays music.
*/

void playMusic( int* p_notes, uint8_t tempo, uint8_t scale)	{							 /** paying tempo from 0 to 100. Higher value = slower playback*/
//	uint16_t size = sizeof(*p_notes);

	int duration;
	int note;
	uint8_t i = 0;
	uint16_t delay = tempo * 10000;
   
	while( *p_notes )
	{
		*p_notes = scale* (*p_notes);
		note = *p_notes;
		p_notes++;

		duration = *p_notes;
		p_notes++;

		if( p == note )
		{
			//pause, do not generate any sound
			OCR1B = 0;
		}

		else
		{
			//not a pause, generate tone
			OCR1B = DEFAULT_VOLUME;

			//set frequency
			ICR1H = (note >> 8);
			ICR1L = note;
		}
		// wait duration
		for(i=0;i<32/duration;i++)
		{
			for(int j = 0; j<5; j++){
			_delay_loop_2( delay );
			}			
		}
	}
	

	//turn off any sound
	OCR1B = 0;
}
