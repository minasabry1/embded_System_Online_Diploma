/*
 * fifo.c
 *
 *  Created on: Dec 24, 2022
 *      Author: minas
 */
#include "fifo.h"
FIFO_Buff_status_t FIFO_init(FIFO_Buff_t* fifo,element_type* buff,unsigned int length){
	if (buff == NULL)
		return FIFO_Null;
	fifo->base=buff;
	fifo->head=buff;
	fifo->tail=buff;
	fifo->length=length;
	fifo->counter=0;
	return FIFO_no_error;
}
FIFO_Buff_status_t FIFO_enqueue(FIFO_Buff_t* fifo,element_type item){
	if (!fifo->base ||!fifo->head || !fifo->tail)
		return FIFO_Null; //check about head and tail and base in or not
	if(FIFO_Isfull(fifo)== FIFO_full)
		return FIFO_full;

	*(fifo->head)=item;
	fifo->counter++;
	//circular
	if(fifo->head ==(fifo->base + fifo->length * sizeof(element_type))){//to check if head at the end of my array.
		fifo->head= fifo->base;}
	else{
		fifo->head++;
	}
	return FIFO_no_error;
}
FIFO_Buff_status_t FIFO_dequeue(FIFO_Buff_t* fifo,element_type* item){
	if (!fifo->base ||!fifo->head || !fifo->tail){
		return FIFO_Null; //check about head and tail and base in or not
	}
	//check if empty
	if(fifo->counter ==0){
		return FIFO_empty;}
	*item=*(fifo->tail);
	fifo->counter--;
	if(fifo->tail ==(fifo->base + fifo->length * sizeof(element_type))){//to check if tail at the end of my array.
		fifo->tail= fifo->base;
	}
	else{
		fifo->tail++;
	}
	return FIFO_no_error;
}
FIFO_Buff_status_t FIFO_Isfull(FIFO_Buff_t* fifo){
	if (!fifo->base|!fifo->head || !fifo->tail)
		return FIFO_Null; //check about head and tail and base in or not
	if(fifo->length ==fifo->counter)
		return FIFO_full;
	return FIFO_no_error;
}

void FIFO_print(FIFO_Buff_t* fifo){
	element_type *temp;
	int i;
	if(fifo->counter ==0){
		printf("\n===FIFO Is EmMpty===\n");
	}
	else{
		temp=fifo->tail; //why tail?because if we aleady pop elements so we have to start at tail
		printf("\n===FIFO_Print===\n");
		for(i=0;i < fifo->counter ;i++){
			printf("\t %x\n",*temp);
		temp++;
		}
	}
	printf("\n ===============");
}
