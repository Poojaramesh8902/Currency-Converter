#include "employee_management.h"

// Function to calculate employee utilization
void calculateUtilization(Person employees[], int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        if (employees[i].isFullTime==1)
        {
            employees[i].utilization = (int)((employees[i].hoursWorked / 8.0) * 100);
        }
        else 
        {
            employees[i].utilization = (int)((employees[i].hoursWorked / 4.0) * 100);
        }
    }
}
