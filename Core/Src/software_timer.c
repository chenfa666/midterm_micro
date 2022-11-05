/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_

#include "main.h"


int timer1_counter = HALF_OF_ONE_SECOND;
int timer1_flag = CLEAR;
int timer2_counter = ONE_SECOND;
int timer2_flag = CLEAR;
int time_out_counter = STANDBY_TIME;
int time_out_flag = CLEAR;
void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = CLEAR;
}
void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = CLEAR;
}

void checkBlinkLed(){
	if(timer1_flag == WRITTEN){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer1(HALF_OF_ONE_SECOND);
	}
}
void checkStandBy(){
	if(timer2_flag == WRITTEN){
		if(time_out_flag == WRITTEN){
			if(VALUE == 0){
				display7SEGMENT(VALUE);
			}
			else{
				VALUE--;
				display7SEGMENT(VALUE);
			}
		}
		setTimer2(ONE_SECOND);
	}
}
void TimerRun(){
	if( timer1_counter > 0){
		timer1_counter = timer1_counter - 10;
		if(timer1_counter <= 0){
			timer1_flag = WRITTEN;
		}
	}
	if( timer2_counter > 0){
			timer2_counter = timer2_counter - 10;
			if(timer2_counter <= 0){
				timer2_flag = WRITTEN;
			}
	}
	if(time_out_counter > 0){
	time_out_counter = time_out_counter - 10;
		if(time_out_counter == 0){
			if (VALUE!=0){
				time_out_flag = WRITTEN;
			}
		time_out_counter = STANDBY_TIME;
		}
	}
	checkStandBy();
	checkBlinkLed();

}


#endif /* SRC_SOFTWARE_TIMER_C_ */
