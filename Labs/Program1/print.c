#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

void printGrades(Student students[]){
	fclose(fopen("output.txt","w"));//wipe the contents of output.txt if it already exists
	FILE *fptr = fopen("output.txt","a"); //FILE pointer to our output file, set to append
        if(fptr == NULL){//file not found check
                return;
 	}
	for(int i = 0; i < 33 ; i ++){ //iterate through the students array, and print a formated string containing the data to output.txt
		fprintf(fptr,"Name: %s %s Grade: %.7s %s Curved? %c \n",students[i].fname,students[i].lname,
				students[i].grade,students[i].letter,students[i].rounded);  //append in the string
		//print the same information to the terminal.
		printf("Name: %s %s Grade: %.7s %s Curved? %c \n",students[i].fname,students[i].lname,
				students[i].grade,students[i].letter,students[i].rounded);
	}
        fclose(fptr);
        return;	

}
