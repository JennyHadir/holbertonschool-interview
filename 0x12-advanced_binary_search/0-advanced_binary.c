#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - binary search
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: index of value, -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size < 1)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}

/**
 *binary_search - binary search
 * @array: array to search
 * @left: left index
 * @right: right index
 * @value: value to search for
 *
 * Return: index of value, -1 if not found
 */
int binary_search(int *array, int left, int right, int value)
{
	int mid = (left + right) / 2;
	int i;

	if (left > right)
		return (-1);
	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

	if (array[left] == value)
		return (left);

	if (array[mid] < value)
		return (binary_search(array, mid + 1, right, value));

	return (binary_search(array, left, mid, value));
}