/*
 * EEPROM.c
 *
 * Created: 4/9/2023 6:20:25 PM
 *  Author: minas
 */ 

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C.h"

#define EEPROM_WRITE_ADDRESS 0xA0
#define EEPROM_READ_ADDRESS 0xA1

// void EEPROM_Init(void)
// {
// 	I2C_Init(100000UL); // Initialize I2C module with SCL clock of 100kHz
// }

void EEPROM_WriteByte(unsigned short address, unsigned char data)
{
	I2C_Start(); // Send start condition
	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
	I2C_Master_Write(data); // Send data byte
	I2C_Stop(); // Send stop condition
}

unsigned char EEPROM_ReadByte(unsigned short address)
{
	unsigned char data;
	I2C_Start(); // Send start condition
	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
	I2C_Start(); // Send repeated start condition
	I2C_Master_Write(EEPROM_READ_ADDRESS); // Send read address of EEPROM
	data = I2C_Read_NACK(); // Read data byte with NACK
	I2C_Stop(); // Send stop condition
	return data;
}

void EEPROM_WritePage(unsigned short page, unsigned char *data)
{
	unsigned short i;
	unsigned short address = page * 64;
	I2C_Start(); // Send start condition
	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
	for (i = 0; i < 64; i++)
	{
		I2C_Master_Write(*data++); // Send data byte
	}
	I2C_Stop(); // Send stop condition
}

void EEPROM_ReadPage(unsigned short page, unsigned char *data)
{
	unsigned short i;
	unsigned short address = page * 64;
	I2C_Start(); // Send start condition
	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
	I2C_Start(); // Send repeated start condition
	I2C_Master_Write(EEPROM_READ_ADDRESS); // Send read address of EEPROM
	for (i = 0; i < 63; i++)
	{
		*data++ = I2C_Master_Read(); // Read data byte with ACK
	}
	*data = I2C_Read_NACK(); // Read last data byte with NACK
	I2C_Stop(); // Send stop condition
}