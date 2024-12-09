#include<stdio.h>
#include<stdlib.h>

#define MAX_RATING 10
#define MIN_RATING 1


typedef struct Employee
{
    int* ratings;  
    int totalScore;  
} Employee;

void inputEmployees(int** ratings, int numEmployees, int numPeriods) 
{
    for (int i = 0; i < numEmployees; i++) 
    {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) 
        {
            do 
            {
                printf(" Period %d (Rating between 1 and 10): ", j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < MIN_RATING || ratings[i][j] > MAX_RATING);
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) 
{
    printf("\nEmployee Performance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) 
    {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) 
        {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) 
{
    int bestEmployee = -1;
    float highestAvg = -1.0f;

    for (int i = 0; i < numEmployees; i++) 
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) 
        {
            total += ratings[i][j];
        }

        float avg = (float)total / numPeriods;
        if (avg > highestAvg) 
        {
            highestAvg = avg;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) 
{
    int bestPeriod = -1;
    float highestAvg = -1.0f;

    for (int j = 0; j < numPeriods; j++) 
    {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) 
        {
            total += ratings[i][j];
        }

        float avg = (float)total / numEmployees;
        if (avg > highestAvg) 
        {
            highestAvg = avg;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) 
{
    int worstEmployee = -1;
    float lowestAvg = 11.0f;  

    for (int i = 0; i < numEmployees; i++) 
    {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) 
        {
            total += ratings[i][j];
        }

        float avg = (float)total / numPeriods;
        if (avg < lowestAvg) 
        {
            lowestAvg = avg;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main() 
{
    int numEmployees, numPeriods;

    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for (int i = 0; i < numEmployees; i++) 
    {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);

    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("\nHighest Rated Period: Period %d\n", highestRatedPeriod + 1);


    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("\nWorst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) 
    {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
