#ifndef DEQUE_H
#define DEQUE_H

#include "../queue_new_ver/CircularLinkedQueue.h"

void insertFront(CircularLinkedQueue *Queue, int data);

int removeFront(CircularLinkedQueue *Queue);
int removeRear(CircularLinkedQueue *Queue);

#endif