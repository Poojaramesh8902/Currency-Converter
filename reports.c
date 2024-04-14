#include "employee_management.h"

// Function for admin to view all employee reports
void viewAllReports(Person employees[], int numEmployees)
{
    printf("Employee Reports:\n");
    for (int i = 0; i < numEmployees; i++)
    {
        printf("Employee %d - %s: ", i + 1, employees[i].name);
        if (employees[i].present == 1)
        {
            printf("Present");
        }
        else
        {
            printf("Absent");
        }
        printf(", Utilization: %d%%\n", employees[i].utilization);
    }
}
