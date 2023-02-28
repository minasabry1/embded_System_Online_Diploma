/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 

#define F_CPU 1000000UL
#include "HAL/LCD_DRIVER/LCD.h"
#include "MCAL/Include/PORT_DDR.h"
#include "util/delay.h"

void wait(int t)
{
	int i , j;
	for(i = 0 ; i < t ; i++)
	for(j = 0 ; j < 255 ; j++);
}

int main(void)
{	
	//Port_Mode(PORTA,OUTPUT);
	LCD_clear_screen();
	LCD_init();
	LCD_Send_A_String("Learn in Depth ..");



	/* Replace with your application code */
	while (1)
	{

	}
}

