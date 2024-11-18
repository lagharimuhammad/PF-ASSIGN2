#include<stdio.h>
#include<ctype.h>

void up_down(char grid[][5], int*, int*, int*, int*);
void left_right(char grid[][5], int*, int*, int*, int*);
void print_grid(char grid[5][5]);

int main(){
    char grid[5][5] = {
    {' ', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', 'P'}
    };

    printf("**Welcome to Grid Game**\n\n");
    printf("Enter following keys to play\nW: up\nS: down\nA: left\nD: right\nQ: quit.\n\n");
    printf("Let's Begin\n");
    int p1=4, p2=4, item=0;

    char input;
    while(input != 'Q'){
        int p3=0;
        print_grid(grid);
        printf("\nEnter your move: ");
        scanf(" %c", &input);
        
        input = toupper(input);

        if(input == 'W')
		{
            p3=p1-1;
            up_down(grid, &p2, &p1, &p3, &item);
        }
        else if(input == 'S')
		{
            p3=p1+1;
            up_down(grid, &p2, &p1, &p3, &item);
        }
        else if(input == 'A')
		{
            p3=p2-1;
            left_right(grid, &p1, &p2, &p3, &item);
        }
        else if(input == 'D')
		{
            p3=p2+1;
            left_right(grid, &p1, &p2, &p3, &item);
        }
        else if(input == 'Q')
		{ 
            printf("game terminated\n");
            printf("collected items: %d", item);
            return 0;
        }
        else printf("invalid input\n");
    }
}

void print_grid(char grid[5][5])
{
    for(int i=0; i<5; i++)
	{
        for(int j=0; j<5; j++)
		{
            printf("|'%c'", grid[i][j]);
        }
        printf("|\n");
    }
}

void up_down(char grid[][5], int *i, int *j, int *k, int *item)
{
    if(*k >= 0 && *k <= 4)
	{
        if(grid[*k][*i] == ' ' || grid[*k][*i] == 'I')
		{
            if(grid[*k][*i] == 'I') 
			(*item)++;
			
            grid[*j][*i] = ' ';
            grid[*k][*i] = 'P';
            *j = *k;
        }
    }
    else 
	printf("invalid input\n");
}

void left_right(char grid[][5], int *i, int *j, int *k, int *item)
{
    if(*k >= 0 && *k <= 4)
	{
        if(grid[*i][*k] == ' ' || grid[*i][*k] == 'I')
		{
            if(grid[*i][*k] == 'I') 
			(*item)++;
			
            grid[*i][*j] = ' ';
            grid[*i][*k] = 'P';
            *j = *k;
        }
    }
    else printf("Invalid Input\n");
    return;
}
