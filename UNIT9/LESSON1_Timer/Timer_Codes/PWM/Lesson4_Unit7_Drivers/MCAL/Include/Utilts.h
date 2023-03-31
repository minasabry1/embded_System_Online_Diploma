/*
 * MemMap.h
 *
 * Created: 23/2/2023 7:31:54 PM
 *  Author: Mina Sabry
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define Set_Bit(PORT,Bit)       PORT |=  (1<<Bit)		// Set pin
#define Reset_Bit(PORT,Bit)     PORT &= ~(1<<Bit)		// Reset pin
#define Toggle_Bit(PORT,Bit)    PORT ^=  (1<<Bit)		// Toggle pin
#define Read_Bit(PORT,Bit)     ((PORT >> Bit) & 1)		// Read from pin
//#define Read_Bit(PORT,Bit) (PORT=PORT&(1<<Bit)>>Bit)  //Read bit =1 or =0

#endif /* UTILS_H_ */