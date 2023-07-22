#include <stdio.h>

int count_space(const char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
		
}

int main(void)
{
	char str[] = "my space is one";
	printf("%d", count_space(str));
	return (0);
}
