/*
 * I2C.h
 *
 * Created: 3/14/2023 6:15:07 PM
 *  Author: minas
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Utilts.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START 0x08        // start has been sent
#define TW_REP_START 0x10    // repeated start
#define TW_MT_SLA_W_ACK 0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK 0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK 0x28  // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK 0x50  // Master received data and send ACK to slave
#define TW_MR_DATA_NACK 0x58 // Master received data but doesn't send ACK to slave

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void I2C_Init(uint8_t no,unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Master_Write(unsigned char cByte);
void I2C_Stop(void);

//=======MASTER READ  & SLAVE TRANSMIT
uint8_t I2C_Read_ACK(void);
uint8_t I2C_Read_NACK(void);
uint8_t I2C_GetStatus(void);

//=====I2C-Door-Lock
void TWI_init(void);

#endif /* I2C_H_ */