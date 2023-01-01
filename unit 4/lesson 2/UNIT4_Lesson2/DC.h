/*
 * CA.h
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#ifndef DC_H_
#define DC_H_
#include "State.h"
enum{
	DC_idle,
	DC_busy
}DC_Status_id;

//declare state functions.
State_define(DC_idle);
State_define(DC_busy);
void DC_init();
//states ptrs to funcs.
extern void (*DC_state )();

#endif /* DC_H_ */
