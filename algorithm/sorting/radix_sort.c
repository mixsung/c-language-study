#include "sorting.h"
// #include <math.h>

// negative digits: 11
// positive digits: 10
// 정렬되지 않은 Queue를 가지고 radix sort

// static int get_digits(int num, int digit_pos)
// {
// 	int divider = 1;
// 	int i = 0;

// 	while (i < digit_pos)
// 	{
// 		divider *= 10;
// 		i++;
// 	}
// 	return ((num / divider) % 10);
// }

// static int get_max_digits(CircularLinkedQueue* queue) {
//     int max_digits = 1;
//     Node *current = queue->front;
//     while (current != NULL) {
//         int digits = 1;
//         int temp = current->Data;
//         if (temp < 0)
//             temp = -temp;
//         while (temp >= 10) {
//             temp /= 10;
//             digits++;
//         }
//         if (digits > max_digits)
//             max_digits = digits;
//         current = current->link;
//     }
//     return max_digits;
// }

void radix_sort(int *arr, int size)
{
	int factor = 1;
	CircularLinkedQueue *queues[10];

	for (int d = 0; d < 32; d++)
	{
		for (int b = 0; b < 10; b++)
			createQueue(&queues[b]);
		for (int i = 0; i < size; i++)
		{
			int digit = (arr[i] / factor) % 10;
			enqueue(queues[digit], arr[i]);
		}
		int index = 0;
		for (int b = 0; b < 10; b++)
		{
			while (!isEmpty(queues[b]))
				arr[index++] = dequeue(queues[b]);
			free(queues[b]);
		}
		factor *= 10;
		display_arr(arr, size);
	}
	
}  