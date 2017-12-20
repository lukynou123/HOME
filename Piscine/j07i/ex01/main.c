#include <stdio.h>
#include <stdlib.h>
int *ft_range(int min, int max);

int main()
{
	int *a;
	int i ;

	i = 0;
	a = ft_range(5, 9);
	while(a[i] != '\0')
	{	
		printf("%d, ", a[i]);
		i++;
	}

//	printf("%d", a[1]);
//	printf("%d", a[2]);
//	printf("%d", a[3]);
//	printf("%d", a[4]);
//	printf("%d", a[5]);

//	printf("%d", ft_range(7,9));
	return (0);
}
