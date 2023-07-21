#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
  ElementType Data;
} Node;

typedef struct tagCircularQueue
{
  int Capacity;
  int Front;     // 전단
  int Rear;      // 후단 (실제 후단보다 + 1)
  Node *Nodes;   //Nodes를 메모리에 할당할 때는 'Capacity + 1'만큼 할당
                 //노드 하나를 공백/포화 상태 구분용 'Dummy Node'로 사용해서
} CircularQueue;

void  CQ_CreateQueue(CircularQueue **Queue, int Capacity);
void  CQ_DestroyQueue(CircularQueue *Queue);

void  CQ_Enqueue(CircularQueue *Queue, ElementType Data);
ElementType CQ_Dequeue(CircularQueue *Queue);

int   CQ_GetSize(CircularQueue *Queue);
int   CQ_IsEmpty(CircularQueue *Queue);
int   CQ_IsFull(CircularQueue *Queue);
void  display(CircularQueue *Queue);
ElementType peek(CircularQueue *Queue);

#endif