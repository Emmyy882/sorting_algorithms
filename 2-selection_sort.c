#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 *
 * Description: This function implements the selection sort algorithm
 *              to sort an array of integers in ascending order. It
 *              repeatedly finds the minimum element from the unsorted
 *              portion of the array and places it at the beginning.
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, low_idx;

	if (array != NULL)
	{
		for (i = 0; i < size - 1; i++)
		{
			low_idx = i;
			for (j = size - 1; j > i; j--)
			{
				if (array[j] < array[low_idx])
				{
					low_idx = j;
				}
			}
			if (i != low_idx)
			{
				/* Swap the minimum element with the current element */
				temp = array[i];
				array[i] = array[low_idx];
				array[low_idx] = temp;

				/* Print the current state of the array */
				print_array(array, size);
			}
		}
	}
}
