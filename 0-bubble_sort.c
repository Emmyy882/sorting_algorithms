#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swaaping elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				
				/* print the current order of ellements of the arrray */
				print_array(array, size);
			}
		}
	}

}
