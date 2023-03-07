// Iterative code for Quick_Sort Sorting Algorithm

#include<stdio.h>

void quick_sort(int arr[], int arr_size);
int partition(int arr[], int beg, int end);
void swap(int *, int *);

/*******************************************************/
//						MAIN FUNCTION								  
/*******************************************************/
int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	
	quick_sort(arr, sizeof(arr)/sizeof(arr[0]));
	
	// Printing the Sorted Array
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ",arr[i]);
	}
}
/*******************************************************/
//					FUNCTION TO SWAP INTEGERS
/*******************************************************/
void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
/*******************************************************/
//						PARTITION FUNCTION
/*******************************************************/
int partition(int arr[], int beg, int end)
{
	// Selecting end element as pivot element
	int pivot_value = arr[end];
	int i = beg;
	
	for (int j = beg; j < end; j++)
	{
		if(arr[j] <= pivot_value)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[end]);
	return i;
}

/*******************************************************/
//				ITERATIVE SORTER FUNCTION
/*******************************************************/
void quick_sort(int arr[], int arr_size)
{
	// top -> top of the stack
	// beg, end -> lower bound and upper bound of array
	// pivot_index -> location of pivot element
	// lower_stack, upper_stack -> maintains index of sub arrays
	int top = -1, lower_stack[arr_size/2], upper_stack[arr_size/2];
	int  beg, end;

	// Pushing initial values to stacks only if array can be sorted
	if (arr_size > 1)
	{
		top = top + 1;
		lower_stack[top] = 0;
		upper_stack[top] = arr_size - 1;
	}

	// performing operations until stacks get empty
	while(top != -1)
	{
		// Popping bounds from the stacks (here right subarrays will be sorted first)
		// As they are pushed later
		beg = lower_stack[top];
		end = upper_stack[top];
		top = top - 1;
		int pivot_index = partition(arr, beg, end);  
      // Left part -> Push
		if(beg < pivot_index - 1)
		{
			top = top +1;
			lower_stack[top] = beg;
			upper_stack[top] = pivot_index - 1;
		}
		// Right part -> Push
		if(pivot_index + 1 < end)
		{
			top = top +1;
			lower_stack[top] = pivot_index + 1;
			upper_stack[top] = end;
		}
	}
}
/*******************************************************/
