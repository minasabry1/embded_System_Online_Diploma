/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 



/*
while (!(TWCR & (1<<TWINT)));
while ((TWSR) != 0x18);
In summary, the first line waits for the completion of the current TWI operation,
 while the second line waits for a specific condition (successful transmission and ACK reception) 
 before proceeding with the next operation.
  They are two different mechanisms that serve different purposes in TWI communication.*/


#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CPU_CONFIGRATION.h"
int main(void)
{
// 	unsigned char ch=0;
// 	I2C_Init(0x48);
// 	while (1)
// 	{
// 		_delay_ms(500);
// 		I2C_Start();                    //Trasmit Start Condition
// 		I2C_Write(0b11010000+0);       //Transmit  SLA + W(0) ..SLA is Slave Adress
// 		while ((TWSR) != 0x18);       //SLA + W(0) has been transmitted and ACK has been Received (For Only SLA)
// 		I2C_Write(ch++);             // Transmit Data
// 		while ((TWSR) != 0x28);     //Data has been transmitted and ACK has been Received (For Only DATA)
// 		I2C_Stop();                //Transmit Stop condition
// 	}


//==========SLAVE============
   DDRA=0xFF;							//Output to 7-Segments
   I2C_Set_Address(0b11010000);         //Enable slave at address 01101000 and Don't accept general call
   while (1)
   {
	   PORTA = I2C_Read();             // Receive Byte and send ACK
   }
   return 0;


}

