#include <stdio.h>
#include "student_data.h"

int main() {
    char* stdSubjects[NUM_SUBJECTS] = {"Math", "English", "Kiswahili", "Science", "Computer"};
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    FILE *htmlFile = fopen("index.html", "w");
    generateHTMLHeader(htmlFile);

    for (int i = 0; i < numStudents; i++) {
        inputStudentData(&students[i], stdSubjects);
        calculateStudentData(&students[i]);
        logStudentData(&students[i], htmlFile);
    }

    generateHTMLFooter(htmlFile);
    fclose(htmlFile);

    return 0;
}