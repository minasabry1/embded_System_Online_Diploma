/*
 * Stm32f103x6.h
 *
 *  Created on: Feb 17, 2023
 *      Author: minas
 */

#ifndef INCLUDE_STM32F103X6_H_
#define INCLUDE_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include <stdint.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define Flash_Memory_Base						0x08000000UL
#define System_Memory_Base						0x1FFFF000UL
#define Sram_Memory_Base						0x20000000UL

#define Peripherals_Base						0x40000000UL
#define Cortex_M3_Internal_Peripherals_Base		0xE0000000UL


//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------
#define RCC_Base								0x40021000UL
//#define RCC_Base								(Peripherals_Base + 0x00021000UL)

//-----------------------------
//Base addresses for APB2 BUS Peripherals
//-----------------------------

//GPIO
//A&B Fully Inlcuded at LQFP48
#define GPIOA_Base								0x40010800UL
#define GPIOB_Base								0x40010C00UL
//C&D Partially Inlcuded at LQFP48
#define GPIOC_Base								0x40011000UL
#define GPIOD_Base								0x40011400UL
//E is Not Inlcuded at LQFP48
#define GPIOE_Base								0x40011800UL

//AFIO
#define AFIO_BASE 								0x40010000UL
//EXTI
#define EXTI_BASE 								0x40010400UL

//-----------------------------
//Base addresses for APB1 BUS Peripherals
//-----------------------------


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CRL;//0x00
	volatile uint32_t CRH;//0x04
	volatile uint32_t IDR;//0x08
	volatile uint32_t ODR;//0x0C
	volatile uint32_t BSRR;//0x10
	volatile uint32_t BRR;//0x14
	volatile uint32_t LCKR;//0x18
}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t CR;//0x00
	volatile uint32_t CFGR;//0x04
	volatile uint32_t CIR;//0x08
	volatile uint32_t APB2RSTR;//0x0C
	volatile uint32_t APB1RSTR;//0x10
	volatile uint32_t AHBENR;//0x14
	volatile uint32_t APB2ENR;//0x18
	volatile uint32_t APB1ENR;//0x1C
	volatile uint32_t BDCR;//0x20
	volatile uint32_t CSR;//0x24
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t IMR;//0x00
	volatile uint32_t EMR;//0x04
	volatile uint32_t RTSR;//0x08
	volatile uint32_t FTSR;//0x0C
	volatile uint32_t SWIER;//0x10
	volatile uint32_t PR;//0x14
}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t EVCR;//0x00
	volatile uint32_t MAPR;//0x04
	volatile uint32_t EXTICR1;//0x08
	volatile uint32_t EXTICR2;//0x0C
	volatile uint32_t EXTICR3;//0x10
	volatile uint32_t EXTICR4;//0x14
	uint32_t RESERVED;		 //0x18
	volatile uint32_t MAPR2;//0x1C
}AFIO_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA_PR		((GPIO_Typedef*)GPIOA_Base)
#define GPIOB_PR		((GPIO_Typedef*)GPIOB_Base)
#define GPIOC_PR		((GPIO_Typedef*)GPIOC_Base)
#define GPIOD_PR		((GPIO_Typedef*)GPIOD_Base)
#define GPIOE_PR		((GPIO_Typedef*)GPIOE_Base)

#define RCC_PR		    ((RCC_Typedef*)RCC_Base)

#define EXTI_PR			((EXTI_Typedef*)EXTI_BASE)

#define AFIO_PR			((AFIO_Typedef*)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//Enable GPIO'S Clock
#define RCC_GPIOA_CLK_EN()		(RCC_PR->APB2ENR |=(1<<2))
#define RCC_GPIOB_CLK_EN()		(RCC_PR->APB2ENR |=(1<<3))
#define RCC_GPIOC_CLK_EN()		(RCC_PR->APB2ENR |=(1<<4))
#define RCC_GPIOD_CLK_EN()		(RCC_PR->APB2ENR |=(1<<5))
#define RCC_GPIOE_CLK_EN()		(RCC_PR->APB2ENR |=(1<<6))

//Enable AFIO's Clock
#define RCC_AFIO_CLK_EN()	(RCC_PR->APB2ENR |= (1 << 0))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INCLUDE_STM32F103X6_H_ */
