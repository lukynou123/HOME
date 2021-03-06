/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 20:02:21 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/21 11:48:25 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if ((*f)(tab[i]) == 1)
			j++;
		i++;
	}
	return (j);
}
