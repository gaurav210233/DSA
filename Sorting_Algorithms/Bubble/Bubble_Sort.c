// Implementation of simple BUBBLE SORT

#include<stdio.h>

void bubble_sort(int arr[], int length);
void swap(int *x, int *y);
					
/****************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	bubble_sort(arr,length);

	// printing the sorted array
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

/************ FUNCTION TO SWAP INTEGERS *************/

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
		
/********** ITERATIVE SORTER FUNCTION **************/

void bubble_sort(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{	
		// we are comparing j^th and (j+1)^th so we will go to last index - 1 only 
		// also on first iteration the greatest number will go to last index
		// similarly on second the 2^nd greatest goes to last 2^nd index and so on
		// thats why on every iteration of i we take j from 0 to < length - 1 - i 
		for(int j = 0; j < (length - i - 1); j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

