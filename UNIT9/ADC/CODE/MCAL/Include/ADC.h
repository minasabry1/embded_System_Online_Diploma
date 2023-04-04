/*
 * ADC.h
 *
 * Created: 4/3/2023 8:15:15 PM
 *  Author: minas
 */ 


#ifndef ADC_H_
#define ADC_H_

/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"

/******************************************************************************
*					Typedef-Defines-ENUMS	                				  *
*******************************************************************************/
#define VoltRef			5000	//MilliVolt
#define Resolution		1024	//10Bit Resolution

typedef enum{
	Vref_Aref,
	Vref_AVCC,
	Vref_256
	}ADC_VREF_TYPE_t;

typedef enum{
	ADC_Scaller_2=0,
	ADC_Scaller_4=2,
	ADC_Scaller_8,
	ADC_Scaller_16,
	ADC_Scaller_32,
	ADC_Scaller_64,
	ADC_Scaller_128,
	}ADC_Scaller_t;

typedef enum{
	CH0=0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,
	CH6,
	CH7,
	}ADC_SELECT_CHANNEL;	


/******************************************************************************
*									APIS				                      *
*******************************************************************************/
void ADC_Init(ADC_VREF_TYPE_t voltage,ADC_Scaller_t Scalling);
uint16_t ADC_READ(ADC_SELECT_CHANNEL Channel);
#endif /* ADC_H_ */