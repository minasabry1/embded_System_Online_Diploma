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
	uint8_t x;
 	uint32_t num;
 	char name[]={"sabry"};
	char name2[30];
	LCD_clear_screen();
	LCD_init();
	Uart_init();

	LCD_GOTO_XY(0,0);
	LCD_Send_A_String("UART TR Ready");
	Uart_Send('M');//sending from MCU to terminal
	Uart_Send('I');
	Uart_Send('N');
	Uart_Send('A');
	UART_Send_String(name);
   // Uart_Send32(20);
// Uart_Send32(300);
// Uart_Send32(400);
// UART_Send_String("Mina sabry");

	/* Replace with your application code */
	while (1)
	{
	 LCD_GOTO_XY(2,0);	
	// x= Uart_Recieve();//send from terminal to MCU to LCD.*/
	//num=Uart_Recieve32();
	 LCD_Send_A_Character(Uart_Recieve());
	//LCD_Send_A_String(UART_Receive_String());
}

}
