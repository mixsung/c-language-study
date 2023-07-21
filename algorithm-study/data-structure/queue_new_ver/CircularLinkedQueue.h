#ifndef CIRCULAR_LINKED_QUEUE_H
#define CIRCULAR_LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
  int Data;
  struct tagNode *link;
} Node;

typedef struct tagCircularLinkedQueue
{
  Node *front;
  Node *rear;
} CircularLinkedQueue;

void createQueue(CircularLinkedQueue **Queue);
Node *createNode(int data);

void destroyQueue(CircularLinkedQueue *Queue);

Node *getLink(Node *_Node);
void setLink(Node *_Node, Node *next);

void enqueue(CircularLinkedQueue *Queue, int NewData);
int dequeue(CircularLinkedQueue *Queue);

int isEmpty(CircularLinkedQueue *Queue);
int getSize(CircularLinkedQueue *Queue);

Node *peek(CircularLinkedQueue *Queue);
void display(CircularLinkedQueue *Queue);

#endif