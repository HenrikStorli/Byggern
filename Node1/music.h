/*
 * music.h
 *
 * Created: 13.11.2020 20:31:48
 *  Author: Herbe
 */ 

/**
* @file
* @brief Library for using buzzer
*/

#ifndef MUSIC_H_
#define MUSIC_H_

/**
 * @brief Initializes the pwm signal used for the buzzer
 */
void InitMusic(void);

/**
 * @brief Initializes the CAN-controller with the given mode
 *
 * @param p_notes pointer to the notes that should be played
 * @param scale How the notes should be scaled
 */
void playMusic(int* p_notes, uint8_t scale);

#endif /* MUSIC_H_ */