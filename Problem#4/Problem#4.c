#include <stdio.h>
#include<string.h>

int main()
{
int n;
int prt=0;

printf("Enter the number of words: ");
scanf("%d",&n);

char arr[n][100];

int i,j,k,l,inc=0;

for(i = 0; i < n; i++)
{
	printf("Enter the %d word: ",i+1);
	scanf("%s", &arr[i]);
}

for(i = n-1; i >= 0; i--)
{
	if(arr[i][0]!=' ')
	{
		int len1 = strlen(arr[i]);
	
		printf("[%s",arr[i]);
		
		for(j= i-1 ; j >= 0 ;j--)
		{
			int len2 = strlen(arr[i]);

			for(k = 0; arr[i][k] != '\0'; k++)
			{
				for(l=0; arr[j][l]!='\0'; l++) 
				if(arr[i][k] == arr[j][l]) 
				break;
				  if(arr[j][l] == '\0')  
				  break;
			}    
		        if(arr[i][k] == '\0' && len1 == len2)	
				{
		            printf(",%s",arr[j]);
		            
			        while(arr[j][inc] != '\0')
					{
	            		arr[j][inc]=' ';
		            	inc++;
					}
					inc=0;
	            }						             
	    }
	            printf("],");
	}
}
    return 0;
}
