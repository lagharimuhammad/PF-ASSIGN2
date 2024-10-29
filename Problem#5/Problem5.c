#include<stdio.h>

void histogram( int );

void histogram( int count)
{
	int array[count];
	
	for(int i = 0; i < count; i++)
	{
		printf("Enter element in array: ");
		scanf("%d", &array[i]);
	}
	printf("\n");
	
	for(int j = 0; j<count; j++)
	{
		printf("Value: %d ", j+1);
		for(int k = 1; k <= array[j]; k++)
		{
			printf(" *");
		}
		printf("\n");
	}
	
	printf("\n");
	
		int max = 0;
	//find largest number in array
	for(int i = 0; i < count; i++)
	{		
		if(max < array[i])
		{
			max = array[i];
		}
	}
	
	for(int i = max; i > 0; i--)
	{
		for(int j = 0; j < count; j++)
		{
			if(array[j] >= i)
			{
				printf(" * ");
			}
			else
			printf("   ");
			
		}
		printf("\n");
	}
	
	for(int i = 0; i < count; i++)
	{
	printf(" %d ", array[i]);
	}
}

int main()
{
	int size;
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	
	histogram(size);
	
 	return 0;
}

