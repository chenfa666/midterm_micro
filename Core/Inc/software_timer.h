/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: chivz
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer1_counter;
extern int timer2_flag;
extern int timer2_counter;
extern int time_out_counter;
extern int time_out_flag;
void setTimer1(int duration);
void TimerRun();
void checkCountDown();
void timeOutChecker();
#endif /* INC_SOFTWARE_TIMER_H_ */
