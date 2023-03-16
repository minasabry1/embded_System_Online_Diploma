/*
 * Lesson4_Unit7_Drivers.c
 *
 * Created: 2/27/2023 6:33:19 PM
 * Author : minas
 */ 





#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CPU_CONFIGRATION.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C_Slave.h"
int main(void)
{
	//=======MASTER SEND ============
// 	unsigned char ch=0;
// 	I2C_Init(0x48);
// 	while (1)
// 	{
// 		_delay_ms(500);
// 		I2C_Start();                    //Trasmit Start Condition
// 		I2C_Master_Write(0b11010000+0);       //Transmit  SLA + W(0) ..SLA is Slave Adress
// 		while ((TWSR) != 0x18);       //waits for a specific condition (successful transmission and ACK reception)
									 //before proceeding with the next operation.
// 		I2C_Write(ch++);             // Transmit Data
// 		while ((TWSR) != 0x28);     //Data has been transmitted and ACK has been Received (For Only DATA)
// 		I2C_Stop();                //Transmit Stop condition
// 	}


//==========SLAVE RECIEVE============
//    DDRA=0xFF;							//Output to 7-Segments
//    I2C_Set_Address(0b11010000);         //Enable slave at address 01101000 and Don't accept general call
//    while (1)
//    {
// 	   PORTA = I2C_Read();             // Receive Byte and send ACK
//    }
//    return 0;


//=======MASTER RECIEVE========
// 	uint8_t ch;
//    DDRA=0xFF;                                   //PORTA is Output
//    I2C_Init(0x48);                             //Initialize TWI for Master Code
//    while (1)
//    {
// 	   _delay_ms(1000);
// 	   I2C_Start();                       //Transmit Start condition
// 	   I2C_Master_Write(0b11010000+1);          //Transmit SLA+R(1)
// 	   while((TWSR)!= 0x40);      // SLA+R has been transmitted, ACK has been received
// 	   ch=I2C_Master_Read();                  //read last Byte , send NACK
// 	   while(TWSR !=0x50); //Data byte has been received & ACK has been returned
// 	   I2C_Stop();
// 	   PORTA=ch;
//    }


// ===========SLAVE TRANSMITER==========
uint8_t ch=0;
I2C_Set_Address(0b11010000);
while(1){
	I2C_Slave_Read_STRANSMITER();
	I2c_Slave_Transmiter(ch++);
}
return 0;
}

