/*
 * main.c
 *
 *  Created on: Dec 30, 2022
 *      Author: minas
 */
#include "CA.h"
#include "DC.h"
#include "US.h"
void setup(void)
{
	// init all the drivers
	// init IRQ ....
	// init HAL US_Driver DC_Driver
	// init BLOCK
	// Set States pointers for each block
	US_init();
	DC_init();
	CA_state= STATE(CA_waitng);
	US_state= STATE(US_busy);
	DC_state= STATE(DC_idle);
	//this pts not meaning to jump
}

int main(void)
{
	volatile int d;
	setup();

	while(1)
	{
		US_state();
		CA_state(); //here we jump but wont be overflow why?because since we at waiting time not new stack creating and once we done this stack is deleted and going to main.
		DC_state();
		// Call state for each block
		// Delay
		for(d=0;d <=1000;d++);
	}
	return 0;
}


