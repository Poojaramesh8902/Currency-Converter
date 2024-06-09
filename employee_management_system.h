#ifndef EMPLOYEE_MANAGEMENT_SYSTEM_H
#define EMPLOYEE_MANAGEMENT_SYSTEM_H

#define MAX_EMPLOYEES 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define FILENAME "employees.txt"

// Typedef for person structure
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    float hoursWorked;
    float leaveBalance;
    int isFullTime; // 1 for full-time, 0 for part-time
    int present;
    int utilization;
} Person;

// Function declarations
int markAttendance(char *username);
void calculateUtilization(Person employees[], int numEmployees);
void viewAllReports(Person employees[], int numEmployees);
void saveEmployeesToFile(Person employees[], int numEmployees);
void adminFunctionalities(Person employees[], int numEmployees);
void applyForLeave(Person *employee, Person employees[], int numEmployees);
void viewLeaveBalance(Person *employee);
void employeeMenu(Person *employee, Person employees[], int numEmployees);
void toLowerCase(char *str);

#endif // EMPLOYEE_MANAGEMENT_SYSTEM_H
