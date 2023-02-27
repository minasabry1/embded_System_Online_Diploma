/*
 * LCD.c
 *
 * Created: 2/15/2023 7:59:51 PM
 *  Author: minas
 */ 
#include "LCD.h"
void LCD_clear_screen (){//clears the LCD screen.
	
	LCD_Send_A_Command(LCD_CLEAR_SCREEN);
}
void LCD_lcd_kick (void){//sends a pulse to the EN pin of the LCD to initiate a data transfer.
	//Enable read at Falling(H>>L)
	
	LCD_Control |= (1<<Enable_Switch);
	_delay_ms(50);
	 LCD_Control &= ~(1<<Enable_Switch);
		
}
void LCD_GOTO_XY(unsigned char line, unsigned char position){// positions the cursor at the specified line and position on the LCD screen.
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_Send_A_Command(LCD_BEGIN_AT_SECOND_RAW+position);
		}
	}
}



void LCD_check_lcd_isbusy(void){//checks whether the LCD is busy processing a command or data transfer.
	// initializes the LCD display with the required settings.
	LCD_Port_Direction &= ~(0xFF<<DATA_shift); //DDRA>>(INPUT)Read Mode
	LCD_Control |=(1<<RW_SWITCH); //RW ON
	LCD_Control &=~(1<<RS_SWITCH); //RS OFF
    LCD_lcd_kick(); //Enable
	
		#ifdef EIGHT_BIT_MODE
		LCD_Port_Direction |=  (0xFF<<DATA_shift);
		#endif
		
		#ifdef FOUR_BIT_MODE
		LCD_Port_Direction |=  (0xF0<<DATA_shift);
		#endif
	//LCD_Port_Direction |= (0xFF<<DATA_shift);; //DDRA>>Output Mode
	LCD_Control &=~(1<<RW_SWITCH);//Rest
}

void LCD_init(void){//initializes the LCD display with the required settings.
	_delay_ms(20);
	LCD_check_lcd_isbusy();
	LCD_Control_Direction |= (1<<Enable_Switch | 1<<RW_SWITCH | 1<<RS_SWITCH);//DDRB>>OUTPUT (Enable,RS,RW)
	LCD_Control &= ~(1<<Enable_Switch | 1<<RS_SWITCH | 1<<RW_SWITCH);//PortB
	LCD_Port_Direction =0xFF;
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef Eight_Bit_Mode
	
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
    #endif // Eight_Bit_Mode

	#ifdef Four_Bit_Mode
	LCD_Send_A_Command(0x02);
	LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif // Eight_Bit_Mode	
	
	LCD_Send_A_Command(LCD_ENTRY_MODE);
	LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK);//turns on the display, the cursor and makes the cursor blink.


}
void LCD_Send_A_Command(unsigned char command){//sends a command to the LCD display.
	 //send commands already intialized at datasheet and there are steps for doing it.
	#ifdef Eight_Bit_Mode
	LCD_check_lcd_isbusy();
	LCD_PORT=command;
	LCD_Control &=~((1 << RS_SWITCH) | (1<<RW_SWITCH)); ;//PortB
	_delay_ms(1);
	LCD_lcd_kick();
	#endif // Eight_Bit_Mode
	#ifdef Four_Bit_Mode
		LCD_check_lcd_isbusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_Control &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick ();
		_delay_ms(100);
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		LCD_Control &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
		LCD_lcd_kick();
	#endif	
}
void LCD_Send_A_Character(unsigned char character){//writes a character to the LCD display.
	#ifdef Eight_Bit_Mode
	LCD_check_lcd_isbusy();
	LCD_PORT=character;
	LCD_Control &=~(1<<RW_SWITCH);//PortB
	LCD_Control |=1<<RS_SWITCH;
	_delay_ms(1);
	LCD_lcd_kick();
	#endif // Eight_Bit_Mode
	
    #ifdef Four_Bit_Mode
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_Control |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_Control &= ~(1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_Control |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_Control &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick();
	#endif
	}

void LCD_Send_A_String(char* string){//: writes a string of characters to the LCD display.

	int count = 0;
	while (*string > 0){// if became at end will be =0
		count++;
		LCD_Send_A_Character(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 31)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(0,0);
			count = 0;
		}
	}
}