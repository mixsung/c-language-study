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

// void radix_sort(int *arr, int size)
// {
// 	int factor = 1;
// 	CircularLinkedQueue *queues[10];

// 	for (int d = 0; d < 32; d++)
// 	{
// 		for (int b = 0; b < 10; b++)
// 			createQueue(&queues[b]);
// 		// for (int i = 0; i < size; i++)
// 		// {
// 		// 	int digit = (arr[i] / factor) % 10;
// 		// 	enqueue(queues[digit], arr[i]);
// 		// }
// 		for (int i = 0; i < size; i++)
// 		{
// 			int value = arr[i] >= 0 ? arr[i] : -arr[i];
// 			int digit = (value / factor) % 10;
// 			enqueue(queues[digit], arr[i]);
// 		}
// 		int index = 0;
// 		for (int b = 0; b < 10; b++)
// 		{
// 			while (!isEmpty(queues[b]))
// 				arr[index++] = dequeue(queues[b]);
// 			free(queues[b]);
// 		}
// 		factor *= 10;
// 		display_arr(arr, size);
// 	}
	
// }  

void radixSort(int* list, int size) {
    int factor = 1;
    CircularLinkedQueue* positiveQueues[10];
    CircularLinkedQueue* negativeQueues[10];

    // Initialize the queues for positive and negative values
    for (int b = 0; b < 10; b++) {
        createQueue(&positiveQueues[b]);
        createQueue(&negativeQueues[b]);
    }

    // Distribute elements to the appropriate queues based on the current digit and sign
    for (int d = 0; d < 32; d++) {
        for (int i = 0; i < size; i++) {
            int value = list[i] >= 0 ? list[i] : -list[i];
            int digit = (value / factor) % 10;
            if (list[i] < 0) {
				enqueue(negativeQueues[digit], list[i]);
            } else {
				enqueue(positiveQueues[digit], list[i]);
            }
        }

        // Collect elements back from the queues into the original list
        int index = 0;
        for (int b = 0; b < 10; b++) {
			while (!isEmpty(negativeQueues[b])) {
                list[index++] = dequeue(negativeQueues[b]);
            }
			while (!isEmpty(positiveQueues[b])) {
                list[index++] = dequeue(positiveQueues[b]);
            }
        }

        factor *= 10;
    }
	    // Free the memory for the queues
    for (int b = 0; b < 10; b++) {
        free(negativeQueues[b]);
        free(positiveQueues[b]);
    }
}