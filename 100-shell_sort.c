#include "sort.h"

/**
*swap - the positions of two elements
*@array: array
*@itm1: array element
*@itm2: array element
*/
void swap(int *array, int itm1, int itm2)
{

	int temp;

	temp = array[itm1];
	array[itm1] = array[itm2];
	array[itm2] = temp;
}
/**
 * shell_sort - function that sorts using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t lig = 1, j, index = 0;

	if (array == NULL || size < 2)
		return;
	while (lig < size / 3)
		lig = 3 * lig + 1;
	while (lig >= 1)
	{
		for (j = lig; j < size; j++)
			for (index = j; index >= lig &&
			 (array[index] < array[index - lig]); index -= lig)
				swap(array, index, index - lig);
		print_array(array, size);
		lig /= 3;
	}
}
