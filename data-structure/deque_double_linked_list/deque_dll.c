#include "deque_dll.h"

void create_deque(Deque **deque)
{
	(*deque) = (Deque *)malloc(sizeof(Deque));
	(*deque)->front = NULL;
	(*deque)->rear = NULL;
}

Node *create_node(int data)
{
	Node *new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

size_t is_empty(Deque *deque)
{
	return (deque->front == NULL);
}

void add_front(Deque **deque, int new_data)
{
	Node *front = NULL;
	Node *new_node = create_node(new_data);

	if (is_empty(*deque))
	{
		(*deque)->front = new_node;
		(*deque)->rear = new_node;
	}
	else
	{
		front = get_front(*deque);
		front->prev = new_node;
		new_node->next = front;
		(*deque)->front = new_node;
	}
}

int delete_front(Deque **deque)
{
	int deleted_front;
	Node *front;

	if (is_empty(*deque))
	{
		printf("Deque is empty. Cannot remove.\n");
		return (1);
	}
	deleted_front = (*deque)->front->data;
	front = get_front(*deque);
	(*deque)->front->prev = NULL;
	(*deque)->front = (*deque)->front->next;
	if ((*deque)->front == NULL)
		(*deque)->rear = NULL;
	free(front);
	return (deleted_front);
}

void add_rear(Deque **deque, int new_data)
{
	Node *rear = NULL;
	Node *new_node = create_node(new_data);
	
	if (is_empty(*deque))
	{
		(*deque)->front = new_node;
		(*deque)->rear = new_node;
	}
	else
	{
		rear = get_rear(*deque);
		rear->next = new_node;
		new_node->prev = rear;
		(*deque)->rear = new_node;
	}
}

int delete_rear(Deque **deque)
{
	int deleted_rear;
	Node *rear;

	if (is_empty(*deque))
	{
		printf("Deque is empty. Cannot remove.\n");
		return (1);
	}
	deleted_rear = (*deque)->rear->data;
	rear = get_rear(*deque);
	(*deque)->rear->prev->next = NULL;
	(*deque)->rear = (*deque)->rear->prev;
	free(rear);
	return (deleted_rear);
}

void destroy_deque(Deque *deque)
{
	if (deque == NULL)
		return ;
	while (!is_empty(deque))
		delete_front(&deque);
}

Node *get_front(Deque *deque)
{
	if (!deque)
		return (NULL);
	return (deque->front);
}

Node *get_rear(Deque *deque)
{
	if (!deque)
		return (NULL);
	return (deque->rear);
}

int get_size(Deque *deque)
{
	Node *current;
	size_t i = 0;

	current = deque->front;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void display_deque(Deque *deque)
{
	Node *current;

	current = deque->front;
	while (current != NULL)
	{
		printf(" <%d>", current->data);
		current = current->next;
	}
}


