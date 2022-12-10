#include "uart.h"
unsigned char str[100]="mina sabry learn in depth";
const unsigned char str2[100]="mina sabry learn in depth";
void main(void){
	uart_send(str);
}