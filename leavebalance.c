#include "employee_management.h"

// Function for employee to view leave balance
void viewLeaveBalance(Person *employee)
{
    printf("Leave Balance: %.2f\n", employee->leaveBalance);
}
