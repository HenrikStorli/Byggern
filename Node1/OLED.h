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

/**
 * @brief Initializes the OLED module
 */
void OLED_init(void);

/**
 * @brief writes data on the oled-screen
 *
 * @param data The data to be written
 */
void write_data(uint8_t data);

/**
 * @brief Writes a command to the OLED
 *
 * @param cmd The command to be executed
 */
void write_cmd(uint8_t cmd);

/**
 * @brief Selects a given page, so it can be written on
 *
 * @param page Page to be selected
 */
void oled_sel_row(uint8_t page);

/**
 * @brief Selects a given coloumn, so it can be written to
 *
 * @param col The colon that is to be selected
 */
void oled_sel_col(uint8_t col);

/**
 * @brief Sets the position to be written in top left corner
 */
void oled_home(void);

/**
 * @brief Adjust the writing area a numbers of line down
 *
 * @param lineNR The number of lines to be adjusted
 */
void oled_line_down(uint8_t lineNR);

/**
 * @brief Clears the screen
 */
void oled_clear(void);

/**
 * @brief Sets the position to be written to
 *
 * @param row The row that should be written to
 * @param col The col that should be written to
 */
void oled_pos_set(uint8_t row, uint8_t col);

/**
 * @brief Clears a given line on the OLED
 *
 * @param page The page that should be cleared
 */
void oled_clear_line(uint8_t page);

/**
 * @brief Writes a char on the OLED
 *
 * @param c The character that is written
 */
void oled_write_character(uint8_t c);

/**
 * @brief Writes a string in the OLED
 *
 * @param c A pointer to a character that is to be written
 */
void oled_print(char* c);

/**
 * @brief Prints an arraow in the screen in the given position
 *
 * @param The row that the arrow should be printed in
 * @param  The coloum the arrow should be printed in
 */
void oled_print_arrow(uint8_t row, uint8_t col);

typedef struct oled_pos{
    uint8_t row, col;
    } oled_pos_t;

volatile oled_pos_t oled_position;

#endif /* OLED_H_ */
