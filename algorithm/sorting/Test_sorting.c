#include "sorting.h"

int main(void)
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    // printf("\n=== Sorting using selection sort ===\n");
	// selection_sort(arr, arr_size);

    // printf("\n=== Sorting using insertion sort ===\n");
    // insertion_sort(arr, arr_size);

    printf("\n=== Sorting using bubble sort ===\n");
    bubble_sort(arr, arr_size);

	display(arr, arr_size);
	return (0);
}