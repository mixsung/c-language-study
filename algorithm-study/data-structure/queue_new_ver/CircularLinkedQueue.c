#include "CircularLinkedQueue.h"

void createQueue(CircularLinkedQueue **Queue)
{
    (*Queue) = (CircularLinkedQueue *)malloc(sizeof(CircularLinkedQueue));

    (*Queue)->front = NULL;
    (*Queue)->rear = NULL;
}

Node *createNode(int data)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    if (NewNode != NULL)
    {
        NewNode->Data = data;
        NewNode->link = NULL;
    }
    return (NewNode);
}

Node *getLink(Node *_Node)
{
    return (_Node->link);
}

void setLink(Node *_Node, Node *next)
{
    _Node->link = next;
}

void enqueue(CircularLinkedQueue *Queue, int NewData)
{
    Node *NewNode;

    NewNode = createNode(NewData);
    if (NewNode == NULL)
    {
        printf("Memory allocation error. Cannot enqueue.\n");
        return ;
    }
    if (isEmpty(Queue))
    {
        Queue->front = NewNode;
        Queue->rear = NewNode;
    }
    else
    {
        // setLink(Queue->rear, NewNode);
        Queue->rear->link = NewNode;
        Queue->rear = NewNode;
    }
}

int dequeue(CircularLinkedQueue *Queue)
{
    int dequeuedValue;
    Node *temp;

    dequeuedValue = Queue->front->Data;
    temp = NULL;
    if (isEmpty(Queue))
    {
        printf("Queie is empty. Cannot dequeue.\n");
        return (1);
    }
    // Queue->front = getLink(Queue->front); // front--;
    if (Queue->front->link == NULL)
    {
        free(Queue->front);
        Queue->front = NULL;
        Queue->rear = NULL;
    }
    else
    {
        temp = Queue->front;
        Queue->front = Queue->front->link;
        free(temp);
    }
    return (dequeuedValue);
}

int isEmpty(CircularLinkedQueue *Queue)
{
    return (Queue->front == NULL);
}

int getSize(CircularLinkedQueue *Queue)
{
    Node *i;
    int  size;

    i = Queue->front;
    size = 0;
    while (i != NULL)
    {
        i = getLink(i);
        size++;
    }
    return (size);
}

Node *peek(CircularLinkedQueue *Queue)
{
    if (!isEmpty(Queue))
        return (Queue->front);
    else
        return (NULL);
}

void display(CircularLinkedQueue *Queue)
{
    Node *i;

    i = Queue->front;
    while (i != NULL)
    {
        printf(" <%d>", i->Data);
        i = getLink(i);
    }
}

void destroyQueue(CircularLinkedQueue *Queue)
{
    if (Queue == NULL)
        return ;
    while (!isEmpty(Queue))
        dequeue(Queue);
}

