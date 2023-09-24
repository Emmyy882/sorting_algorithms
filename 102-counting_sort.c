#include "sort.h"

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 *
 * Description: This function sorts an array using the counting sort algorithm,
 *              which works for non-negative integers. It creates a count array
 *              to store the frequency of each element in the input array.
 *              It then modifies the count array to store the cumulative sum
 *              of the frequencies. Finally, it uses the count array to build
 *              the sorted array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr = NULL, *array_sorted = NULL, max_val = 0;
	size_t i;

	if ((array == NULL) || (size < 2))
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++) {
		max_val = (array[i] > max_val ? array[i] : max_val);
		if (array[i] < 0)
			return; /* Counting sort only works for non-negative integers */
	}

	/* Create the count array */
	count_arr = malloc(sizeof(int) * (max_val + 1));
	if (count_arr == NULL)
		return;

	/* Create the sorted array */
	array_sorted = malloc(sizeof(int) * size);
	if (array_sorted == NULL) {
		free(count_arr);
		return;
	}

	/* Initialize the count array */
	for (i = 0; i < (size_t)(max_val + 1); i++)
		count_arr[i] = 0;

	/* Count the frequency of each element */
	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	/* Modify the count array to store the cumulative sum */
	for (i = 1; i < (size_t)(max_val + 1); i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max_val + 1);

	/* Build the sorted array using the count array */
	for (i = size - 1;; i--) {
		count_arr[array[i]]--;
		array_sorted[count_arr[array[i]]] = array[i];
		if (i == 0)
			break;
	}

	/* Copy the sorted array back to the input array */
	for (i = 0; i < size; i++)
		array[i] = array_sorted[i];

	free(array_sorted);
	free(count_arr);
}
