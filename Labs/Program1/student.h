typedef struct{    //structure that contains the first name, last name, grade, letter grade, and finally a boolean char 
	char fname[20],
		lname[20],
			grade[20],
				 letter[3];
	char rounded;
}Student;


//Method declarations
void readGrades(Student students[]);
void printGrades(Student students[]);
void calculateLetterGrade(Student students[]);
