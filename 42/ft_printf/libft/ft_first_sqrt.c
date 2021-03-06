/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_sqrt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:49:02 by lucdubos          #+#    #+#             */
/*   Updated: 2017/12/06 16:11:56 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_first_sqrt(int nb)
{
	int		i;

	i = 0;
	while (i * i != nb)
	{
		i = 0;
		while (i * i != nb && i < 46341)
		{
			i++;
			if (i * i == nb)
				return (i);
		}
		nb++;
	}
	i++;
	return(i);
}
