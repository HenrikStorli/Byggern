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

void InitMusic(void);
void playMusic( int* p_notes, uint8_t scale);


#endif /* MUSIC_H_ */