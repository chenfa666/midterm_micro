/*
 * fsm_init.c
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#include "fsm_init.h"

int VALUE = 0;
int status = 0;

void fsm_simple_buttons_run () {
	if(isPressedButton() == 1){
		switch(status){
			case RESET:
			{
				VALUE = MINIMUM_VALUE;
				display7SEGMENT(VALUE);
				time_out_counter = STANDBY_TIME;
				time_out_flag = CLEAR;
				break;
			}
			case INC:
			{
				if(VALUE == MAXIMUM_VALUE) {
					VALUE = MINIMUM_VALUE;
				}
				else {
					VALUE++;
				}
				time_out_flag = CLEAR;
				time_out_counter = STANDBY_TIME;
				display7SEGMENT(VALUE);
				break;
			}
			case DEC:
			{
				if(VALUE == MINIMUM_VALUE) {
					VALUE = MAXIMUM_VALUE;
				}
				else {
					VALUE--;
				}
				time_out_flag = CLEAR;
				time_out_counter = STANDBY_TIME;
				display7SEGMENT(VALUE);
				break;

			}
		}
	}
}
