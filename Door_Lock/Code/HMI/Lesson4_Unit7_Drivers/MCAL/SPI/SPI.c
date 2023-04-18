/*
 * SPI.c
 *
 * Created: 3/11/2023 4:13:57 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\SPI.h"
void Spi_init(uint8_t Mode){
	if(Mode ==1){
	SPCR |=(1<<MSTR);//emable master
	
	/*• Bit 3 – CPOL: Clock Polarity
	When this bit is written to one, SCK is high when idle. When CPOL is written to zero, SCK is low
	when idle*/
	SPCR &=(~(1<<CPOL));	
	}else{
		SPCR &=(~(1<<MSTR)); //enable slave
	}
	SPCR |=(1<<SPE);//enable spi
	//Speed =2MHZ-->8/4=2MHz === SPR0&SPR1=0.
	speed_init(Divides_By_4);
	
}

void speed_init(enum speed s){
	switch (s){
	case 0:
	SPCR &=(~(1<<SPR0));
	SPCR &=(~(1<<SPR1));
	break;
	case 1:	
	SPCR |=((1<<SPR0));
	SPCR &=(~(1<<SPR1));
	break;
	case 2:
	SPCR |=((1<<SPR1));
	SPCR &=(~(1<<SPR0));
	break;
	case 3:
	SPCR |=((1<<SPR1));
	SPCR |=((1<<SPR0));
	break;
	case 4:
	SPCR &=(~(1<<SPR0));
	SPCR &=(~(1<<SPR1));
	SPSR |=((1<<SPI2X));
	break;
	case 5:
	SPCR |=((1<<SPR0));
	SPCR &=(~(1<<SPR1));
	SPSR |=((1<<SPI2X));
	case 6:	
	SPCR |=((1<<SPR1));
	SPCR &=(~(1<<SPR0));
	SPSR |=((1<<SPI2X));	
		}
	}
	
uint8_t SPI_Transmit_Recieve(uint8_t Data)
{
	/* Start transmission */
	SPDR = Data;
	/* Wait for transmission complete .
	The SPIF (SPI Interrupt Flag) bit in the SPI Status Register (SPSR) is set to 1 after a data transfer is completed on the SPI interface.*/
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}	