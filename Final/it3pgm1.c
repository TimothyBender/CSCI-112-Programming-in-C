#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Timothy Bender
 * CSCI 112
 * Test3 Program 1
 *
 */

//Here is our struct to store data
typedef struct{
	char name[20],
		code[4],
			 number[10];

}Contact;

//method delcaration
void readcontacts(Contact contacts[]);

int main(void){
	//create an array of structs to store data
	Contact contacts[6];
	readcontacts(contacts); //call readcontacts
	for(int i = 0; i < 6; i ++){
		printf("Business: %s Area Code: %s Phone: %s\n",contacts[i].name,contacts[i].code,contacts[i].number);	
	}
		

	return(1);
}


void readcontacts(Contact contacts[]){
	char c[40]; //will store each line in here
	FILE *fptr; //filepointer

	int counter = 0;
	//test if the file can be found and assign the pointer to it using write 
	if((fptr = fopen("/public/test3/phone_numbers.txt","r")) == NULL){
		printf("Error, file not found");
		return;
	} 
	//read in the data line by line, send into the array of structs
	while(fgets(c,40,fptr)){
		strncpy(contacts[counter].name,strtok(c," "),15);
		strncpy(contacts[counter].code,strtok(NULL,"-"),4);
		strncpy(contacts[counter].number,strtok(NULL,"\0"),15);
		counter++;
	}
	fclose(fptr);
	
}

