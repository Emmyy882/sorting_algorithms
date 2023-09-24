#include "sort.h"

/**
 * selection_sort - a function that sorts am array of integers in ..
 * ascendinng order using the selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 * 
 * Description: sorts array in ascending order. print the array after each time of swapping two elements.
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > array[i + 1])
		{
			/* swaaping the elements */
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;

			/* printing the cuurent state of the array */
			print_array(array, size);
		}
	}
}
