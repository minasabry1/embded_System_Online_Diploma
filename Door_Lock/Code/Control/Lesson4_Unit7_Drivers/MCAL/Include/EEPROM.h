/*
 * EEPROM.h
 *
 * Created: 4/9/2023 6:19:54 PM
 *  Author: minas
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/interrupt.h>
#include "C:\Users\minas\Documents\Atmel Studio\7.0\Lesson4_Unit7_Drivers\Lesson4_Unit7_Drivers\MCAL\Include\Atmega32.h"
// Macros for control registers
#define EEPROM_WRITE_ADDRESS 0xA0
#define EEPROM_READ_ADDRESS 0xA1
// Macros for EEPROM memory map
#define EEPROM_SIZE 0x0050 
#define EEPROM_PAGE_SIZE 16 // Page size is 16 bytes
#define EEPROM_START_ADDRESS 0x0000 // Start address of EEPROM
// 
// void EEPROM_Init(void);
// void EEPROM_WriteByte(unsigned short address, unsigned char data);
// unsigned char EEPROM_ReadByte(unsigned short address);
// void EEPROM_WritePage(unsigned short page, unsigned char *data);
// void EEPROM_ReadPage(unsigned short page, unsigned char *data);


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
// void EEPROM_init(void);
// uint8_t EEPROM_writeByte(uint16_t uint16_taddr, uint8_t uint8_tdata);
// uint8_t EEPROM_readByte(uint16_t uint16_taddr, uint8_t *uint8_tdata);


// void EEPROM_init(void);
// uint8_t EEPROM_writeByte(uint16_t uint16_taddr,uint8_t uint8_tdata);
// uint8_t EEPROM_readByte(uint16_t uint16_taddr,uint8_t *uint8_tdata);


// #define EEPROM_ADDRESS 0xA0 // M24C16 EEPROM Address
// #define EEPROM_SIZE 2048 // EEPROM Size
// void EEPROM_WriteByte(uint16_t address, uint8_t data);
// uint8_t EEPROM_ReadByte(uint16_t address);
// void EEPROM_WriteData(uint16_t address, uint8_t *data, uint16_t length);
// void EEPROM_ReadData(uint16_t address, uint8_t *data, uint16_t length);




extern void EEPROM_write(const uint16_t address, const uint8_t data);

/**
 * @brief read byte from specific address
 * 
 * @param address to read from
 * @return uint8_t byte from address
 */
extern uint8_t EEPROM_read(const uint16_t address);

/**
 * @brief Enable eeprom ready interrupt
 * 
 */
extern void EEPROM_intEnable(void);

/**
 * @brief disable eeprom ready interrupt
 * 
 */
extern void EEPROM_intDisable(void);

/**
 * @brief Set callback function for eeprom ready interrupt
 * 
 * @param localFptr pointer to function to run when eeprom ready interrupt fired
 */
extern void EEPROM_intSetCallback(void (*localFptr)(void));

#endif /* EEPROM_H_ */