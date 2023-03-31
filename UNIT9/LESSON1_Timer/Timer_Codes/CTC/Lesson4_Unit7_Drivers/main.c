/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 


#define F_CPU 8000000UL
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CTC.h"
#include <util/delay.h>

extern Over_Flow_Number;
void Over_Flow(void){
	Toggle_Bit(PORTC,0);
	_delay_ms(500);
	PORTA =Over_Flow_Number;
}

int main(void)
{
	Set_Bit(DDRC,0);
	DDRA = 0xFF;
	sei();
	TIMER0_CALLBACK_CompareMatch_INTERRUPT(Over_Flow);
	Timer_Config_t Config={CTC,TOIE_DISABLE,OCIE_ENABLE,PRESCALING_CLK8};
	TIMER0_GetCompare(0xF0);	
	TIMER0_Init(&Config);
		
	while (1)
	{
	}
}


