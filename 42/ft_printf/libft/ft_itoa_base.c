#include "libft.h"

char *ft_itoa_base(int value, int base)
{
	int i;
	int stock;
	char *str;
	int neg;

	if (value == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	i = 0;
	neg = 0;
	if (value < 0 && base == 10)
	{
		neg = 1;
		value *= -1;
	}
	if (value < 0 && base != 10)
		value *= -1;
	stock = value;
	while (stock >= 1)
	{
		stock /= base;
		i++;
	}
	i = i + neg;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	if (neg == 1)
		str[0] = '-';
	i--;
	while (i >= neg)
	{
		if (value % base > 9)
			str[i] = value % base + 'A' - 10;
		else
			str[i] = value % base + '0';
		value /= base;
		i--;
	}
	return (str);
}

