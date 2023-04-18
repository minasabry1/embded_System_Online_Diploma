/*
 * EEPROM.c
 *
 * Created: 4/9/2023 6:20:25 PM
 *  Author: minas
 */ 

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\I2C.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\EEPROM.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\HAL\LCD_DRIVER\LCD.h"
#include <util/delay.h>

#define EEPROM_WRITE_ADDRESS 0xA0
#define EEPROM_READ_ADDRESS 0xA1

// void EEPROM_init(void)
// {
//     /* just initialize the I2C(TWI) module inside the MC */
//     TWI_init();
// }
// 
// uint8_t EEPROM_writeByte(uint16_t uint16_taddr, uint8_t uint8_tdata)
// {
//     /* Send the Start Bit */
//     I2C_Start();
//     if (I2C_GetStatus() != TW_START)
//         return ERROR;
// 
//     /* Send the device address, we need to get A8 A9 A10 address bits from the
//     /* memory location address and R/W=0 (write) */
//     I2C_Master_Write((uint8_t)(0xA0 | ((uint16_taddr & 0x0700) >> 7)));
//     if (I2C_GetStatus() != TW_MT_SLA_W_ACK)
//         return ERROR;
// 		
// 	//	_delay_ms(100);
//     /* Send the required memory location address */
//     I2C_Master_Write((uint8_t)(uint16_taddr));
//     if (I2C_GetStatus() != TW_MT_DATA_ACK)
//         return ERROR;
// 	//_delay_ms(100);
//     /* write byte to eeprom */
//     I2C_Master_Write(uint8_tdata);
//     if (I2C_GetStatus() != TW_MT_DATA_ACK)
//         return ERROR;
// 	//_delay_ms(100);
//     /* Send the Stop Bit */
//     I2C_Stop();
// 
//     return SUCCESS;
// }
// 
// uint8_t EEPROM_readByte(uint16_t uint16_taddr, uint8_t *uint8_tdata)
// {
//     /* Send the Start Bit */
//     I2C_Start();
//     if (I2C_GetStatus() != TW_START)
//         return ERROR;
// 
//     /* Send the device address, we need to get A8 A9 A10 address bits from the
//     /* memory location address and R/W=0 (write) */
//     I2C_Master_Write((uint8_t)((0xA0) | ((uint16_taddr & 0x0700) >> 7)));
//     if (I2C_GetStatus() != TW_MT_SLA_W_ACK)
//         return ERROR;
// 
//     /* Send the required memory location address */
//     I2C_Master_Write((uint8_t)(uint16_taddr));
//     if (I2C_GetStatus() != TW_MT_DATA_ACK)
//         return ERROR;
// 
//     /* Send the Repeated Start Bit */
//     I2C_Start();
//     if (I2C_GetStatus() != TW_REP_START)
//         return ERROR;
// 
//     /* Send the device address, we need to get A8 A9 A10 address bits from the
//     /* memory location address and R/W=1 (Read) */
//     I2C_Master_Write((uint8_t)((0xA0) | ((uint16_taddr & 0x0700) >> 7) | 1));
//     if (I2C_GetStatus() != TW_MT_SLA_R_ACK)
//         return ERROR;
// 
//     /* Read Byte from Memory without send ACK */
//     *uint8_tdata = I2C_Read_NACK	();
//     if (I2C_GetStatus() != TW_MR_DATA_NACK)
//         return ERROR;
// 
//     /* Send the Stop Bit */
//     I2C_Stop();
//     return SUCCESS;
// }

