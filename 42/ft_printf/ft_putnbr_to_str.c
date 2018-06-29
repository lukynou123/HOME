/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:33:32 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/21 13:31:05 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_to_str(t_struct *f, unsigned long n)
{
//	char *tmp;

	if (n > 4294967295)
		return (0);
	if (!(f->conversion = ft_itoa((int)n)))
		return (0);
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

