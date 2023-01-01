/*
 * CA.h
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#ifndef CA_H_
#define CA_H_
#include "State.h"
enum{
	CA_WAITING,
	CA_DRIVING
}CA_Status_id;

//declare state functions.
State_define(CA_waitng);
State_define(CA_driving);
//states ptrs to funcs.
extern void (*CA_state )();

#endif /* CA_H_ */
