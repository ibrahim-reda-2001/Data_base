/*
 * Linked_List_Student_Project.h
 *
 *  Created on: 17 Aug 2023
 *      Author: Eldeeb
 */

#ifndef LINKED_LIST_STUDENT_PROJECT_H_
#define LINKED_LIST_STUDENT_PROJECT_H_

#define DPRINTF(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;

};
struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextStudent;
};




//APIS
void AddStudent ();
int delete_student();
void view_students();
void DeleteAll();
int Search ();
void Count();
int Node_from_the_end();
void Mid();
void Reverse();




#endif /* LINKED_LIST_STUDENT_PROJECT_H_ */
