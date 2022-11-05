/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */
#include "main.h"

static GPIO_PinState debounceButtonBuffer0 [NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1 [NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2 [NUMBER_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3 [NUMBER_OF_BUTTONS];

static uint8_t flagForButtonPress1s [NUMBER_OF_BUTTONS];


uint16_t buttonDataPin[NUMBER_OF_BUTTONS] = {
	RESET_Pin,
	INC_Pin,
	DEC_Pin,
};
GPIO_TypeDef * buttonDataPort[NUMBER_OF_BUTTONS] = {
	RESET_GPIO_Port,
	INC_GPIO_Port,
	DEC_GPIO_Port,
};
int TimerForKeyPress = LONG_PRESS_TIME;
int isPressedButton(){
	for (int idx = 0 ; idx < NUMBER_OF_BUTTONS ; idx++){
		if(flagForButtonPress1s[idx] == 1){
			status = idx;
			flagForButtonPress1s[idx] = 0;
			return 1;
		}
	}
	return 0;
}

void button_reading ( void ) {
	for ( int i = 0; i <NUMBER_OF_BUTTONS; i ++) {
		debounceButtonBuffer0 [i] = debounceButtonBuffer1 [i];
		debounceButtonBuffer1 [i] = debounceButtonBuffer2 [i];
		debounceButtonBuffer2 [i] = HAL_GPIO_ReadPin (buttonDataPort[i], buttonDataPin[i]);
		if(( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])&&(debounceButtonBuffer0 [i] == debounceButtonBuffer1 [i])){
			if(debounceButtonBuffer3 [i] != debounceButtonBuffer2 [i]){
				debounceButtonBuffer3 [i] = debounceButtonBuffer2 [i];
				if(debounceButtonBuffer2[i] == PRESSED_STATE){
						flagForButtonPress1s [i] = 1;
						TimerForKeyPress = LONG_PRESS_TIME;

				}
			}
		else{
			TimerForKeyPress--;
				if(TimerForKeyPress <= 0){
					if(debounceButtonBuffer3[i] == PRESSED_STATE){
						flagForButtonPress1s[i] = 1;
					}
				TimerForKeyPress = SHORT_PRESS_TIME;
				}
			}
		}
	}
}







