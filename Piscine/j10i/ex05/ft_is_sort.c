/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:56:07 by lucdubos          #+#    #+#             */
/*   Updated: 2017/09/20 13:53:43 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
//	int j;
//	int k;
	int tmp;

	i = 0;
	while (tab[i] < tab[i + 1] && tab[i] != '\0')
	{
//		j = tab[i];
//		k = tab[i + 1];
		f(tab[i], tab[i + 1]);
		i++;
	}
	if (tab[i] == '\0')
		return (1);
	return (0);
}
