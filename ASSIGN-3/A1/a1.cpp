#include<stdio.h>
#include<string.h>


typedef struct Employee
{ 
    int employee_code;
    char employee_name[50];
    int date_of_joining[3];
} Employee;

void assign_employee(Employee *emp, int code, const char *naam, int day, int month, int year) 
{
    emp->employee_code = code;
    strcpy(emp->employee_name, naam);
    
    emp->date_of_joining[0] = day;
    emp->date_of_joining[1] = month;
    emp->date_of_joining[2] = year;
}

void tenure(Employee employees[], int size) 
{
    int current_date[3];
    printf("Enter dd: ");
    scanf("%d", &current_date[0]);
    printf("Enter mm: ");
    scanf("%d", &current_date[1]);
    printf("enter yyyy: ");
    scanf("%d", &current_date[2]);

    int num = 0;

    for (int i = 0; i < size; i++) 
	{
        int years = current_date[2] - employees[i].date_of_joining[2];
        int months = current_date[1] - employees[i].date_of_joining[1];
        int days = current_date[0] - employees[i].date_of_joining[0];
        
        if (months < 0 || (months == 0 && days < 0)) 
            years--;

        if (years > 3) 
		{
            num++;
            printf("employee code: %d\n", employees[i].employee_code);
            printf("employee name: %s\n", employees[i].employee_name);
            printf("date of joining: %02d/%02d/%04d\n", employees[i].date_of_joining[0], employees[i].date_of_joining[1], employees[i].date_of_joining[2]);
            
        }
    }

    printf("total employees with tenure of more than 3 years: %d\n", num);
}

int main() 
{
	Employee employees[4];
	
    assign_employee(&employees[0], 22, "Omer", 7, 5, 2022);
    assign_employee(&employees[1], 33, "Anwer", 13, 10, 2021);
    assign_employee(&employees[2], 39, "Kashif", 21, 1, 2020);
    assign_employee(&employees[3], 51, "Hassan", 1, 4, 2018);

	tenure(employees, 4);

    return 0;
}

