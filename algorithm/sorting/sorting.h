#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include "../../data-structure/queue_new_ver/CircularLinkedQueue.h"

void display_arr(int *arr, size_t size);
void swap(int *a, int *b);
void selection_sort(int *arr, size_t size);
void insertion_sort(int *arr, size_t size);
void insertion_sort2(int *arr, size_t size);
void bubble_sort(int *arr, size_t size);
void quick_sort(int *arr, int left, int right);
void quick_sort2(int *arr, int left, int right);
void quick_sort_deque(CircularLinkedQueue *deque);
// void radix_sort(int *arr, int size);
void radixSort(int* list, int size);
void merge_sort_deque(CircularLinkedQueue *deque);

#endif