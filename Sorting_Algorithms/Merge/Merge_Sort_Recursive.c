// Implementation of merge sort

#include<stdio.h>

void merge_sort(int arr[], int length);
void merge_recursive_split(int arr[], int l_index, int r_index);
void merge_arrays(int arr[], int l_index, int m_index, int r_index);

/****************** MAIN FUNCTION ******************/

int main()
{
	int arr[] = {2,5,6,3,0,7,9,8,1,4};
	int length = sizeof(arr)/sizeof(arr[0]);

	merge_sort(arr, length);

	// printing sorted array
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}
}

/**********  WRAPPER OF RECURSIVE SORTER FUNCTION **************/

void merge_sort(int arr[], int length)
{
	// providing the range of array to be sorted
	merge_recursive_split(arr, 0, length - 1);	
}

/********** RECURSIVE SORTER FUNCTION (SPLIT ARRAYS) **************/

void merge_recursive_split(int arr[], int l_index, int r_index)
{
	// performing recursive steps untill l_index >= r_index
	if(l_index < r_index)
	{
		int m_index = l_index + (r_index - l_index)/2;
	
		merge_recursive_split(arr, l_index, m_index);
		merge_recursive_split(arr, m_index + 1, r_index);

		// after splitting call merge array function
		merge_arrays(arr, l_index, m_index, r_index);	
	}		
}

/********** FUNCTION TO MERGE TWO ARRAYS AFTER COMPARING **************/

void merge_arrays(int arr[], int l_index, int m_index, int r_index)
{
	int l_length = m_index - l_index + 1;// as indexing starts from 0
	int r_length = r_index - m_index;

	int temp_arr_l[l_length];
	int temp_arr_r[r_length];

	// Copying elements to temporary arrays
	for(int i = 0; i < l_length; i++)
	{
		temp_arr_l[i] = arr[l_index + i];
	}

	for(int i = 0; i < r_length; i++)
	{
		temp_arr_r[i] = arr[m_index + 1 + i];
	}

	int i = 0, j = 0, k;

	for(k = l_index; k <= r_index; k++ )
	{
		// Copying elements to original array after comparing
		if( (i < l_length) && (j >= r_length || temp_arr_l[i] <= temp_arr_r[j]) )
		{
			arr[k] = temp_arr_l[i];
			i++;
		}

		else
		{
			arr[k] = temp_arr_r[j];
			j++;
		}
	}
}
