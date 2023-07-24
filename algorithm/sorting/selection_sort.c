#include "sorting.h"

size_t find_least(int *arr, size_t index, size_t size)
{
    size_t	least_index = index + 1;

    while (index < size)
    {
        if (arr[index] < arr[least_index])
			least_index = index;
		index++;
    }
	return (least_index);
}

void selection_sort(int *arr, size_t size)
{
    size_t i = 0;

    while (i < size - 1)
    {
        size_t least = find_least(arr, i, size);
		if (i != least)
			swap(&arr[i], &arr[least]);
		display_arr(arr, size);
		i++;
    }
	printf("\n-- sorting done -- \n");
}

/*
1 2 4 6 5 3 
1 2 4 6 5 3 
1 2 3 6 5 4 
1 2 3 4 5 6 
1 2 3 4 5 6 

-- sorting done -- 
1 2 3 4 5 6 
*/