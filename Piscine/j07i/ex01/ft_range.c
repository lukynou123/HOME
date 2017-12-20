/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 00:00:36 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/14 00:56:10 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *str;
	int i;

	i = 0;
	str = NULL;
	while (min < max - 1)
	{
		min++;
		i++;
	}
	min = min - i;
	if (min < max)
		str = (int*)malloc(sizeof(*str) * (i + 1));
	else
		return (str);
	i = 0;
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	str[i] = '\0';
	return (str);
}
