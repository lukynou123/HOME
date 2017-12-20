/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:10:34 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/20 22:39:04 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(char *str)
{
	int stock;
	int i;
	int neg;

	neg = 1;
	i = 0;
	stock = 0;
	while ((str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f'
			|| str[i] == ' ') && str[i] != '\b')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		stock = stock * 10 + (str[i] - 48);
		i++;
	}
	stock = stock * neg;
	return (stock);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
	}
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb % 10 <= 9 && nb % 10 >= 0)
		ft_putchar(nb % 10 + 48);
}
