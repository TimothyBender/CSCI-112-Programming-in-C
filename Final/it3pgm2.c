#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Timothy Bender
 * CSCI 112
 * Test 3 
 * Program 2
 */

typedef struct number{
	char num[2];
	struct number* next;

}number_t;

number_t* readnumbers(number_t*);
number_t* insert(number_t*,number_t*);
int main(void){
	number_t* head = NULL;
	head = readnumbers(head);
	number_t* iterate = head;
	while(iterate != NULL){
		printf("%s",iterate->num);
		iterate = iterate -> next;

	}	
	return(1);
}


number_t* readnumbers(number_t* head){
	FILE* fptr = fopen("/public/test3/numbers.txt","r");
	char input[3];
	if(fptr == NULL){
		printf("Error: file not found");
	}
	while(fgets(input,sizeof(input),fptr) != NULL){
		number_t *temp = malloc(sizeof(number_t));
		temp->next = NULL;
		//printf("%s",input);
		strcpy(temp -> num,input);		
		head = insert(temp,head);	
	}
	fclose(fptr);
	return head;	
}

number_t* insert(number_t* temp, number_t* head){
	temp->next = head;
	return temp;
}



