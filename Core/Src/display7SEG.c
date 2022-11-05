/*
 * display7SEG.c
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */
#include "main.h"

uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

uint16_t sevenSegmentDataPin[7] = {
		SEG0_Pin,
		SEG1_Pin,
		SEG2_Pin,
		SEG3_Pin,
		SEG4_Pin,
		SEG5_Pin,
		SEG6_Pin,
};
GPIO_TypeDef * sevenSegmentDataPort[7] = {
		SEG0_GPIO_Port,
		SEG1_GPIO_Port,
		SEG2_GPIO_Port,
		SEG3_GPIO_Port,
		SEG4_GPIO_Port,
		SEG5_GPIO_Port,
		SEG6_GPIO_Port,
};

void display7SEGMENT(uint8_t val){
	uint8_t idx;
	for(idx = 0; idx < 7; idx ++){
	HAL_GPIO_WritePin(sevenSegmentDataPort[idx], sevenSegmentDataPin[idx], ((sevenSegmentLEDConversion[val]>>idx)&0x01));
	}
}


