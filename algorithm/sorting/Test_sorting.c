#include "sorting.h"

int main(void)
{
	int arr[6] = { 5, 2, 4, 6, 1, 3 };
    // int arr[6] = {1, 2, 3, 5, 6, 4};
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    // printf("\n=== Sorting using selection sort ===\n");
	// selection_sort(arr, arr_size);

    // printf("\n=== Sorting using insertion sort ===\n");
    // insertion_sort(arr, arr_size);

    // printf("\n=== Sorting using insertion sort2 ===\n");
    // insertion_sort2(arr, arr_size);

    // printf("\n=== Sorting using bubble sort ===\n");
    // bubble_sort(arr, arr_size);

    printf("\n=== Sorting using quick sort ===\n");
    quick_sort(arr, 0, arr_size - 1);

	display(arr, arr_size);
	return (0);
}