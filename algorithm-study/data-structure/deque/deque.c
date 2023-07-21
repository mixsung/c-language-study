#include "deque.h"

void insertFront(CircularLinkedQueue *Queue, int data)
{
    Node *NewNode = createNode(data);
    if (NewNode == NULL)
    {
        printf("Memory allocation error. Cannot insert.\n");
        return ;
    }
    if (isEmpty(Queue))
    {
        Queue->front = NewNode;
        Queue->rear = NewNode;
    }
    else
    {
        NewNode->link = Queue->front;
        Queue->front = NewNode;
    }
}

int removeFront(CircularLinkedQueue *Queue)
{
    int frontValue = Queue->front->Data;
    Node *temp = Queue->front;

    if (isEmpty(Queue))
    {
        printf("Queue is empty. Cannot remove.\n");
        return (1);
    }
    Queue->front = Queue->front->link;
    free(temp);
    if (Queue->front == NULL)
        Queue->rear = NULL;
    return (frontValue);
}

int removeRear(CircularLinkedQueue *Queue)
{
    int removedValue = Queue->rear->Data;
    Node *current = Queue->front;

    if (isEmpty(Queue))
    {
        printf("Deque is empty. Cannot remove from the rear\n");
        return (1);
    }
    while (current->link != Queue->rear)
        current = current->link;
    free(Queue->rear);
    Queue->rear = current;
    Queue->rear->link = NULL;

    if (Queue->rear == NULL)
        Queue->front = NULL;

    // if (Queue->front == Queue->rear) // 하나밖에 없다는거?
    // {
    //     free(Queue->rear);
    //     Queue->front = NULL;
    //     Queue->rear = NULL;
    // }
    return (removedValue);
}