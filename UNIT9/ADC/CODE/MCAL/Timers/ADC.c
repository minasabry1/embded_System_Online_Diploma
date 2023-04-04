/*
 * ADC.c
 *
 * Created: 4/3/2023 9:39:37 PM
 *  Author: minas
 */ 

/******************************************************************************
*                              INCLUDES                                       *
*******************************************************************************/
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\ADC.h"

/******************************************************************************
*								 APIS IMPLEMENTATION			              *
*******************************************************************************/
void ADC_Init(ADC_VREF_TYPE_t voltage,ADC_Scaller_t Scalling){
	switch(voltage){
		case Vref_Aref:
		Reset_Bit(ADMUX,6);
		Reset_Bit(ADMUX,7);
		break;
		
		case Vref_AVCC:
		Set_Bit(ADMUX,6);
		Reset_Bit(ADMUX,7);
		break;
		
		case Vref_256:
		Set_Bit(ADMUX,6);
		Set_Bit(ADMUX,7);
		break;
}
		
		//Clear 3 Bits ADPS & Set 	
		ADCSRA &=0xF8;
		ADCSRA |=Scalling;
		//Enable ADEN
		Set_Bit(ADCSRA,7);
		
	
}
uint16_t ADC_READ(ADC_SELECT_CHANNEL Channel){
	//Cleas MUX bits[4:0]
	ADMUX &=0xE0;
	ADMUX |= Channel;
	
	//start Conversion(sampling)
	/*When the ADSC bit is set (by writing a logic 1 to the bit),
	 the ADC module starts a single conversion on the selected ADC channel.
	 During the conversion, the ADSC bit remains set and the ADC hardware
	 automatically clears the bit when the conversion is complete.*/
	Set_Bit(ADCSRA,6);
	//waiting for the conversion to complete before reading the result.
	while(Read_Bit(ADCSRA,6));
	
    //Return the ADC value as a 16-bit result (combine ADCH and ADCL)
    uint16_t ADC_result = ADCL | (ADCH << 8);
    return ADC_result;
}