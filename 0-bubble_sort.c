#include "sort.h"
/**
 * bubble_sort - sort array from min to max
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, j, k = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
			k = array[j];
			array[j] = array[j + 1];
			array[j + 1] = k;
			print_array(array, size);
			}
		}
}
