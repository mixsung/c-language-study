#include "sorting.h"

// quick sort는 int 값으로 비교하기때문에 size_t 대신 int 사용

static int partition(int *arr, int left, int right)
{
	int first = left;
	int pivot = arr[first];

	++left;
	while (left <= right)
	{
		while (arr[left] <= pivot && left < right)
			++left;
		while (arr[right] >= pivot && left <= right)
			--right;
		if (left < right)
			swap(&arr[left], &arr[right]);
		else
			break;
	}
	swap(&arr[first], &arr[right]);
	return (right);
}

void quick_sort2(int *arr, int left, int right)
{
	int pivot = 0;

	if (left < right)
	{
		pivot = partition(arr, left, right); 
		quick_sort2(arr, left, pivot - 1); // 왼쪽 부분집합 정렬
		quick_sort2(arr, pivot + 1, right); // 오른쪽 부분집합 정렬
	}
}