/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern uint16_t buttonDataPin[];
extern GPIO_TypeDef * buttonDataPort[];
extern int status;

void getKeyInput();
int isPressedButton();
void button_reading();

#endif /* INC_BUTTON_H_ */
