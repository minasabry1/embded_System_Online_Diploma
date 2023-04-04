/*
 * PWM.h
 *
 * Created: 3/29/2023 10:56:21 PM
 *  Author: minas
 */ 


#ifndef PWM_H_
#define PWM_H_


/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"
#include <avr/interrupt.h>

/******************************************************************************
*					Typedef-Defines-ENUMS	                				  *
*******************************************************************************/
typedef void(*Ptr_Func)(void);
#define NULL_PTR		((void*) (0))

typedef enum{
	Fast_PWM=0x40,
	Phase_Coreect_PWM=0x08
}PWM_Modes_t;
	
/*• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
Timer/Counter0 Overflow interrupt is enabled.*/
typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOIE_t;

/*• Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
Timer/Counter0 Compare Match interrupt is enabled.*/
typedef enum
{
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCIE_t;

typedef enum{
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,
}TIMER_CLOCK_t;

typedef enum
{
	PWM_INVERTING = 0x30,
	PWM_Non_INVERTING = 0x10
}PWM_INV_t;

/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/
typedef struct{
	PWM_Modes_t Mode;
	TOIE_t Overflow;
	OCIE_t Compare;
	TIMER_CLOCK_t CLK;
	PWM_INV_t Invering;
	}PWM_t;
	
/******************************************************************************
*									APIS				                      *
*******************************************************************************/
void PWM0_Init(PWM_t* configuartion);
void PWM0_Stop();

void PWM0_GetCompare(unsigned char* TicksNumber);
void PWM0_SetCompare(uint8_t TicksNumber);

void PWM0_GetCounter(unsigned char* TicksNumber);
void PWM0_SetCounter(uint8_t TicksNumber);

void PWM0_GetOverflow(unsigned char* TicksNumber);
void PWM0_SetOverflow(uint8_t TicksNumber);

void PWM0_CALLBACK_Overflow_INTERRUPT(Ptr_Func callback);
void PWM0_CALLBACK_CompareMatch_INTERRUPT(Ptr_Func callback);


#endif /* PWM_H_ */