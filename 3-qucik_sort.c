#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 *
 * Description:
 * This function swaps two items in an array by exchanging their values.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub-array of an array using the
 *                            quicksort algorithm and Lomuto's partition scheme
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 *
 * Description: This function implements the quicksort algorithm with Lomuto's
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t k, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				/* Swap elements and print the current state of the array */
				swap_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		/*
		 * Move the pivot element to its final position and print the
		 * current state of the array
		 */
		swap_items(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		quick_sort_range_lomuto(array, low, k - 1, size);
	if (high - k > 1)
		quick_sort_range_lomuto(array, k + 1, high, size);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The number of elements in the array.
 *
 * Description: This function applies the quicksort algorithm with Lomuto's
 *              partition scheme to sort an array of integers
 *              in ascending order.
 *              It partitions the array around a pivot element and recursively
 *              sorts the left and right partitions until
 *              the entire array is sorted.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		/* Call the helper function to perform quicksort on the entire array */
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
