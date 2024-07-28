#include <stdio.h>
#include <stdlib.h>
#include "Employee_Management.h"

// Save employee data to file
void save_employees_to_file() {
    FILE *file = fopen("employees.txt", "w");
    if (!file) {
        printf("Error saving employee data!\n");
        return;
    }
    fprintf(file, "%d\n", employee_count);
    for (int i = 0; i < employee_count; i++) {
        fprintf(file, "%s\n%s\n%d\n%d\n%d\n", 
                employees[i].name, employees[i].email, 
                employees[i].leave_balance, employees[i].days_present, 
                employees[i].attendance_count);
        for (int j = 0; j < employees[i].attendance_count; j++) {
            fprintf(file, "%s\n%s\n%s\n", 
                    employees[i].attendance[j].date, 
                    employees[i].attendance[j].check_in, 
                    employees[i].attendance[j].check_out);
        }
    }
    fclose(file);
}

// Load employee data from file
void load_employees_from_file() {
    FILE *file = fopen("employees.txt", "r");
    if (!file) {
        printf("No saved employee data found. Initializing default data.\n");
        initialize_employees();
        return;
    }
    fscanf(file, "%d\n", &employee_count);
    for (int i = 0; i < employee_count; i++) {
        fgets(employees[i].name, sizeof(employees[i].name), file);
        strtok(employees[i].name, "\n");
        fgets(employees[i].email, sizeof(employees[i].email), file);
        strtok(employees[i].email, "\n");
        fscanf(file, "%d\n%d\n%d\n", &employees[i].leave_balance, 
               &employees[i].days_present, &employees[i].attendance_count);
        for (int j = 0; j < employees[i].attendance_count; j++) {
            fgets(employees[i].attendance[j].date, sizeof(employees[i].attendance[j].date), file);
            strtok(employees[i].attendance[j].date, "\n");
            fgets(employees[i].attendance[j].check_in, sizeof(employees[i].attendance[j].check_in), file);
            strtok(employees[i].attendance[j].check_in, "\n");
            fgets(employees[i].attendance[j].check_out, sizeof(employees[i].attendance[j].check_out), file);
            strtok(employees[i].attendance[j].check_out, "\n");
        }
    }
    fclose(file);
}
