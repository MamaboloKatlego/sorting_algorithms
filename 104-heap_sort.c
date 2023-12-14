#include "sort.h"

/**
 * siftDown - It ensures that the max heap property is maintained for the
 *            subtree
 * @array: An array
 * @start: A root node
 * @end: Last index of the unsorted portion of the array
 * @size: The size of the array
 *
 * Return: A void.
 */
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root, swap, child;
	int tmp;

	root = start;

	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heapify - It rearranges the elements of the array to form a max heap
 * @array: An array
 * @size: The size of the array
 *
 * Return: A void.
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size - 1 - 1) / 2;

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - It sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 * @array: An array
 * @size: The size of the array
 *
 * Return: A void.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;

	if (!array || size < 2)
		return;
	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		end--;
		siftDown(array, 0, end, size);
	}
}
