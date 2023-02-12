/*
 * IncFile1.h
 *
 * Created: 2/12/2023 2:03:39 AM
 *  Author: minas
 */ 


#ifndef Memory_Map_H_
#define Memory_Map_H_



#define DDRA (*(volatile unsigned char *)0x3A)
#define PORTA (*(volatile unsigned char *)0x3B)
#define PINA (*(volatile unsigned char *)0x39)

#define DDRC (*(volatile unsigned char *)0x34)
#define PORTC (*(volatile unsigned char *)0x35)
#define PINA (*(volatile unsigned char *)0x33)

#define DDRD (*(volatile unsigned char *)0x31)
#define PORTD (*(volatile unsigned char *)0x32)
#define PIND (*(volatile unsigned char *)0x30)

#endif /* INCFILE1_H_ */