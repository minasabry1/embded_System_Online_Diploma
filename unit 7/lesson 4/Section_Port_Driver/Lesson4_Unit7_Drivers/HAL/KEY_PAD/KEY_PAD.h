/*
 * KEY_BAD.h
 *
 * Created: 2/16/2023 12:05:40 AM
 *  Author: minas
 */ 


#ifndef KEY_BAD_H_
#define KEY_BAD_H_




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

#define KEYPAD_PORT *((uint8_t *)(0x32))
#define DataDir_KEYPAD_PORT *((uint8_t *)(0x31))
#define keypadPIN *((uint8_t *)(0x30))
// #define KEYPAD_PORT PORTD
// #define KEYPAD_PIN PIND
// #define KEYPAD_DataDir DDRD

void Keypad_init();
char Keypad_getkey();


#endif /* KEY_BAD_H_ */