#include "CircularLinkedQueue.h"

#define SIZE 10
int arr[SIZE] = {0, 1, 2, 3, 4};

int main(void)
{
    CircularLinkedQueue *Queue;
    createQueue(&Queue);

    size_t  i = 0;
    while (i < SIZE)
    {
        enqueue(Queue, arr[i]);
        i++;
    }
    display(Queue);
    destroyQueue(Queue);
    free(Queue);
    return (0);
}