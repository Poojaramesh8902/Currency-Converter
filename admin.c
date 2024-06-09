#include "employee_management_system.h"
#include <stdio.h>

// Function for admin to view all employee reports
void viewAllReports(Person employees[], int numEmployees) {
    printf("Employee Reports:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d - %s: ", i + 1, employees[i].username);
        if (employees[i].present == 1) {
            printf("Present");
        } else {
            printf("Absent");
        }
        printf(", Utilization: %d%%\n", employees[i].utilization);
    }
}

// Function for admin functionalities
void adminFunctionalities(Person employees[], int numEmployees) {
    // Admin functionalities
    viewAllReports(employees, numEmployees);
    saveEmployeesToFile(employees, numEmployees);
}
