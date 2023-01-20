/*
 * Students.h
 *
 *  Created on: Jan 18, 2023
 *      Author: minas
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Platform.h"
#include "fifo.h"

// Total available number of students
#define Buffer_Length      50
#define Names_Max_size     20
#define Number_Of_Courses  5


// System Units
struct Student_Queue
{
	char    fName[Names_Max_size];	  // First name
	char    lName[Names_Max_size];   // Last name
	uint32  Roll;                    // Roll number
	float32 GPA;       // GPA
	uint32  Course_ID[Number_Of_Courses];  // Course ID
} Student_Database[Buffer_Length];  // Array of structures ((Buffer_Length) structure)


// system APIs
/*
 Number of total students and
 how many students could be added 		  */
void Total_Students();

/*
   Add a student manually after checking the
   uniqueness of the roll number If the roll
   number is not unique, error message will
   appear and nothing will be saved            */
void Add_Student_Manually();

/*
   Add the information of a group of students
   automatically from a text file after
   checking the uniqueness of the roll number
   of each student                             */
void Add_Student_From_File();

/*
   Find a student by the unique roll number    */
void Find_Student_by_Roll_Number();

/*
   Find a student the first name               */
void Find_Student_by_First_Name();

/*
   Find the students enrolled in a certain
   course (by the course ID)                   */
void Find_Students_by_Course();

/*
   Delete a students who has a certain roll
   number                                      */
void Delete_Student_by_Roll_Number();

/*
   Update one of the fields of the student
   information                                 */
void Update_Student_by_Roll_Number();

/*
   Print all the information of all students   */
void Show_Students_Info();

// Creating enum and union to handle searching function
enum Search_Type {ByRoll , ByGPA , ByfName , ByID};

union Type_Value
{
   uint32   Roll_U;
   float32 GPA_U;
   char* FName_U;
   uint32  Course_U;
};

#endif /* STUDENTS_H_ */
