/*
 * main.c
 *
 *  Created on: Dec 24, 2022
 *      Author: minas
 */
#include "fifo.h"
void main(){
	element_type i,temp=0;
	FIFO_Buff_t uart;
	if (FIFO_init(&uart,uart_buff,5)== FIFO_no_error)
		printf("fifo init ----Done	\n");
	for (i=0;i<7;i++){
		printf("\t fifo Enqueu(%x)----Done \n",i);
		if (FIFO_enqueue(&uart,i)== FIFO_no_error)
			printf("\t fifo enqueu ----Done \n");
		else
			printf("\t fifo enqueu----failed \n");
	}
	FIFO_print(&uart);
	if (FIFO_dequeue(&uart,&temp)== FIFO_no_error)
		printf("\nfifo dequeue ----Done(%x) \n",temp);
	if (FIFO_dequeue(&uart,&temp)== FIFO_no_error)
			printf("fifo dequeue ----Done(%x) \n",temp);
	FIFO_print(&uart);
}
