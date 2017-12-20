/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:19:00 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/21 01:43:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int stock;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (s1[i] == s2[i])
	{
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
	}
	stock = (s1[i] - s2[i]);
	return (stock);
}

void	ft_sort_wordtab(char **tab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j + 1] != 0)
	{
		if (ft_strcmp(tab[j], tab[j + 1]) < 0)
		{
			tmp = tab[j + 1];
			tab[j + 1] = tab[j];
			tab[j] = tmp;
			j = 0;
		}
		else
			j++;
	}
}
