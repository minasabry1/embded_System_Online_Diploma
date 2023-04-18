/*
 * KEY_BAD.h
 *
 * Created: 2/16/2023 12:05:40 AM
 *  Author: minas
 */ 


#ifndef KEY_BAD_H_
#define KEY_BAD_H_



#include <avr/io.h>
#define F_CPU 1000000UL
#include "util/delay.h"


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT				PORTA
#define DataDir_KEYPAD_PORT		DDRA
#define keypadPIN				PINA


void Keypad_init();
uint8_t Keypad_getkey();


#endif /* KEY_BAD_H_ */