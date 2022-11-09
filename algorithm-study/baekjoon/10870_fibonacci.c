#include <stdio.h>

/*
https://www.acmicpc.net/problem/10870
*/

int ft_fibonacci(int n)
{
    if (n == 0)
        return (0);
    else if (n == 1)
        return (1);
    else
        return (ft_fibonacci(n - 1) + ft_fibonacci(n - 2));
}

int main(void)
{
    int num;

    num = 0;
    scanf("%d", &num);
    printf("%d", ft_fibonacci(num));
    return (0);
}