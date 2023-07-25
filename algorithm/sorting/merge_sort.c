#include "sorting.h"
#include "../../data-structure/deque/deque.h"

// not done

static Node *get_middle(Node *front)
{
	Node *slow = front;
	Node *fast = front->link;
	
	if (front == NULL)
		return (NULL);
	while (fast != NULL)
	{
		fast = fast->link;
		if (fast != NULL)
		{
			slow = slow->link;
			fast = fast->link;
		}
	}
	return (slow);
}

void merge_sort_deque(CircularLinkedQueue *deque)
{
	Node *mid = get_middle(deque->front);
	printf("mid data: %d", mid->Data);
}