/*
 * SPI.c
 *
 * Created: 3/10/2023 8:23:52 PM
 * Author : minas
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL
#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

void Spi_Master_Init(void){
		//Bit 7 – SPIE: SPI Interrupt Enable
		//Bit 6 – SPE: SPI Enable
		/*Bit 5 – DORD: Data Order
		When the DORD bit is written to one, the LSB of the data word is transmitted first.
		When the DORD bit is written to zero, the MSB of the data word is transmitted first.
		Bit 4 – MSTR: Master/Slave Select
		This bit selects Master SPI mode when written to one, and Slave SPI mode when written logic zero.
		*/
		
		//// Set MOSI, SCK and SS as Output Pins
	DDRB = (1<<SS)|(1<<MOSI)|(1<<SCK);
		/* Set MISO input */
		DDRB &= ~(1<<MISO);
	// Enable SPI, Master mode, Shift Clock = CLK /16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); 
}

unsigned char Spi_Master_Transmiti(unsigned char cdata){
	PORTB &= ~(1 << SS);
	SPDR =cdata;	// Start transmission
	while(!(SPSR & (1<<SPIF)));	// Wait for transmission complete ..IF 0 Them still Transmit Data
	return SPDR;	// return the received data
}	
int main(void)
{
	Spi_Master_Init();
	DDRA=0xFF;
	unsigned char data;
	
	for (data=0;data <=255;data++)
	{
		_delay_ms(1000);
		PORTA=Spi_Master_Transmiti(data);
	}
 
}

 