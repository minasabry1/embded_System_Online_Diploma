/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 
/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#define F_CPU 8000000UL
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\KEY_PAD\KEY_PAD.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\PWM.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\EEPROM.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\UART.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CTC.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\functions.h"
#include <util/delay.h>


/******************************************************************************/
/******************************************************************************
*                           GLOBLAL VALUES			                          *
*******************************************************************************/
	static unsigned short address = 0x0302;
	static unsigned short address2;
	static unsigned short start_address=0x0302;
	
	 uint8_t Error_time=1;
	
	// Delay
	#define DELAY_TIME 3
	volatile uint8_t timer_ovf_count = 0;
	uint8_t Numver_Display[2];
	//here if 2 passwords matching then save here
	uint8_t array_password[20];
	//if want change password
	uint8_t New_password[20];
	//enter password for open
	uint8_t Enter_password[20];
/******************************************************************************
*                               FUNCTIONS			                          *
*******************************************************************************/
void Recieve_Password(uint8_t* array,uint8_t data){
	static uint8_t i=0;
	array[i] = data;
	_delay_ms(100);
	LCD_Send_A_Character(array[i]);
	i++;
	
}
void delay(uint16_t sec)
{
	uint16_t ovf_count = (F_CPU / 256UL) * sec / 8UL; // Calculate the number of overflows required for the delay
	TCNT0 = 0; // Reset Timer0 count value to 0
	while (ovf_count)
	{
		if (TIFR & (1 << TOV0)) // Check if Timer0 overflow flag is set
		{
			TIFR |= (1 << TOV0); // Clear Timer0 overflow flag by writing 1 to it
			ovf_count--; // Decrement the number of remaining overflows
		}
		if(ovf_count ==0){
			break;
		}
	}
}
void rotate_servo(uint8_t angle) {
	// Rotate the servo to +90 degrees
	//  rotate_servo(90);
	//Compare value = (Duty cycle * 256) / 100
	//duty cycle of 30%, the compare value can be calculated as follows:
	//Compare value = (30 * 256) / 100 = 76.8
	if (angle==1){
		PWM_t Config_Close={Phase_Coreect_PWM,PRESCALING_CLK64,PWM_INVERTING};
		PWM0_SetCompare(75);
		PWM0_Init(&Config_Close);
		
	}
	// Rotate the servo to -90 degrees
	//rotate_servo(-90);
	//Duty cycle = (Compare value * 100) / 256 = (155 * 100) / 256 = 60.55%
	else{
		PWM_t Config_Open={Phase_Coreect_PWM,PRESCALING_CLK1,PWM_INVERTING};
		PWM0_SetCompare(155);
		PWM0_Init(&Config_Open);
		
	}
}

void alram(uint8_t Error_time){
	if (Error_time==3){
	static uint8_t time_error=0;
	while(time_error !=15){
	LCD_clear_screen();
	LCD_GOTO_XY(1,0);
	LCD_Send_A_String("=======THIEF======");
	DDRB |= (1 << PB0); // Set PB0 as an output pin
	Set_Bit(PORTB,0); // Turn the buzzer on
	//Used Delay to keep MCU here and not doing any thing expect Alram
	_delay_ms(5000); // Wait for 500 ms
	Reset_Bit(PORTB,0); // Turn the buzzer off
	_delay_ms(100); // Wait for 500 ms
	time_error++;
					
		}
		Error_time=1;	
			}	
	
}

uint8_t Compare_Password(uint8_t* arrayone, uint8_t* arraytwo, uint8_t size){
	
	uint8_t isEqual = 1;
	for (uint8_t  i = 0; i < size; i++) {
		if (arrayone[i] != arraytwo[i]) {
			isEqual = 0;
			break;
		}
	}
		if (isEqual==1) {
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("Password Are Matched: ");
		_delay_ms(1000);
		return 1;

	}

	else {
		alram(Error_time);
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("====Wrong Password===");
		_delay_ms(100);
		LCD_GOTO_XY(2,0);
		LCD_Send_A_String("====Try Again===");
		_delay_ms(100);
		Error_time++;
		return 0;
	}
	

}
void open_door(void){
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			LCD_Send_A_String("Lock is OPEN For 5 Seconds: ");
			LCD_GOTO_XY(2,0);
			
			rotate_servo(0);
			for(uint8_t i=1;i<=5;i++){
				delay(DELAY_TIME);
				sprintf(Numver_Display,"%d",i);
				LCD_Send_A_String(Numver_Display);
				delay(5);
			}
			PWM0_Stop();
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			LCD_Send_A_String("Locked:");
			rotate_servo(1); // Lock the servo
			_delay_ms(100);
			PWM0_Stop();
}

void change_Pass(void){
	for(uint8_t i=0;i<5;i++){
		array_password[i]=New_password[i];
}
}


