/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:03:23 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/21 11:51:35 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(int *tab2)
{
	int i;

	i = 0;
	while (tab2[i] != '\0')
		i++;
	return (i);
}

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab2;

	i = 0;
	tab2 = (int*)malloc(sizeof((*tab2) * (ft_strlen(tab))));
	while (i < length)
	{
		tab2[i] = (*f)(tab[i]);
		i++;
	}
	return (tab2);
}
