#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_strdup(char *src);

int main()
{
	char *a;
	a = "je me comprend";

	printf("%s", ft_strdup(a));
//	printf("%s", strdup(a));
	return (0);
}
