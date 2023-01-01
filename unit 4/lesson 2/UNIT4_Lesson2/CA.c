/*
 * CA.c
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#include "CA.h"

int CA_Speed=0;
int CA_Distance=0;
int CA_Threshold =50;

//states ptrs to funcs.
void (*CA_state )();
void US_Set_Distance(int Distance){
	CA_Distance=Distance;
	(CA_Distance <= CA_Threshold)?(CA_state= STATE(CA_waitng)):(CA_state=STATE(CA_driving));
	printf("US ----distance=%d----> CA",CA_Distance);
}

State_define(CA_waitng){
	//State Name
	CA_Status_id=CA_WAITING;
	printf("\n CA_WAITING= Speed=(%d) Distance(%d) \n",CA_Speed,CA_Distance);
	//State Action
	CA_Speed=0;
	DC_motor(CA_Speed);

}
State_define(CA_driving)
{

	//State Name
	CA_Status_id =CA_DRIVING;
	printf("\n CA_DRIVING= Speed=(%d) Distance(%d) \n",CA_Speed,CA_Distance);
	//State Action
	CA_Speed=30;
	DC_motor(CA_Speed);

}



