#include <stdio.h>
#include <string.h>
#include "Employee_Management.h"

// Validate date format
bool validate_date_format(char *date) {
    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) == 3) {
        if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            if (month == 2 && day > 29) return false; // Simplified leap year check
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
            return true;
        }
    }
    return false;
}

// Validate time format
bool validate_time_format(char *time) {
    int hour, minute;
    char period[3];
    if (sscanf(time, "%d:%d %2s", &hour, &minute, period) == 3) {
        if ((strcasecmp(period, "AM") == 0 || strcasecmp(period, "PM") == 0) && hour >= 1 && hour <= 12 && minute >= 0 && minute <= 59) {
            return true;
        }
    } else if (sscanf(time, "%d:%d", &hour, &minute) == 2) {
        if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
            return true;
        }
    }
    return false;
}

// Edit existing attendance record
void edit_attendance(Employee *employee, int index, char *date, char *check_in, char *check_out) {
    char choice;
    printf("Attendance for %s on %s already exists.\n", employee->name, date);
    printf("Current Record:\n");
    printf("Check-in: %s\n", employee->attendance[index].check_in);
    printf("Check-out: %s\n", employee->attendance[index].check_out);
    printf("Do you want to (E)dit or (S)ave? ");
    scanf(" %c", &choice);
    
    if (choice == 'E' || choice == 'e') {
        strcpy(employee->attendance[index].check_in, check_in);
        strcpy(employee->attendance[index].check_out, check_out);
        printf("Record updated.\n");
    } else if (choice == 'S' || choice == 's') {
        printf("Record saved.\n");
    } else {
        printf("Invalid choice! Record not updated.\n");
    }
}

// Mark attendance
void mark_attendance(Employee *employee) {
    char date[20], check_in[10], check_out[10];
    int in_hour, in_minute, out_hour, out_minute;
    char in_period[3], out_period[3];

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]", date);
    if (!validate_date_format(date)) {
        printf("Invalid date format!\n");
        return;
    }

    printf("Enter check-in time (HH:MM AM/PM or HH:MM): ");
    scanf(" %[^\n]", check_in);
    if (!validate_time_format(check_in)) {
        printf("Invalid check-in time format!\n");
        return;
    }

    printf("Enter check-out time (HH:MM AM/PM or HH:MM): ");
    scanf(" %[^\n]", check_out);
    if (!validate_time_format(check_out)) {
        printf("Invalid check-out time format!\n");
        return;
    }

    sscanf(check_in, "%d:%d %2s", &in_hour, &in_minute, in_period);
    sscanf(check_out, "%d:%d %2s", &out_hour, &out_minute, out_period);

    if (strcasecmp(in_period, "PM") == 0 && in_hour != 12) in_hour += 12;
    if (strcasecmp(in_period, "AM") == 0 && in_hour == 12) in_hour = 0;
    if (strcasecmp(out_period, "PM") == 0 && out_hour != 12) out_hour += 12;
    if (strcasecmp(out_period, "AM") == 0 && out_hour == 12) out_hour = 0;

    int check_in_minutes = in_hour * 60 + in_minute;
    int check_out_minutes = out_hour * 60 + out_minute;

    if (check_out_minutes <= check_in_minutes) {
        printf("Check-out time must be after check-in time!\n");
        return;
    }

    if (check_out_minutes - check_in_minutes > 12 * 60) {
        printf("Invalid check-in/check-out times! Ensure you are working no more than 12 hours.\n");
        return;
    }

    for (int i = 0; i < employee->attendance_count; i++) {
        if (strcmp(employee->attendance[i].date, date) == 0) {
            edit_attendance(employee, i, date, check_in, check_out);
            save_employees_to_file();
            return;
        }
    }

    strcpy(employee->attendance[employee->attendance_count].date, date);
    strcpy(employee->attendance[employee->attendance_count].check_in, check_in);
    strcpy(employee->attendance[employee->attendance_count].check_out, check_out);
    employee->attendance_count++;
    employee->days_present++;
    save_employees_to_file();
    printf("Attendance marked for %s on %s\n", employee->name, date);
}

// View attendance
void view_attendance(Employee *employee) {
    if (employee->attendance_count == 0) {
        printf("No attendance records found.\n");
    } else {
        printf("\nAttendance records for %s:\n", employee->name);
        printf("+------------+------------+------------+\n");
        printf("| Date       | Check-in   | Check-out  |\n");
        printf("+------------+------------+------------+\n");
        for (int i = 0; i < employee->attendance_count; i++) {
            printf("| %-10s | %-10s | %-10s |\n", 
                   employee->attendance[i].date, 
                   employee->attendance[i].check_in, 
                   employee->attendance[i].check_out);
        }
        printf("+------------+------------+------------+\n");
    }
}

// Apply leave
void apply_leave(Employee *employee) {
    int num_days;
    printf("Enter the number of days to apply for leave: ");
    if (scanf("%d", &num_days) != 1 || num_days <= 0) {
        printf("Invalid number of days! Please enter a valid number.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    if (employee->leave_balance >= num_days) {
        employee->leave_balance -= num_days;
        save_employees_to_file();
        printf("Leave applied for %d days successfully! Leave balance: %d\n", num_days, employee->leave_balance);
    } else {
        printf("Insufficient leave balance!\n");
    }
}

// View leave balance
void view_leave_balance(Employee *employee) {
    printf("Leave balance: %d\n", employee->leave_balance);
}
// Employee menu
void employee_menu(Employee *employee) {
    int choice;
    while (1) {
        printf("\nEmployee Menu\n");
        printf("1. Mark Attendance\n");
        printf("2. View Attendance Records\n");
        printf("3. Apply Leave\n");
        printf("4. View Leave Balance\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid option.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                mark_attendance(employee);
                break;
            case 2:
                view_attendance(employee);
                break;
            case 3:
                apply_leave(employee);
                break;
            case 4:
                view_leave_balance(employee);
                break;
            case 5:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
}
