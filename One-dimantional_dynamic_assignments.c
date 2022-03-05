/* Assignment: 4
Author: Oran Bourak, ID: 204788285
*/
#define _CRT_SECURE_NO_WARNINGS
#define s_size 50
#include <stdio.h>
#include <string.h>

void str_statistics(char* str, int*small, int* capital, int* numbers);

int main()
{
	int s_letters=0, c_letters=0, numbers=0;
	char str[s_size];
	printf("Please enter a string:\n"); 
	gets(str);  //recieved string from the user
	str_statistics(str,&s_letters,&c_letters,&numbers);  
	printf("\n%d small letters\n",s_letters); //printing number of small letters
	printf("\n%d capital letters\n",c_letters);//printing number of capital letters
	printf("\n%d digits\n",numbers);//printing number of digits 

		return 0;
}


/*count 1)small letters  2)capital letters 3)numbers, in a string  and update the values if the main function*/
void str_statistics(char* str, int* small, int* capital, int* numbers) 
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			*small+=1;
		if (str[i] >= 'A' && str[i] <= 'Z')
			*capital+=1;
		if (str[i] >= '0' && str[i] <= '9')
			*numbers+=1;
}
	}