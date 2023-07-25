#include "sorting.h"

// not done

void quick_sort_deque(CircularLinkedQueue *deque)
{
	Node *pivot = deque->front;
	Node *left = deque->front->link;
	Node *right = deque->rear;

	while (left != right)
	{
		while (left->Data <= pivot->Data && left->link != right)
			left = left->link;
		while (right->Data >= pivot->Data && left->link != right)
			right = right;
		left = left->link;
	}
}