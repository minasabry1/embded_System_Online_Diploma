/*
 * lifo.c

 *
 *  Created on: Dec 23, 2022
 *      Author: minas
 */
#include "lifo.h"
LIFO_status Lifo_Add_Item(LIFO_Buf_t* buff,unsigned int item){
	//valid or not
	if(!buff->base || !buff->head)
		return LIFO_Null;
	//full or not
	if(buff->head >= (buff->base + (buff->length*4)))
		return LIFO_Full;

	//add item
	*(buff->head)=item;
	buff->count++;
	buff->head++;
	return LIFO_No_Error;
}
LIFO_status Lifo_Get_Item(LIFO_Buf_t* buff,unsigned int* item){

	//valid or not
	if(!buff->base || !buff->head)
		return LIFO_Null;

	//is empty or not
	if(buff->count ==0)
		return LIFO_Empty;
	buff->head--;
	*(item) = *(buff->head);
	buff->count--;

	return LIFO_No_Error;
}




LIFO_status Lifo_Init(LIFO_Buf_t* buff,unsigned int* buf, unsigned int length){
	if(buf == NULL){ //if the dynamic allocation is full so will return null and became invalid
		return LIFO_Null;
	}
	buff->base=buf;
	buff->head=buf;
	buff->count=0;
	buff->length=length;
	return LIFO_No_Error;
}

