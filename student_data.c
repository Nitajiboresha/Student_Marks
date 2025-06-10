#include <stdio.h>
#include <string.h>
#include "student_data.h"

void inputStudentData(Student *student, char* stdSubjects[]) {
    printf("Enter student name: ");
    scanf("%49s", student->name);
    for (int a = 0; a < NUM_SUBJECTS; a++) {
        printf("Enter marks for %s: ", stdSubjects[a]);
        scanf("%f", &student->marks[a]);
    }
}

void calculateStudentData(Student *student) {
    student->total = 0.0;
    for (int a = 0; a < NUM_SUBJECTS; a++) {
        student->total += student->marks[a];
    }
    student->average = student->total / NUM_SUBJECTS;
    if (student->average >= 50.0) {
        strcpy(student->status, "PASS");
    } else {
        strcpy(student->status, "FAIL");
    }
}

void logStudentData(Student *student, FILE *file) {
    fprintf(file, "<tr><td>%s</td><td>%.2f</td><td>%.2f</td><td>%s</td></tr>\n",
            student->name, student->total, student->average, student->status);
}