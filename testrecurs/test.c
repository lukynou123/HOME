#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void recurs(int i, int j)
{
//	int i;
//	int j;

//recurs(i,j);
	if(i < 5)
		recurs((i + 1), j);
	if(i < 4)
	{
	ft_putchar(i + 48);
	ft_putchar(j + 48);
	}
}

int main()
{
int i;
int j;

i = 0;
j = 1;
recurs(i, j);
return (0);
}
