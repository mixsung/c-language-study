// O(N)

int multiple(int num)
{
	int result = 0;
	while (num >= 0)
	{
		if (num % 3 == 0 || num % 5 == 0)
			result += num;
		num--;
	}
	return (result);
}

#include <stdio.h>
int main(void)
{
	printf("\n%d", multiple(16));
	printf("\n%d", multiple(34567));
	printf("\n%d", multiple(27639));
	return (0);
}
