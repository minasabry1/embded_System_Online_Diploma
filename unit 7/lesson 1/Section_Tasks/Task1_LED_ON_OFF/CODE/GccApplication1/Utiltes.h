/*
 * Utiltes.h
 *
 * Created: 2/12/2023 3:19:13 PM
 *  Author: minas
 */ 


#ifndef UTILTES_H_
#define UTILTES_H_

#define Set_Bit(reg,bit) (reg=reg|(1<<bit))   //set bit to 1
#define Clear_Bit(reg,bit) (reg=reg&~(1<<bit)) //clear bit to 0
#define  Read_Bit (reg,bit) (reg=reg&(1<<bit)>>bit) //read bit =1 or =0
//#define  Read_Bit (reg,bit) reg=((reg>>bit)&1)
#define Toggle_Bit(reg,bit) (reg=reg^(1<<bit))
#endif /* UTILTES_H_ */