/*
 * State.h
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */

#ifndef CA_STATES_H_
#define CA_STATES_H_
#include <stdio.h>
#include <stdlib.h>
#define State_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_
void US_Set_Distance(int Distance);
void DC_motor(int Speed);
#endif /* CA_STATES_H_ */
