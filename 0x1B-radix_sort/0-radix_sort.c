#include "sort.h"

/**
 * getMax - get max value
 * @array: array contains values
 * @n: size of array
 * Return: max number of array
 */
int getMax(int array[], int n)
{
  	int i, max;

	for (max = array[0], i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - counting sort according to the digit
 * @array: array to be sorted
 * @size: size of array
 * @place: placeof digits
 * Return: None
 */
void countingSort(int array[], int size, int place)
{
	int *output, i, count[10] = { 0 };

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	// Calculate count of elements
	for (int i = 0; i < size; i++)
	{
		count[(array[i] / place) % 10]++;
	}
	// Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (int i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Sort an array with radix sort
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int place, max;

	if (size < 2)
		return;
	// Get maximum element
	max = getMax(array, size);
	// Apply counting sort to sort elements based on place value
	for (place = 1; max / place > 0; place *= 10)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}
