#include <stdio.h>

int ft_strlen(char str[])
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

int main(void)
{
	char date3[7] = "June 14";
	int size = ft_strlen(date3);

	for (int i = 0; i < size; i++)
	{
		printf("%c", date3[i]);
	}
	printf("\n");
	printf("%s", date3);
	return (0);
}
