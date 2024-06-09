#include "employee_management_system.h"
#include <stdio.h>

// Function to save employee data to a file
void saveEmployeesToFile(Person employees[], int numEmployees) 
{
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < numEmployees; i++) 
    {
        fprintf(file, "Employee %d\n", i + 1);
        fprintf(file, "Username: %s\n", employees[i].username);
        fprintf(file, "Password: %s\n", employees[i].password);
        fprintf(file, "Hours Worked: %.2f\n", employees[i].hoursWorked);
        fprintf(file, "Leave Balance: %.2f\n", employees[i].leaveBalance);
        fprintf(file, "Full-Time: %d\n", employees[i].isFullTime);
        fprintf(file, "Present: %d\n", employees[i].present);
        fprintf(file, "Utilization: %d%%\n", employees[i].utilization);
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Employee data saved to %s\n", FILENAME);
}
