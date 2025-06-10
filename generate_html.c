#include <stdio.h>
#include <time.h>
#include <string.h>
#include "student_data.h"

/**
 * Generates HTML header with embedded CSS and improved structure
 * @param file File pointer for HTML output
 */
void generateHTMLHeader(FILE *file) {
    if (file == NULL) {
        printf("Error: Invalid file pointer for HTML generation.\n");
        return;
    }
    
    // Get current time for report generation timestamp
    time_t now = time(NULL);
    char* timeStr = ctime(&now);
    // Remove newline from time string
    size_t len = strlen(timeStr);
    if (len > 0 && timeStr[len - 1] == '\n') {
        timeStr[len - 1] = '\0';
    }
    
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html lang=\"en\">\n");
    fprintf(file, "<head>\n");
    fprintf(file, "    <meta charset=\"UTF-8\">\n");
    fprintf(file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(file, "    <title>Student Marks Report</title>\n");
    fprintf(file, "    <style>\n");
    fprintf(file, "        * {\n");
    fprintf(file, "            margin: 0;\n");
    fprintf(file, "            padding: 0;\n");
    fprintf(file, "            box-sizing: border-box;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        body {\n");
    fprintf(file, "            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\n");
    fprintf(file, "            background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%);\n");
    fprintf(file, "            min-height: 100vh;\n");
    fprintf(file, "            padding: 20px;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .container {\n");
    fprintf(file, "            max-width: 1200px;\n");
    fprintf(file, "            margin: 0 auto;\n");
    fprintf(file, "            background: white;\n");
    fprintf(file, "            border-radius: 10px;\n");
    fprintf(file, "            box-shadow: 0 10px 30px rgba(0,0,0,0.2);\n");
    fprintf(file, "            overflow: hidden;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .header {\n");
    fprintf(file, "            background: linear-gradient(45deg, #2c3e50, #34495e);\n");
    fprintf(file, "            color: white;\n");
    fprintf(file, "            padding: 30px;\n");
    fprintf(file, "            text-align: center;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        h1 {\n");
    fprintf(file, "            font-size: 2.5em;\n");
    fprintf(file, "            margin-bottom: 10px;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .timestamp {\n");
    fprintf(file, "            font-size: 0.9em;\n");
    fprintf(file, "            opacity: 0.8;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .table-container {\n");
    fprintf(file, "            padding: 20px;\n");
    fprintf(file, "            overflow-x: auto;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        table {\n");
    fprintf(file, "            width: 100%%;\n");
    fprintf(file, "            border-collapse: collapse;\n");
    fprintf(file, "            margin: 20px 0;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        th, td {\n");
    fprintf(file, "            padding: 15px;\n");
    fprintf(file, "            text-align: left;\n");
    fprintf(file, "            border-bottom: 1px solid #ddd;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        th {\n");
    fprintf(file, "            background-color: #f8f9fa;\n");
    fprintf(file, "            font-weight: 600;\n");
    fprintf(file, "            color: #2c3e50;\n");
    fprintf(file, "            text-transform: uppercase;\n");
    fprintf(file, "            font-size: 0.9em;\n");
    fprintf(file, "            letter-spacing: 0.5px;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        tr:hover {\n");
    fprintf(file, "            background-color: #f8f9fa;\n");
    fprintf(file, "            transform: scale(1.01);\n");
    fprintf(file, "            transition: all 0.2s ease;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .pass {\n");
    fprintf(file, "            background-color: #d4edda !important;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .fail {\n");
    fprintf(file, "            background-color: #f8d7da !important;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .pass td:last-child {\n");
    fprintf(file, "            color: #155724;\n");
    fprintf(file, "            font-weight: bold;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .fail td:last-child {\n");
    fprintf(file, "            color: #721c24;\n");
    fprintf(file, "            font-weight: bold;\n");
    fprintf(file, "        }\n");
    fprintf(file, "        .summary {\n");
    fprintf(file, "            padding: 20px;\n");
    fprintf(file, "            background-color: #f8f9fa;\n");
    fprintf(file, "            border-top: 1px solid #ddd;\n");
    fprintf(file, "            text-align: center;\n");
    fprintf(file, "            color: #6c757d;\n");
    fprintf(file, "        }\n");
    fprintf(file, "    </style>\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "    <div class=\"container\">\n");
    fprintf(file, "        <div class=\"header\">\n");
    fprintf(file, "            <h1>📊 Student Marks Report</h1>\n");
    fprintf(file, "            <div class=\"timestamp\">Generated on: %s</div>\n", timeStr);
    fprintf(file, "        </div>\n");
    fprintf(file, "        <div class=\"table-container\">\n");
    fprintf(file, "            <table>\n");
    fprintf(file, "                <thead>\n");
    fprintf(file, "                    <tr>\n");
    fprintf(file, "                        <th>Student Name</th>\n");
    fprintf(file, "                        <th>Total Marks</th>\n");
    fprintf(file, "                        <th>Average</th>\n");
    fprintf(file, "                        <th>Grade</th>\n");
    fprintf(file, "                        <th>Status</th>\n");
    fprintf(file, "                    </tr>\n");
    fprintf(file, "                </thead>\n");
    fprintf(file, "                <tbody>\n");
}

/**
 * Generates HTML footer with summary statistics
 * @param file File pointer for HTML output
 */
void generateHTMLFooter(FILE *file) {
    if (file == NULL) {
        printf("Error: Invalid file pointer for HTML generation.\n");
        return;
    }
    
    fprintf(file, "                </tbody>\n");
    fprintf(file, "            </table>\n");
    fprintf(file, "        </div>\n");
    fprintf(file, "        <div class=\"summary\">\n");
    fprintf(file, "            <p>Report generated by Student Marks Management System</p>\n");
    fprintf(file, "        </div>\n");
    fprintf(file, "    </div>\n");
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");
}
