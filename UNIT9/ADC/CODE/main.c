/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 


#define F_CPU 8000000UL
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\ADC.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"

#include <util/delay.h>
/* ================================================================ */
/* ======================= Global Macros ====================== */
/* ================================================================ */
#define LM35_REFVOLT				5000UL

/* ================================================================ */
/* ======================= Global Functions ====================== */
/* ================================================================ */

//This function returns the temperature value in Celsius with decimal points
//ADCVal IS DOUT
uint8_t ADC_GetTemprature(uint16_t ADCVal)
{
	uint16_t TempVal = 0 ;
	TempVal = ((ADCVal * LM35_REFVOLT / 1024)) / 10;
	return TempVal; //TempVal is DOUT after scalling according to LM35
}

	int main(void)
	{
		DDRA =0xFF;
		DDRB=0xFF;
		DDRC=0xFF;
		DDRD=0xFF;		
		char str[32];
		char TempString[10];
		uint16_t data;
		uint16_t volt;
		uint16_t per_value;
		
		uint16_t ADC_Data;
		uint16_t Temp;
		uint8_t arr[16]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		LCD_init();
		ADC_Init(Vref_AVCC,ADC_Scaller_64);
		LCD_GOTO_XY(1,0);
		//LCD_Send_A_String("ADC:");
		//LCD_Send_A_String("VOLT:");
		//LCD_Send_A_String("ADC Percent:");
		LCD_Send_A_String("Temperature =");
		LCD_GOTO_XY(2,1);	
		while (1)
		{
			//*****fIRST Test******
			//vin is an voltage
			//Data is Dout OF ADC
			//data=ADC_READ(CH3);
			//sprintf(str,"%d",data);
			
			//*****Second Test******
			//Volt is the vin 
			//volt = ((uint32_t )ADC_READ(CH3)*5000)/1024;
			//sprintf(str,"%d",volt);
			
			//*****Third Test******
			//per_value=((uint32_t )ADC_READ(CH3)*100)/1024;
			//sprintf(str,"%d",per_value);
			ADC_Data=ADC_READ(CH3);
			Temp=ADC_GetTemprature(ADC_Data);
			sprintf(str,"%d",Temp);
			
			LCD_GOTO_XY(2,1);
			LCD_Send_A_String(str);
			LCD_GOTO_XY(2,5);
			LCD_Send_A_String('C');

		}
	}


