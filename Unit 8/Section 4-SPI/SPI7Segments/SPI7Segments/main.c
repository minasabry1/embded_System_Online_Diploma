/*
 * SPI7Segments.c
 *
 * Created: 3/10/2023 10:28:09 PM
 * Author : minas
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define SCK 7


void SPI_MasterInit()
{
	/* Set MOSI, SCK and SS output*/	
	DDRB |= (1 << MOSI) | (1 << SS) | (1 << SCK);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR |= (1 << MSTR) | (1 << SPE) | (1 << SPR0);	
}

void execute(unsigned char command, unsigned char Data)
{
	PORTB &= ~(1 << SS);
	SPDR = command;
	while (!(SPSR & (1 << SPIF)));
	SPDR = Data;
	while (!(SPSR & (1 << SPIF)));
	PORTB |= (1 << SS);
}

int main(void)
{
    /* Replace with your application code */
	unsigned char counter = 0;
	unsigned char index_display;
	SPI_MasterInit();
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
    while (1) 
    {
		for (index_display = 1; index_display < 9; index_display++)
			execute(index_display, counter++);
		_delay_ms(1000);
    }
}



