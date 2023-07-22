#include "sorting.h"

void insertion_sort(int *arr, size_t size)
{
    size_t i = 1;
    int j = 0;
    int key;

    while (i < size)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;   // while문을 빠져나오고 해당 위치 +1 해서 적절한 삽입 위치에 key 삽입
        display(arr, size);
        i++;
    }
    printf("\n-- sorting done -- \n");
}

