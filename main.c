#include "employee_management_system.h"
#include "admin.c"
#include "employee.c"
#include "file.c"
#include <stdio.h>
#include <string.h>

int main() {
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];

    // Array of person structures to store data for multiple employees
    Person employees[MAX_EMPLOYEES];

    // Store the Number of Employees to be Managed
    int numEmployees;
    printf("Enter the Number of Employees in your Organization: ");
    scanf("%d", &numEmployees);

    // Get User Input to store employee data
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter a username for Employee %d: ", i + 1);
        scanf("%s", employees[i].username);
        printf("Enter a password for Employee %d: ", i + 1);
        scanf("%s", employees[i].password);
        printf("Enter the number of hours worked by Employee %d: ", i + 1);
        scanf("%f", &employees[i].hoursWorked);
        employees[i].leaveBalance = 4; // Initialize leave balance

        // Error handling for isFullTime input
        int validInput = 0;
        while (!validInput) {
            printf("Enter 1 for full-time, 0 for part-time for Employee %d: ", i + 1);
            scanf("%d", &employees[i].isFullTime);
            if (employees[i].isFullTime == 1 || employees[i].isFullTime == 0) {
                validInput = 1;
            } else {
                printf("Invalid input! Please enter 1 for full-time or 0 for part-time.\n");
            }
        }

        // Call markAttendance function
        employees[i].present = markAttendance(employees[i].username);
    }

    // Call calculateUtilization function
    calculateUtilization(employees, numEmployees);

    // Save employee data to file
    saveEmployeesToFile(employees, numEmployees);

    // Prompt user for login credentials
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Convert input username to lowercase for case-insensitive comparison
    toLowerCase(username);

    // Admin functionalities
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        adminFunctionalities(employees, numEmployees);
    } else {
        printf("Employee access granted.\n");
        int found = 0;
        for (int i = 0; i < numEmployees; i++) {
            char storedUsername[MAX_USERNAME_LENGTH];
            strcpy(storedUsername, employees[i].username);
            toLowerCase(storedUsername);
            if (strcmp(username, storedUsername) == 0 && strcmp(password, employees[i].password) == 0) {
                employeeMenu(&employees[i], employees, numEmployees);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Employee not found or invalid credentials.\n");
        }
    }

    return 0;
}
