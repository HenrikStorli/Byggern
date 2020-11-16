/*
 * OLED.c
 *
 * Created: 22.09.2020 15:40:08
 *  Author: Herbe
 */

/**
* @file
* @brief Implementation file for OLED
*/

#include <avr/io.h>
#include <stdio.h>
#include "OLED.h"
#include "fonts.h"

#define PXL_WIDTH 127       // begins at 0 |128|
#define PXL_HEIGHT 63       // begins at 0 |64|
#define OLED_CMD_ADR 0x1000
#define OLED_DATA_ADR 0x1200      
#define HORIZONTAL_ADRSNG_MODE 0x22
#define VERTICAL_ARDSNG_MODE
volatile char* oled_write_cmd = (char *)0x1000;
volatile char* oled_write_data =(char *)0x1200;


void OLED_init()    {
    write_cmd(0xae); // display off
    write_cmd(0xa1); //segment remap
    write_cmd(0xda); //common pads hardware: alternative
    write_cmd(0x12);
    write_cmd(0xc8); //common output scan direction:com63~com0
    write_cmd(0xa8); //multiplex ration mode:63
    write_cmd(0x3f);
    write_cmd(0xd5); //display divide ratio/osc. freq. mode
    write_cmd(0x80);
    write_cmd(0x81); //contrast control
    write_cmd(0x50);
    write_cmd(0xd9); //set pre-charge period
    write_cmd(0x21);
    write_cmd(0x20); //Set Memory Addressing Mode
    write_cmd(0x02);
    write_cmd(0xdb); //VCOM deselect level mode
    write_cmd(0x30);
    write_cmd(0xad); //master configuration
    write_cmd(0x00);
    write_cmd(0xa4); //out follows RAM content
    write_cmd(0xa6); //set normal display
    write_cmd(0xaf); // display on

    oled_clear();
    oled_home();
}

void write_data(uint8_t data){
    oled_write_data[0] = data;     
}

void write_cmd(uint8_t cmd){
    oled_write_cmd[0] = cmd;     
}

void oled_sel_row(uint8_t page){
    oled_position.row = page;
    page = page % 8;
    write_cmd(0xB0 + page);
}
void oled_sel_col(uint8_t col){
    oled_position.col = col;
    uint8_t numLow = col % 16;
	uint8_t numHigh = col / 16;

	write_cmd(numLow);
	write_cmd(16 + numHigh);

}
void oled_home(void){
     oled_pos_set(0,0);
}
void oled_line_down(uint8_t lineNR){
    write_cmd(0xB0 + lineNR);
}
void oled_clear(void){
   for(uint8_t i = 0; i < 8; i++){      // page select
        oled_line_down(i);
        for(uint8_t j = 0; j < 128; j++){
                for(uint8_t k = 0; k < 8; k++){
                write_data(pgm_read_byte( &(font8[0][k] ) ) );   // gets blank spaces from font.h //
                }
        }
   }
    oled_home();
}


void oled_pos_set(uint8_t row, uint8_t col){
    oled_sel_row(row);
    oled_sel_col(col);
}

void oled_clear_line(uint8_t page){
    oled_line_down(page);

    for(uint8_t j = 0; j < 128; j++){
        write_data(0b00000000);   // sets bitmask of zero to a line/page
    }
}

void oled_write_character(uint8_t c){
     for(uint8_t i = 0; i < 8; i++){
         write_data(pgm_read_byte( &font8[c-32][i] ) );
     }
}

void oled_print(char* string){
    int length = strlen(&string[0]);

    for(int i = 0; i < length; i++ ){

        oled_write_character(string[i]);
    }
}


void oled_print_arrow(uint8_t row, uint8_t col){
    oled_pos_set(row, col);
    write_data(0b00011000);
    write_data(0b00011000);
    write_data(0b01111110);
    write_data(0b00111100);
    write_data(0b00011000);
}
