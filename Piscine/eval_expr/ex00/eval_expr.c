/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:38:55 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/16 17:13:24 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (nb % 10 <= 9 && nb % 10 >= 0)
		ft_putchar(nb % 10 + 48);
}

int		eval_expr(char *str)
{

	int test;
	int stock;
	int i;
	int plus;

	i = 0;
	test = 0;
	plus = 0;
	while (str[i] != 0)
	{ 

		if (str[i] == ' ')
			i++;
		while (str[i] >= 48 && str[i] <= 57)
		{
			test = test * 10 + str[i] - 48;
			i++;
		}

		if (str[i] == ' ')
			i++;
		if (str[i] == '+')
			test = test + test2;
	}
	stock = test;
//renvoi resultat et putnbr l affiche
	return (stock);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
