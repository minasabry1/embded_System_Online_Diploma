/*
 * SPI.h
 *
 * Created: 3/11/2023 4:13:29 PM
 *  Author: minas
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\PORT_DDR.h"



#define F_CPU 8000000UL
#define MASTER	1
#define SLAVE	2
//#define SPI_MODE MASTER
//#define SPI_MODE SLAVE
enum speed{
	Divides_By_4,
	Divides_By_16,
	Divides_By_64,
	Divides_By_128,
	Divides_By_2,
	Divides_By_8,
	Divides_By_32,
	};

void Spi_init(uint8_t Mode);
void speed_init(enum speed s);
uint8_t SPI_Transmit_Recieve(uint8_t Data);

#endif /* SPI_H_ */