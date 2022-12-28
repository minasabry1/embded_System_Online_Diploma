/*
 * main.c
 *
 *  Created on: Dec 23, 2022
 *      Author: minas
 */
#include "lifo.h"
unsigned int buff1[5];

void main(){
	unsigned int i,temp=0;
	LIFO_Buf_t uart,i2c;
	//static
	Lifo_Init(&uart,buff1,5);
	//dynamic
	unsigned int* buff2=(unsigned int*) malloc(5 * sizeof(unsigned int));
	Lifo_Init(&i2c,buff2,5);
	for(i=0;i<5;i++){
		if(	Lifo_Add_Item(&uart,i) == LIFO_No_Error)
			printf("\n uart_lifo add :%d \n",i);
	}
	printf("================");
	for(i=0;i<5;i++){
		if (Lifo_Get_Item(&uart,&temp)== LIFO_No_Error)
			printf("\n uart_lifo get :%d \n",temp);
	}

}

