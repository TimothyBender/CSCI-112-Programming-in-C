#include <stdio.h>
#include "grades.h" 
#include <string.h>

//this method will use selection sort with data swap to sort the linked list. 
void sort(Student_t* head){
	Student_t* temp = head; 

	//iterate through the list
	while(temp != NULL){
		Student_t* max = temp;
		Student_t* iterate = temp -> next;
		//Now we will iterate through the unsorted part of the list
		while(iterate != NULL){
			//sorting highest to lowest
			if(max->grade < iterate->grade){
				max = iterate;
			}
			iterate = iterate->next;
		}
	//store temp's data into temporary variables
	char fname[30],lname[30],letter[3],curved = temp-> curved;
	strcpy(fname,temp->first_name);
	strcpy(lname,temp->last_name);
	double grade = temp-> grade;
	strcpy(letter,temp->letter_grade);
	//swap the data from max into temp
	strcpy(temp->first_name, max->first_name);
	strcpy(temp->last_name, max->last_name);
	temp->grade = max->grade;
	strcpy(temp->letter_grade, max->letter_grade);
	temp->curved = max->curved;
	//swap temp's stored data into max
	strcpy(max->first_name, fname);
        strcpy(max->last_name, lname);
	max->grade = grade;
        strcpy(max->letter_grade, letter);
	max->curved = curved;
	//continue iterating
	temp = temp->next;

	
	}


}


