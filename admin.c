#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee_Management.h"

// Validate email format
bool validate_email(const char *email) {
    size_t len = strlen(email);
    if (len <= EMAIL_DOMAIN_LENGTH || 
        strcmp(email + len - EMAIL_DOMAIN_LENGTH, EMAIL_DOMAIN) != 0) {
        return false;
    }
    for (size_t i = 0; i < len - EMAIL_DOMAIN_LENGTH; i++) {
        if (!isalnum(email[i]) && email[i] != '.' && email[i] != '_') {
            return false;
        }
    }
    return true;
}

// Add a new employee
void add_employee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Employee limit reached!\n");
        return;
    }
    
    char email[50];
    printf("Enter employee name: ");
    scanf(" %[^\n]", employees[employee_count].name);
    
    // Suggest email format
    //printf("Suggested email: %s%s\n", employees[employee_count].name, EMAIL_DOMAIN);
    printf("Enter employee email [YourName@company.com]: ");
    scanf(" %[^\n]", email);
    
    // Validate email
    while (!validate_email(email)) {
        printf("Invalid email format. Please enter a valid email ending with %s: ", EMAIL_DOMAIN);
        scanf(" %[^\n]", email);
    }
    strcpy(employees[employee_count].email, email);
    
    employees[employee_count].leave_balance = 12;
    employees[employee_count].days_present = 0;
    employees[employee_count].attendance_count = 0;
    employee_count++;
    save_employees_to_file();
    printf("Employee added successfully!\n");
}

// Delete an employee
void delete_employee() {
    int id;
    printf("Current Employees:\n");
    for (int i = 1; i < employee_count; i++) {
        printf("%d. %s\n", i, employees[i].name);
    }
    printf("Enter the employee ID to delete: ");
    if (scanf("%d", &id) != 1 || id < 1 || id >= employee_count) {
        printf("Invalid input! Please enter a valid employee ID.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    for (int i = id; i < employee_count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employee_count--;
    save_employees_to_file();
    printf("Employee deleted successfully!\n");
}

// View employee report
void view_employee_report() {
    printf("\nEmployee Report:\n");
    printf("+----+--------------------+---------------------+----------------+-------------------+\n");
    printf("| ID | Name               | Email               | Leave Balance  | Days Present      |\n");
    printf("+----+--------------------+---------------------+----------------+-------------------+\n");
    for (int i = 1; i < employee_count; i++) {
        printf("| %2d | %-18s | %-19s | %14d | %17d |\n", 
               i, employees[i].name, employees[i].email, 
               employees[i].leave_balance, employees[i].days_present);
    }
    printf("+----+--------------------+---------------------+----------------+-------------------+\n");
}
// Admin menu
void admin_menu() {
    int choice;
    while (1) {
        printf("\nAdmin Menu\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. View Employee Report\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                delete_employee();
                break;
            case 3:
                view_employee_report();
                break;
            case 4:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}
