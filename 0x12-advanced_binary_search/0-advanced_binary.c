#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 *
 * Return: return the index where value is located, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size < 1)
		return (-1);

	return (recur_search(array, 0, size - 1, value));
}

/**
 * recur_search - recursive search for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @first: is the first element of the array
 * @last: is the last element of the array
 * @value: value to search for
 *
 * Return: return the index where value is located, -1 otherwise
 */
int recur_search(int *array, int first, int last, int value)
{
	int mid = (first + last) / 2;
	int i;

	if (first > last)
		return (-1);
	printf("Searching in array: ");

	for (i = first; i <= last; i++)
	{
		if (i < last)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

	if (array[first] == value)
		return (first);

	if (array[mid] < value)
		return (recur_search(array, mid + 1, last, value));

	return (recur_search(array, first, mid, value));
}
