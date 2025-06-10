#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H

#define NUM_SUBJECTS 5
#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    float marks[NUM_SUBJECTS];
    float total;
    float average;
    char status[10];
} Student;

void inputStudentData(Student *student, char* stdSubjects[]);
void calculateStudentData(Student *student);
void logStudentData(Student *student, FILE *file);

#endif