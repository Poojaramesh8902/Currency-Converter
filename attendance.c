#include "employee_management.h"

// Function to mark attendance
int markAttendance(char *name)
{
    char attendance[4];
    int validInput = 0;

    while (!validInput)
    {
        printf("Is %s present today? (yes/no): ", name);
        scanf("%s", attendance);
        if (strcmp(attendance, "yes") == 0 || strcmp(attendance, "YES") == 0 || strcmp(attendance, "Yes") == 0)
        {
            return 1; // Present
        } else if (strcmp(attendance, "no") == 0 || strcmp(attendance, "NO") == 0 || strcmp(attendance, "No") == 0)
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