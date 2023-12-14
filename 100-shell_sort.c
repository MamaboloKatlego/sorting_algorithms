#include "sort.h"

/**
 * shell_sort - It sorts an array of ints in ascending order using the Shell
 *              sort algo, using the Knuth sequence
 * @array: An array
 * @size: The size of the array
 * Return: A void.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{

		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= tmp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = tmp;

		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
