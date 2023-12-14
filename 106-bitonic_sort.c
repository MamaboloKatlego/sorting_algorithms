#include "sort.h"
#include <stdio.h>

/** bitonic_sort */

/**
* bitonic_comp - It sort bitonic algorithm
* @top: The direction of sorting
* @array: A sub-array to sort
* @size: The size of the sub-array
*
* Return: A void.
*/

void bitonic_comp(char top, int *array, size_t size)
{
	size_t i, eva;
	int swap;

	eva = size / 2;
	for (i = 0; i < eva; i++)
	{
		if ((array[i] > array[i + eva]) == top)
		{
			swap = array[i];
			array[i] = array[i + eva];
			array[i + eva] = swap;
		}
	}
}

/**
* bit_join - The recursion to mergess ub-arrays
* @top: The direction of sorting
* @array: A sub-array to sort
* @size: The size of the sub-array
*
* Return: A void.
*/

void bit_join(char top, int *array, size_t size)
{
	if (size < 2)
		return;
	bitonic_comp(top, array, size);
	bit_join(top, array, size / 2);
	bit_join(top, array + (size / 2), size / 2);
}

/**
* rec_sort - The recursive bitonic sort algorithm
* @top: The direction of sorting
* @array: A sub-array to sort
* @size: The size of the sub-array
* @t: A total size of the original array
*
* Return: A void.
*/
void rec_sort(char top, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (top == 1) ? "top" : "DOWN");
	print_array(array, size);
	rec_sort(1, array, size / 2, t);
	rec_sort(0, array + (size / 2), size / 2, t);
	bit_join(top, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (top == 1) ? "top" : "DOWN");
	print_array(array, size);

}

/**
* bitonic_sort - It sorts an array in ascending order
* @array: An array to sort
* @size: The size of the array
*
* Return: A void.
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rec_sort(1, array, size, size);
}
