#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int BinarytoDecimal(int num);
void DecimaltoBinary(int num);
void DecimaltoHexadecimal(int num);
void HexadecimaltoDecimal(char *hex);
void BinarytoHexadecimal(int num);
void HexadecimaltoBinary(char *hex);

void menu()
{	
	while(1)
	{
	int option = 0, num = 0;
	char hex[50] = {0};
	
	printf("\t-----Menu-----\n");
	printf("1: Binary to Decimal\n");
	printf("2: Decimal to Binary\n");
	printf("3: Decimal to Hexadecimal\n");
	printf("4: Hexadecimal to Decimal\n");
	printf("5: Binary to Hexadecimal\n");
	printf("6: Hexadecimal to Binary\n");
	printf("7: Exit\n");
	
	printf("Enter your option(1-7): ");
	scanf("%d",&option);
	
		switch(option)
		{
			case 1:
				printf("Enter a Binary Number: ");
				scanf("%d", &num);
				printf("%d", BinarytoDecimal(num));
				printf("\n");
				break;
				
			case 2:
				printf("Enter a Decimal Number: ");
				scanf("%d", &num);
				DecimaltoBinary(num);
				printf("\n");
				break;
				
			case 3:
				printf("Enter a Decimal Number: ");
				scanf("%d", &num);
				DecimaltoHexadecimal(num);
				printf("\n");
				break;
				
			case 4:
				printf("Enter a Hexadecimal Number: ");
				getchar();
				fgets(hex, 50, stdin);
				hex[strcspn(hex, "\n")] = '\0';
				HexadecimaltoDecimal(hex);
				printf("\n");
				break;
				
			case 5:
				printf("Enter a Binary Number: ");
				scanf("%d", &num);
				BinarytoHexadecimal(num);
				printf("\n");
				break;
				
			case 6:
				printf("Enter a Hexadecimal Number: ");
				getchar();
				fgets(hex, 50, stdin);
				hex[strcspn(hex, "\n")] = '\0';
				HexadecimaltoBinary(hex);
				printf("\n");
				break;
				
			case 7:
				printf("Program End");
			return;
				
			default: 
			printf("Enter choice from 1 to 7: ");
			
		}
	
	}
}

int main()
{
	menu();
 	return 0;
}

int BinarytoDecimal(int num)
{
	
	int rem, sum = 0;
	for(int i = 0; num > 0 ; i++)
	{
		rem = num % 10;
		sum = sum + (rem*(int)pow(2,i));
		num = num/10;
	}
	return sum;
}

void DecimaltoBinary(int num)
{
	int array[64];
	int count = 0;
	for(int index = 0; num > 0; index++)
	{
		array[index]= num % 2;
		num /= 2;
		count++;
	}
	
	for (int i = count - 1; i >= 0; i--)
	    {
	        printf("%d", array[i]);
	}
}

void DecimaltoHexadecimal(int num)
{
	char hexadecimal_values[]= "0123456789ABCDEF";
	char hexa_input[10];
	int rem, count = 0;
	
	
	for(int i = 0; num > 0 ; i++)
	{
		rem = num % 16;
		hexa_input[i] = hexadecimal_values[rem];
		num /= 16;
		count++;
	}
	
	for(int j = count - 1  ; j >= 0; j--)
	{
		printf("%c", hexa_input[j]);
	}
}

void HexadecimaltoDecimal(char *hex)
{
	int num = 0;
	
	int size = strlen(hex);
	for(int i = size - 1; i >= 0; i-- )
	{
		char value = toupper(hex[i]);
		int hexa_value = 0;
		
		if( value <= 'F' && value >= 'A')
		{
			hexa_value = value - 'A' + 10;
		}
		
		else if( value <= '9' && value >= '0')
		{
			hexa_value = value - '0';
		}
		
		else 
		{
			printf("Invalid input");
			break;
		}
		
		num = num +  hexa_value * (int)pow(16, size - 1 - i);	
	}
	
	printf("%d", num);
}

void BinarytoHexadecimal(int num)
{
	int c = BinarytoDecimal(num);
	DecimaltoHexadecimal(c);
}

void HexadecimaltoBinary(char *hex)
{
	for(int i = 0; i < strlen(hex); i++)
	{
		char digit = hex[i];
		digit = toupper(digit);
		
		if ((digit <= '9' && digit >= '0') || (digit <= 'F' && digit >= 'A'))
		{
			if (digit == '0') { printf("0000"); }
			else if (digit == '1') { printf("0001"); }
			else if (digit == '2') { printf("0010"); }
			else if (digit == '3') { printf("0011"); }
			else if (digit == '4') { printf("0100"); }
			else if (digit == '5') { printf("0101"); }
			else if (digit == '6') { printf("0110"); }
			else if (digit == '7') { printf("0111"); }
			else if (digit == '8') { printf("1000"); }
			else if (digit == '9') { printf("1001"); }
			else if (digit == 'A') { printf("1010"); }
			else if (digit == 'B') { printf("1011"); }
			else if (digit == 'C') { printf("1100"); }
			else if (digit == 'D') { printf("1101"); }
			else if (digit == 'E') { printf("1110"); }
			else if (digit == 'F') { printf("1111"); }
		}
		else
		{
			printf("Invalid input");
			break;
		}
	}
}
