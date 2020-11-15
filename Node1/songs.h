/*
 * songs.h
 *
 * Created: 13.11.2020 20:27:33
 *  Author: Herbe
 */ 


#ifndef SONGS_H_
#define SONGS_H_
#include "notes.h"

int imperial_march[] = {
	A4,4, A4,4, A4,16, A4,16, A4,16, A4,16, F4,8, p,8,
	A4,4, A4,4, A4,16, A4,16, A4,16, A4,16, F4,8, p,8,
	A4,4, A4,4, A4,4, F4,8, C5,16,

	A4,4, F4,8, C5,16, A4,2,//4
	E5,4, E5,4, E5,4, F5,8, C5,16,
	A4,4, F4,8, C5,16, A4,2,

	A5,4, A4,8, A4,16, A5,4, Gis5,8, G5,16, //7
	Dis5,16, D5,16, Dis5,8, p,8, A4,8, Dis5,4, D5,8, Cis5,16,

	C5,16, B4,16, C5,16, p,8, F4,8, Gis4,4, F4,8, A4,16,//9
	C5,4, A4,8, C5,16, E5,2,

	A5,4, A4,8, A4,16, A5,4, Gis5,8, G5,16, //7
	Dis5,16, D5,16, Dis5,8, p,8, A4,8, Dis5,4, D5,8, Cis5,16,

	C5,16, B4,16, C5,16, p,8, F4,8, Gis4,4, F4,8, A4,16,//9
	A4,4, F4,8, C5,16, A4,2,
	MUSIC_END
};

int Mario_theme[] = {
	E7, 12, E7, 12, p, 12, E7,
	12, p, 12, C7, 12, E7, 12, p,
	12, G7, 12, p, 12, p, 12, p,
	12, G6, 12, p, 12, p,12, p,
	
	12, C7, 12, p, 12, p, 12, G6,
	12, p, 12, p, 12, E6, 12, p,
	12, p, 12, A6, 12, p, 12, B6,
	12, p, 12, Ais6, 12, A6, 12, p,
	
	9, G6, 9, E7, 9, G7,
	12, A7, 12, p, 12, F7, 12, G7,
	12, p, 12, E7, 12, p, 12, C7,
	12, D7, 12, B6, 12, p, 12, p,
	
	12, C7, 12, p, 12, p, 12, G6,
	12, p, 12, p, 12, E6, 12, p,
	12, p, 12, A6, 12, p, 12, B6,
	12, p, 12, Ais6, 12, A6, 12, p,
	
	9, G6, 9, E7, 9, G7,
	12, A7, p, 12, F7, 12, G7,
	12, p, 12, E7, 12, p, 12, C7,
	12, D7, 12, B6,
	12, p, 12, p,
	MUSIC_END
};


int underworld_melody[] = {
	C4, 12, C5, 12, A3, 12, A4,
	12 ,Ais3, 12, Ais4, 12, p,
	p,
	12, C4, 12, C5, 12, A3, 12, A4,
	12, Ais3, 12, Ais4, 12, p,
	p,
	12, F3, 12, F4, 12, D3, 12, D4,
	12, Dis3, 12, Dis4, 12, p,
	p,
	12, F3, 12, F4, 12, D3, 12, D4,
	12, Dis3, 12, Dis4, 12, p,
	p, Dis4, Cis4, D4,
	Cis4, Dis4,
	Dis4, Gis3,
	G3, Cis4,
	C4, Fis4, F4, E3, Ais4, A4,
	Gis4, Dis4, B3,
	Ais3, A3, Gis3,
	//p, p, p,
	MUSIC_END
};

// Star Wars
const int starwars[] =
{
	Ais2,8, Ais2,8, p,16, F3,8, F3,8, p,16, Dis3,16, p,16, D3,16, p,16, C3,16, p,16, Ais3,8,
	Ais3,8, p,16, F3,8, p,16, Dis3,16, p,16, D3,16, p,16, C3,16, p,16, Ais3,8, Ais3,8, p,16,
	F3,8, p,16, Dis3,16, p,16, D3,16, p,16, Dis3,16, p,16, C3,8, C3,8,
	MUSIC_END
};

// Fur Elise
const int furelise[] =
{
	e4, 8, d4x, 8, e4, 8, d4x, 8, e4, 8, b3, 8, d4, 8, c4, 8, a3,8, p, 8,
	c3, 8, e3, 8, a3, 8,  b3, 4, p, 8, e3, 8, g3x, 8, b3, 8, c4, 4, p, 8, e3, 8,
	e3, 8, d4x, 8, e4, 8, d4x, 8, e4, 8, b3, 8, d4, 8, c4, 8, a3, 8, p, 8, c3, 8,
	e3, 8, a3, 8, b3, 4, p, 8, e3, 8, c4, 8, b3, 8, a3, 4,
	MUSIC_END
};

// Beatles, Hey Jude
const int Jude[] =
{
	G2,8, E2,8, p,16, E2,16, E2,16, G2,16, A2,16, D2,8, p,16, D2,16, E2,16, F2,8,
	C3,8, C3,16, C3,16, H2,16, G2,16, A2,16, G2,16, F2,16, E2,8, p,16, G2,16,
	A2,16, A2,8, A2,16, D3,16, C3,16, H2,16, H2,16, C3,16, A2,16, G2,8, p,16,
	C2,16, D2,16, E2,16, A2,16, A2,16, G2,8,
	MUSIC_END
};

const int octave[] = {c4, 8, d4, 8, e4, 8, f4, 8, g4, 8, a4, 8, h4, 8, c5, 8, MUSIC_END};

int end_melody[] = {
262, 4, 196, 8, 196, 8, 220, 4, 196, 4, 1, 4, 247, 4, 262, 4, MUSIC_END};

int end_melody2[] = {
  262, 8, 150, 8, 300, 2, 400, 4, MUSIC_END};
  
int start_melody[] = {
	400, 4, 300, 2, 150, 8, 262, 8, MUSIC_END};
  
#endif /* SONGS_H_ */