/*
 * US.h
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#ifndef US_H_
#define US_H_
#include "State.h"
enum{
	US_busy,
}US_Status_id;

//declare state functions.
State_define(US_busy);
void US_init();

//states ptrs to funcs.
extern void (*US_state )();

#endif /* US_H_ */
