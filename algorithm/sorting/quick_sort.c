#include "sorting.h"

// quick sort는 int 값으로 비교하기때문에 size_t 대신 int 사용

static int partition(int *arr, int left, int right)
{
    int low = left + 1;
    int high = right;
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

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot - 1);
        quick_sort(arr, pivot + 1, right);
    }
}