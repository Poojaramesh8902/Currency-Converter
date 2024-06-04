//Employee Management System

#include <stdio.h>
#include <string.h>
#include "employee_management.h"
#include "attendance.c"
#include "utilization.c"
#include "reports.c"
#include "adminfun.c"
#include "applyleave.c"
#include "leavebalance.c"
#include "empfun.c"

void saveEmployees(Person employees[], int numEmployees, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "%s %f %d %d\n", employees[i].name, employees[i].hoursWorked, employees[i].isFullTime, employees[i].present);
    }

    fclose(file);
}

void loadEmployees(Person employees[], int *numEmployees, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    *numEmployees = 0;
    while (fscanf(file, "%s %f %d %d", employees[*numEmployees].name, &employees[*numEmployees].hoursWorked, &employees[*numEmployees].isFullTime, &employees[*numEmployees].present) == 4) {
        (*numEmployees)++;
    }

    fclose(file);
}


int main()
{
    char username[20], password[20];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
    {
        Person employees[10];
        int numEmployees;
        printf("Enter the Number of Employees in your Organization: ");
        scanf("%d", &numEmployees);

	// Load existing employee data from file
        loadEmployees(employees, &numEmployees, "employees.txt");

        for (int i = 0; i < numEmployees; i++)
        {
            printf("\nEnter the name of Employee %d: ", i + 1);
            scanf("%s", employees[i].name);
            printf("Enter the number of hours worked by Employee %d: ", i + 1);
            scanf("%f", &employees[i].hoursWorked);
            printf("Enter 1 for full-time, 0 for part-time for Employee %d: ", i + 1);
            scanf("%d", &employees[i].isFullTime);

            employees[i].present = markAttendance(employees[i].name);
        }
	//Save the data to the file
	saveEmployees(employees, numEmployees, "employees.txt");

        calculateUtilization(employees, numEmployees);
        adminFunctionalities(employees, numEmployees);
    }
    else
    {
        Person employee;
        strcpy(employee.username, username);
        strcpy(employee.password, password);
	    employee.leaveBalance = 20.0;
        employeeMenu(&employee);
    }

    return 0;
}
