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
 * Return:  The return description
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int temp, pivot;

	pivot = (*array)[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
			if ((*array)[i] !=  (*array)[j])
				print_array(*array, size);
		}
	}

	temp =  (*array)[i + 1];
	(*array)[i + 1] = (*array)[high];
	(*array)[high] = temp;
	if ((*array)[i + 1] !=  (*array)[high])
		print_array(*array, size);
	return (i + 1);
}

/**
 * qS - A short description
 *
 * Description: A long description
 *
 * @array: An arg_1 description
 * @low: An arg_2 description
 * @high: An arg_2 description
 * @size: An arg_2 description
 *
 * Return: The return description
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		if (pi != 0)
			qS(array, low, (pi - 1), size);
		if (pi < size - 1)
			qS(array, (pi + 1), high, size);
	}
}

/**
 * quick_sort - A short description
 *
 * Description: A long description
 *
 * @array: An arg_1 description
 * @size: An arg_2 description
 *
 * Return: The return description
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
