/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:34:35 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/20 17:20:13 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		false_arg(int argc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 4)
	{
		ft_putchar('0');
		return (0);
	}
	return (1);
}

int		op2(char op, int tmp, int tmp2)
{
	if (op == '/')
	{
		if (tmp2 == 0)
		{
			ft_putstr("Stop : divison by zero\n");
			return (5);
		}
		ft_putnbr(tmp / tmp2);
		return (3);
	}
	if (op == '%')
	{
		if (tmp2 == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (5);
		}
		ft_putnbr(tmp % tmp2);
		return (4);
	}
	return (5);
}

int		operateur(char op, int tmp, int tmp2)
{
	if (op == '*')
	{
		ft_putnbr(tmp * tmp2);
		return (0);
	}
	if (op == '+')
	{
		ft_putnbr(tmp + tmp2);
		return (1);
	}
	if (op == '-')
	{
		ft_putnbr(tmp - tmp2);
		return (2);
	}
	op2(op, tmp, tmp2);
	return (5);
}

int		main(int argc, char **argv)
{
	int (*f[5])(int(char, int, int));
	int tmp;
	int tmp2;

	if (false_arg(argc) == 0)
		return (0);
	tmp = ft_atoi(argv[1]);
	tmp2 = ft_atoi(argv[3]);
	if (f[operateur(argv[2][0], tmp, tmp2)])
		return (0);
	return (0);
}
