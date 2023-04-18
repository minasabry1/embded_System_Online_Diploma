/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 


#define F_CPU 8000000UL

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\KEY_PAD\KEY_PAD.h"
 #include "F:\Learn-in-depth\PROJEct\My Test\HMI New Test\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"
#include <util/delay.h>

#include <util/delay.h>
	int main(void)
	{
		DDRC=0xFF;
		DDRA=0xFF;
		Set_Bit(DDRD,1);
		Reset_Bit(DDRD,0);			
		//sei(); // Enable global interrupts
		
		uint8_t key_pressed,i=0;
		uint8_t j=0;
		Uart_init();
		Keypad_init();
		LCD_init();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("Enter Password 5 digits:");
		LCD_GOTO_XY(2,0);
		
		while (i<5)
		{
	    key_pressed = Keypad_getkey();
		LCD_GOTO_XY(2,i);
	    switch(key_pressed){
		    case 'A':
		    break;
		    case '?': //ON/C
		    LCD_clear_screen();
		    break;
		    default:
			LCD_GOTO_XY(2,i);
			Uart_Send(key_pressed);
		    LCD_Send_A_Character('*');
			i++;
		    break;
		
				}
			}
			
		i=0;
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("Re-Enter Password");
		LCD_GOTO_XY(2,0);
		while (i<5)
		{
			key_pressed = Keypad_getkey();
			LCD_GOTO_XY(2,i);
			switch(key_pressed){
				case 'A':
				break;
				case '?': //ON/C
				LCD_clear_screen();
				break;
				default:
				LCD_GOTO_XY(2,i);
				Uart_Send(key_pressed);
				LCD_Send_A_Character('*');
				i++;
				break;
				
			}
			
		}
// 
// 	  while (Uart_Recieve() != 10)
// 		 {
// 		 }
// 		LCD_Send_A_String("Password Are Matched");
// 		_delay_ms(100);	
		
		i=0;
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("+ or -");
		LCD_GOTO_XY(2,0);
		while (1)
		{

			
			key_pressed = Keypad_getkey();
			LCD_GOTO_XY(2,i);
			switch(key_pressed){
				case 'A':
				break;
				case '?': //ON/C
				LCD_clear_screen();
				break;
				default:
				LCD_GOTO_XY(2,i);
				Uart_Send(key_pressed);
				LCD_Send_A_Character('*');
				i++;
				if(i==30){
					i=0;
				}
				
				break;
				
			}
	}


	}