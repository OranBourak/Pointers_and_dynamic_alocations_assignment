/* Assignment: 4
Author: Oran Bourak, ID: 204788285
*/
#define _CRT_SECURE_NO_WARNINGS
#define s_size 50
enum{Add=1,Twice=2,Find=3,Print=4,End=5};
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void menu();
char** init_arr(int* psize);
void print(char** arr, int size);
int find(char** arr, int size, char* str);
void twice(char** arr, int size, int index);
char** add(char** arr, int* psize, char* str);

int main()
{
	int size,i,choice,index;
	char temp[s_size];
	char** array,**array2;
	printf("Please enter the size of the array:");
	scanf("%d",&size);
	array=init_arr(&size);
	getchar(); //gets 'enter' siting in the buffer after scanf
	for (i = 0; i < size; i++) {
		printf("\nPlease enter word number %d\n", i + 1);
		gets(array[i]);
	}
	
	do {
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case Add: //add word to the array
			printf("Please enter a word.\n");
			scanf("%s",temp);
			array2 = array;
			array=add(array, &size, temp); //add the word and creat new array
			
			if (array != NULL) {   
				printf("The word was added.\n");
			} else {  //if realloc fails
				array = array2;
			}
			break;

		case Twice:// recived index  and doubled  the word in index location
			printf("Please enter the index of the word you want to double in the array.\n");
			scanf("%d", &index);
			twice(array, size, index);
			break;
		
		case Find: // recived word and print the location if the word exist in the array
			printf("Please enter a word that you want to find its location.\n");
			scanf("%s", temp);
			index = find(array, size, temp);
			if (index == -1)
				printf("The word that you enterd is not in the array.\n ");
			else
				printf("The word location is %d.\n", index);
			break;

		case Print: //printing the array
			print(array,size);
			break;

		case End: //exit the program
			for (i = 0; i < size; i++)
				free(array[i]);
			free(array);
			printf("Goodbay.");
			break;

		default:
			printf("You enterd an invalid choice.\n");
		}
	} while (choice != End);

	return 0;
}

char** init_arr(int* psize) // get size and creates a two-dimensional string
{
	int i;
	char** str = (char**)malloc(*psize * sizeof(char*));
if (str == NULL)/*if malloc fails*/
{
	printf("Cannot allocate memory.");
	return NULL;
}
for (i = 0; i < *psize; i++){
	str[i] = (char*)malloc(s_size* sizeof(char));
	if (str[i] == 0)/*if malloc fails*/
	{
		printf("Cannot allocate memory.");
		return NULL;
	}
}
return str;
}

/*The function accepts as an parameter an array of stringsand its size, as well as another string.If the string does not appear in the array,
the function createsand returns a new array that contains all the members of the array, as well as the string.
It also updates the size.*/
char** add(char** arr, int* psize, char* str)
{
	int i;
	char** new_array;
	for (i = 0; i < *psize; i++)
	{
		if (!strcmp(arr[i], str)) {//check if str exist in arr
			printf("That word alrady exists in the array.");
			return NULL;
			
		}
	}
	new_array = (char**)realloc(arr, (*psize + 1) * sizeof(char*)); //aloocate new array that contain the old one
	if (new_array == NULL)
	{
		printf("Cannot allocate memory.");
		return NULL;
	}
	new_array[*psize] = (char*)malloc(strlen(str) * sizeof(char)+1);
	if (new_array[*psize] == NULL)
	{
		printf("Cannot allocate memory.");
		return NULL;
	}
	strcpy(new_array[*psize], str);
	*psize += 1; //update the size

	return new_array;
}
/*The function accepts as an parameter an array of stringsand its size, as well as an index in the array.
If the index is correct, the function doubles the string on the index location*/
void twice(char** arr, int size, int index)
{
	if (index<0 || index>size - 1) {
		printf("The index that you enterd is out of the range.\nPlease try again.\n");
		return;
	}
	char temp[s_size]; 
	strcpy(temp, arr[index]); //copy the array to temp
	arr[index] = (char*)realloc(*(arr+index), ((strlen(arr[index]) * 2) + 1)*sizeof(char)); //allocating doubel size for the string 
	if (arr[index] == NULL)/*if realloc fails*/
	{
		printf("Cannot allocate memory.");
		return;
	}
	strcat(arr[index], temp);
	printf("The word has been successfully doubled.\n");
}

/*check if str contained in arr*/
int find(char** arr, int size, char* str) {
	int index, i;
	for (i = 0; i < size; i++)
	{
		if (!(strcmp(arr[i], str)))
			return i;
	}
	return -1;
}
/*Print an array of strings*/
void print(char** arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
			printf("%s ",arr[i]);
}

void menu()/*printing the menu*/
{
	printf("\nPlease enter your choice:\n");
	printf("1 - Add\n2 - Twice\n3 - Find\n4 - Print\n5 - End\n");
}