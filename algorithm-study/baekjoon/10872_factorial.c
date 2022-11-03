#include <stdio.h>

/*
https://www.acmicpc.net/problem/10872
*/

int ft_factorial(int n)
{
    if (n > 1)
        return (n * ft_factorial(n - 1));
    return (1);   
}

int main(void)
{
    int num;
    num = 0;
    
    scanf("%d", &num);
    printf("%d", ft_factorial(num));
    return (0);
}