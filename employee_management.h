#ifndef EMPLOYEE_MANAGEMENT_H
#define EMPLOYEE_MANAGEMENT_H
#include <stdio.h>

// Nested structure to store employee Address
struct address {
    char city[50];
    char state[20];
};

// Typedef for person structure
typedef struct {
    char name[10];
    float hrs;
    char shift[20];
    int present;
    int utilization;
    struct address addr; // Nested Structure
} person;

int Attendance(char *name);
void calculateUtilization(person employee[], int n);

#endif //end of macro (ifndef)
