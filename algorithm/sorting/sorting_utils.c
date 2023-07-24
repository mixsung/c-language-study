#include "sorting.h"

void display_arr(int *arr, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void swap(int *a, int *b) {
    int	temp = *a;
    *a = *b;
    *b = temp;
}
