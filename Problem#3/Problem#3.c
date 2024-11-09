#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void compress(char word[][200], int total_word);

int main()
{
    int size_of_word, total_words;
    
    printf("Enter the number of words: ");
    scanf("%d", &total_words);

    printf("Enter the size of the largest words: ");
    scanf("%d", &size_of_word);
    getchar();
    
    char word[total_words][200];
    
    for(int a = 0; a < total_words; a++)
    {
        printf("Enter the words: ");
        fgets(word[a], size_of_word + 1, stdin);
        getchar();
    }
    
    compress(word, total_words);
    
    return 0;
}
    
    
void compress(char word[][200], int total_word)
{

    char compressed_word[total_word][200];

    for(int i = 0; i < total_word; i++)
    {
        int length = strlen(word[i]);
        int unique_words = 0;
        for(int j = 0; j < length; j++ )
        {
        	bool unique = true;
        	
            for (int k = 0; k < unique_words; k++)
            {
                if (compressed_word[i][k]==word[i][j])
                {
                	unique = false;
                    continue;
                }
                
            }
            if(unique)
            {
            	compressed_word[i][unique_words] = word[i][j];
            	unique_words++;
			}

        }
        compressed_word[i][unique_words] = '\0';
    }
    
    for(int  l = 0 ; l < total_word ; l++)
    {
        printf("%s\n",compressed_word[l]) ;
    }

}
