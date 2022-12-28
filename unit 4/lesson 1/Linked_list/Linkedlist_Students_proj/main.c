/*
 * main.c
 *
 *  Created on: Dec 28, 2022
 *      Author: minas
 */


#include "Linked_list.h"
struct Student_Node_t* gFirst_student = NULL;

void Fill_A_New_Record(struct Student_Node_t *NewStudent)
{
	char temp_text[Max_Name_Size];

	DPRINTF("Enter the student's ID : ");
	gets(temp_text);
	NewStudent->Student.ID = atoi(temp_text);

	DPRINTF("Enter the student's name : ");
	gets(NewStudent->Student.name);

	DPRINTF("Enter the student's hight : ");
	gets(temp_text);
	NewStudent->Student.hight = atof(temp_text);
}

void Add_Student(void)
{
	struct Student_Node_t* PnewStudent;
	struct Student_Node_t* PlastStudent;

	if(gFirst_student == NULL)
	{
		//Creat a new record
		PnewStudent = (struct Student_Node_t*) malloc(sizeof(struct Student_Node_t));

		// Check for invalid allocation
		if(PnewStudent == NULL)
		{
			DPRINTF("Error: Can't create new student\n");
			return;
		}

		//Assign it to gFirst_student
		gFirst_student = PnewStudent;
	}
	else
	{
		//Navigate until reach the last record
		PlastStudent = gFirst_student;
		while(PlastStudent->Next_Student_Ptr)//not eaual null.
		{
			PlastStudent = PlastStudent->Next_Student_Ptr;
		}

		//Creat a new record
		PnewStudent = (struct Student_Node_t*) malloc(sizeof(struct Student_Node_t));

		// Check for invalid allocation
		if(PnewStudent == NULL)
		{
			DPRINTF("Error: Can't create new student\n");
			return;
		}

		// Assign its next to it
		PlastStudent->Next_Student_Ptr = PnewStudent;
	}
	// Fill the record
	Fill_A_New_Record(PnewStudent);

	// Assign its next to null
	PnewStudent->Next_Student_Ptr = NULL;
}

int Delete_Student(void)
{
	char temp_text[Max_Name_Size];
	unsigned int selected_id;

	// Get the selected ID from the user
	DPRINTF("\nEnter Student's ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);
	//check if list is empty
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		struct Student_Node_t* PPreviousStudent = NULL;
		//loop on all records
		while(PselectedStudent)//loop till the last node
		{
			//Compare each node with the selected ID
			if(PselectedStudent->Student.ID == selected_id)
			{
				if (PPreviousStudent) //The selected student is not the first one
				{
					PPreviousStudent->Next_Student_Ptr = PselectedStudent->Next_Student_Ptr;
				}
				else //the first one
				{
					gFirst_student = PselectedStudent->Next_Student_Ptr;
				}
				free(PselectedStudent);
				DPRINTF("\nThe selected ID have deleted. \n");
				return 1;
			}

			PPreviousStudent = PselectedStudent;
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
		}
		DPRINTF("\n\tThe selected ID not find. \n");
		return 0;
	}

	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return 0;
	}
}

void View_students(void)
{
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		unsigned int counter = 1 ;
		while(PselectedStudent)
		{
			DPRINTF("\n Record Number %d",counter);
			DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
			DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
			DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			counter++;
		}
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
}

void Delete_All(void)
{
	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;
		while(PselectedStudent)
		{
			struct Student_Node_t* PtempStudent = PselectedStudent;
			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			free(PtempStudent);
		}
		gFirst_student = NULL;
		DPRINTF("\nThe list's elements have deleted\n");
		return;
	}

	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return;
	}
}
void Get_Node(unsigned int index)
{
	unsigned int counter = 1;

	if(index < 0)
	{
		DPRINTF("\nInvalid index\n");
		return;
	}

	if(gFirst_student)
	{
		struct Student_Node_t* PselectedStudent = gFirst_student;

		while(PselectedStudent)
		{
			if(counter == index)
			{
				DPRINTF("\n Record Index %d",index);
				DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
				DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
				DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
				return;
			}

			PselectedStudent = PselectedStudent->Next_Student_Ptr;
			counter++;
		}
		return;
	}

	else
	{
		DPRINTF("\nThe list is NULL !\n");
		return;
	}
}

