/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 

#define F_CPU  8000000UL
#include <avr/io.h>
#include "HAL/LCD_DRIVER/LCD.h"
//#include "MCAL/Include/PORT_DDR.h"
//#include "util/delay.h"
// #include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\UART.h"
//#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\SPI.h"

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7

int main(void)	
{
		/* Set MOSI, SCK and SS output, all others input */
		DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
		/* Set MISO input */
		DDRB &= ~(1<<MISO);
			unsigned char ch = 0;
	DDRA = 0xFF;
	Spi_init(1);
	
		for (ch = 0; ch <= 255; ch++)
		{
			_delay_ms(1000);
			PORTA = SPI_Transmit_Recieve(ch);
		}
	
}

