/*
 * OLED.h
 *
 * Created: 22.09.2020 15:40:21
 *  Author: Herbe
 */

#ifndef OLED_H_
#define OLED_H_

#include <string.h>


//void OLED_printf(char* data);
volatile char* oled_write_cmd;
volatile char* oled_write_data;

void OLED_init(void);

void write_data(uint8_t data);

void write_cmd(uint8_t cmd);

void oled_sel_row(uint8_t page);

void oled_sel_col(uint8_t col);

void oled_home(void);

void oled_line_down(uint8_t lineNR);

void oled_clear(void);

void oled_pos_set(uint8_t row, uint8_t col);

void oled_clear_line(uint8_t page);

void oled_write_character(uint8_t c);

void oled_print(char* c);

//void oled_sel_line(uint8_t line);

void oled_print_arrow(uint8_t row, uint8_t col);

typedef struct oled_pos{
    uint8_t row, col;
    } oled_pos_t;

volatile oled_pos_t oled_position;

#endif /* OLED_H_ */
