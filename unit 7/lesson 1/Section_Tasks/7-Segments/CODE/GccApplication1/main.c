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
 //7-Segments
static unsigned char SEGMENT_PATTERN[] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

int main(void)
{
	int i,j;
	for(i=0;i<=7;i++){
		Set_Bit(DDRA,i);
	}
	for(i=0;i<=7;i++){
		Set_Bit(DDRC,i);
	}
	Clear_Bit(DDRD,0);//Pin 0>>PortD>>Input
	Set_Bit(PORTD,0);//PullUP
	
    /* Replace with your application code */
    while (1) 
    {
	    for(i=0;i<=9;i++){
			for(j=0;j<=9;j++){
				PORTC = (0b10<<2)| (i<<4);//ON 1st 7-Segments
				_delay_ms(300);
				PORTC = (0b01<<2)| (j<<4);//ON 2nd 7-Segments
				_delay_ms(300);(100);
			}
			
		}

	}
}

