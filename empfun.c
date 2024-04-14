#include "employee_management.h"

// Function for employee functionalities menu
void employeeMenu(Person *employee)
{
    int choice;
    do {
        printf("\nEmployee Functionalities Menu:\n");
        printf("1. Apply for Leave\n");
        printf("2. View Leave Balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                applyForLeave(employee);
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
