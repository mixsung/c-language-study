#ifndef DEQUE_DLL_H
#define DEQUE_DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int	data;
	struct tagNode *prev;
	struct tagNode *next;
} Node;

typedef struct deque_double_linked_list
{
	Node *front;
	Node *rear;	
} Deque;

void create_deque(Deque **deque);
Node *create_node(int data);

void add_front(Deque **deque, int new_data);
int delete_front(Deque **deque);
void add_rear(Deque **deque, int new_data);
int delete_rear(Deque **deque);

void destroy_deque(Deque *deque);

size_t is_empty(Deque *deque);
Node *get_front(Deque *deque);
Node *get_rear(Deque *deque);
int get_size(Deque *deque);
void display_deque(Deque *deque);

#endif