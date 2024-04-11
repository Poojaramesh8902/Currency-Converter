//Employee Management System

#include <stdio.h>
#include <string.h>
#include "employee_management.h"
#include "attendance.c"
#include "utilization.c"

int main()
{
    // Array of person structures to store data for multiple employees
    person Emp[2];

    //Store the Number of Employees to be Managed
    int n;
    printf("Enter the Number of Employees in your Organization: ");
    scanf("%d",&n);

    //Get User Input to analyse the reports of Employee
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the name of Employee %d: ",i+1);
        scanf("%s", Emp[i].name);
        printf("Enter the number of hours worked by Employee %d: ",i+1);
        scanf("%f", &Emp[i].hrs);
        printf("Enter the shift of Employee %d (full time/part time): ",i+1);
        scanf("%s", Emp[i].shift);
        printf("Enter the Employee %d city: ",i+1);
        scanf("%s", Emp[i].addr.city);
        printf("Enter the Employee %d state: ",i+1);
        scanf("%s", Emp[i].addr.state);

        //Call Attendance marking function
        Emp[i].present = Attendance(Emp[i].name);

        //Calculate utilization for each employee
        if(strcmp(Emp[i].shift,"full")==0)
        {
            Emp[i].utilization=(int)((Emp[i].hrs/8.0)*100);
        }
        else
        {
            Emp[i].utilization=(int)((Emp[i].hrs/4.0)*100);
        }

    }

    //Display Attendance Report
    printf("\nAttendance Report:\n");
    for(int i=0;i<n;i++)
    {
        printf("Employee %d - %s: ",i+1,Emp[i].name);
        if (Emp[i].present == 1)
        {
            printf("Present");
        }
        else
        {
            printf("Absent");
        }
        printf(" from %s, %s\n",Emp[i].addr.city,Emp[i].addr.state);
    }

    //Display Utilization report
    printf("\nUtilization Report:\n");
    for(int i=0;i<n;i++)
    {
        printf("Employee %d - %s: %d%%\n",i+1,Emp[i].name,Emp[i].utilization);
    }
}
