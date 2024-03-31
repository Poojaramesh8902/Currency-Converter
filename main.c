//Employee Management System

#include <stdio.h>
#include <string.h>
#pragma pack(1)

//Nested structure to store employee Address
struct address
{
    char city[50];
    char state[20];
};

// Typedef for person structure
typedef struct{
    char name[10];
    float hrs;
    char shift[20];
    int present;
    int utilization;
    struct address addr; //Nested Structure
}person;

// Function to mark attendance
int Attendance(char *name)
{
    char attendance[4];
    int valid_ip = 0;

    while (!valid_ip)
        {
        printf("Is %s present today? (yes/no): ", name);
        scanf("%s", attendance);

        if (strcmp(attendance, "yes") == 0)
        {
            return 1; // Present
        }
        else if (strcmp(attendance, "no") == 0)
        {
            return 0; // Absent
        }
        else
        {
            printf("Invalid input! Please enter 'yes' or 'no'.\n");
        }
    }

    return 0;
}


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
