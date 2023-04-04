/*
 * I2C.c
 *
 * Created: 3/14/2023 6:15:32 PM
 *  Author: minas
 */ 
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"
#define prescaler 1 //values =1, 4, 16, 64.
#define Read_Bit(PORT,Bit)     ((PORT >> Bit) & 1)


void I2C_Init(unsigned long SCL_Clock){
	//TWSR0 & TWSR1 to set value of prescaler
		if (prescaler == 1){
		Reset_Bit(TWSR,0);
		Reset_Bit(TWSR,1);
		}
		else if (prescaler == 4){
		Set_Bit(TWSR,0);
		Reset_Bit(TWSR,1);
		}
		
		else if (prescaler == 16){
		Reset_Bit(TWSR,0);
		Set_Bit(TWSR,1);
		}
		
		else if (prescaler == 64){
		Set_Bit(TWSR,0);
		Set_Bit(TWSR,1);
		}
	//Set the value of Bit Rate Register
	TWBR =(unsigned char)(((F_CPU/SCL_Clock)-16)/(2*prescaler));		
	
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
	
	while ((TWSR)!=0x08); //When value of TWSR=0x08 So Start is Transmited(Done)	
	
}
void I2C_Master_Write(unsigned char cByte){
	TWDR = cByte;
	TWCR = (1<<TWINT)|(1<<TWEN);/*Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	OR
	Load DATA into TWDR Register. Clear
	TWINT bit in TWCR to start transmission
	of data is that transmit data to slave */
	
	 while (!(TWCR & (1<<TWINT)));		/*waits for the completion of the current TWI operation.*/
	                              // OR--> while ((TWSR)!=0x28);	For Data && -->	while ((TWSR)!=0x20); For SLA.
}

void I2C_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN); /*Transmit STOP condition*/
}

//=======MASTER READ  & SLAVE TRANSMIT
uint8_t I2C_Master_Read(void){
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while ((TWCR & 1<<7) == 0);
		return TWDR;
}