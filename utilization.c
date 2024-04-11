#include "employee_management.h"

// Function to calculate employee utilization
void calculateUtilization(person employee[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(employee[i].shift, "full") == 0) {
            employee[i].utilization = (int)((employee[i].hrs / 8.0) * 100);
        } else {
            employee[i].utilization = (int)((employee[i].hrs / 4.0) * 100);
        }
    }
}

