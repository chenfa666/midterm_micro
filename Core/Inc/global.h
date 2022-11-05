/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET
#define NUMBER_OF_DECIMAL_DIGITS			10
#define	NUMBER_OF_SEVEN_SEGMENT_LEDS		4
#define	NUMBER_OF_BUTTONS		3
#define LONG_PRESS_TIME 300
#define RESET 0
#define INC 1
#define DEC 2
#define MAXIMUM_VALUE 9
#define MINIMUM_VALUE 0
#define STANDBY_TIME 10000
#define SHORT_PRESS_TIME 100
#define ONE_SECOND 1000
#define HALF_OF_ONE_SECOND 500
#define CLEAR 0
#define WRITTEN 1
extern int VALUE;
#define DURATION_FOR_AUTO_INCREASING 200
#endif /* INC_GLOBAL_H_ */
