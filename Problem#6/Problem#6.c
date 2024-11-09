#include<stdio.h>

int sticks_pick( int num)
{
	if(num % 5 == 0)
	{
		return -1;
	}
	
	if(num % 5 != 0)
	{
		return num % 5;
	}
}

int main()
{
	int sticks;
	
	printf("Enter no. of matchsticks: ");
	scanf("%d", &sticks);
	
	
	int win = sticks_pick(sticks);
	
	if( win == -1)
	printf("It is impossible for Player A to win.");
	
	else
	printf("Player A should pick %d sticks to win.", win);

 	return 0;
}

