#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t index, count;
	int temp, swap, fg = 0;

	if (array == NULL)
		return;
	for (index = 0; index < size; index++)
	{
		temp = index;
		fg = 0;
		for (count = index + 1; count < size; count++)
		{
			if (array[temp] > array[count])
			{
				temp = count;
				fg += 1;
			}
		}
		swap = array[index];
		array[index] = array[temp];
		array[temp] = swap;
		if (fg != 0)
			print_array(array, size);
	}
}
