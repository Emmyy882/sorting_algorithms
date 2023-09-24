#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 *
 * Description: This function implements the shell sort algorithm to sort
 *              an array of integers in ascending order. The algorithm
 *              sorts the array by comparing elements that are a certain
 *              distance apart and gradually reducing the gap until all
 *              elements are compared and the array is sorted.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, tmp, gap = 0;

	if ((array == NULL) || (size < 2))
		return;
	/* Calculate initial gap using Knuth's sequence */
	while (gap <= ((int)size / 3))
		gap = (gap * 3) + 1;
	for (; gap > 0; )
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > tmp); j -= gap)
			{
				/* Shift elements to the right until correct position is found */
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		/* Print the current state of the array */
		print_array(array, size);
	}
}
