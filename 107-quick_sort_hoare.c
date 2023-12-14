#include "sort.h"
#include <stdio.h>

/**
 * partition - A short description
 * Description: A long description
 *
 * @array: An arg_1 description
 * @low: An arg_2 description
 * @high: An arg_2 description
 * @size: An arg_2 description
 *
 * Return: return description
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	int pivot = (*array)[high];
	int i = low - 1, j = high + 1, temp;

	while (i < j)
	{
		do {
			i++;
		} while ((*array)[i] < pivot);

		do {
			j--;
		} while ((*array)[j] > pivot);

		if (i < j)
		{
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
			print_array(*array, size);
		}
	}
	return (i);
}

/**
 * qS - A short description
 * Description: A long description
 *
 * @array: An  arg_1 description
 * @low: An arg_2 description
 * @high: An arg_2 description
 * @size: An arg_2 description
 *
 * Return: It returns description
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		qS(array, low, (pi - 1), size);
		qS(array, pi, high, size);
	}
}

/**
 * quick_sort_hoare - A short description
 * Description: A long description
 *
 * @array: An arg_1 description
 * @size: An arg_2 description
 *
 * Return: It returns description
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
