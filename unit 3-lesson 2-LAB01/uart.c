#include "uart.h"
#define UARt0DR *((volatile unsigned int *)((unsigned int*)0x101f1000))
void uart_send(unsigned char* p){
while(*p != '\0'){
	UARt0DR=(unsigned int)(*p);
	p++;
}

}