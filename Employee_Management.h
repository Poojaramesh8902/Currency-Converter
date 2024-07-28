#ifndef EMPLOYEE_MANAGEMENT_H
#define EMPLOYEE_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 100
#define EMAIL_DOMAIN "@company.com"
#define EMAIL_DOMAIN_LENGTH 12 // Length of "@company.com" including the null terminator

typedef struct {
    char date[20];
    char check_in[10];
    char check_out[10];
} Attendance;

typedef struct {
    char name[50];
    char email[50];
    int leave_balance;
    int days_present;
    Attendance attendance[365];
    int attendance_count;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

// Function prototypes
void save_employees_to_file();
void load_employees_from_file();
bool validate_email(const char *email);
void add_employee();
void delete_employee();
void view_employee_report();
bool validate_date_format(char *date);
bool validate_time_format(char *time);
void edit_attendance(Employee *employee, int index, char *date, char *check_in, char *check_out);
void mark_attendance(Employee *employee);
void view_attendance(Employee *employee);
void apply_leave(Employee *employee);
void view_leave_balance(Employee *employee);
void admin_menu();
void employee_menu(Employee *employee);

// Initialize employees with default data
void initialize_employees() {
    employee_count = 3;
    strcpy(employees[0].name, "Admin");
    strcpy(employees[0].email, "admin@company.com");
    employees[0].leave_balance = 0;
    employees[0].days_present = 0;
    employees[0].attendance_count = 0;

    strcpy(employees[1].name, "Derek");
    strcpy(employees[1].email, "derek@company.com");
    employees[1].leave_balance = 12;
    employees[1].days_present = 0;
    employees[1].attendance_count = 0;

    strcpy(employees[2].name, "George");
    strcpy(employees[2].email, "george@company.com");
    employees[2].leave_balance = 12;
    employees[2].days_present = 0;
    employees[2].attendance_count = 0;
}


#endif
