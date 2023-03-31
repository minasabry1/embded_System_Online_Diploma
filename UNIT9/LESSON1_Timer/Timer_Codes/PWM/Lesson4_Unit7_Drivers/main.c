/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 


#define F_CPU 8000000UL
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\PWM.h"
#include <util/delay.h>

extern PWM_Over_Flow_Number;
extern PWM_Compare_Number;

	void Compare_Func(void){
		Toggle_Bit(PORTB,0);
		_delay_ms(100);	
		PORTA =PWM_Compare_Number;
	}
	void Over_Flow_Func(void){
		Toggle_Bit(PORTB,1);
		_delay_ms(100);
		PORTC =PWM_Over_Flow_Number;
	}

	int main(void)
	{
		DDRA =0xFF;
		DDRB=0xFF;
		DDRC=0xFF;
		DDRD=0xFF;		

		volatile uint8_t value;
		PWM0_GetCompare(&value);
		PORTD=value;
		
		sei();
		PWM0_CALLBACK_CompareMatch_INTERRUPT(Compare_Func);
		PWM0_CALLBACK_Overflow_INTERRUPT(Over_Flow_Func);
		PWM_t Config={Phase_Coreect_PWM,TOIE_ENABLE,OCIE_ENABLE,PRESCALING_CLK8,PWM_Non_INVERTING};
		PWM0_SetCompare(0x7F);	
		PWM0_Init(&Config);
		
		while (1)
		{
			
		}
	}


