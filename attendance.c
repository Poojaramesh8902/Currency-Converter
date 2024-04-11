#include "employee_management.h"

// Function to mark attendance
int Attendance(char *name) {
    char attendance[4];
    int valid_input = 0;

    while (!valid_input) {
        printf("Is %s present today? (yes/no): ", name);
        scanf("%s", attendance);

        if (strcmp(attendance, "yes") == 0) {
            return 1; // Present
        } else if (strcmp(attendance, "no") == 0) {
            return 0; // Absent
        } else {
            printf("Invalid input! Please enter 'yes' or 'no'.\n");
        }
    }

    return 0;
}
