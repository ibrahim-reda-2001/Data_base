#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
	#define Dprintf(...)        {fflush(stdout);\
						         fflush(stdin);\
						         printf(__VA_ARGS__);\
						         fflush(stdout);\
						         fflush(stdin);}

typedef struct {
	int id;
	char name[50];
	float height;
} Sdata;
//linked list node
struct SStudent {
	Sdata student;
	struct	SStudent* PNexStudent;
};
//is empty so point to null
struct SStudent* gpfirststudent=NULL;
void ADDSTUDENT(){
	struct	SStudent* PNweStudent;
	struct	SStudent* PLastStudent;
	char temp_text[40];
	//check list is empty
	if(gpfirststudent==NULL)//so it is empty
	{
		//create new recored
		PNweStudent=(struct SStudent*)malloc(sizeof(struct SStudent));
		gpfirststudent=PNweStudent;

		//assign it to gpfirststudent
	}
	else //list no empty
	{
		//navigate till reach last recored
		PLastStudent=gpfirststudent;
		while(PLastStudent->PNexStudent){
			PLastStudent=PLastStudent->PNexStudent;
			//create new recored
			PNweStudent=(struct SStudent*)malloc(sizeof(struct SStudent));
			PNweStudent=PLastStudent->PNexStudent;
		}

	}
	//fill new recored
	Dprintf("/nEnter the id \n");
	gets(temp_text);
	PNweStudent->student.id=atoi(temp_text);
	Dprintf("/nEnter the full name \n");
	gets(PNweStudent->student.name);
	Dprintf("/nEnter the height \n");
	gets(temp_text);
	PNweStudent->student.height=atof(temp_text);
	//set next pointer
	PNweStudent->PNexStudent=NULL;
}
int delet_student(){
	char temp_text[40];
	int selected_id;
	//get selected id
	Dprintf("/nEnter the student id to be deleted \n");
	gets(temp_text);
	selected_id=atoi(temp_text);
	//list is empty
	if(gpfirststudent){
		struct	SStudent* PSelectedStudent=gpfirststudent;
		struct	SStudent* PPreviousStudent=NULL;
		//loop all recorded
		while(PSelectedStudent){
			//compare id
			if(PSelectedStudent->student.id==selected_id){
				if(PPreviousStudent){
					PPreviousStudent->PNexStudent=PSelectedStudent->PNexStudent;
				}
				else{
					gpfirststudent=PSelectedStudent->PNexStudent;
				}
				free(PSelectedStudent);
				return 1;
			}
			PPreviousStudent=PSelectedStudent;
			PSelectedStudent=PSelectedStudent->PNexStudent;
		}
	}
	Dprintf("/n cannot find student id\n");
	return 0;
}
void view_student(){
	int count=0 ;
	struct	SStudent* PCurrentstudent=gpfirststudent;
	if(gpfirststudent==NULL){
		Dprintf("\n Empty\n");
	}
	while(PCurrentstudent){
		Dprintf("/n Recorded number: %d \n",count+1);
		Dprintf("/n ID : %d \n",PCurrentstudent->student.id);
		Dprintf("/n Name : %s \n",PCurrentstudent->student.name);
		Dprintf("/n Height : %.2f \n",PCurrentstudent->student.height);
		PCurrentstudent=PCurrentstudent->PNexStudent;
		count++;
	}

}
void delete_all(){
	struct	SStudent* PCurrentstudent=gpfirststudent;
	if(gpfirststudent==NULL){
		Dprintf("\n Empty\n");
	}
	while(PCurrentstudent){
		struct	SStudent* PTempstudent=PCurrentstudent;
		PCurrentstudent=PCurrentstudent->PNexStudent;
		free(PTempstudent);
	}
}
int main(){
	char temp_text[20];
	while(1){
		Dprintf("-------------------------\n");
		Dprintf("choose one of following options\n");
		Dprintf(" 1 : Add_Student \n");
		Dprintf(" 2 : Delete_Student \n");
		Dprintf(" 3 : View_Students \n");
		Dprintf(" 4 : Delete_All \n");
		Dprintf(" Enter the option number  \n");
		gets(temp_text);
		Dprintf("\n-------------------------\n");
		switch(atoi(temp_text)){
		case 1:
			ADDSTUDENT();
			break;
		case 2:
			delet_student();
			break;
		case 3:
			view_student();
			break;
		case 4:
			delete_all();
			break;
		default:
			Dprintf("\n wrong option \n");
			break;
		}
	}

	return 0;
}
