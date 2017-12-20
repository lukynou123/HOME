/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 19:30:14 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/14 19:30:15 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
    int *str;
	int i;
	
	*str = NULL;
	i = 0;
	if (min < max)
		str = (int*)malloc(sizeof(*str) * (max - min));
	else
		return (0);
	 if (str = NULL)
		return (0);
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	*range = str;
	return (i);
}
