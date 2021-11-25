#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps and prints elements of array
 * @head: index of first element to swap
 * @swp: index of second element to swap
 * @array: array of element to swap
 * @size: size of array
 */
void swap(size_t head, size_t swp, int *array, size_t size)
{
	int tmp = array[head];

	array[head] = array[swp];
	array[swp] = tmp;
	print_array(array, size);
}

/**
 * sift_down - sift down method to sort
 * @array: array of integers to sort
 * @first: index of first element
 * @last: index of last element
 * @size: size of array
 */
void sift_down(int *array, size_t first, size_t last, size_t size)
{
	size_t head = first;
	size_t child, swp;

	while (head * 2 + 1 <= last)
	{
		child = head * 2 + 1;
		swp = head;

		if (array[swp] < array[child])
			swp = child;
		if (child + 1 <= last && array[swp] < array[child + 1])
			swp = child + 1;
		if (swp == head)
			return;
		swap(head, swp, array, size);
		head = swp;
	}
}

/**
 * heapify - convert an array to a heap
 * @array: array to convert
 * @size: size of array
 */
void heapify(int *array, size_t size)
{
	size_t first = (size - 2) / 2;

	while (first < size)
	{
		sift_down(array, first, size - 1, size);
		first--;
	}
}

/**
 * heap_sort - heap sort method to sort an array in ascending order
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i;
	size_t last = size - 1;

	if (size < 2)
		return;
	heapify(array, size);
	for (i = size; i > 1; i--)
	{
		swap(last, 0, array, size);
		last--;
		sift_down(array, 0, last, size);
	}
}