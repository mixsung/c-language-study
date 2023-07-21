#include "deque.h"

#define SIZE 7
int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6};

int main(void)
{
    CircularLinkedQueue *Queue;
    size_t  i = 0;

    createQueue(&Queue);
    while (i < SIZE)
        enqueue(Queue, arr[i++]);
    printf("\n* Enqueue int arr[7] = {0,1,2,3,4,5,6}\n");
    display(Queue);

    printf("\n* Dequeue value: %d\n", dequeue(Queue));
    display(Queue);

    enqueue(Queue, 30);
    printf("\n* Enqueue 30\n");
    display(Queue);

    insertFront(Queue, 40);
    printf("\n* Insert 40\n");
    display(Queue);

    printf("\n* Remove value: %d\n", removeRear(Queue));
    display(Queue);
    
    enqueue(Queue, 50);
    printf("\n* Enqueue 50\n");
    display(Queue);

    destroyQueue(Queue);
    free(Queue);
    return (0);
}