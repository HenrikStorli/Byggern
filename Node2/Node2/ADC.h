/*
 * IR.h
 *
 * Created: 19.10.2020 14:10:40
 *  Author: Herbe
 */ 


#ifndef IR_H_
#define IR_H_

#include "sam.h"
//#include <sam3x8e.h>
void IR_init(void);
uint16_t IR_read(void);
uint8_t IR_check(uint16_t data);

#endif /* IR_H_ */