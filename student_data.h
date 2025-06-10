#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H

#include <stdio.h>

#define NUM_SUBJECTS 5
#define MAX_STUDENTS 50
#define NAME_LENGTH 100
#define STATUS_LENGTH 20
#define MIN_MARK 0.0
#define MAX_MARK 100.0
#define PASS_MARK 50.0

typedef struct {
    char name[NAME_LENGTH];
    float marks[NUM_SUBJECTS];
    float total;
    float average;
    char status[STATUS_LENGTH];
    char grade;
} Student;

// Function prototypes
int inputStudentData(Student *student, char* stdSubjects[]);
void calculateStudentData(Student *student);
void logStudentData(Student *student, FILE *file);
void generateHTMLHeader(FILE *file);
void generateHTMLFooter(FILE *file);
char calculateGrade(float average);
int validateMark(float mark);
void clearInputBuffer(void);

#endif
