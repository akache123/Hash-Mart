#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define SIZE 20
#define MAX_NAME 256

struct Customer {
	char *email;
	char *name;
	char *shoesize;
	char *favfood;
	struct Customer *next;
};
int  indexshashi = 0;
struct Customer* hashArray[SIZE];
struct Customer* dummyCustomer;
struct Customer* item;
void init_hash_table(){

	for(int i = 0; i < SIZE; i++){
		hashArray[i] = NULL;

	}//end of for loop

}//end of init_hash_table
int hashCode(char *email1) {

char *email;
email=strdup(email1);



    unsigned long hash = 5381;
    int c;

    while((c = (*email++))){
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        hash = hash % SIZE;

    }

    return hash;

}

struct Customer* find(char *email1) {
	struct Customer *ptr5 = (struct Customer*) malloc(sizeof(struct Customer));
	char *email;
    email=strdup(email1);
	int hashIndex = hashCode(email);
	//hashIndex %= SIZE;
for(ptr5=hashArray[hashIndex] ; ptr5 !=NULL; ptr5 = ptr5->next)
 {
   if(strcmp(ptr5->email,email)==0) {
        return ptr5;
   }
 }
	free(ptr5);
  
	return NULL;
}


struct Customer* lookup(char *email1) {
	struct Customer *ptr = (struct Customer*) malloc(sizeof(struct Customer));
	char *email;
    email=strdup(email1);
	int hashIndex = hashCode(email);
	//hashIndex %= SIZE;
for(ptr=hashArray[hashIndex] ; ptr !=NULL; ptr = ptr->next)
 {
   if(strcmp(ptr->email,email)==0) {
        printf("Customer found\n");
        
        printf("Name = %s\n", ptr->name);
        printf("Shoe Size = %s\n", ptr->shoesize);
        printf("Favorite Food = %s\n", ptr->favfood);
        printf("\n \n");
        return ptr;
   }
 }
	printf("Customer not found\n");
free(ptr);
	return NULL;
}

void insert(char email[],char name[], char shoesize[], char favfood[]) {

	struct Customer *item1 = (struct Customer*) malloc(sizeof(struct Customer));

	item1->email= email;
	item1->name= name;
	item1->shoesize= shoesize;
	item1->favfood= favfood;

	int hashIndex = hashCode(email);

if(hashArray[hashIndex] == NULL){

    item1->next = NULL;
    hashArray[hashIndex] = item1;
}else{
    item1->next = hashArray[hashIndex];
    hashArray[hashIndex] = item1;

}

}

struct Customer* delete(char *email1) {

struct Customer *ptr = (struct Customer*) malloc(sizeof(struct Customer));
struct Customer *ptr1 = (struct Customer*) malloc(sizeof(struct Customer));
	char *email;
    email=strdup(email1);
	int hashIndex = hashCode(email);

	if(strcmp(hashArray[hashIndex]->email,email)==0){

	    ptr = hashArray[hashIndex];
	    hashArray[hashIndex] = hashArray[hashIndex]->next;
	    free(ptr);
	    printf("Customer with email %s is deleted successfully.\n",email);
	    return 0;
	}
    for(ptr=hashArray[hashIndex] ; ptr->next !=NULL; ptr = ptr->next)
     {
        ptr1=ptr->next;
        if(strcmp(ptr1->email,email)==0) {
           ptr->next=ptr1->next;
            free(ptr1);
            printf("Customer with email %s is deleted successfully.\n",email);
            break;
        }
     }
free(email);
free(ptr);
free(ptr1);
	return NULL;
}

