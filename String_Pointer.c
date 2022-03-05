/* Assignment: 4
Author: Oran Bourak, ID: 204788285
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* divide(int* arr1, int size_1, int* arr2, int size_2);

int main()
{
	int size1, size2, i;
	int* arr1, * arr2, * arr3;

	printf("Please enter size for the first array:\n");
	scanf("%d", &size1);
	arr1 = (int*)malloc(size1 * sizeof(int));
	if (arr1 == NULL) /*if malloc fails*/
	{
		printf("Cannot allocate memory.\n");
		return 0;
	}
	printf("Please enter the first array:\n");
	for (i = 0; i < size1; i++) //scanf second array
	{
		scanf("%d", arr1+i);
	}


	printf("Pleas enter size for the second array:\n");
	scanf("%d", &size2);
	arr2 = (int*)malloc(size2 * sizeof(int)); 
	if (arr2 == NULL) /*if malloc fails*/
	{
		printf("Cannot allocate memory.\n");
		return 0;
	}

	printf("Please enter the second array:\n");
	for (i = 0; i < size2; i++) //scanf second array
	{
		scanf("%d", arr2+i);
		if (arr2[i] == 0)
			arr2[i] = 1; //change 0 to 1 in the second array
	}

	arr3 = divide(arr1, size1, arr2, size2); 

	for (i = 0; i < size2; i++) //printing the new array values
	{
		printf("%d ", arr3[i]);
	}
	/*releases the memory*/
	free(arr1);
	free(arr2);
	free(arr3);

	return 0;
}

/*The function accepts as parameters an arr1 array of integers and its size, and also an arr2 array of integers and its size. 
It forms an arr3 array of integers, the size of which is equal to the size of the array b.
It writes in arr3 [i] the number of members in the array arr1 that are divided by arr2 [i]. Finally it returns the array c address*/
int* divide(int* arr1, int size_1, int* arr2, int size_2) 
{
	int counter = 0, i, j;
	int* arr3 = (int*)malloc(size_2 * sizeof(int));

	if (arr3 == NULL) /*if malloc fails*/ {
		printf("cannot allocate memory.");
		return 0;
	}

	for (j = 0; j < size_2; j++){ 
		for (i = 0; i < size_1; i++)
		{
			if (arr1[i] % arr2[j] == 0) //count how many number from array1 are divide by arr2[j]
				counter++;
		}
		arr3[j] = counter;
		counter = 0;
	}
	return arr3;
}