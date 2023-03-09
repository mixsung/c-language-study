int func3(int n)
{
	int i = 1;
	while (i <= n / i)
	{
		if (i * i == n)
			return (1);
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(void)
{
	printf("\n%d", func3(9));
	printf("\n%d", func3(693953651));
	printf("\n%d", func3(756580036));
	return (0);
}
