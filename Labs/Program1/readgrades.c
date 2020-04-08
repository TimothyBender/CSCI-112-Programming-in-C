#include "student.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//this method will read in the data from our input file
void readGrades(Student students[]){
        char c[200]; //holds the input from file
        FILE *fptr;
        //catch file not found errors
	int counter = 0; //will be used to iterate through the array of student structs
        //file not found check
	if((fptr = fopen("/public/examples/pgm1/grades.txt", "r")) == NULL){
                printf("Error, file not found");
                return;
        }
        while(fgets(c,200,fptr)){ //read the file in line by line, for each line add the data into the struct. 
		//We will need to slice off an added \n symbol on the grade that kept popping up for some reason
		char temp[20];
		strncpy(students[counter].lname,strtok(c,","),15); //store the last name
		strncpy(students[counter].fname,strtok(NULL,","),15); //store the first name
		strncpy(temp, strtok(NULL,","),15); //store the grade in temp
		strncpy(students[counter].grade,strtok(temp,"\n"),15); //use another strtok to slice off that \n
		counter++; 
	}
        fclose(fptr); //close the file

}

