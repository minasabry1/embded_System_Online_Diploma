/*
 * GccApplication3.c
 *
 * Created: 2/12/2023 9:14:09 PM
 * Author : minas
 */ 

#define F_CPU 8000000UL
#define DDRA (*(volatile unsigned char *)0x3A)
#define PORTA (*(volatile unsigned char *)0x3B)
#define PINA (*(volatile unsigned char *)0x39)

#define DDRC (*(volatile unsigned char *)0x34)
#define PORTC (*(volatile unsigned char *)0x35)
#define PINA (*(volatile unsigned char *)0x33)

#define DDRD (*(volatile unsigned char *)0x31)
#define PORTD (*(volatile unsigned char *)0x32)
#define PIND (*(volatile unsigned char *)0x30)

#define Set_Bit(reg,bit) (reg=reg|(1<<bit))   //set bit to 1
#define Clear_Bit(reg,bit) (reg=reg&~(1<<bit)) //clear bit to 0
//#define Read_Bit(reg,bit) (reg=reg&(1<<bit)>>bit) //read bit =1 or =0
#define  Read_Bit(reg,bit) reg=(reg>>bit)&1
#define Toggle_Bit(reg,bit) (reg=reg^(1<<bit))

#include <util/delay.h>
int main(void)
{
	int i;
	int flag = 0;

	for (i = 0; i <= 7; i++) {
		Set_Bit(DDRA, i);
	}
	Clear_Bit(DDRD, 0); // Pin 0>>PortD>>Input
	Set_Bit(PORTD, 0); // PullUP

	/* Replace with your application code */
	while (1) {
		if (Read_Bit(PIND, 0) == 0) {
			for (i = 0; i <= flag; i++) {
				if (!Read_Bit(PORTA, i)) { // check if LED is already on
					Set_Bit(PORTA, i);
					_delay_ms(500);
				}
			}
			flag += 1;
			if (flag == 8) {
				flag = 0;
			}
		}
	}
}
