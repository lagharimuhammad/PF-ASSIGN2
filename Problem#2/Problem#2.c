#include<stdio.h>
#include<string.h>
#include<ctype.h>

void analyze(char *word)
{
	int repetition[126]={0};
	
	int i;
	for(i = 0; word[i] != '\0'; i++)
	{
	char letter = word[i];
	
		if ((letter >= '0' && letter <= '9') || (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || (letter == ' ')) 
		{
			letter = toupper(letter);
			repetition[(int)letter]++;
		}
	}
	
	int j;
	for(j = 0; j < 126; j++)
	{
		if(repetition[j] != 0)
		{
		printf("Letter %c repeats: %d \n", (char)j, repetition[j]);
		}
	}
	printf("\n");
	
}


int main()
{
	char *word[] ={"save big","limited offer","buy now"};
	
	int c;
	for(c = 0; c < 3; c++)
	{
		analyze(word[c]);
	}
	

 	return 0;
}

