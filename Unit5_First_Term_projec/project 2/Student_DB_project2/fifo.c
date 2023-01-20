/*
 * fifo.c
 *
 *  Created on: Jan 18, 2023
 *      Author: minas
 */
#include "fifo.h"
#include "Students.h"
//stack ptr is controlling where am i and where to put or remove data

FIFO_Status FIFO_init(FIFO_Buffer_t *FIFO_buf, Element_Type *item_buf, uint32 buf_len)
{
	if(FIFO_buf == NULL || item_buf == NULL || buf_len == 0)
	{
		printf("FIFO Initialization failed: Null pointer or zero length is passed\n");
		return FIFO_Is_Null;
	}

	FIFO_buf->Base = item_buf;
	FIFO_buf->Head = FIFO_buf->Base;
	FIFO_buf->Tail = FIFO_buf->Head;
	FIFO_buf->length = buf_len;
	FIFO_buf->counter = 0;

	return FIFO_No_Error;
}

FIFO_Status FIFO_enqueue(FIFO_Buffer_t *FIFO_buf, Element_Type item)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO Enqueue failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if((FIFO_is_full(FIFO_buf)) == FIFO_Is_Full)
	{
		printf("Enqueue failed: FIFO is full\n");
		return FIFO_Is_Full;
	}

	*(FIFO_buf->Head) = item;

	if((FIFO_buf->Head ) == (FIFO_buf->Base + (FIFO_buf->length * sizeof(Element_Type))))
	{
		FIFO_buf->Head = FIFO_buf->Base;
	}
	else
	{
		FIFO_buf->Head++;
	}

	FIFO_buf->counter++;

	return FIFO_No_Error;
}

FIFO_Status FIFO_dequeue(FIFO_Buffer_t *FIFO_buf, Element_Type *item)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO Dequeue failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if((FIFO_is_empty(FIFO_buf)) == FIFO_Is_Empty)
	{
		printf("Dequeue failed: FIFO is empty\n");
		return FIFO_Is_Empty;
	}

	*(item) = *(FIFO_buf->Tail);

	if((FIFO_buf->Tail ) == (FIFO_buf->Base + (FIFO_buf->length * sizeof(Element_Type))))
	{
		FIFO_buf->Tail = FIFO_buf->Base;
	}
	else
	{
		FIFO_buf->Tail++;
	}

	FIFO_buf->counter--;

	return FIFO_No_Error;
}

FIFO_Status FIFO_print(FIFO_Buffer_t *FIFO_buf)
{
	Element_Type* temp  = FIFO_buf->Base;
	Element_Type* Ctemp = FIFO_buf->Base;
	uint32 i , j;
	for(i = 0; i < GCounter ; i++)
		{
			printf("\n");
			printf("Student first name: %s\n"
				   "Student last name:  %s\n"
				   "Student roll number: %d\n"
				   "Student GPA number: %.2f\n"
				   "The courses IDs are: "
				   ,temp -> fName, temp -> lName, temp -> Roll, temp -> GPA);

			for(j = 0 ; j < Number_Of_Courses ; j++)
			{
				printf("%d ",Ctemp -> Course_ID[j]);
			}

			printf("\n");
			printf("----------------------------------------------\n");

			Ctemp++;
			temp++;
		}
	return FIFO_No_Error;
}

FIFO_Status FIFO_is_full(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO is full test failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if(FIFO_buf->counter == FIFO_buf->length)
	{
		printf("FIFO is full \n");
		return FIFO_Is_Full;
	}

	return FIFO_Is_NOT_Full;
}

FIFO_Status FIFO_is_empty(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO is empty test failed: Null is passed\n");
		return FIFO_Is_Null;
	}

	if(FIFO_buf->counter == 0)
	{
		printf("FIFO is empty \n");
		return FIFO_Is_Empty;
	}

	return FIFO_Is_NOT_Empty;
}

FIFO_Status FIFO_make_empty(FIFO_Buffer_t *FIFO_buf)
{
	if(FIFO_buf == NULL || FIFO_buf->Base == NULL || FIFO_buf->Head == NULL || FIFO_buf->Tail == NULL)
	{
		printf("FIFO make empty failed: Null is passed\n");
		return FIFO_Is_Null;
	}
	FIFO_buf->Head = FIFO_buf->Base;
	FIFO_buf->Tail = FIFO_buf->Head;
	FIFO_buf->counter = 0;

	return FIFO_No_Error;
}