int Students_Length_Iterative(void){
	static unsigned int count=1;
	struct Student_Node_t* PselectedStudent = gFirst_student;
	if(gFirst_student)
	{
		while(PselectedStudent)
		{
			if(PselectedStudent->Next_Student_Ptr == NULL)
				break;
			PselectedStudent=PselectedStudent->Next_Student_Ptr;
			count++;
		}
		return count;
	}
	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return 0;
	}
}
int Students_Length_Recursive(struct Student_Node_t* head){
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + (Students_Length_Recursive(head->Next_Student_Ptr)));
		//each time will return 1+1+1+1 till get null and plus all ones and return no.
	}
}
void Get_Node_fromend(unsigned int index){

	if(index < 0)
	{
		DPRINTF("\nInvalid index\n");
		return;
	}
	if(gFirst_student)
	{
		static unsigned int i,count=0;
		struct Student_Node_t* Main_Student = gFirst_student;
		struct Student_Node_t* Previous_Student = gFirst_student;
		while(Previous_Student){
			Previous_Student=Previous_Student->Next_Student_Ptr;
			count++;
			if(count == index){
				break;
			}
		}
		while(Previous_Student){
			Previous_Student=Previous_Student->Next_Student_Ptr;
			Main_Student=Main_Student->Next_Student_Ptr;

		}
		DPRINTF("\n\t ID : %d",Main_Student->Student.ID);
		DPRINTF("\n\t Name : %s",Main_Student->Student.name);
		DPRINTF("\n\t Height : %0.2f\n",Main_Student->Student.hight);

	}
	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return;
	}
}
/*     NOTE:the method at lecture about get the mdidle node is wrong--(why)?
 * its true for odd node because we have to stop at last node to get middle not at null
 * but at even we have to go to null,so it not serving both,only odd nodes
 */
void Get_Middle_Student(void){
	unsigned int i=1;
	unsigned int count=	Students_Length_Iterative();
	struct Student_Node_t* PselectedStudent = gFirst_student;
	if(gFirst_student)
	{
		if (count %2 ==0){
			for(i;i <= count/2;i++){
				PselectedStudent=PselectedStudent->Next_Student_Ptr;
			}
			DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
			DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
			DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
			return;
		}
		else if(count %2 !=0){
			for(i;i <= count/2;i++){
				PselectedStudent=PselectedStudent->Next_Student_Ptr;
			}
			DPRINTF("\n\t ID : %d",PselectedStudent->Student.ID);
			DPRINTF("\n\t Name : %s",PselectedStudent->Student.name);
			DPRINTF("\n\t Height : %0.2f\n",PselectedStudent->Student.hight);
			return;
		}

	}


	else
	{
		DPRINTF("\nThe list is already NULL !\n");
		return;
	}
}
void Reverse_Students(void)
{
	struct Student_Node_t* Pnext 	  = NULL;
	struct Student_Node_t* Pcurrent  = gFirst_student;
	struct Student_Node_t* Pprevious = NULL;

	while(Pcurrent)
	{
		Pnext = Pcurrent->Next_Student_Ptr;
		Pcurrent->Next_Student_Ptr = Pprevious;
		Pprevious = Pcurrent;
		Pcurrent = Pnext;
	}
	gFirst_student = Pprevious;
	while(Pprevious !=NULL){

	DPRINTF("\n\t ID : %d",Pprevious->Student.ID);
	DPRINTF("\n\t Name : %s",Pprevious->Student.name);
	DPRINTF("\n\t Height : %0.2f\n",Pprevious->Student.hight);
	Pprevious=Pprevious->Next_Student_Ptr;
}
}

int main(void)
{
	char temp_text[Max_Name_Size];
	int num = 0;
	struct Student_Node_t *gpStudent = NULL ;

	while(1)
	{
		DPRINTF(" ============================= ");
		DPRINTF("\n Choose one from the following options \n");
		DPRINTF("\n\t 1: Add Student");
		DPRINTF("\n\t 2: Delete Student");
		DPRINTF("\n\t 3: View Students");
		DPRINTF("\n\t 4: Delete All");
		DPRINTF("\n\t 5: Get Node");
		DPRINTF("\n\t 6: Get Students count by Iteration");
		DPRINTF("\n\t 7: Get Students count by Recursion");
		DPRINTF("\n\t 8: Get Node from the end");
		DPRINTF("\n\t 9: Get the middle student");
		DPRINTF("\n\t 10: Reverse student");
		DPRINTF("\n\t 11: Exit");
		DPRINTF("\n\n Enter option number: ");

		gets(temp_text);
		DPRINTF("\n ============================= \n");
		switch(atoi(temp_text))
		{
		case 1:
			Add_Student();
			break;

		case 2:
			Delete_Student();
			break;

		case 3:
			View_students();
			break;

		case 4:
			Delete_All();
			break;

		case 5:
			DPRINTF("Enter Node Number: ");
			gets(temp_text);
			num = atoi(temp_text);
			Get_Node(num);
			break;

		case 6:
			num = Students_Length_Iterative();
			DPRINTF("Student Numbers : %d\n", num);
			break;

		case 7:
			num = Students_Length_Recursive(gpStudent);
			DPRINTF("Student Numbers : %d\n", num);
			break;

		case 8:
			DPRINTF("Enter Node Number from the end : ");
			gets(temp_text);
			num = atoi(temp_text);
			Get_Node_fromend(num);
			break;

		case 9:
			Get_Middle_Student();
			break;

		case 10:
			Reverse_Students();
			break;

		case 11:
			return 0;

		default:
			DPRINTF("\n Wrong Option: Try Again \n\n");
			break;

		}

	}
	return 0;
}




