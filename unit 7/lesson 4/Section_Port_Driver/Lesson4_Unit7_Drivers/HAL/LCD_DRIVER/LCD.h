/*
 * LCD.h
 *
 * Created: 2/15/2023 7:59:35 PM
 *  Author: minas
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU 1000000UL
#include "util/delay.h"
#include <avr/io.h>

#include <stdlib.h>
#include <stdio.h>

// #define LCD_PORT				*((uint8_t *)(0x3B)) //Data pins of LCD connected to all portA Pins
// #define LCD_Port_Direction		*((uint8_t *)(0x3A))
// 
// #define LCD_Control				*((uint8_t *)(0x38)) //Control pins of LCD connected PortB
// #define LCD_Control_Direction	*((uint8_t *)(0x37))

#define LCD_PORT					PORTA //Data pins of LCD connected to all portA Pins
#define LCD_Port_Direction			DDRA

#define LCD_Control					PORTB //Control pins of LCD connected PortB
#define LCD_Control_Direction		DDRB


#define RS_SWITCH			1
#define RW_SWITCH			2
#define Enable_Switch		3
#define DATA_shift			4 // in 8 bit mode 0 and in 4 bit mode 4 
//#define Eight_Bit_Mode
#define Four_Bit_Mode

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick (void);
void LCD_Send_A_Command(unsigned char command);
void LCD_Send_A_Character(unsigned char character);
void LCD_Send_A_String(char *string);
void LCD_init(void);
void LCD_clear_screen ();
void LCD_GotoXY(unsigned char line, unsigned char position );
void LCD_display_number (int Number );
void LCD_display_real_number (double  Number );


#endif /* LCD_H_ */