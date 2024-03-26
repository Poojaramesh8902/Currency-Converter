#include<stdio.h>
#include<string.h>
struct person
{
    char name[10];
    float hrs;
    char shift[100];
};
int main()
{
    struct person Emp1;
    struct person Emp2;

    printf("Enter the name: ");
    scanf("%s",Emp1.name);
    printf("Enter the number of worked hrs: ");
    scanf("%f",&Emp1.hrs);
    printf("Enter the shift full time/part time: ");
    scanf("%s",Emp1.shift);

    int Utilization=0;
    if(strcmp(Emp1.shift,"full")==0)
    {
        Utilization = (Emp1.hrs / 8.0)*100;
        printf("Emp1 Utilization in terms of percentage is %d",Utilization);
    }
    else{
        Utilization = (Emp1.hrs/4)*100;
        printf("Emp1 Utilization in terms of percentage is %d",Utilization);
    }

    printf("\nEnter the name: ");
    scanf("%s",Emp2.name);
    printf("Enter the number of worked hrs: ");
    scanf("%f",&Emp2.hrs);
    printf("Enter the shift full time/part time: ");
    scanf("%s",Emp2.shift);
    Utilization=0;
    if(strcmp(Emp2.shift,"full")==0)
    {
        Utilization = (Emp2.hrs/8)*100;
        printf("Emp2 Utilization in terms of percentage is %d",Utilization);
    }
    else{
        Utilization = (Emp2.hrs/4)*100;
        printf("Emp2 Utilization in terms of percentage is %d",Utilization);
    }

}
