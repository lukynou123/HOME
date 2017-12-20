/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:35:50 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/14 19:27:02 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	char	*stock;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 1;
	y = 0;
	while (x < argc)
	{
		while (argv[x][y] != '\0')
		{
			i++;
			y++;
		}
		x++;
		y = 0;
	}
	stock = (char*)malloc(sizeof(*stock) * (i + 1));
	i = 0;
	x = 1;
	y = 0;
	while (x < argc)
	{
		while (argv[x][y] != '\0')
		{
			stock[i] = argv[x][y];
			y++;
			i++;
		}
		if (x != argc - 1)
			stock[i] = '\n';
		i++;
		x++;
		y = 0;
	}
	stock[i] = '\0';
	return (stock);
}
