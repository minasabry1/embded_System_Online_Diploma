/*
 * GccApplication1.c
 *
 * Created: 2/12/2023 1:56:50 AM
 * Author : minas
 */ 


#include "Memory_Map.h"
#include "Utiltes.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	int i=0;
	int j=7;
    /* Replace with your application code */
    while (1) 
    {
		for(i;i<8;i++){
		Set_Bit(DDRA,i);
		Set_Bit(PORTA,i);
		_delay_ms(500);
    }
	    for (j = 7; j >= 0; j--)
	    {
		    Clear_Bit(PORTA, j);
		    _delay_ms(500);
	    }
//	Clear_Bit(PORTA,7);
	//_delay_ms(500);
	//Clear_Bit(PORTA,6);
	//_delay_ms(500);
	//Clear_Bit(PORTA,5);
	//_delay_ms(500);
	//Clear_Bit(PORTA,4);
	//_delay_ms(500);
	//Clear_Bit*/(PORTA,3);
	//_delay_ms(500);
	//Clear_Bit(PORTA,2);
	//_delay_ms(500);
	//Clear_Bit(PORTA,1);
	//_delay_ms(500);
	//Clear_Bit(PORTA,0);
	//_delay_ms(500);
	}
}

