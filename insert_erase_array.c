#include <stdio.h>

void insert(int idx, int num, int arr[], int *len)
{
    *len += 1; // 배열 뒷쪽부터 작업하기 위해 미리 늘리기
    
    int size = *len;
    int i = size - 1;
    while (i > idx)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[idx] = num;
}

void erase(int idx, int arr[], int *len)
{
    *len -= 1;
    
    int size = *len;
    int i = idx;
    while (i < size)
    {
        arr[i] = arr[i + 1];
        i++;
    }
}

void printArr(int arr[], int *len)
{
    int size = *len;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int size = 7;
    int arr[size];
    int i = 0;
    while (i < size)
    {
        arr[i] = i;
        i++;
    }
    printArr(arr, &size);

    insert(4, 10, arr, &size);
    printf("\n after insert \n");
    printArr(arr, &size);

    erase(4, arr, &size);
    printf("\n after erase \n");
    printArr(arr, &size);
    return (0);
}