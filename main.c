#include <stdio.h>
#include <string.h>

struct person {
    char name[10];
    float hrs;
    char shift[20];
    int present;
    int utilization;
};

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
    struct person Emp1;
    struct person Emp2;

    printf("Enter the name of Employee 1: ");
    scanf("%s", Emp1.name);
    printf("Enter the number of hours worked by Employee 1: ");
    scanf("%f", &Emp1.hrs);
    printf("Enter the shift of Employee 1 (full time/part time): ");
    scanf("%s", Emp1.shift);

    Emp1.present = Attendance(Emp1.name);

    if(strcmp(Emp1.shift,"full")==0)
    {
        Emp1.utilization=(int)((Emp1.hrs/8.0)*100);
    }
    else
    {
      Emp1.utilization=(int)((Emp1.hrs/4.0)*100);
    }

    printf("Enter the name of Employee 2: ");
    scanf("%s", Emp2.name);
    printf("Enter the number of hours worked by Employee 2: ");
    scanf("%f", &Emp2.hrs);
    printf("Enter the shift of Employee 2 (full time/part time): ");
    scanf("%s", Emp2.shift);

    Emp2.present = Attendance(Emp2.name);

    if(strcmp(Emp2.shift,"full")==0)
    {
        Emp2.utilization=(int)((Emp2.hrs/8.0)*100);
    }
    else
    {
      Emp2.utilization=(int)((Emp2.hrs/4.0)*100);
    }

    printf("\nAttendance Report:\n");
    printf("Employee 1 - %s: ", Emp1.name);
    if (Emp1.present == 1) {
        printf("Present\n");
    } else {
        printf("Absent\n");
    }
    printf("Employee 2 - %s: ", Emp2.name);
    if (Emp2.present == 1) {
        printf("Present\n");
    } else {
        printf("Absent\n");
    }
    printf("\nUtilization Report:\n");
    printf("Employee 1 - %d%%\n", Emp1.utilization);
    printf("Employee 2 - %d%%\n", Emp2.utilization);


}
