#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pv = array[high], i = low - 1, temp;
	int j = low;

	while (j < high)
	{
		if (array[j] <= pv)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - helper function for quick_sort
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
*/

void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort(array, low, pivot_index - 1, size);
		quicksort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}