//char strr[10];
// void EEPROM_Init(void)
// {
// 	I2C_Init(1,100000UL); // Initialize I2C module with SCL clock of 100kHz
// }
// 
// void EEPROM_WriteByte(unsigned short address, unsigned char data)
// {
// 	I2C_Start(); // Send start condition
// 	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
// 	_delay_ms(100);
// 	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
// 	_delay_ms(100);
// 	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
// 	_delay_ms(100);
// 	I2C_Master_Write(data); // Send data byte
// 	_delay_ms(100);
// 		//sprintf(strr, "%x", address);
// 		//LCD_Send_A_String(strr);
// 		//_delay_ms(5000);
// 	I2C_Stop(); // Send stop condition
// 
// 
// }
// 
// unsigned char EEPROM_ReadByte(unsigned short address)
// {
// 	unsigned char data;
// 	I2C_Start(); // Send start condition
// 	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
// 	_delay_ms(100);
// 	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
// 	_delay_ms(100);
// 	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
// 	_delay_ms(100);
// 	I2C_Start(); // Send repeated start condition
// 	I2C_Master_Write(EEPROM_READ_ADDRESS); // Send read address of EEPROM
// 	_delay_ms(100);
// 	data = I2C_Read_NACK(); // Read data byte with NACK
// 	//_delay_ms(100);
// 	I2C_Stop(); // Send stop condition
// 	return data;
// 
//  }
// 	 
// void EEPROM_WritePage(unsigned short page, unsigned char *data)
// {
// 	unsigned short i;
// 	unsigned short address = page * 64;
// 	I2C_Start(); // Send start condition
// 	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
// 	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
// 	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
// 	for (i = 0; i < 64; i++)
// 	{
// 		I2C_Master_Write(*data++); // Send data byte
// 	}
// 	I2C_Stop(); // Send stop condition
// }


// void EEPROM_ReadPage(unsigned short page, unsigned char *data)
// {
// 	unsigned short i;
// 	unsigned short address = page * 64;
// 	I2C_Start(); // Send start condition
// 	I2C_Master_Write(EEPROM_WRITE_ADDRESS); // Send write address of EEPROM
// 	I2C_Master_Write((address >> 8) & 0xFF); // Send high byte of memory address
// 	
// 	I2C_Master_Write(address & 0xFF); // Send low byte of memory address
// 	I2C_Start(); // Send repeated start condition
// 	I2C_Master_Write(EEPROM_READ_ADDRESS); // Send read address of EEPROM
// 	for (i = 0; i < 63; i++)
// 	{
// 		*data++ = I2C_Read_ACK(); // Read data byte with ACK
// 	}
// 	*data = I2C_Read_NACK(); // Read last data byte with NACK
// 	I2C_Stop(); // Send stop condition
// }

#define NULLPTR ((void *)0)
static void (*eeprom_rdy_fPtr)(void) = NULLPTR;

void EEPROM_write(const uint16_t address, const uint8_t data)
{
    /* Wait for completion of previous write */
    while (1 == Read_Bit(EECR, EEWE));

    /* Set up address and data registers */
    EEAR = address;
    EEDR = data;

    /* disable global interrupt */
    cli();

    /* Write logical one to EEMWE */
    Set_Bit(EECR, EEMWE);

    /* Start EEPROM write by setting EEWE--> must be done withing four clock cycles
    *  after setting EEMWE so I use cli() and sei() 
    */
    Set_Bit(EECR, EEWE);

    /* enable global interrupt */
    sei();
}

uint8_t EEPROM_read(const uint16_t address)
{
    /* Wait for completion of previous write */
    while (1 == Read_Bit(EECR, EEWE));

    /* Set up address register */
    EEAR = address;

    /* Start EEPROM read by writing EERE */
    Set_Bit(EECR, EERE);

    /* Return data from data register */
    return EEDR;
}

void EEPROM_intEnable(void)
{
    Set_Bit(EECR, EERIE);
}

void EEPROM_intDisable(void)
{
    CLR_BIT(EECR, EERIE);
}

void EEPROM_intSetCallback(void (*localFptr)(void))
{
    eeprom_rdy_fPtr = localFptr;
}

ISR(EE_RDY_VECT)
{
    if (eeprom_rdy_fPtr != NULLPTR)
    {
        eeprom_rdy_fPtr();
    }
}
