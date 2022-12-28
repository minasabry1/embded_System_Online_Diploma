/*
 * fifo.h
 *
 *  Created on: Dec 24, 2022
 *      Author: minas
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"
//user configuration
//select the element type

#define element_type uint8_t
//choose size of array
#define width 5
//create buffer
element_type uart_buff[width];
//FIFO datatybes.
typedef struct{
	unsigned int length;
	unsigned int counter;
	element_type* head; //	element_type* will read with ptr datatybe.
	element_type* tail;
	element_type* base;
}FIFO_Buff_t;
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Buff_status_t;

//fifo functions declerations
FIFO_Buff_status_t FIFO_init(FIFO_Buff_t* fifo,element_type* buff,unsigned int length); //intialize buffer and array
FIFO_Buff_status_t FIFO_enqueue(FIFO_Buff_t* fifo,element_type item);//add item to array
FIFO_Buff_status_t FIFO_dequeue(FIFO_Buff_t* fifo,element_type* item);//remove item from array and get its data
FIFO_Buff_status_t FIFO_Isfull(FIFO_Buff_t* fifo);//check if full
void FIFO_print(FIFO_Buff_t* fifo);//print the array
#endif /* FIFO_H_ */
