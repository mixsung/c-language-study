#include "data-structure/deque_double_linked_list/deque_dll.h"

void swapNodes(Node** head_ref, Node* node1, Node* node2) {
    // If either of the nodes is NULL or the same, no need to swap
    if (node1 == NULL || node2 == NULL || node1 == node2)
        return;

    // If node1 is not the head of the list, update the previous node's 'next' pointer
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *head_ref = node2;

    // If node2 is not the head of the list, update the previous node's 'next' pointer
    if (node2->prev != NULL)
        node2->prev->next = node1;
    else
        *head_ref = node1;

    // Swap the 'prev' pointers of node1 and node2
    Node* temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    // Swap the 'next' pointers of node1 and node2
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

void insertion_sort_deque(Deque **deque)
{
	Node *front = get_front(*deque);
	Node *current = (*deque)->front->next;
	Node *new_start = NULL;
	int value = 0;

	while (current != NULL)
	{
		if (front->data <= current->data)	
			current = current->next;
		else
		{
			value = current->data;
			new_start = (*deque)->front;
			while (new_start != current)
			{
				if (new_start->data > value)
				{
					// temp = new_start->data;
					// new_start->data = new_start->next->data;
					// new_start->next->data = temp;
					swapNodes(&front, new_start, new_start->next);
					break;
				}
				new_start = new_start->next;
			}
			// display_deque(deque);
			current = current->next;
		}
	}
}

int main(void)
{
	Deque *deque;
	create_deque(&deque);

	// int arr[] = {-2, 0, -100, 20, 43, 3};
	int arr[] = {23, 42, 1, 2, 9, 34};
	size_t arr_size = sizeof(arr) / sizeof(arr[0]);

	size_t i = 0;
	while (i < arr_size)
	{
		add_rear(&deque, arr[i]);
		i++;
	}
	printf("\n");
	display_deque(deque);

	insertion_sort_deque(&deque);
	printf("\nAfter sort using insertion sort\n");
	display_deque(deque);
	
	return (0);
}