/*
 * display7SEG.h
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_
#include "main.h"

extern uint8_t sevenSegmentLEDConversion[];
extern uint16_t sevenSegmentDataPin[];
extern GPIO_TypeDef * sevenSegmentDataPort[];

void display7SEGMENT(uint8_t val);

#endif /* INC_DISPLAY7SEG_H_ */
