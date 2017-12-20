/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:03:23 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/19 19:17:26 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab2;

	i = 0;
	tab2 = (int*)malloc(sizeof((*tab) * (length + 1)));
	while (i < length)
	{
		f(tab[i]);
		tab2[i] = tab[i];
		i++;
	}
	return (tab2);
}
