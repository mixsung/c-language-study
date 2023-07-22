#include <unistd.h>

void print_c(int *arr, int n)
{
    char tmp;
    int i = 0;
    while (i < n)
    {
        tmp = arr[i] +'0';
        write(1, &tmp, 1);
        i++;
    }
}

void combn_cal(int *arr, int n)
{
        print_c(arr, n);
        if (arr[0] == 9 - n + 1)
            return ;
        write(1, ", ", 2);
        int i = n - 1;
        while (arr[i] == 9 - (n - i) + 1)
            i--;
        arr[i]++;
        i++;
        while (i < n)
        {
            arr[i] = arr[i - 1] + 1;
            i++;
        }
        combn_cal(arr, n);
}

void combn(int n)
{
    int arr[9];

    arr[0] = 0;

    int i = 1;
    while (i < n)
    {
        arr[i] = arr[i - 1] + 1;
        i++;
    }
    combn_cal(arr, n);
    write(1, "\n", 1);
}

int main(void)
{
    combn(9);
    return (0);
}