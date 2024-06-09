#include "employee_management_system.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to mark attendance
int markAttendance(char *username) 
{
    char attendance[4];
    int validInput = 0;

    while (!validInput) 
   {
        printf("Is %s present today? (yes/no): ", username);
        scanf("%s", attendance);

        if (strcmp(attendance, "yes") == 0) 
        {
            return 1; // Present
        } 
	else if (strcmp(attendance, "no") == 0) 
	{
            return 0; // Absent
        } 
	else 
	{
            printf("Invalid input! Please enter 'yes' or 'no'.\n");
        }
    }

    return 0;
}

// Function to calculate employee utilization
void calculateUtilization(Person employees[], int numEmployees) 
{
    for (int i = 0; i < numEmployees; i++) 
    {
        if (employees[i].isFullTime) 
	{
            employees[i].utilization = (int)((employees[i].hoursWorked / 8.0) * 100);
        } 
	else 
	{
            employees[i].utilization = (int)((employees[i].hoursWorked / 4.0) * 100);
        }
    }
}

// Function for employee to apply for leave
void applyForLeave(Person *employee, Person employees[], int numEmployees) 
{
    int days;
    printf("Enter number of days for leave: ");
    scanf("%d", &days);
    if (days <= employee->leaveBalance) 
    {
        employee->leaveBalance -= days;
        printf("Leave applied successfully!\n");
        saveEmployeesToFile(employees, numEmployees); // Save data after leave is applied
    } 
    else 
    {
        printf("Insufficient leave balance!\n");
    }
}

// Function for employee to view leave balance
void viewLeaveBalance(Person *employee) 
{
    printf("Leave Balance: %.2f\n", employee->leaveBalance);
}

// Function for employee functionalities menu
void employeeMenu(Person *employee, Person employees[], int numEmployees) 
{
    int choice;
    do {
        printf("\nEmployee Functionalities Menu:\n");
        printf("1. Apply for Leave\n");
        printf("2. View Leave Balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                applyForLeave(employee, employees, numEmployees);
                break;
            case 2:
                viewLeaveBalance(employee);
                break;
            case 3:
                printf("Exiting Employee Functionalities.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);
}

// Convert a string to lowercase
void toLowerCase(char *str) 
{
    for (int i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}
