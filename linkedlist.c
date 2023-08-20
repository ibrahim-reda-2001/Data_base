

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "linkedlist.h"

struct SStudent* gpFirstStudent=NULL ;

void AddStudent ()
{
	 //gpFirstStudent=NULL;
	//struct SStudent* gpFirstStudent=NULL ;
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text[40];
	//check list is emppty == yes
	if (gpFirstStudent==NULL)
	{
		//create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		//assign it to gpfirst
		gpFirstStudent = pNewStudent;
	}
	else //list contains records
	{
		//navigate until reach to the last
		pLastStudent = gpFirstStudent;
		while (pLastStudent->PNextStudent)
			pLastStudent=pLastStudent->PNextStudent;
		//create new record
		if (pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent))){
			pLastStudent->PNextStudent=pNewStudent;}

	}
	//fill new record
	DPRINTF("\n Enter the ID : ");
	gets (temp_text);
	pNewStudent->student.ID =atoi(temp_text);

	DPRINTF("\n Enter student full name : ");
	gets (pNewStudent->student.name);


	DPRINTF("\n Enter the height : ");
	gets (temp_text);
	pNewStudent->student.height =atof(temp_text);

	//set the next pointer
	pNewStudent->PNextStudent=NULL;
}


int delete_student()
{
	//struct SStudent* gpFirstStudent=NULL ;

	char temp_text[40];
	unsigned int selected_id;

	//get the selected id
	DPRINTF("\n enter the student id to be deleted :");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//list is not empty
	if (gpFirstStudent)
	{
		struct SStudent* pSlectedStudent =gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;

		//loop on all records
		while(pSlectedStudent)
		{
			//compare each node with the selected ID
			if(pSlectedStudent->student.ID==selected_id)
			{
				if(pPreviousStudent) // the first student is not the selected one
				{
					pPreviousStudent->PNextStudent = pSlectedStudent->PNextStudent ;
				}
				else //1st student == ID
				{
					gpFirstStudent=pSlectedStudent->PNextStudent;
				}
				free(pSlectedStudent);
				return 1;
			}
			pPreviousStudent = pSlectedStudent ;
			pSlectedStudent = pSlectedStudent->PNextStudent;

		}
	}
	DPRINTF("\n Cannot find student ID.");
	return 0;
}

void view_students()
{
	//struct SStudent* gpFirstStudent=NULL ;

	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int count=0;

	if(gpFirstStudent==NULL)
		{DPRINTF("\n Empty List");}
	else
	{
		while (pCurrentStudent)
		{
			DPRINTF("\n record number %d ",count+1);
			DPRINTF("\n \t ID: %d ",pCurrentStudent->student.ID);
			DPRINTF("\n \t Name %s ",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %f ",pCurrentStudent->student.height);
			pCurrentStudent=pCurrentStudent->PNextStudent;
			count++;
		}
	}
}

void DeleteAll()
{
	//struct SStudent* gpFirstStudent=NULL ;

	struct SStudent* pCurrentStudent =gpFirstStudent ;
	if (gpFirstStudent==NULL)
		{DPRINTF("\n Empty List");}
	else
	{
		while (pCurrentStudent)
		{
			struct SStudent* pTempStudent=pCurrentStudent ;
			pCurrentStudent=pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent=NULL;
	}
}

int Search()
{
	//struct SStudent* gpFirstStudent ;

	char index[40];
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int search,count=0;
	if(gpFirstStudent==NULL)
		{DPRINTF("\n Empty List");}
	else
	{
		DPRINTF("\nEnter the index : ");
		gets(index);
		search=atoi(index);
		while (pCurrentStudent)
		{
			if(count==search)
			{
			DPRINTF("\n record number %d ",count+1);
			DPRINTF("\n \t ID: %d ",pCurrentStudent->student.ID);
			DPRINTF("\n \t Name %s ",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %f ",pCurrentStudent->student.height);
			return 1;
			}
			else
			{
				pCurrentStudent=pCurrentStudent->PNextStudent;
				count++;
			}
		}
	}
	DPRINTF("INVALID INDEX");
	return 0 ;
}

void Count()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	int count=0;
	if(gpFirstStudent==NULL)
			{DPRINTF("\n Empty List");}
	while (pCurrentStudent)
	{
		pCurrentStudent=pCurrentStudent->PNextStudent;
		count++;
	}
	DPRINTF("\n number of nodes %d",count);

}

int Node_from_the_end()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	struct SStudent* pReferenceStudent =gpFirstStudent ;
	int count=0,counter=0;
	char node[40];
	int search;
	DPRINTF("\nEnter index : ");
	gets(node);
	search = atoi(node);
	while(count!=search)
	{
		count++;
		pReferenceStudent=pReferenceStudent->PNextStudent;
	}
	while (pReferenceStudent)
	{
		if (counter==search)
		{
			DPRINTF("\n record number %d ",counter);
			DPRINTF("\n \t ID: %d ",pCurrentStudent->student.ID);
			DPRINTF("\n \t Name %s ",pCurrentStudent->student.name);
			DPRINTF("\n \t height: %f ",pCurrentStudent->student.height);
			return 1;
		}
		else
		{
		counter++;
		pReferenceStudent=pCurrentStudent->PNextStudent;
		pReferenceStudent=pReferenceStudent->PNextStudent;
		}
	}

return 0;
}

void Mid()
{
	struct SStudent* pSlowStudent =gpFirstStudent ;
	struct SStudent* pFastStudent =gpFirstStudent ;
	int count = 0;
	while (pFastStudent)
	{
		count++;
		pFastStudent=pFastStudent->PNextStudent;
		pFastStudent=pFastStudent->PNextStudent;
		pSlowStudent=pSlowStudent->PNextStudent;
	}
	DPRINTF("\n record number %d ",count);
	DPRINTF("\n \t ID: %d ",pSlowStudent->student.ID);
	DPRINTF("\n \t Name %s ",pSlowStudent->student.name);
	DPRINTF("\n \t height: %f ",pSlowStudent->student.height);

}

void Reverse()
{
	struct SStudent* pCurrentStudent =gpFirstStudent ;
	struct SStudent* pPreviousStudent =NULL ;
	struct SStudent* pNextStudent =NULL ;

    while (pCurrentStudent) {
        // Store next
    	pNextStudent = pCurrentStudent->PNextStudent;

        // Reverse current node
    	pCurrentStudent->PNextStudent = pPreviousStudent;

        // Move pointers one position ahead.
    	pPreviousStudent = pCurrentStudent;
    	pCurrentStudent = pNextStudent;
    }
    gpFirstStudent= pPreviousStudent;
}
