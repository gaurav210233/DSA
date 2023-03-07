// Iterative code for Quick_Sort Sorting Algorithm

#include<stdio.h>

void quick_sort(int arr[], int arr_size);
void quick_sort_bound(int arr[], int arr_size, int beg, int end, int *pivot);

/* Function to put the pivot element at its correct position */
void quick_sort_bound(int arr[], int arr_size, int beg, int end, int *pivot)
{
	int left, right;
	left = beg;
	right = end;
	*pivot = beg;

	/************************************************/
	step_1:
	while( (arr[*pivot] <= arr[right]) && (*pivot != right) )
	{
		right = right - 1;
	}
	if(*pivot == right) return; // This means that all element to the right of pivot are greater  
	if(arr[*pivot] > arr[right])
	{
		arr[*pivot] = arr[*pivot] ^ arr[right];
		arr[right] = arr[*pivot] ^ arr[right]; // Performing swap without third variable 
		arr[*pivot] = arr[*pivot] ^ arr[right];
	}
	*pivot = right;
	goto step_2;
	/************************************************/

	/************************************************/
	step_2:
	while( (arr[left] <= arr[*pivot]) && (left != *pivot) )
	{
		left = left + 1;
	}
	if(left == *pivot) return;// This means that all element to the left of pivot are smaller
	if(arr[left] > arr[*pivot])
	{
		arr[*pivot] = arr[*pivot] ^ arr[left];
		arr[left] = arr[*pivot] ^ arr[left];  // Performing swap without third variable 
		arr[*pivot] = arr[*pivot] ^ arr[left];
	}
	*pivot = left;
	goto step_1;
	/************************************************/

}

/* Function to perform QS, it keeps track of array and sub-arrays by maintaining
   used defined stack.
*/
void quick_sort(int arr[], int arr_size)
{
	// top -> top of the stack
	// beg, end -> lower bound and upper bound of array
	// loc -> location of pivot element
	// lower_stack, upper_stack -> maintains index of sub arrays
	int top = -1, beg, end, loc, lower_stack[arr_size/2], upper_stack[arr_size/2];

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
		quick_sort_bound(arr, arr_size, beg, end, &loc);
        
        // Left part -> Push
		if(beg < loc - 1)
		{
			top = top +1;
			lower_stack[top] = beg;
			upper_stack[top] = loc - 1;
		}

		// Right part -> Push
		if(loc + 1 < end)
		{
			top = top +1;
			lower_stack[top] = loc + 1;
			upper_stack[top] = end;
		}
	}
}

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