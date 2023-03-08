/*
 * UART.h
 *
 * Created: 3/4/2023 4:52:54 PM
 *  Author: minas
 */ 


#ifndef UART_H_
#define UART_H_

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utils.h"


#define Default_Stop '\r'

void Uart_init(void);
void Uart_Send(uint8_t Data);
uint8_t Uart_Recieve(void);

void Uart_Send32(uint32_t Num);
uint32_t Uart_Recieve32(void);

void UART_Send_String (uint8_t* str);
char* UART_Receive_String (void);

uint8_t Uart_Recieve_Periodcheck();
void Send_NoBlock(uint8_t Data);
uint8_t Receive_NoBlock(void);

void UartRX_Interrupt_Enable(void);
void UartRX_Interrupt_Disable(void);
void UartTX_Interrupt_Enable(void);
void UartTX_Interrupt_Disable(void);

void Uart_Send_String_Asyn(uint8_t* str);
void UART_Receive_String_Asyn(void);
#endif /* UART_H_ */