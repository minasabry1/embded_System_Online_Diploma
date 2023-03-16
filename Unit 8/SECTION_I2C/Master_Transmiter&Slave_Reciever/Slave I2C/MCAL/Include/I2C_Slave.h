/*
 * I2C_Slave.h
 *
 * Created: 3/15/2023 4:45:50 PM
 *  Author: minas
 */ 


#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CPU_CONFIGRATION.h"

void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read();


#endif /* I2C_SLAVE_H_ */