void list() {

	int i = 0;



	for(i = 0; i<SIZE; i++) {


		if(hashArray[i] != NULL){
      struct Customer *ptr = hashArray[i];
      while(ptr != NULL){

        printf("\n \n");
        printf("Email = %s\n",ptr->email);
        printf("Name = %s\n", ptr->name);
        printf("Shoe Size = %s\n", ptr->shoesize);
        printf("Favorite Food = %s\n", ptr->favfood);
        ptr = ptr->next;


      }



    }
		else
		continue;
	}//for loop

	printf("\n");

}
void add(){

struct Customer *ptr2 = (struct Customer*) malloc(sizeof(struct Customer));
char email[50];
char name[50];
char shoesize[50];
char favfood[50];



char * email1;
char * name1;
char * shoesize1;
char * favfood1;

printf("Please enter an email address \n");

scanf("%s",email);
email1 = strdup(email);
while(getchar() != '\n');
printf("Please enter a name \n");

scanf("%[^\n]", name);
name1 = strdup(name);
while(getchar() != '\n');
printf("Please enter a shoe size \n");

scanf("%s",shoesize);
shoesize1 = strdup(shoesize);
while(getchar() != '\n');
printf("Please enter a favorite food \n");

scanf("%s",favfood);
favfood1 = strdup(favfood);
ptr2 = (struct Customer*) malloc(sizeof(struct Customer));
ptr2 =find(email1);
if(ptr2 != NULL){
    ptr2->name = name1;
    ptr2->shoesize = shoesize1;
    ptr2->favfood=favfood1;

}else{
insert(email1, name1, shoesize1, favfood1);
}

free(ptr2);
list();

}

void save(){
const char* STUDENT_DATA_FORMAT = "%s\t%s\t%s\t%s\n";
	FILE *fp = NULL;
	if((fp = fopen("customers.tsv", "w")) == NULL){

		printf("Could not open the file\n");

		return;

	}//end of first if statment

	/////////////
	int i = 0;

fseek(fp,0,SEEK_SET);

	for(i = 0; i<SIZE; i++) {


    if(hashArray[i] != NULL){
      struct Customer *ptr = hashArray[i];
      while(ptr != NULL){

        printf("\n \n");
        printf("Email = %s\n",ptr->email);
        printf("Name = %s\n", ptr->name);
        printf("Shoe Size = %s\n", ptr->shoesize);
        printf("Favorite Food = %s\n", ptr->favfood);
        fprintf(fp,STUDENT_DATA_FORMAT,ptr->email,ptr->name,ptr->shoesize,ptr->favfood);
        ptr = ptr->next;


      }



    }
		else
		continue;
	}//for loop


fclose(fp);
}
void action(char strcmd[]){


char email[50];
char *email1;
	if(strcmp(strcmd, "add") == 0){
		add();
	}

	if(strcmp(strcmd, "delete") == 0){

	printf("Enter the email to delete: \n");
    scanf("%s",email);
    email1 = strdup(email);
    if(lookup(email1) == NULL){

        printf("Could not find customer to delete.\n");
    }else{
        delete(email1);
    }

	}
	if(strcmp(strcmd, "lookup") == 0){

    printf("Enter the email: \n");
    scanf("%s",email);
    email1 = strdup(email);
    lookup(email1);


	}


	if(strcmp(strcmd, "list") == 0){

		list();


	}


	if(strcmp(strcmd, "save") == 0){

		save();
	}


	if(strcmp(strcmd, "quit") == 0){
		exit(0);
	}
}
void display(){

	char strcmd[20];
	printf("\tTo add a customer, please enter command (add)\n");
	printf("\tTo delete a customer, please enter command (delete)\n");
	printf("\tTo lookup a customer, please enter command (lookup)\n");
	printf("\tTo list all the customers, please enter command (list)\n");
	printf("\tTo save all the customers, please enter command (save)\n");
	printf("\tTo quit all the customers, please enter command (quit)\n");
	scanf("%s", strcmd);
	action(strcmd);
}
void load_customer(){
	int index = 0;
	FILE *fp = NULL;
	char *line = malloc(200);
	//char *ptr = NULL;
	char * email2;
	char * name2;
	char * shoesize2;
	char * favfood2;
	if((fp = fopen("customers.tsv", "r")) == NULL){

		printf("Could not open the file\n");

		return;

	}//end of first if statment

	while(fgets(line, 80 ,fp)){
    char email1[20];
	char name1[20];
	char shoesize1[3];
	char favfood1[20];

		//printf("line at :%s\n", line);
	   sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n", email1, name1,shoesize1,favfood1);
	   fflush(stdin);
		index = 0;
        email2 = strdup(email1);
        name2 = strdup(name1);
        shoesize2 = strdup(shoesize1);
        favfood2 = strdup(favfood1);
		insert(email2,name2,shoesize2,favfood2);

	}//end of while loop

free(line);
fclose(fp);


//list();
}//end of load_customer function

int main() {

	int i = 0;
	init_hash_table();

	load_customer();
	list();

	for(i = 0; ;i++){
		display();
	}


}

