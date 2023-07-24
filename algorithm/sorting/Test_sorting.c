#include "sorting.h"
#include "math.h"

int main(void)
{
	int arr[] = {5, -2, 4, 6000, -100, 3};
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

	// printf("\n=== Sorting using quick sort ===\n");
	// quick_sort(arr, 0, (int)arr_size - 1);

    // printf("\n=== Sorting using quick sort2 ===\n");
    // quick_sort2(arr, 0, (int)arr_size - 1);

	printf("\n=== Sorting using radix sort ===\n");
	// CircularLinkedQueue *queue;
	// createQueue(&queue);

	// size_t i = 0;
	// while (i < arr_size)
	// 	enqueue(queue, arr[i++]);
	// printf("Original Queue: ");
	// display(queue);
	display_arr(arr, arr_size);

	radixSort(arr, arr_size);

	printf("\nSorted Queue: ");
	display_arr(arr, arr_size);

	// int num = -2;
	// int num2 = -100;
	// if (num < num2)
	// 	printf("-2 < 100");
	// else
	// 	printf("-2 > -100");
	return (0);
}