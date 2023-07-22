#include "sorting.h"

static size_t partition(int *arr, size_t left, size_t right)
{
    size_t low = left + 1;
    size_t high = right;
    int    pivot = arr[left];

    while (low < high)
    {
        while (low <= right && arr[low] < pivot)
            low++;
        while (high >= left && arr[high] > pivot)
            high--;
        if (low < high)
            swap(&arr[low], &arr[high]);
    }
    swap(&arr[left], &arr[high]);
    return (high);
}

void quick_sort(int *arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}