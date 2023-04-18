/*
 * I2C.c
 *
 * Created: 3/14/2023 6:15:32 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C.h"
#define prescaler 2 //values =1, 4, 16, 64.
#define Read_Bit(PORT,Bit)     ((PORT >> Bit) & 1)
#define F_CPU 8000000UL

void TWI_init(void)
{
    /* Bit Rate: 200.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
   // TWBR = 0xC8;
	TWBR = 32; // For F_CPU = 8 MHz and prescaler = 1, TWBR = 32 gives 100 kHz SCL frequency
    TWSR = 0x00;

    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
    //TWAR = 0b00000010; // my address = 0x01 :)
	TWAR = 0b10100000; // Set slave address to 0x01
	//TWAR = (0x50 << 1); 

    TWCR = (1 << TWEN); /* enable TWI */
}

void I2C_Init(uint8_t PRE,unsigned long SCL_Clock){
	//TWSR0 & TWSR1 to set value of prescaler
		if (PRE == 1){
 		Reset_Bit(TWSR,0);
 		Reset_Bit(TWSR,1);

		}
		else if (PRE == 4){
		Set_Bit(TWSR,0);
		Reset_Bit(TWSR,1);
		}
		
		else if (PRE == 16){
		Reset_Bit(TWSR,0);
		Set_Bit(TWSR,1);
		}
		
		else if (PRE == 64){
		Set_Bit(TWSR,0);
		Set_Bit(TWSR,1);
		}

	//Set the value of Bit Rate Register
	TWBR =(unsigned char)(((F_CPU/SCL_Clock)-16)/(2*PRE));
	//TWSR = 0x01;
	//TWBR = 32;

		
	
}
void I2C_Start(void){
	/*Bit 2 - TWEN: TWI Enable
	Making this bit HIGH enables the TWI module.
	Bit 5 - TWSTA: TWI START condition Bit
	Making this bit HIGH will generate a START condition
	if the bus is free
	Bit 7 – TWINT: TWI interrupt
	This bit gets set whenever TWI completes its current event (like start, stop, transmit, receive, etc).
	The TWINT bit in the TWCR register is automatically cleared by hardware after each I2C operation is completed.
	
	Here is the way to tell atmega32 to start*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	
	/*When an I2C operation is completed: The TWINT bit is set to 1 by the hardware when an I2C operation
	(such as a start condition, stop condition, or data transfer) is completed successfully.
	The TWINT bit indicates that the I2C hardware is ready to initiate another I2C operation.
	When an error occurs: The TWINT bit may also be set to 1 if an error occurs during an I2C operation, such as a bus collision or a timeout.
	
	
	Wait for TWINT Flag set. This indicates
	that the START condition has been
	transmitted*/
	while ((Read_Bit(TWCR,7)==0));
	
	while ((TWSR)!=0x08); //When value of TWSR=0x08 So Start has been Transmited(Done)	
	
}
void I2C_Master_Write(unsigned char cByte){
	TWDR = cByte;
	TWCR = (1<<TWINT)|(1<<TWEN);/*Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	OR
	Load DATA into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of data is that transmit data to slave */
	
	/*The TWINT Flag must be cleared by software by writing a logic one to it. Note that this flag is not
	automatically cleared by hardware when executing the interrupt routine. Also note that clearing
	this flag starts the operation of the TWI, so all accesses to the TWI Address Register (TWAR),
	TWI Status Register (TWSR), and TWI Data Register (TWDR) must be complete before clearing
	this flag.*/
	 while (!(TWCR & (1<<TWINT)));	/*waits for the completion of the current TWI operation.*/
	                              // OR--> while ((TWSR)!=0x28);	For Data && -->	while ((TWSR)!=0x20); For SLA.
}

void I2C_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN); /*Transmit STOP condition*/
}

//=======MASTER READ  & SLAVE TRANSMIT
uint8_t I2C_Read_ACK(void){
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while ((TWCR & 1<<7) == 0);
		return TWDR;
}

uint8_t I2C_Read_NACK(void)
{
	// Receive data with NACK
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for data to be received
	while ((TWCR & 1<<7) == 0);

	// Return received data
	return TWDR;
}

uint8_t I2C_GetStatus(void)
{
    uint8_t status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}