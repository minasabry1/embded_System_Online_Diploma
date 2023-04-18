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

#define PORTA	*((volatile uint8_t *)(0x3B))
#define DDRA	*((volatile uint8_t *)(0x3A))
#define PINA	*((volatile uint8_t *)(0x39))

#define PORTB	*((volatile uint8_t *)(0x38))
#define DDRB	*((volatile uint8_t *)(0x37))
#define PINB	*((volatile uint8_t *)(0x36))

#define PORTC	*((volatile uint8_t *)(0x35))
#define DDRC	*((volatile uint8_t *)(0x34))
#define PINC	*((volatile uint8_t *)(0x33))

#define PORTD	 *((volatile uint8_t *)(0x32))
#define DDRD	 *((volatile uint8_t *)(0x31))
#define PIND	 *((volatile uint8_t *)(0x30))

/************************************** ADC-Registers *******************************************/
#define ADMUX   (*(volatile uint8_t*) (0x27))
#define ADCSRA  (*(volatile uint8_t*) (0x26))
#define ADCH    (*(volatile uint8_t*) (0x25))
#define ADCL    (*(volatile uint8_t*) (0x24))
#define ADC_DTA (*(volatile uint8_t*)(0x24))
/************************************** INTERRUPT-Registers *******************************************/
#define SREG    (*(volatile uint8_t*) (0x5F))
#define GICR    (*(volatile uint8_t*) (0x5B))
#define GIFR    (*(volatile uint8_t*) (0x5A))
#define MCUCR   (*(volatile uint8_t*) (0x55))
#define MCUCSR  (*(volatile uint8_t*) (0x54))
/************************************** TIMER0-Registers *********************************************/
#define TCNT0  (*(volatile uint8_t*) (0x52))
#define TCCR0  (*(volatile uint8_t*) (0x53))
#define TIMSK  (*(volatile uint8_t*) (0x59))
#define OCR0   (*(volatile uint8_t*) (0x5C))
/************************************** ADC-Registers *********************************************/
#define SFIOR  (*(volatile uint8_t*) (0x50))
#define ADMUX  (*(volatile uint8_t*) (0x27))
#define ADCSRA (*(volatile uint8_t*) (0x26))
#define ADCH   (*(volatile uint8_t*) (0x25))
#define ADCL   (*(volatile uint8_t*) (0x24))

/************************************** Watch_Dog-Registers *********************************************/
#define WDTCR  (*(volatile unsigned char*) (0x41))

//-------------------------------------------------------------
//		   			USART Registers
//-------------------------------------------------------------

#define UDR							(*(volatile uint8_t *)0x2C)
#define UCSRA						(*(volatile uint8_t *)0x2B)
#define UCSRB						(*(volatile uint8_t *)0x2A)
#define UCSRC						(*(volatile uint8_t *)0x40)
#define UBRRH						(*(volatile uint8_t *)0x40)
#define UBRRL						(*(volatile uint8_t *)0x29)

//-------------------------------------------------------------
//		   			I2C Registers
//-------------------------------------------------------------

#define TWDR						(*(volatile uint8_t *)0x2C)
#define TWAR						(*(volatile uint8_t *)0x23)
#define TWCR						(*(volatile uint8_t *)0x56)
#define TWSR						(*(volatile uint8_t *)0x21)
#define TWBR						(*(volatile uint8_t *)0x20)

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

//WatchDog
#define WDP0		0			
#define WDP1		1				
#define WDP2		2
#define WDE			3				
#define WDTOE		4

//Timer --- TCCR0
#define CS00		0
#define CS01		1
#define CS02		2
#define WGM01		3
#define COM00		4
#define COM01		5
#define WGM00		6
#define FOC0		7

//Timer --- TIMSK
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5
#define TOIE2		6
#define OCIE2		7


//I2C --- TWCR
#define TWIE		0
#define TWEN		2
#define TWWC		3
#define TWSTO		4
#define TWSTA		5
#define TWEA		6
#define TWINT		7

//I2C --- TWSR
#define TWPS0		0
#define TWPS1		1
#define TWS3		3
#define TWS4		4
#define TWS5		5
#define TWS6		6
#define TWS7		7
				
#endif /* ATMEGA32_H_ */