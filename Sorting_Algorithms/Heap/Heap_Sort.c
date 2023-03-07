// Implementation of heap sort

#include<stdio.h>

void swap(int *x, int *y);
void create_heap(int arr[], int length);
void heap_sort(int arr[], int length);
void heapify(int arr[], int current_node, int heap_size);

/****************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};;
	int length = sizeof(arr)/sizeof(arr[0]);

	heap_sort(arr, length);

	//printing the sorted array
	for(int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

/************ FUNCTION TO SWAP INTEGERS *************/

void swap(int *x, int *y)
{
	int tempX = *x;
	*x = *y;
	*y = tempX;
}

/************ FUNCTION TO CREATE A HEAP *************/

// this function creates heap when array of elements is provided
void create_heap(int arr[], int length)
{
	// this variable stores the index of parent of last leaf node
	int last_nlf_node_index = length/2 - 1;// [ {ceil(length-1)/2} - 1) == length/2 -1 ]

	for(int i = last_nlf_node_index; i >= 0; i--)
	{
		heapify(arr, i, length);
	}
}

/********* FUNCTION TO PERFORM HEAP SORT **********/

void heap_sort(int arr[], int length)
{
	// we will create the heap first from the elements in array
	create_heap(arr, length);

	// In heap the largest element is at the root
	// So we remove element(largest) from the root and add the last leaf node element to the root 
	// now the it may happen that tree is not a heap anymore so we will make it using [heapify] function 
	// the removed largest elements will will ne stored at last index, lastindex -1, lastindex -2.....
	// Hence the array will be automatically sorted
	for(int i = length - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr,0,i);
	}

}

/********* FUNCTION TO HEAPIFY THE TREE **********/

void heapify(int arr[], int current_node, int heap_size)
{
	// start to heapify from current_node till the top of tree
	int max = current_node;
	// variables saving the left and right child of current node to perform comparisions
	int l_node = 2 * current_node + 1;
	int r_node = 2 * current_node + 2;

	if(l_node < heap_size && arr[l_node] > arr[max])
	{
		max = l_node;
	}

	if(r_node < heap_size && arr[r_node] > arr[max])
	{
		max = r_node;
	}

	// if element at l or r node is greater than current then swap
	if(max != current_node)
	{
		swap(&arr[current_node], &arr[max]);

		heapify(arr, max, heap_size);
	}
}