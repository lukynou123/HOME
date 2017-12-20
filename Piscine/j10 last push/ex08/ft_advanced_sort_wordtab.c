/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:53:26 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/21 01:43:37 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j + 1] != 0)
	{
		if (cmp(tab[j], tab[j + 1]) < 0)
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
