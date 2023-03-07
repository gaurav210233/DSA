// Program to perform Selection sort

#include<stdio.h>

void selection_Sort(int arr[], int length);
void swap(int *x, int *y);

/*******************************************************/
//					FUNCTION TO SWAP INTEGERS
/*******************************************************/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*******************************************************/
//				SORTER FUNCTION
/*******************************************************/
void selection_Sort(int arr[], int length)
{
	for(int i = 0; i < length -1; i++)
	{
		int min_index = i;
		for(int j = i + 1; j < length; j++)
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		if(min_index != i)
		{
			swap(&arr[i],&arr[min_index]);
		}
	}
}

/*******************************************************/
//						MAIN FUNCTION
/*******************************************************/
int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = (sizeof(arr)/sizeof(arr[0]));
	
	selection_Sort(arr, length);

	for(int i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
}
/*****************************************************/
