/*
 * UART.c
 *
 * Created: 3/4/2023 4:58:49 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\UART.h"
#include "avr/interrupt.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"

uint8_t data[100];
static uint8_t flag_send=1;
static uint8_t flag_receive=1;
static uint8_t* TX_STR;
static uint8_t* RX_STR;

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
	Uart_Send(Default_Stop);//telling the reciever  to Stop at Enter Pressing.
}

char* UART_Receive_String (void)
{
	char i;
	char get =Uart_Recieve();
	for(i=0;get !=Default_Stop;i++)
	{
		data[i]=get;
		get =Uart_Recieve();
	}
	data[i]='\0';
	return data;
}
uint8_t Uart_Recieve_Periodcheck(){
	uint8_t *p;
 	p=data;
	if (Read_Bit(UCSRA, RXC)){//if UDR recieved Data
	*p=UDR;
	LCD_GOTO_XY(2,1);
	LCD_Send_A_Character(p[0]);
	return '1';	
	}
	else{
	return '0';	
	}

	
}

void Send_NoBlock(uint8_t Data){
	UDR=Data;
}
uint8_t Receive_NoBlock(void){
	return UDR;
}


//Every Byte is Recieved or Transmited the interrupt flag is on.
//The CPU will work Sepratelly till recieve or Transmit.
/*• Bit 7 – RXCIE: RX Complete Interrupt Enable
Writing this bit to one enables interrupt on the RXC Flag. A USART Receive Complete Interrupt
will be generated only if the RXCIE bit is written to one, the Global Interrupt Flag in SREG is writ-
ten to one and the RXC bit in UCSRA is set*/
void UartRX_Interrupt_Enable(void){
   sei();
	Set_Bit(UCSRB,RXCIE);
}
void UartRX_Interrupt_Disable(void){
	Reset_Bit(UCSRB,RXCIE);
}

/*• Bit 6 – TXCIE: TX Complete Interrupt Enable
Writing this bit to one enables interrupt on the TXC Flag. A USART Transmit Complete Interrupt
will be generated only if the TXCIE bit is written to one, the Global Interrupt Flag in SREG is writ-
ten to one and the TXC bit in UCSRA is set*/
void UartTX_Interrupt_Enable(void){
    sei();
	Set_Bit(UCSRB,TXCIE);	
}
void UartTX_Interrupt_Disable(void){
	Reset_Bit(UCSRB,TXCIE);
}


//if flag=1 then TX_Interrupt will be enabled and but first element of recieved array at UDR and go to the ISR then flag turn off.
void Uart_Send_String_Asyn(uint8_t* str){
	if (flag_send ==1){
		TX_STR=str;		
		UartTX_Interrupt_Enable();
		Send_NoBlock(str[0]);

	    flag_send=0;

	}
}

void UART_Receive_String_Asyn(void){
	if (flag_receive ==1){
		flag_receive=0;
		RX_STR=data;
		UartRX_Interrupt_Enable();
	}
}

//if UDR Transimeted then flag will be on

ISR(USART_TXC_vect)
{
	// USART transmission complete interrupt handler
	// Perform some additional processing or initiate another transmission
	static uint8_t i =1;
	if (TX_STR[i] !=0)
	{
		Send_NoBlock(TX_STR[i]);
		i++;
	}
	else{
		i=1;
		flag_send=1;
	}
}

ISR(USART_RXC_vect){
	cli();
	static uint8_t i =0;
	RX_STR[i] =Receive_NoBlock();
	LCD_GOTO_XY(2,i);
	LCD_Send_A_Character(RX_STR[i]);
	
	if(RX_STR[i] == Default_Stop){
		RX_STR[i] = '\0';
		flag_receive=1    ;
		UartRX_Interrupt_Disable();
		
	}
	i++;
	sei();
}
