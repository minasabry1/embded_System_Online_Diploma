/*
 * Students.c

 *
 *  Created on: Jan 18, 2023
 *      Author: minas
 */
#include "Students.h"
#include "fifo.h"
#include<conio.h>

// Global counter for number of students
uint32 GCounter = 0;

//Another APIs for searching and deleting
uint8  FIFO_Search(FIFO_Buffer_t *Buff , union Type_Value value , enum Search_Type type);
void FIFO_Delete_by_Key(FIFO_Buffer_t *Buff, Element_Type* Buffer , union Type_Value value , uint32 Buff_Length);

// System APIs Implementation

void Add_Student_Manually()
{
	uint32 i ;
	// Create Student_ptrorary structure for the student information
	Element_Type* Student_ptr = (&Student_Data)->Base ;
	Element_Type  Current_Data ;
	if(GCounter == Buffer_Length)
	{
		printf("System is full \n");
		return;
	}
	/* Get the Roll number */
	printf("Enter the Roll Number: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Current_Data.Roll));
	/* Check if it is unique or not
	   Search for this Roll number through the queue */
	for (i = 0; (i < (&Student_Data) -> length) ; i++)
		{
			if  (Student_ptr -> Roll == Current_Data.Roll)
			{
				printf("===ERROR== Roll Number %d is already taken\n", Current_Data.Roll);
				printf("========Failed to add student========\n");
				return ;
			}
			Student_ptr++;
		}

	// If unique then get the other fields
		printf("Enter the first name of student: ");
		fflush(stdin);	fflush(stdout);
		gets(Current_Data.fName);
		printf("Enter the last name of student: ");
		fflush(stdin);	fflush(stdout);
		gets(Current_Data.lName);
		printf("Enter the GPA you obtained: ");
		fflush(stdin);	fflush(stdout);
		scanf("%f", &Current_Data.GPA);
		printf("Enter the course ID of each course\n");
		for (i = 0 ; i < Number_Of_Courses ; i++)
		{
			printf("Course %d id: ", i+1);
			fflush(stdin);	fflush(stdout);
			scanf("%d", &Current_Data.Course_ID[i]);
		}

		if(FIFO_enqueue(&Student_Data , Current_Data) == FIFO_No_Error)
		{
			printf("Student's Data are added successfully\n");
			GCounter++;
			printf("----------------------------------------------\n");
			Total_Students();
			return;
		}

		printf("========Failed to add student========\n");
}

void Add_Student_From_File()
{
	//  Open file in reading mode
	FILE *ptrFile;
	ptrFile = fopen ("data.txt", "r");

	// Check if NULL >> failed to open, else it is opened successfully
	if(ptrFile == NULL)
	{
		printf("===ERROR=== Can't open this .txt file \n");
		return;
	}

	char retChar ;
	char Student_ptrArr[20] = {0};
	uint32 i = 0, j = 0 , k = 6 ;

	uint8 flag = 0;
	uint32 z, Student_ptrPrint = 0;
	union Type_Value Student_ptrRollNum;
	Element_Type* Student_ptr = (&Student_Data) -> Head;
	Element_Type Student_ptr1 ;

	while(!feof(ptrFile))
	{
		//Check if Queue is full
		if(GCounter == Buffer_Length)
		{
			printf("System's Queue is full \n");
			return;
		}
		// Reading roll number of the student
		fscanf(ptrFile, "%d", &Student_ptr1.Roll);

		Element_Type* Student_ptrSearch = (&Student_Data) -> Head;
		flag = 0;
		for (i = 0; (i < (&Student_Data) -> length) ; i++)
		{
			if  (Student_ptrSearch -> Roll == Student_ptr1.Roll)
			{
				printf("===ERROR=== Roll Number %d is already taken\n",Student_ptr1.Roll);
				printf("========Failed to add student========\n");

				// Ignore the rest of the line
				fscanf(ptrFile, "%*[^\n]");
				flag = 1 ;
				break;
			}
			Student_ptrSearch++;
			}
			if(flag == 1)
			{
				continue;
				fscanf(ptrFile, "%*[^\n]");
			}
			else
			{
				Student_ptr -> Roll = Student_ptr1.Roll;
				GCounter++;

				fscanf(ptrFile, "%s", Student_ptr1.fName);
				strcpy(Student_ptr->fName , Student_ptr1.fName);

				fscanf(ptrFile, "%s", Student_ptr1.lName);
				strcpy(Student_ptr->lName , Student_ptr1.lName);

				fscanf(ptrFile, "%f", &Student_ptr1.GPA);
				Student_ptr -> GPA = Student_ptr1.GPA;

				for (i = 0; i < Number_Of_Courses; ++i)
				{
					fscanf(ptrFile, "%d", &Student_ptr1.Course_ID[i]);
				}

				for (i = 0; i < Number_Of_Courses; ++i)
				{
					Student_ptr->Course_ID[i] = Student_ptr1.Course_ID[i];
				}
				Student_ptr++;
		}
	}

	printf("  Students details are saved successfully\n");
	printf("----------------------------------------------\n");
	Total_Students();
	// Closing the file
	fclose(ptrFile);
}

void Find_Student_by_Roll_Number()
{
	union Type_Value Student_ptr;
	uint8 flag;

	printf("Enter the Roll number of the student: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Student_ptr.Roll_U));

	flag = FIFO_Search (&Student_Data, Student_ptr, ByRoll);

	if (flag == 0)
		printf("===ERROR=== Roll number %d not found\n", Student_ptr.Roll_U);
	printf("\n--------------------------------\n");
}

void Find_Student_by_First_Name()
{
	union Type_Value Student_ptr;
	uint8 flag;

	printf("Enter the first name of the student: ");
	fflush(stdin);	fflush(stdout);
	gets(Student_ptr.FName_U);

	flag = FIFO_Search (&Student_Data, Student_ptr, ByfName);

	if (flag == 0)
		printf("===ERROR=== The student's first name %s not found\n", Student_ptr.FName_U);
	printf("\n--------------------------------\n");
}

void Find_Students_by_Course()
{
	union Type_Value Student_ptr;
	uint8 flag;

	printf("Enter the course ID: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Student_ptr.Course_U));

	flag = FIFO_Search (&Student_Data, Student_ptr, ByID);
}

void Total_Students()
{
	printf("  The total number of students is %d\n", GCounter);
	printf("  You can add up to %d students\n", Buffer_Length);
	printf("  You can add %d more students\n", Buffer_Length - GCounter);
}

void Delete_Student_by_Roll_Number()
{
	union Type_Value Student_ptr;

	// Get the Roll number from the user
	printf("Enter the Roll number which you want to delete: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d", &(Student_ptr.Roll_U));

	// Call the function to delete
	FIFO_Delete_by_Key (&Student_Data , Student_Database , Student_ptr , Buffer_Length);
}

void Update_Student_by_Roll_Number()
{
	Element_Type* Student_ptr = (&Student_Data)->Base;
	uint32 i , j , Student_ptrRoll ;
	uint8 Option;

	printf("Enter the Roll number to update the entry: ");
	fflush(stdin);	fflush(stdout);
	scanf("%d",&Student_ptrRoll);

	for(i = 0 ; i < (&Student_Data)->length ; i++)
	{
		if(Student_ptr->Roll == Student_ptrRoll)
		{
			printf("Select a Number to edit \n");
			printf("1. First name\n2. Last name\n3. Roll number\n4. GPA\n5. Courses\n");
			fflush(stdin);	fflush(stdout);
			scanf("%d", &Option);

			switch(Option)
			{
				case 1:
					printf("Enter the first name: ");
					fflush(stdin);	fflush(stdout);
					gets(Student_ptr -> fName);
					break;
				case 2:
					printf("Enter the last name: ");
					fflush(stdin);	fflush(stdout);
					gets(Student_ptr -> lName);
					break;
				case 3:
					printf("Enter the Roll number: ");
					fflush(stdin);	fflush(stdout);
					scanf("%d", &(Student_ptr -> Roll));
					break;
				case 4:
					printf("Enter the GPA: ");
					fflush(stdin);	fflush(stdout);
					scanf("%f", &(Student_ptr -> GPA));
					break;
				case 5:
					printf("Enter the courses' IDs:\n");
					fflush(stdin);	fflush(stdout);
						for (j = 0; j < 5; j++)
						{
							printf("Course %d ID is : ", (j+1));
							fflush(stdin);  fflush(stdout);
							scanf("%d", &(Student_ptr -> Course_ID[j]));
						}
					break;
			}

			printf("  UPDATED SUCCESSFULLY.\n");
			return;
		}

		else
			Student_ptr++;
	}

	printf("===ERROR=== This Roll number %d not found\n", Student_ptrRoll);

}

void Show_Students_Info()
{
	FIFO_print(&Student_Data);
}

uint8 FIFO_Search(FIFO_Buffer_t* Buff , union Type_Value value , enum Search_Type type)
{
	/* Input: 1. Pointer to buffer
			  2. Data to search for
			  3. Type of data
	*/
	Element_Type* Student_ptr = Buff -> Base;
	uint32 i;
	uint32 j , Counter_S = 0 ;

	switch(type)
	{
		case ByRoll :	// Roll number
			for(i = 0 ; i < Buff->length ; i++)
			{
				if(Student_ptr->Roll == value.Roll_U)
				{
					// Print student information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The GPA is %.2f\nThe courses IDs are:",Student_ptr->fName , Student_ptr->lName , Student_ptr->GPA);
						for(j = 0 ; j < Number_Of_Courses ; j++)
						{
							printf("%d ", Student_ptr->Course_ID[j]);
						}
						return 1;
				}
				else
					Student_ptr++;
			}
			break;


		case ByfName :	// First Name
			for(i = 0 ; i < Buff->length ; i++)
			{
				if( !strcmp(Student_ptr->fName , value.FName_U))
				{
					// Print student information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The Roll number is %d \nThe GPA is %.2f\nThe courses IDs are:",Student_ptr->fName , Student_ptr->lName , Student_ptr->Roll , Student_ptr->GPA);
						for(j = 0 ; j < Number_Of_Courses ; j++)
						{
							printf("%d ", Student_ptr->Course_ID[j]);
						}
						return 1;
				}
				else
					Student_ptr++;
			}
			break;

		case ByID :	// Course ID
			for(i = 0 ; i < Buff->length ; i++)
			{
				for(j = 0 ; j < Number_Of_Courses ; j++)
				{
					if(Student_ptr -> Course_ID[j] == value.Course_U)
					{
						Counter_S++;
						// Print all students information
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The Roll number is %d \nThe GPA is %.2f\n",Student_ptr->fName , Student_ptr->lName , Student_ptr->Roll , Student_ptr->GPA);
					}
				}
				Student_ptr++;
			}
			if(Counter_S == 0)
			{
				printf("===ERROR=== course id %d not found\n", value.Course_U);
				printf("\n--------------------------------\n");
				return 0 ;
			}
			else
			{
				printf("Total number of students =: %d\n", Counter_S);
				printf("\n--------------------------------\n");
				return 1 ;
			}
			break;
	}

	// If not founded
	return 0;
}

void FIFO_Delete_by_Key(FIFO_Buffer_t* Buff, Element_Type* Buffer, union Type_Value value , uint32 Buff_Length)
{
	Element_Type* Student_ptr = Buff -> Base;
	uint32 Student_ptr1 = 0;
	uint32 i;
	for(i = 0 ; i < Buff->length ; i++)
	{
		if(Student_ptr->Roll == value.Roll_U)
		{
			Student_ptr1 = i;
			break ;
		}

		else
			Student_ptr++;
	}

	if(i >= Buff->length)
	{
		printf("===ERROR=== This Roll number %d not found\n", value.Roll_U);
		return;
	}

	Buff_Length = Buff_Length - 1 ;

	for (Student_ptr1 = i; Student_ptr1 < Buff_Length; Student_ptr1++)
	{
		Buffer[Student_ptr1] = Buffer[Student_ptr1 + 1];
	}

	// Decrement the buffer Head
	(Buff->Head)--;

	// Decrease the global counter by one to decrease the number of students
	GCounter--;
	printf("The Roll number %d is removed successfully\n", value.Roll_U);
}
