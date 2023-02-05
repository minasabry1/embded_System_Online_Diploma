/*
 * main.c
 *
 *  Created on: Feb 3, 2023
 *      Author: minas
 */
#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>

//Base Addresses
#define IO_Base  0x20

//Define Registers at 2 bits
//The Global Interrupt Enable bit must be set for the interrupts to be enabled.
#define SREG (*(volatile unsigned int*)(IO_Base+ 0x3f))

/* MCUCR
 * 01 Any logical change on INT1 generates an interrupt request.
   10 The falling edge of INT1 generates an interrupt request.*/
#define MCUCR (*(volatile unsigned int*)(IO_Base+ 0x35))


/*MCUCSR
Bit 6 – ISC2: Interrupt Sense Control 2
The Asynchronous External Interrupt 2 is activated by the external pin INT2
if the SREG I-bit and
the corresponding interrupt mask in GICR are set.
 */
#define MCUCSR (*(volatile unsigned int*)(IO_Base+ 0x34))

/*GICR
 Bit 7 – INT1: External Interrupt Request 1 Enable
  Bit 6 – INT0: External Interrupt Request 0 Enable*/
#define GICR (*(volatile unsigned int*)(IO_Base+ 0x3B))

/*Bit 6 – INTF0: External Interrupt Flag 0
  Bit 7 – INTF1: External Interrupt Flag 1
  Bit 5 – INTF2: External Interrupt Flag 2
 */
#define GIFR (*(volatile unsigned int*)(IO_Base+ 0x3A))

/*DDRD  >>0 As Onput -->>1 As Output
  PORTD >>Used As Output
  PIND  >>Used As Input
 */
#define DDRD (*(volatile unsigned int*)(IO_Base+ 0x11))
#define PORTD (*(volatile unsigned int*)(IO_Base+ 0x12))
#define PIND (*(volatile unsigned int*)(IO_Base+ 0x10))

void INTERRUPT_DRIVER(void){
	SREG |=(1<<7); //Enable Global Register
	GICR |=(1<<6); //INT0 Enable
	GICR |=(1<<7); //INT1 Enable
	GICR |=(1<<5); //INT2 Enable

	MCUCSR |=(1<<6); //INT2 Enable
	MCUCR |=(0b11<<0);//Rising INT0
	MCUCR |=(0b10<<0);//Falling INT0
	MCUCR |=(0b11<<2);//Rising INT1
	MCUCR |=(0b10<<2);//Falling INT1


}

ISR(INT0_vect)
{    PORTD |= (1<<5); // Turn on LED
     _delay_ms(500);   // Delay for 1 second
     PORTD &= ~(1<<5); // Turn off LED
     GIFR |= (1<<6);   // Clear the interrupt flag
}

ISR(INT1_vect)
{
	PORTD |= (1<<6); // Turn on LED
	_delay_ms(500);  // Delay for 1 second
	PORTD &= ~(1<<6);// Turn off LED
	GIFR |= (1<<7);  // Clear the interrupt flag
}

ISR(INT2_vect)
{    PORTD |= (1<<7); // Turn on LED
     _delay_ms(500);  // Delay for 1 second
     PORTD &= ~(1<<7);// Turn off LED
     GIFR |= (1<<5);  // Clear the interrupt flag
}
int main(void){

	// Define the direction of the pins as input
	DDRD &= ~(1<<2); // INT0 as input
	DDRD &= ~(1<<3); // INT1 as input
	DDRD &= ~(1<<7); // INT2 as input
	// Define the direction of the pins as output
	DDRD |= (1<<5); // LED 1 as output
	DDRD |= (1<<6); // LED 2 as output
	DDRD |= (1<<7); // LED 3 as output
	//To enable Global interrupt
	sei();
	INTERRUPT_DRIVER();

	while(1)
	{
		//Turn LEDs off
		PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
	}


}
