/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:18:28 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/19 20:00:18 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_any(char **tab, int(*f)(char*))
{
	int i;
	int j;
//	int **tab2;
	char*  tmp;
	i = 0;
	j = 0;
	
	while (tab[j] != '\0')
	{
		while (tab[j][i] != '\0')
		{
			*tmp = tab[j][i];
			if ((f(tmp) == 1))
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}