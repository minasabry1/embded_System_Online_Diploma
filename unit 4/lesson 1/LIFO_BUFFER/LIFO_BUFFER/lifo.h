
#ifndef _LIFO_H
#define _LIFO_H
#include <stdio.h>
#include "stdlib.h"
//type Definitions
typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_Buf_t;

typedef enum{
	LIFO_No_Error, //0
	LIFO_Full, //1
	LIFO_Empty, //2
	LIFO_Null //3
}LIFO_status;


//APIS
LIFO_status Lifo_Add_Item(LIFO_Buf_t* buff,unsigned int item);
LIFO_status Lifo_Get_Item(LIFO_Buf_t* buff,unsigned int* item);
LIFO_status Lifo_Init(LIFO_Buf_t* buff,unsigned int* buf, unsigned int length);
#endif
