#include "deque_dll.h"
/*

First deque init. current size: 7
 <8> <5> <200> <0> <1> <3> <4>
 deleted rear. current size: 6
 <8> <5> <200> <0> <1> <3>
 deleted front. current size: 5
 <5> <200> <0> <1> <3>
 added front 4242 value. current size: 6
 <4242> <5> <200> <0> <1> <3>% 

*/
// int main(void)
// {
// 	int arr[] = {4, 3, 1, 0, 200, 5, 8};
// 	int arr_size = sizeof(arr) / sizeof(arr[0]);
// 	Deque *deque;

// 	create_deque(&deque);
// 	for (int i = 0; i < arr_size; i++)
// 		add_front(&deque, arr[i]);
// 	printf("\nFirst deque init. current size: %d\n", get_size(deque));
// 	display_deque(deque);
	
// 	delete_rear(&deque);
// 	printf("\n deleted rear. current size: %d\n", get_size(deque));
	
// 	display_deque(deque);
	
// 	delete_front(&deque);
// 	printf("\n deleted front. current size: %d\n", get_size(deque));

//  	display_deque(deque);

// 	add_front(&deque, 4242);
// 	printf("\n added front 4242 value. current size: %d\n", get_size(deque));
// 	display_deque(deque);

// 	destroy_deque(deque);
// 	return (0);
// }

void pb(Deque **dequeA, Deque **dequeB)
{
	int value = delete_front(dequeA);
	add_front(dequeB, value);
}

int main(void)
{
	int arr[] = {4, 3, 1, 0, 200, -3, 8};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	Deque *dequeA;
	Deque *dequeB;
	create_deque(&dequeA);
	create_deque(&dequeB);

	for (int i = 0; i < arr_size; i++)
		add_rear(&dequeA, arr[i]);
	printf("\nFirst deque init. current size: %d\n", get_size(dequeA));
	display_deque(dequeA);

	Node *currentNode = dequeA->front;
	Node *least = currentNode->next;
	while (currentNode->next != NULL)
	{
		if (currentNode->data < currentNode->next->data)
			least = currentNode;
		currentNode = currentNode->next;
	}
	printf("\n least value: %d\n", least->data);

	pb(&dequeA, &dequeB);
	printf("\n dequeA\n");
	display_deque(dequeA);
	printf("\n dequeB\n");
	display_deque(dequeB);
	return (0);
}