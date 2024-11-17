#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

fill(char puzzle[6][5]) 
{
for(int i = 0; i < 6; i++) 
	{
        for(int j = 0; j < 5; j++) 
		{
            puzzle[i][j] = 'A' + (rand() % 26);
        }
    }
    puzzle[5][0] = '0';
    puzzle[5][1] = '0';
    puzzle[5][2] = '0';
    puzzle[5][3] = '6';
}

display_Puzzle(char puzzle[6][5]) 
{
    printf("\nCharacter Array:\n");
    
    for (int i = 0; i < 6; i++) 
	{
        for (int j = 0; j < 5; j++) 
		{
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int search(char puzzle[6][5], const char *str) 
{
    int size = strlen(str);
    
    for (int i = 0; i < 6; i++) 
	{
        for (int j = 0; j <= 5 - size; j++) 
		{
            if (strncmp(&puzzle[i][j], str, size) == 0) 
			{
                return 1;
            }
        }
    }

    for (int j = 0; j < 6; j++) 
	{
        for (int i = 0; i <= 5 - size; i++) 
		{
            bool found = true;
            for (int k = 0; k < size; k++) 
			{
                if (puzzle[i + k][j] != str[k]) 
				{
                    found = false;
                    break;
                }
            }
            if (found == true) 
			{
                return 1;
            }
        }
    }

    return 0; // Not found
}

int main() {
    char characters[6][5];
    char input[100];
    int score = 0;

    srand(time(NULL)); // Seed random number generator

    while (1) {
        fill(characters);
        display_Puzzle(characters);

        while (1) {
            printf("Enter a string to search (or type 'END' to shuffle): ");
            scanf("%s", input);
            
            for (int a = 0; input[a]; a++) 
			{
                input[a] = toupper(input[a]);
            }
            
            if (strcmp(input, "QUIT") == 0) 
			{
                printf("score: %d", score);
                return 0;
            }

            if (strcmp(input, "END") == 0) 
			{
                break;
            }

            if (search(characters, input)) 
			{
                score++;
                printf("%s is present. Score: %d\n", input, score);
            } 
           
			else 
			{
                score--; 
                printf("%s is not present. Score: %d\n", input, score);
            }
        }
    }

    return 0;
}
