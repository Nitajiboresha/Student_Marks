#include <stdio.h>
#include "student_data.h"

void generateHTMLHeader(FILE *file) {
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html lang=\"en\">\n");
    fprintf(file, "<head>\n");
    fprintf(file, "    <meta charset=\"UTF-8\">\n");
    fprintf(file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(file, "    <title>Student Marks</title>\n");
    fprintf(file, "    <link rel=\"stylesheet\" href=\"style.css\">\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "<h1>Student Marks</h1>\n");
    fprintf(file, "<table>\n");
    fprintf(file, "<thead><tr><th>Name</th><th>Total</th><th>Average</th><th>Status</th></tr></thead>\n");
    fprintf(file, "<tbody>\n");
}

void generateHTMLFooter(FILE *file) {
    fprintf(file, "</tbody>\n");
    fprintf(file, "</table>\n");
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");
}