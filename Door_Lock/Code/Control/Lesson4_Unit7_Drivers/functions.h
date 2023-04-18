/*
 * main.h
 *
 * Created: 4/16/2023 5:03:19 PM
 *  Author: minas
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_




void Recieve_Password(uint8_t* array,uint8_t data);
void delay(uint16_t sec);
void rotate_servo(uint8_t angle);
void open_door(void);
void change_Pass(void);
uint8_t Compare_Password(uint8_t* arrayone, uint8_t* arraytwo, uint8_t size);
#endif /* FUNCTIONS_H_ */