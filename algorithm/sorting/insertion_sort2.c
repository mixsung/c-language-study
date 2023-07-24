#include "sorting.h"
#include <string.h>

/* 책 버전 */
/*
Before memmove: arr = {4, 7, 2, 1, 6}
                          j  i

After memmove:  arr = {4, 7, 7, 1, 6}
*/

void insertion_sort2(int *arr, size_t size)
{
    size_t  i;
    size_t  j;
    int     value = 0;

    i = 1;
    while (i < size)
    {
        if (arr[i - 1] <= arr[i])
            i++;
        else
        {
            value = arr[i];
            j = 0;
            while (j < i)
            {
                if (arr[j] > value)
                {
                    memmove(&arr[j + 1], &arr[j], sizeof(arr[0]) * (i - j));
                    arr[j] = value;
                    break;
                }
                j++;
            }
            display_arr(arr, size);
            i++;
        }
    }
    printf("\n-- sorting done -- \n");
}

/*
=== Sorting using insertion sort2 ===
2 5 4 6 1 3 
2 4 5 6 1 3 
1 2 4 5 6 3 
1 2 3 4 5 6 

-- sorting done -- 
1 2 3 4 5 6 

버블정렬은 자료구조가 정렬되어있어도 계속 비교하고 스왑하는 반면
삽입정렬은 자료구조가 정렬되어있으면 비교를 하지 않고 다음 자료구조로 넘어간다.
*/