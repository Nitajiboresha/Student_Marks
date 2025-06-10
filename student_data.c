#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student_data.h"

/**
 * Clears the input buffer to handle invalid input
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Validates if a mark is within acceptable range
 * @param mark The mark to validate
 * @return 1 if valid, 0 if invalid
 */
int validateMark(float mark) {
    return (mark >= MIN_MARK && mark <= MAX_MARK);
}

/**
 * Calculates letter grade based on average
 * @param average The student's average mark
 * @return Letter grade (A, B, C, D, F)
 */
char calculateGrade(float average) {
    if (average >= 90.0) return 'A';
    else if (average >= 80.0) return 'B';
    else if (average >= 70.0) return 'C';
    else if (average >= 60.0) return 'D';
    else return 'F';
}

/**
 * Inputs student data with validation
 * @param student Pointer to student structure
 * @param stdSubjects Array of subject names
 * @return 1 if successful, 0 if failed
 */
int inputStudentData(Student *student, char* stdSubjects[]) {
    printf("\n=== Enter Student Information ===\n");
    
    // Input student name with validation
    printf("Enter student name (max %d characters): ", NAME_LENGTH - 1);
    clearInputBuffer();
    if (fgets(student->name, NAME_LENGTH, stdin) == NULL) {
        printf("Error: Failed to read student name.\n");
        return 0;
    }
    
    // Remove newline character if present
    size_t len = strlen(student->name);
    if (len > 0 && student->name[len - 1] == '\n') {
        student->name[len - 1] = '\0';
    }
    
    // Validate name is not empty
    if (strlen(student->name) == 0) {
        printf("Error: Student name cannot be empty.\n");
        return 0;
    }
    
    // Input marks for each subject with validation
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        float mark;
        int validInput = 0;
        
        while (!validInput) {
            printf("Enter marks for %s (%.1f - %.1f): ", stdSubjects[i], MIN_MARK, MAX_MARK);
            
            if (scanf("%f", &mark) != 1) {
                printf("Error: Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }
            
            if (!validateMark(mark)) {
                printf("Error: Mark must be between %.1f and %.1f.\n", MIN_MARK, MAX_MARK);
                continue;
            }
            
            student->marks[i] = mark;
            validInput = 1;
        }
    }
    
    printf("Student data entered successfully!\n");
    return 1;
}

/**
 * Calculates total, average, status, and grade for a student
 * @param student Pointer to student structure
 */
void calculateStudentData(Student *student) {
    // Calculate total marks
    student->total = 0.0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        student->total += student->marks[i];
    }
    
    // Calculate average
    student->average = student->total / NUM_SUBJECTS;
    
    // Determine pass/fail status
    if (student->average >= PASS_MARK) {
        strcpy(student->status, "PASS");
    } else {
        strcpy(student->status, "FAIL");
    }
    
    // Calculate letter grade
    student->grade = calculateGrade(student->average);
}

/**
 * Logs student data to HTML file with improved formatting
 * @param student Pointer to student structure
 * @param file File pointer for HTML output
 */
void logStudentData(Student *student, FILE *file) {
    if (file == NULL) {
        printf("Error: Invalid file pointer.\n");
        return;
    }
    
    // Add CSS class based on pass/fail status for styling
    const char* statusClass = (strcmp(student->status, "PASS") == 0) ? "pass" : "fail";
    
    fprintf(file, "        <tr class=\"%s\">\n", statusClass);
    fprintf(file, "            <td>%s</td>\n", student->name);
    fprintf(file, "            <td>%.1f</td>\n", student->total);
    fprintf(file, "            <td>%.2f</td>\n", student->average);
    fprintf(file, "            <td>%c</td>\n", student->grade);
    fprintf(file, "            <td class=\"%s\">%s</td>\n", statusClass, student->status);
    fprintf(file, "        </tr>\n");
}
