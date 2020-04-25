
typedef struct student{
    char first_name[30];
    char last_name[30];
    double grade;
    char letter_grade[3];
    char curved;
    struct student* next; 
}Student_t;

typedef struct {
    char letter[3];
    double lower_limit;
} Grade_t;

// function declarations
Student_t* ReadGrades(Student_t*);
void CalculateLetterGrade(Student_t*);
void PrintGrades(Student_t*);
Student_t* inserthead(Student_t*,Student_t*);
void sort(Student_t*);
