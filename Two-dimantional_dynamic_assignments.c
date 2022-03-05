/* Assignment: 4
Author: Oran Bourak, ID: 204788285
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int digitcounter(int num);
long long** shrink(unsigned int** arr, int size);

int main()
{
	int j, i, size;
	unsigned int** arr;
	long long** new_array;
	printf("Please enter the array size:\n");
	scanf("%d", &size);
	arr = (unsigned int**)malloc(size * sizeof(unsigned int*));
	if (arr==NULL) /*if malloc fails*/
	{
		printf("Cannot allocate memory");
		return 0;
	}
	for (i = 0; i < size; i++) /*creating 2 dim array*/
	{
		arr[i] = (unsigned int*)malloc(size * sizeof(unsigned int));
		if (!arr[i])
		{
			printf("Cannot allocate memory");
			return 0;
		}
	}

	for (i = 0; i < size; i++) //recives the array from the user
	{
		printf("\nPlease enter %d numbers for array number %d.\n", size, i + 1);
		for (j = 0; j < size; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	new_array = shrink(arr, size); //free the memory
	for (i = 0; i < size; i++)
		free(arr[i]);
	free(arr);

	printf("\n");
	for (i = 0; i < size / 2; i++) {   /* printing the new array*/
		for (j = 0; j < size / 2; j++)
			printf("%lld ", new_array[i][j]);
		printf("\n");
	}
	for (i = 0; i < size/2; i++) //free the new array memory
		free(new_array[i]);
	free(new_array);

	
	return 0;

}

/*gets a two dim array and size ,creating a long long type 2 dim array in size: size/2  contains the values from the "old" array */
long long** shrink(unsigned int** arr, int size)
{
	if (size % 2) { //odd
		return NULL;
		printf("The function not working with an odd matrix!\nPlease try again.");
	}
	int i, j;
	long long** main_arr = (long long**)malloc((size / 2) * sizeof(long long*)); //allocate memory fot the main array
	if (main_arr == NULL)  /*if malloc fails */
	{
		printf("cannot alocate memory.\n");
		return 0;
	}
	for (i = 0; i < (size / 2); i++)
	{
		main_arr[i] = (long long*)malloc((size / 2) * sizeof(long long));
		if (main_arr[i] == NULL)  /*if malloc fails */
		{
			printf("cannot alocate memory.\n");
			return 0;
		}
	}

	/*"sum" 4 number from the matrix: 2+3+4+5=>2345*/
	for (i = 0; i < (size / 2); i++) {
		for (j = 0; j < (size / 2); j++) {  
			main_arr[i][j] = arr[2 * i][2 * j];
			main_arr[i][j] *= digitcounter(arr[2 * i][2 * j + 1]);
			main_arr[i][j] +=arr[2 * i][2 * j + 1];
			main_arr[i][j] *= digitcounter(arr[2 * i + 1][2 * j]);
			main_arr[i][j] += arr[2 * i + 1][2 * j];
			main_arr[i][j] *= digitcounter(arr[2 * i + 1][2 * j + 1]);
			main_arr[i][j] += arr[2 * i + 1][2 * j + 1];
		}
	}
	return main_arr;
}
/*count digits of num and return 10^counter (power)*/
int digitcounter(int num) 
{
	int counter = 1;
	while (num != 0)
	{
		num /= 10;
		counter *= 10;
	}
	return counter;
}