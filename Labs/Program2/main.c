#include <stdio.h>
#include "grades.h"
#include <stdlib.h>
int main(void) {

    Student_t* head = NULL;
    
    // read in the file and put the data into an array of data structures
    head = ReadGrades(head);
    //sort the file
    sort(head);
    // determine letter grade
    CalculateLetterGrade(head);
    // print out names, numerical grade and letter grade
    PrintGrades(head);

    return(0);
}

