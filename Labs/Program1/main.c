#include <stdio.h>
#include <string.h>
#include "student.h"

/*  Timothy Bender
 * CSCI 112 Programming in C
 * Program 1
 * Dr. Mary Anne Cummings
 * April 7, 2020
 */

int main(void){
	//create out initial array of structures, this will hold all the data about the students and their grades
	Student students[33];
	//to make a later step easier, we will set all of the rounded boolean char's to N
	for(int i = 0; i < 33; i++){
		students[i].rounded = 'N';
	}
	readGrades(students); //call the function to read in the file, and input the data into our students array
	calculateLetterGrade(students); //calculates letter grades, and rounds if necessary
	printGrades(students); //prints to output.txt
	return(0);
}




