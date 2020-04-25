#include <stdio.h>
#include <string.h>
#include "grades.h"
#include <stdlib.h>

//this method will read in data from the input file and store it in a linked list.
//
Student_t* ReadGrades(Student_t* head) {

    //open the file for reading
    FILE* infptr = fopen("/public/examples/pgm1/grades.txt", "r");

    char line[80];

    char *result;

    if (infptr == NULL) {
        printf("ERROR: could not open input file\n");
    }
    //loop until at the en dof the file
    while (fgets(line, sizeof(line), infptr) != NULL) {
	//create a temp node that we will insert
	Student_t *temp = malloc(sizeof(Student_t)); 
	//read in all the data and insert it into our node
	temp->next = NULL;
	result = strtok(line, ",");
        strcpy(temp->last_name, result);
        
        result = strtok(NULL, ",");
        strcpy(temp->first_name, result);        

        result = strtok(NULL, ",");
        sscanf(result, "%lf", &temp->grade);
	//call the function inserthead to put the node into our LL
   	head = inserthead(temp,head);
    }
    fclose(infptr);
    return head;
} 
