# HR Management System

This is a simple HR Management System written in C. The system allows administrators to manage employee records, including adding and deleting employees. Employees can mark their attendance, apply for leave, and view their attendance records and leave balance.

## Features

- **Admin Functionality:**
  - Add a new employee with validated email IDs.
  - Delete an existing employee.
  - View detailed attendance and leave reports of employees in a tabular format.

- **Employee Functionality:**
  - Mark attendance with check-in and check-out times, with time format validation.
  - View attendance records in a tabular format.
  - Apply for leave and view leave balance.
  - Edit existing attendance records.

- **Input Validation:**
  - Validate date format (YYYY-MM-DD).
  - Validate time format (HH:MM AM/PM or HH:MM).
  - Ensure valid check-in and check-out times.
  - Validate email IDs and suggest a format based on the employee’s name.

## Usage

1. Clone the repository:
    ```sh
    git clone https://github.com/Poojaramesh8902/Employee-Management-System.git
    cd Employee-Management-System
    ```

2. Compile the code:
    ```sh
    gcc main.c
    ```

3. Run the program:
    ```sh
    a.exe
    ```

## Menu Options

### Main Menu
- **Admin:** Allows access to the admin menu for managing employee records.
- **Employee Names:** Allows employees to log in and access their functionalities.
- **Exit:** Exits the program.

### Admin Menu
- **Add Employee:** Add a new employee to the system.
- **Delete Employee:** Remove an employee from the system.
- **View Employee Report:** View detailed attendance and leave reports of employees.
- **Logout:** Logout from the admin account and return to the main menu.

### Employee Menu
- **Mark Attendance:** Mark check-in and check-out times for the day.
- **View Attendance:** View attendance records in a tabular format.
- **Apply Leave:** Apply for leave and reduce the leave balance.
- **View Leave Balance:** View the current leave balance.
- **Logout:** Logout from the employee account and return to the main menu.

## Data Persistence

Employee data, including attendance and leave records, is stored in a text file (`employees.txt`). The data is loaded from the file when the program starts and saved back to the file when changes are made.

