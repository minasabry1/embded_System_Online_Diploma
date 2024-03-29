/*
 * LCD.h
 *
 * Created: 2/15/2023 7:59:35 PM
 *  Author: minas
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000UL
#include <stdlib.h>
#include <stdio.h>
#include "Stm32_f103c6_Drivers_Gpio.h"
#include "Stm32f103x6.h"

#define LCD_PORT 			GPIOA_Base
#define LCD_Control 		GPIOA_Base
#define Enable_Switch 		GPIO_PIN_10
#define RW_SWITCH 			GPIO_PIN_9
#define RS_SWITCH 			GPIO_PIN_8

//#define DATA_shift 4 // in 8 bit mode 0 and in 4 bit mode 4
//#define Eight_Bit_Mode
//#define Four_Bit_Mode

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
void LCD_Send_String(char *string);
void LCD_init(void);
void LCD_clear_screen ();
void LCD_GotoXY(unsigned char line, unsigned char position );
void LCD_display_number (int Number );
void LCD_display_real_number (double  Number );


#endif /* LCD_H_ */
