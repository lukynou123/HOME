/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_tetri_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:20:44 by xgilbert          #+#    #+#             */
/*   Updated: 2017/12/18 17:58:58 by xgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

static int		double_conditions(char *str, int k)
{
	if (str[k] == '\n' && str[k - 1] == '\n')
	{
		k++;
		str[k++] = '\n';
		str[k++] = '\n';
		str[k] = '\n';
	}
	if (str[k] == '\0')
	{
		k++;
		str[k] = '\0';
		k++;
		str[k] = '\0';
		k++;
		str[k] = '\0';
	}
	return (k);
}

char			*str_pour_diese_solo(char *str1)
{
	int		k;
	int		i;
	char	*str;

	k = 0;
	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * 650)))
		return (0);
	while (str1[i])
	{
		while (k <= 4)
		{
			str[k] = '\n';
			k++;
		}
		str[k] = str1[i];
		k = double_conditions(str, k);
		k++;
		i++;
	}
	return (str);
}

char			*liste_tetri_to_str(char *liste_tetri)
{
	int		k;
	char	buffer[1];
	int		filein;
	int		nbread;
	char	*str;

	k = 0;
	filein = open((liste_tetri), O_RDONLY);
	nbread = read(filein, buffer, 1);
	if (!(str = (char*)malloc(sizeof(*str) * 650)))
		return (0);
	while (nbread > 0)
	{
		str[k] = buffer[0];
		nbread = read(filein, buffer, 1);
		if (k > 650)
			return (0);
		k++;
	}
	str[k++] = '\n';
	str[k] = '\0';
	close(filein);
	return (str);
}
