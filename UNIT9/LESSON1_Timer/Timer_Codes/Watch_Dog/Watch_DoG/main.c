/*
 * Watch_DoG.c
 *
 * Created: 3/27/2023 5:07:01 PM
 * Author : minas
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define Set_Bit(PORT,Bit)       PORT |=  (1<<Bit)		// Set pin
#define Reset_Bit(PORT,Bit)     PORT &= ~(1<<Bit)		// Reset pin
#define Toggle_Bit(PORT,Bit)    PORT ^=  (1<<Bit)		// Toggle pin
#define Read_Bit(PORT,Bit)     ((PORT >> Bit) & 1)		// Read from pin

#define LED_DDR				DDRC
#define LED_PORT			PORTC
#define Pin_Number			0

	void WDT_OFF(void){
		WDTCR |= (1<<WDTOE)|(1<<WDE);
		WDTCR =0x00;
	}

	void WDT_ON(void){
		WDTCR |= (1 << WDP1) | (1 << WDP2) | (1 << WDE);
		Reset_Bit(WDTCR,WDP0);
	}
int main(void)
{
    Set_Bit(LED_DDR,Pin_Number);//Output pin 0
	_delay_ms(500);
    while (1) 
    {
		WDT_ON();//Reset if CPU stuck.
		Toggle_Bit(LED_PORT,Pin_Number);
		_delay_ms(2000);
		WDT_OFF();
		
    }
}

