// Implementation of improved BUBBLE SORT

#include<stdio.h>
#include<stdbool.h>

void bubble_sort(int arr[], int length);
void swap(int *x, int *y);
		
/***************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};;
	int length = sizeof(arr)/sizeof(arr[0]);

	bubble_sort(arr,length);

	// printing the sorted array
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}
					
/************ FUNCTION TO SWAP INTEGERS ***********/

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
			
/*********** ITERATIVE SORTER FUNCTION **************/

void bubble_sort(int arr[], int length)
{
	for(int i = 0; i < length; i++)
	{	
		// variable to check even a single swap is done or not in an iteration
		bool is_swap = 0;

		for(int j = 0; j < (length - i - 1); j++)
		{
			if(arr[j] > arr[j+1])
			{
				is_swap = 1;
				swap(&arr[j], &arr[j + 1]);
			}
		}

		// if no swapping is done this means array is sorted
		// then no need to continue further we will get out of function 
		if(is_swap == 0)
		{
			return;
		}
	}
}

