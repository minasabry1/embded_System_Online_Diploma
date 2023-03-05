/*
 * UART.c
 *
 * Created: 3/4/2023 4:58:49 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\UART.h"
char data[50];
void Uart_init(void){
	//Baud Rate
	UBRRL =51;
	//Normal Mode--Bit 1
	//Bit 1 – U2X: Double the USART Transmission Speed
	Reset_Bit(UCSRA,U2X);
	 
	
	//Frame
	//No Partiy
	//0 -1 -1- 8-bit
	Set_Bit(UCSRC,UCSZ1);
	Set_Bit(UCSRC,UCSZ0);
	Reset_Bit(UCSRB,UCSZ2);
	
	//Enable
	//• Bit 3 – TXEN: Transmitter Enable
	Set_Bit(UCSRB,TXEN);
	//• Bit 4 – RXEN: Receiver Enable
	Set_Bit(UCSRB,RXEN);
}
void Uart_Send(uint8_t Data){
	//• Bit 5 – UDRE: USART Data Register Empty
	//The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is one, the buffer is empty.
 	while(!Read_Bit(UCSRA,UDRE));
	 UDR=Data;

}
uint8_t Uart_Recieve(void){
	//• Bit 7 – RXC: USART Receive Complete
  // Wait for data to be received
 while (!Read_Bit(UCSRA, RXC));
    // Return received data
	  return UDR;
}

void Uart_Send32(uint32_t Num){
// 	Uart_Send((uint8_t)Num); //send first 8 bits
// 	Uart_Send((uint8_t)(Num>>8)); //send second 8 bits by shifting right to LSB
// 	Uart_Send((uint8_t)(Num>>16));//send third 8 bits by shifting to LSB
// 	Uart_Send((uint8_t)(Num>>24));//send fourth 8 bits by shifting to LSB

char  str[7];
sprintf(str,"%d",Num);  // Adjust the formatting to your liking.

uint8_t* p=str;//ptr can be use as a array what ever what its points to.
Uart_Send(p[0]);
Uart_Send(p[1]);
Uart_Send(p[2]);
Uart_Send(p[3]);

}

uint32_t Uart_Recieve32(void){
// 	uint8_t b1=Uart_Recieve();
// 	uint8_t b2=Uart_Recieve();
// 	uint8_t b3=Uart_Recieve();
// 	uint8_t b4=Uart_Recieve();
// 	uint32_t sum=0;
// 	sum =b1|(uint32_t)b2<<8|(uint32_t)b3<<16|(uint32_t)b4<<24;//First Receing first 8 bits(b1) 
													//then (b2)so shift left with 8 to be sceond 8 nits and so on.
char  str[7];
//uint32_t num;									
uint8_t *p = str;
p[0] = Uart_Recieve();
p[1] = Uart_Recieve();
p[2] = Uart_Recieve();
p[3] = Uart_Recieve();
sprintf(str,"%d",str);  // Adjust the formatting to your liking.	
return str;


}

void UART_Send_String (uint8_t* str)
{
	while(*str != '\0'){
		Uart_Send(*str++);
	}
}

char* UART_Receive_String (void)
{
	char i;
	char get =Uart_Recieve();
	for(i=0;get !='#';i++)
	{
		data[i]=get;
		get =Uart_Recieve();
	}
	data[i]='\0';
	return data;
}