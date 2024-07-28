#include <stdio.h>
#include <stdlib.h>
#include "Employee_Management.h"
#include "Admin.c"
#include "Employee.c"
#include "File.c"
// Main function
int main() {
    load_employees_from_file();

    int choice;
    while (1) {
        printf("\nWelcome to the HR Management System\n");
        printf("Let's know who's accessing the system for today!\n");
        printf("Note: If your name is not in the list, access Admin ID to add one\n");
        printf("1. Admin\n");
        for (int i = 1; i < employee_count; i++) {
            printf("%d. %s\n", i + 1, employees[i].name); // Ensure correct ID assignment
        }
        printf("%d. Exit\n", employee_count + 1);
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 1) {
            admin_menu();
        } else if (choice > 1 && choice < employee_count + 1) {
            employee_menu(&employees[choice - 1]);
        } else if (choice == employee_count + 1) {
            printf("Exiting the HR Management System. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
