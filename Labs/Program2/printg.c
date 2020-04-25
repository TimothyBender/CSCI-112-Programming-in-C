#include <stdio.h>
#include "grades.h"
//this method will print the grades to an output file
void PrintGrades(Student_t* head) {
    //file pointer for output
    FILE* outfptr = fopen("out.txt", "w");
    
    //pointer for iteration
    Student_t* iterate = head;
   
    //loop to the end of the list
    while(iterate != NULL){
	    //bunch of string formating stuff. put in file
	fprintf(outfptr, "Name: %s %s \tGrade: %-4lf %-3s Curved? %c\n",
			iterate->first_name,iterate->last_name,
			iterate->grade, iterate->letter_grade,
			iterate->curved);
    	iterate = iterate ->next; //continue to next position
    }
  	 
    fclose(outfptr); //close the file
    return;
}

