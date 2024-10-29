#include<stdio.h>

int main()
{
	int size;
	
	printf("Enter size of the array: ");
	scanf("%d", &size);
	
	int array[size];
	
	for(int i = 0; i < size; i++)
	{
		printf("Enter value %d in the array: ", i);
		scanf("%d", &array[i]);
		
		
		if(array[i] > 9999 )
		{
				
			for( int j = 0; j < 1; j++)
			{
				printf("Input a value less than 9999\n");
				i--;
				continue;
			}
		}
	}
	
	for(int q = 0; q < size; q++)
	{
		for(int k = 0; k < size-1; k++)
		{
			
			if(array[q] < array[k])
			{
				int num;
				num = array[q];
				array[q] = array[k];
				array[k] = num;	
			}
		}
	}	
	
	

		
	printf("The second smallest in the array is %d", array[1]);
		
	 	return 0;
}

