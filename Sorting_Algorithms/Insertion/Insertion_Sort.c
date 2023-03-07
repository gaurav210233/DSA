#include<stdio.h>

void insertion_sort(int arr[], int length);

/****************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	insertion_sort(arr, length);

	// printing the sorted array
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

/********** ITERATIVE SORTER FUNCTION **************/

void insertion_sort(int arr[], int length)
{
	// we start from second index and go backwards
	for (int i = 1; i < length; i++)
	{
		int key = arr[i];
		int j = i - 1;

		// if number to the left is grater than the key we shift each element
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		// and place our element at correct position
		arr[j + 1] = key;
	}
}

