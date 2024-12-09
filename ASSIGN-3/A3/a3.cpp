#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int validation(char* email)
{
	if(email == NULL || strlen(email) == 0)
	return 0;
	
	bool at_detector = false;
	char* at_ptr = NULL;
	
	for(char* ptr = email; *ptr != '\0'; ptr++)
	{
		if(*ptr == '@')
		{
			at_detector = true;
			at_ptr = ptr;
		}
	}
	
	if(at_detector == false)
	return 0;
	
	if(strchr(at_ptr+1, '.') == NULL)
	return 0;
	
	return 1;
}

int main()
{
	char email[256];
	
	printf("Enter your email: ");
	getchar();
	fgets(email, 256, stdin);
	email[strcspn(email,"\n")] = '\0';
	
	int length = strlen(email);
	
	int ans = validation(email);
	
	if(ans == 1)
	{
		printf("email is valid.");
	}
	else
	{
		printf("Email is invalid");
	}

 	return 0;
}

