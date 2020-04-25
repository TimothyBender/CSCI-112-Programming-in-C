#include <stdio.h>
#include <string.h>
#include "grades.h"

void CalculateLetterGrade(Student_t* head) {

    // Created this to make the calculation code shorter and simpler
    // this struct is defined in grades.h
    Grade_t grades[11] = { {"A", 93.0}, {"A-", 90.0}, {"B+", 87.0},
                           {"B", 83.0}, {"B-", 80.0}, {"C+", 77.0},
                           {"C", 73.0}, {"C-", 70.0}, {"D+", 67.0},
                           {"D", 63.0}, {"D-", 60.0} };
     //Iterate through the LL
     Student_t* iterate = head;
	while(iterate != NULL){
        for (int j = 0; j < 11; ++j) {
            // this if is for determining letter grade 
            if (iterate -> grade >= (grades[j].lower_limit - 0.5)) {
               
                strcpy(iterate -> letter_grade, grades[j].letter);

                // this if is for determining if it hit that letter
                // grade because it was curved (within the .5 of the
                // lower limit
                if (iterate -> grade < (grades[j].lower_limit)) {
                    iterate -> curved = 'y';
                }
                else {
                    iterate -> curved = 'n';
                }
                break;
            }
        }
	//move to next one
	iterate = iterate->next;
    }
    return;
}
             
