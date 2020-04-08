#include <stdio.h>
#include <string.h>
#include "student.h"
#include <stdlib.h>


//this method will determine what a student's letter grade is, and if necessary round it
void calculateLetterGrade(Student students[]){
	for(int x = 0; x < 33; x++){
		double grade = strtod(students[x].grade,'\0'); //convert the string grade into a double		
		
		//from here on it is a simple pattern of checking what range the grade is in, if it is within .5 of the
		//next letter grade's cut off we round the grade and mark it as rounded. 
		//rounded is automatically set to N in our main function.
		if(x >= 93.0){
			strcpy(students[x].letter,"A");
			students[x].rounded= 'N';
		}
		else if(grade >= 90){
			if(grade >= 92.5){
				strcpy(students[x].letter, "A");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter, "A-");
			}
		}
		else if(grade >= 87){
			if(grade>= 89.5){
				strcpy(students[x].letter,"A-");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter, "B+");
			}
		}
		else if(grade >= 83){
			if(grade>= 86.5){
				strcpy(students[x].letter,"B+");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"B");
			}
		}
		else if(grade >= 80){
			if(grade>= 82.5){
				strcpy(students[x].letter,"B");
				students[x].rounded = 'Y';	
			}
			else{
				strcpy(students[x].letter,"B-");
			}
		}
		else if(grade>=77){
			if(grade>= 79.5){
				strcpy(students[x].letter,"B-");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"C+");
			}
		}
		else if(grade>=73){
			if(grade>=76.5){
				strcpy(students[x].letter,"C+");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"C");
			}
		}
		else if(grade>= 70){
			if(grade>=72.5){
				strcpy(students[x].letter,"C");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"C-");
			}
		}
		else if(grade>=67){
			if(grade>=69.5){
				strcpy(students[x].letter,"C-");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"D+");
			}
		}
		else if(grade>=63){
			if(grade>= 66.5){
				strcpy(students[x].letter,"D+");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"D");
			}
		}
		else if(grade>=60){
			if(grade>=62.5){
				strcpy(students[x].letter,"D");
				students[x].rounded = 'Y';
			}
			else{
				strcpy(students[x].letter,"D-");
			}
		}

	}



}


