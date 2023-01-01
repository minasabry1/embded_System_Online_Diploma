/*
 * US.c
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#include "US.h"
int US_Distance=0;
//states ptrs to funcs.
void (*US_state )();
int US_get_distance_random( int min , int max , int count );
void US_init(){
	printf("US_init \n");
}
State_define(US_busy)
{
	//State Name
	US_Status_id=US_busy;
	//State Action
	US_Distance=US_get_distance_random(45,55,1);
	printf("\n US_WAITING=Distance(%d) \n",US_Distance);
US_Set_Distance(US_Distance);
US_state=STATE(US_busy);

}

int US_get_distance_random( int min , int max , int count ){
	//generate random value between min and max
	for ( int i=0 ; i<count ; i++ )
	{
		int rand_num = (rand() % ( max - min + 1 )) + min ;
		return rand_num ;
	}
}



