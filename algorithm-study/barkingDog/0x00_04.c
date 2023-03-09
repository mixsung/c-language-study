#include <stdio.h>

int func4(int n)
{
	int res = 1;
	while (2 * res <= n)
		res = 2 * res;
	return (res);  
}

int main(void)
{
	printf("\n result: %d", func4(1024));
	return (0);
}
