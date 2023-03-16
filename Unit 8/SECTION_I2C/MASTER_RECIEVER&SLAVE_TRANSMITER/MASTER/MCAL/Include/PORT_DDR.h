/*
 * GPIO.h
 *
 * Created: 23/2/2023 7:31:54 PM
 *  Author: Mina Sabry
 */ 

/*******************************************************************************
                                     Includes
 *******************************************************************************/
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"

#ifndef GPIO_H_
#define GPIO_H_

//@ref 1
#define INPUT			0
#define OUTPUT			1
#define INPUT_PULLUP	3
#define INPUT_PULLDOWN	4

//@ref 2
#define LOW				0
#define HIGH			1

//@ref 3
typedef enum
{
	PIN_0 ,
	PIN_1 ,
	PIN_2 ,
	PIN_3 ,
	PIN_4 ,
	PIN_5 ,
	PIN_6 ,
	PIN_7 ,
	}PINS;
	
//@ref 4
typedef enum
{
	PORT_A ,
	PORT_B ,
	PORT_C ,
	PORT_D ,
}PORTS;

/********************************************************************************************
			 All ports and pins should be selected from @ref 3 & @ref 4
*********************************************************************************************/
   
void Pin_Mode(PORTS PORT , PINS PIN , uint8_t mode); // Mode must be set from @ref 1
void Write_On_Specific_Bit(PORTS PORT , PINS PIN , uint8_t value); // Value must be set from @ref 1
void Toggle_Specific_Bit(PORTS PORT , PINS PIN);
uint8_t Read_Specific_Bit(PORTS PORT , PINS PIN);

void Port_Mode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void Port_Write(PORTS PORT , uint8_t value); // Value must be set from @ref 1
void Port_Toggle(PORTS PORT);
uint8_t Port_Read(PORTS PORT);

// For deal with 4 most bits or 4 lowest bits
void MSB_Port_Mode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void MSB_Port_Write(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t MSB_Port_Read(PORTS PORT);

void LSB_Port_Mode(PORTS PORT , uint8_t mode); // Mode must be set from @ref 1
void LSB_Port_Write(PORTS PORT , uint8_t value); // Value must be set from @ref 1
uint8_t LSB_Port_Read(PORTS PORT);

#endif /* GPIO_H_ */