void main(void) {
	//LCD is OUTPUT
	DDRB=0xFF;
	//LCD is OUTPUT
	DDRA=0xFF;
	//TX is OUTPUT
	Set_Bit(DDRD,1);
	//RX is INPUT
	Reset_Bit(DDRD,0);
	//PINS is OUTPUT TO Motor
	Set_Bit(DDRD,6);

	//PINS is OUTPUT TO EEPROM
	Set_Bit(DDRB,3);

	//PINS is OUTPUT TO BUZZER
	Set_Bit(DDRB,0);
	
	uint8_t array1[10];
	uint8_t array2[10];
	uint8_t array3[20];
	uint8_t array4[20];
	
	sei(); // Enable global interrupts
	uint8_t key_pressed, i = 0;
	uint8_t j = 0;
	
 	Uart_init();
 	LCD_init();
	LCD_GOTO_XY(1,0);
	LCD_Send_A_String("Enter Password:");
	LCD_GOTO_XY(2,0);
	
	//Receiving first 5 digits password from EEPROM
		for (uint8_t i=0; i < 5; i++) {
Recieve_Password(&array1,Uart_Recieve());
			}
	//Receiving Second 5 digits password from EEPROM
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("Re-Enter Password:");
		LCD_GOTO_XY(2,0);
		for (uint8_t i=0; i < 5; i++) {
			array2[i] = Uart_Recieve();
			_delay_ms(100);
			LCD_Send_A_Character(array2[i]);
		}
		
		
	_delay_ms(100);
	TWI_init();
	//Send first 5 Digits to EEPROM
	
	LCD_clear_screen();
	char str[10];
	LCD_GOTO_XY(1,0);
	for (uint8_t i=0; i < 5; i++,address++) {
        EEPROM_write(address, array1[i]);
        _delay_ms(10);
	}
	
	address++;
	address2=address;
	//Send Second 5 Digits to EEPROM
	
	LCD_GOTO_XY(2,0);
	for (uint8_t i=0; i < 5; i++,address++) {
        EEPROM_write(address, array2[i]);
        _delay_ms(10);		
	}
		//PINS is INPUT TO EEPROM
		Reset_Bit(DDRC,0);
		Reset_Bit(DDRC,1);

		for (uint8_t i=0; i < 5; i++,start_address++) {
		array3[i]=EEPROM_read(start_address);
		_delay_ms(100);
	}

	
	//Send Second Password to EEPROM save to array4	
		for (uint8_t i=0; i < 5; i++,address2++) {
			array4[i]=EEPROM_read(address2);
			_delay_ms(10);			
		}
		//LCD_Send_A_String("DONE");
		
		
		uint8_t size = sizeof(array1) / sizeof(array1[0]);
		//Save Password At array_password.
		
		
		if(Compare_Password(array3,array4,size)==1){
				for(uint8_t l=0;l<5;l++){
					array_password[l]=array3[l];
				}
				_delay_ms(100);
				Uart_Send(10);
		while(1){
//Choose + or -
		LCD_clear_screen();
		LCD_GOTO_XY(1,0);
		LCD_Send_A_String("+ :Open Door");
		LCD_GOTO_XY(2,0);
		LCD_Send_A_String("- :Change Password");
		uint8_t Step=Uart_Recieve();
		
		switch (Step){
			case '+':	//Compare Passwords
				LCD_clear_screen();
				LCD_GOTO_XY(1,0);
				LCD_Send_A_String("Enter Password");
				LCD_GOTO_XY(2,0);
		for (uint8_t i=0; i < 5; i++) {
			Enter_password[i] = Uart_Recieve();
			_delay_ms(100);
			LCD_Send_A_Character(Enter_password[i]);
		}
				if (Compare_Password(array_password,Enter_password,size)==1)
				{
					open_door();
				}
				else{
					break;}	
			break;
			
			case '-':
			//Enter First Old Password
				LCD_clear_screen();
				LCD_GOTO_XY(1,0);
				LCD_Send_A_String("Enter OLD Password");
				LCD_GOTO_XY(2,0);
				for (uint8_t i=0; i < 5; i++) {
					Enter_password[i] = Uart_Recieve();
					_delay_ms(100);
					LCD_Send_A_Character(Enter_password[i]);
				}			
			//Enter New Password
				LCD_clear_screen();
				LCD_GOTO_XY(1,0);
				LCD_Send_A_String("Enter NEW Password");
				LCD_GOTO_XY(2,0);
				for (uint8_t i=0; i < 5; i++) {
					New_password[i] = Uart_Recieve();
					_delay_ms(100);
					LCD_Send_A_Character(New_password[i]);
				}
				//Update array_password to New_password
				if (Compare_Password(array_password,Enter_password,size)==1)
				{
				for(uint8_t i=0;i<5;i++){
					array_password[i]=New_password[i];
				}
				break;
				}

				
		}
 		}
		}
		}