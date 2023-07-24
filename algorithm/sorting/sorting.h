#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>

void display(int *arr, size_t size);
void swap(int *a, int *b);
void selection_sort(int *arr, size_t size);
void insertion_sort(int *arr, size_t size);
void insertion_sort2(int *arr, size_t size);
void bubble_sort(int *arr, size_t size);
void quick_sort(int *arr, int left, int right);
void quick_sort2(int *arr, int left, int right);

#endif