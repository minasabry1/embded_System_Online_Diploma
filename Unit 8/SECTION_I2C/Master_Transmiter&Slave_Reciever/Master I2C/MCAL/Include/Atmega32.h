/*
 * Atmega32.h
 *
 * Created: 23/2/2023 7:31:54 PM
 *  Author: Mina Sabry
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "stdint.h"

/*******************************************************************************
                 General Purpose Input Output Peripheral (GPIO)
*******************************************************************************/

#define PORTA	*((uint8_t *)(0x3B))
#define DDRA	*((uint8_t *)(0x3A))
#define PINA	*((uint8_t *)(0x39))

#define PORTB	*((uint8_t *)(0x38))
#define DDRB	*((uint8_t *)(0x37))
#define PINB	*((uint8_t *)(0x36))

#define PORTC	*((uint8_t *)(0x35))
#define DDRC	*((uint8_t *)(0x34))
#define PINC	 *((uint8_t *)(0x33))

#define PORTD	 *((uint8_t *)(0x32))
#define DDRD	 *((uint8_t *)(0x31))
#define PIND	 *((uint8_t *)(0x30))

/************************************** ADC-Registers *******************************************/
#define ADMUX   (*(volatile Uint8t*) (0x27))
#define ADCSRA  (*(volatile Uint8t*) (0x26))
#define ADCH    (*(volatile Uint8t*) (0x25))
#define ADCL    (*(volatile Uint8t*) (0x24))
#define ADC_DTA (*(volatile Uint16t*)(0x24))
/************************************** INTERRUPT-Registers *******************************************/
#define SREG    (*(volatile Uint8t*) (0x5F))
#define GICR    (*(volatile Uint8t*) (0x5B))
#define GIFR    (*(volatile Uint8t*) (0x5A))
#define MCUCR   (*(volatile Uint8t*) (0x55))
#define MCUCSR  (*(volatile Uint8t*) (0x54))
/************************************** TIMER0-Registers *********************************************/
#define TCNT0  (*(volatile Uint8t*) (0x52))
#define TCCR0  (*(volatile Uint8t*) (0x53))
#define TIMSK  (*(volatile Uint8t*) (0x59))
#define OCR0   (*(volatile Uint8t*) (0x5C))


//-------------------------------------------------------------
//		   			USART Registers
//-------------------------------------------------------------

#define UDR							(*(uint8_t *)0x2C)
#define UCSRA						(*(uint8_t *)0x2B)
#define UCSRB						(*(uint8_t *)0x2A)
#define UCSRC						(*(uint8_t *)0x40)
#define UBRRH						(*(uint8_t *)0x40)
#define UBRRL						(*(uint8_t *)0x29)

// USART Control and Status Register A
#define MPCM		0				//Multi-processor Communication Mode
#define U2X			1				// Double the USART Transmission Speed
#define PE			2				// Parity Error
#define DOR			3				// Data overrun
#define FE			4				// Frame Error
#define UDRE		5				// Data Register Empty
#define TXC			6				// Transmit Complete
#define RXC			7				//Recieve Complete


// USART Control and Status Register B
#define TXB8		0
#define RXB8		1
#define UCSZ2		2				//Character Size
#define TXEN		3
#define RXEN		4
#define UDRIE		5
#define TXCIE		6				//Interrupt Enable
#define RXCIE		7				//Interrupt Enable


// USART Control and Status Register C
#define UCPOL		0				//Clock Polarity
#define UCSZ0		1				//Character Size
#define UCSZ1		2
#define USBS		3				//Stop Bit Select
#define UPM0		4				//Parity Mode
#define UPM1		5
#define UMSEL		6		// Mode Select
#define URSEL		7		// Register Select
#endif /* ATMEGA32_H_ */