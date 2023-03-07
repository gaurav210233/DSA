// Recursive code for Quick_Sort Sorting Algorithm

#include<stdio.h>

void swap(int *x, int *y);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

/*******************************************************/
//						MAIN FUNCTION
/*******************************************************/
int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, 0, length - 1);

	for(int i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
}
/*******************************************************/
//					FUNCTION TO SWAP INTEGERS
/*******************************************************/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*******************************************************/
//					RECURSIVE SORTER FUNCTION
/*******************************************************/
void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivot_index = partition(arr, low, high);
		quicksort(arr, low, pivot_index - 1);
		quicksort(arr, pivot_index + 1, high);
	}	
}
/*******************************************************/
//						PARTITION FUNCTION
/*******************************************************/
int partition(int arr[], int low, int high)
{
	int pivot_value = arr[high];

	int i = low;
	for (int j = low; j < high; j++)
	{
		if(arr[j] <= pivot_value)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);

	return i;//This is the index of pivot element
}
/*******************************************************/