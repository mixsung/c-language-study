#include "sorting.h"

void bubble_sort(int *arr, size_t size)
{
    size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		display_arr(arr, size);
		i++;
	}
	printf("\n-- sorting done -- \n");
}