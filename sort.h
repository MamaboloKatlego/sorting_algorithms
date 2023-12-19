#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - The enumeration of Boolen values
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - The doubly linked list node
 *
 * @n: The int strored in the node
 * @prev: The pointer to the prev element of the list
 * @next: The pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void cocktail_sort_list(listint_t **list);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void TopDownSplitMerge(size_t begin, size_t end, int *array, int *copy);

#endif /* SORT_H */
