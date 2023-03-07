// Implementation of EXCHANGE SORT 
// this algorithm is very similar to selection sort
// but swapping is done everytime no. is less/greater

#include<stdio.h>

void exchangeSort(int arr[], int size);
void swap(int *x, int *y);

/***************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	exchangeSort(arr, length);

	//printing the sorted array
	for (int i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}

/************ FUNCTION TO SWAP INTEGERS ***********/

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*********** ITERATIVE SORTER FUNCTION **************/

void exchangeSort(int arr[], int size)
{
	int i, j, temp;

	for (i = 0; i < size - 1; i++) 
	{
		// putting the smallest element to lowest index
		for (j = i + 1; j < size; j++) 
		{
			if (arr[j] < arr[i]) 
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
}


