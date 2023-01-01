/*
 * DC.c
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#include "DC.h"

int DC_Speed=0;
//states ptrs to funcs.
void (*DC_state )();
void DC_init(){
	printf("\n DC_init");
}
void DC_motor(int Speed){
	DC_Speed=Speed;
	DC_state=STATE(DC_busy);
	printf("CA ----Speed=%d----> DC \n",DC_Speed);

}
State_define(DC_idle)
{
	//State Name
	DC_Status_id=DC_idle;
	//State Action
	//Call pwm to make speed=DC_Speed

	printf("\n DC_idle= Speed=(%d)\n",DC_Speed);
}
State_define(DC_busy)
{

	//State Name
	DC_Status_id =DC_busy;
	//State Action
	//Call pwm to make speed=DC_Speed
	DC_Status_id=DC_idle;
	printf("\n DC_busy= Speed=(%d)\n",DC_Speed);


}


