/*
 * GccApplication3.c
 *
 * Created: 2/15/2023 7:58:31 PM
 * Author : Mina Sabry
 */ 

#include <avr/io.h>
#include "LCD_DRIVER/LCD.h"
#include "KEY_PAD/KEY_PAD.h"

int main(void)

{

			
    LCD_init();
	Keypad_init();
    _delay_ms(50);
    unsigned char key_pressed;
    while(1){
	    key_pressed = Keypad_getkey();
	    switch(key_pressed){
		    case 'A':
		    break;
		    case '?':
		    LCD_clear_screen();
		    break;
		    default:
		    LCD_Send_A_Character(key_pressed);
		    break;
	    }
    }
}

