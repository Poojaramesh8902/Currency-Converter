#include "employee_management.h"

// Function for employee to apply for leave
void applyForLeave(Person *employee)
{
    int days;
    printf("Enter number of days for leave: ");
    scanf("%d", &days);
    if (days <= 4)
    {
        printf("Leave applied successfully!\n");
        employee->leaveBalance -= days;
    }
    else
    {
        printf("Insufficient leave balance!\n");
    }
}