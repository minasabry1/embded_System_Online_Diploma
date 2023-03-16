/*
 * I2C.h
 *
 * Created: 3/14/2023 6:15:07 PM
 *  Author: minas
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\CPU_CONFIGRATION.h"

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
void I2C_Stop(void);



#endif /* I2C_H_ */