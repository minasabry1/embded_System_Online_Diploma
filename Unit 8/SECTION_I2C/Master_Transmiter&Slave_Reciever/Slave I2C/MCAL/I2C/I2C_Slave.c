/*
 * I2C_Slave.c
 *
 * Created: 3/15/2023 4:46:39 PM
 *  Author: minas
 */ 

/*ATmega32 microcontroller, the address of the slave device is typically stored
in the Two-Wire Address Register (TWAR) on the slave device.
When the slave device receives a communication on the I2C bus,
it compares the address in the communication
  with the address stored in the TWAR register to determine whether the communication is intended for it.*/
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C_Slave.h"
void I2C_Set_Address(unsigned char address){
	TWAR=address;	
}

unsigned char I2C_Read(){
		unsigned char x=0;
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while ((TWCR & 1<<7) == 0);
		while ((TWSR) != 0x60);           /*This line checks the TWSR (Two-Wire Status Register) to ensure that the Atmega32
															has received its own SLA+W (slave address + write bit) and an ACK bit from the I2C master. I*/
		
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while ((TWCR & 1<<7) == 0);
		while ((TWSR) != 0x80);    /*This line checks the TWSR to ensure that the data has been received
											 and an ACK bit has been sent to the I2C master. */
		return TWDR;
	
}
