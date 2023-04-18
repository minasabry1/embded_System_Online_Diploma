/*
 * Watch_Dog.c
 *
 * Created: 3/27/2023 9:30:26 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\WDG.h"


void WDT_OFF(void){
	WDTCR |= (1<<WDTOE)|(1<<WDE);
	WDTCR =0x00;
}

void WDT_ON(void){
	WDTCR |= (1 << WDP1) | (1 << WDP2) | (1 << WDE);
	Reset_Bit(WDTCR,WDP0);
}