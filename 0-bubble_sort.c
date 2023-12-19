#include "sort.h"

/**
 * bubble_sort - It sorts an array of integers in ascending order using the
 *               Bubble sort algorithm
 * @array: Array of integers
 * @size: The size of the array
 *
 * Return: A void.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i, tmp, s = size;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < s; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;

				swapped = 1;
				print_array(array, size);
			}
		}
		s--;
	}
}
