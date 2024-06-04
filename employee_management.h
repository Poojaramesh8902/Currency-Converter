#ifndef EMPLOYEE_MANAGEMENT_H
#define EMPLOYEE_MANAGEMENT_H
#include <stdio.h>

typedef struct {
    char name[50];
    char username[20];
    char password[20];
    float hoursWorked;
    float leaveBalance;
    int isFullTime;
    int present;
    int utilization;
} Person;

void defaultValue(Person *employee);
int markAttendance(char *name);
void calculateUtilization(Person employees[], int numEmployees);
void viewAllReports(Person employees[], int numEmployees);
void applyForLeave(Person *employee);
void viewLeaveBalance(Person *employee);
void employeeMenu(Person *employee);

#endif //end of macro (ifndef)
