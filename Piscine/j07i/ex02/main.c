#include <stdio.h>
// rechanger prototypage
int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int **a = NULL;
	int i ;
	int c;
	i = 0;

	c = ft_ultimate_range(&a[0], 5, 9);
	while(a[0][i] != '\0')
	{
		printf("%d, ", a[0][0]);
		i++;
	}
	printf("\nvaleur retourne =%d", c);
	return (0);
}
