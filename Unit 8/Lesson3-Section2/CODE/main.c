/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 

#define F_CPU  8000000UL
#include "HAL/LCD_DRIVER/LCD.h"
#include "MCAL/Include/PORT_DDR.h"
#include "util/delay.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\UART.h"


void wait(int t)
{
	int i , j;
	for(i = 0 ; i < t ; i++)
	for(j = 0 ; j < 255 ;   j++);
}

int main(void)	
{	
uint8_t counter='0' ;
	uint8_t x;
 	uint32_t num; 
	LCD_clear_screen();
	LCD_init();
	Uart_init();
	LCD_GOTO_XY(1,2);
	LCD_Send_A_String("UART TR Ready");
	
// 	Uart_Send('M');//sending from MCU to terminal
// 	Uart_Send('I');
// 	Uart_Send('N');
// 	Uart_Send('A');
//  Uart_Send32(20);
//  Uart_Send32(300);
//  Uart_Send32(999);
//UART_Send_String(" Sabry WECLOME :)");
//Async. Dont need while or for loop.

//Cant Send Done because while interrupt working also cpu working and trying send done. 
Uart_Send_String_Asyn("Mina Welcome");
_delay_ms(1000);
Uart_Send_String_Asyn("Done===");
 UART_Receive_String_Asyn();
 
	/* Replace with your application code */
	while(1)
	{	
/*	========1=============
		LCD_GOTO_XY(1,0);
		LCD_Send_A_Character(counter);
		counter++;
		if(counter ==':')
		{
			counter='0';
		}
		_delay_ms(3000);
    LCD_GOTO_XY(2,0);	
	LCD_Send_A_String(UART_Receive_String());
	LCD_Send_A_String("							");
	*/


/*===========2==============POLLING
	if(x=Uart_Recieve_Periodcheck()){
		  LCD_GOTO_XY(2,0);	
		  LCD_Send_A_Character(x);	
	}
		LCD_GOTO_XY(1,0);
		LCD_Send_A_Character(counter);
		counter++;
		if(counter ==':')
		{
			counter='0';
		}
		_delay_ms(200);
	*/	


/* ==========3============
	LCD_GOTO_XY(2,0);
	LCD_Send_A_String(UART_Receive_String());
	LCD_Send_A_String("							");
	LCD_GOTO_XY(1,0);
	LCD_Send_A_Character(counter);
	counter++;
	if(counter ==':')
	{
		counter='0';
	}
	_delay_ms(200);
	*/
	
	
	  
	   
		//LCD_Send_A_String("							");
		LCD_GOTO_XY(1,0);
		LCD_Send_A_Character(counter);
		counter++;
		if(counter ==':')
 		{
 			counter='0';
 		}
 		_delay_ms(2000);
	}

}

