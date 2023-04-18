/*
 * CTC.h
 *
 * Created: 3/27/2023 11:20:25 PM
 *  Author: minas
 */ 


#ifndef CTC_H_
#define CTC_H_

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
	Normal,
	CTC=0x08
}Timer_Modes_t;

/*• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
Timer/Counter0 Overflow interrupt is enabled.*/
typedef enum
{
	TOIE_DISABLE_No_CTC = 0x00,
	TOIE_ENABLE_No_CTC  = 0x01
}TOIE_t_No_CTC;

/*• Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
Timer/Counter0 Compare Match interrupt is enabled.*/
typedef enum
{
	OCIE_DISABLE_No_CTC  = 0x00,
	OCIE_ENABLE_No_CTC  = 0x02
}OCIE_t_No_CTC;

typedef unsigned char E_STATUS_t;
#define E_OK		(E_STATUS_t)(0)
#define E_NOK		(E_STATUS_t)(1)


typedef enum{
	NO_CLK_SRC_No_CTC ,
	NO_PRESCALING_No_CTC ,
	PRESCALING_CLK8_No_CTC ,
	PRESCALING_CLK64_No_CTC ,
	PRESCALING_CLK256_No_CTC ,
	PRESCALING_CLK1024_No_CTC ,
	EXT_CLK_FALLING_No_CTC ,
	EXT_CLK_RISING_No_CTC ,
}TIMER_CLOCK_t_No_CTC;

/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{
	Timer_Modes_t mode;
	TOIE_t_No_CTC Overflow;
	OCIE_t_No_CTC Compare;
	TIMER_CLOCK_t_No_CTC CLK;
}Timer_Config_t;


/******************************************************************************
*									APIS				                      *
*******************************************************************************/

E_STATUS_t TIMER0_Init(Timer_Config_t* configuartion);
E_STATUS_t TIMER0_Stop();

E_STATUS_t TIMER0_GetCompare(unsigned char* TicksNumber);
E_STATUS_t TIMER0_SetCompare(uint8_t u8_TicksNumber);

E_STATUS_t TIMER0_GetCounter(unsigned char* TicksNumber);
E_STATUS_t TIMER0_SetCounter(uint8_t u8_TicksNumber);

E_STATUS_t TIMER0_GetOverflow(unsigned char* TicksNumber);
E_STATUS_t TIMER0_SetOverflow(uint8_t u8_TicksNumber);

void TIMER0_CALLBACK_Overflow_INTERRUPT(Ptr_Func callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(Ptr_Func callback);

void timer0_LOCK(void);

#endif /* CTC_H_ */