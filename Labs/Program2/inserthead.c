#include <stdio.h>
#include <stdlib.h>
#include "grades.h"

Student_t* inserthead(Student_t* temp, Student_t* head){
	temp->next = head;
	return temp;
}
