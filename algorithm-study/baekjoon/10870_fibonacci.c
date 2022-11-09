#include <stdio.h>

/*
https://www.acmicpc.net/problem/10870
*/

int ft_fibonacci(int n)
{
    int i;
    int array[n];

    array[0] = 0;
    array[1] = 1;

    i = 0;
    while (i < n - 1)
    {
        array[i + 2] = array[i] + array[i + 1];
        i++;
    }
    return (array[i + 1]);
}

int main(void)
{
    int num;

    num = 0;
    scanf("%d", &num);
    if (num >= 2)
        printf("%d", ft_fibonacci(num));
    else if (num == 1)
        printf("%d", 1);
    else if (num == 0)
        printf("%d", 0);

    return (0);
}