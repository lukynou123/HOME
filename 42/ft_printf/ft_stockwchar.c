/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stockwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 14:26:37 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/21 13:29:28 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		taille_j_stockwchar(int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc <= 2047)
		return (2);
	else if (wc <= 65535)
		return (3);
	else if (wc <= 1114111)
		return (4);
	else
		return (0);
}

int		ft_stockwchar(wchar_t wc, t_struct *f)
{
//	char *tmp;
	int j;

	if (!(j = taille_j_stockwchar(wc)))
		return (0);
	if (!(f->conversion = (char *)malloc(sizeof(char*) * (j))))
		return (0);
	f->conversion[j] = '\0';
	if (wc <= 127)
		f->conversion[0] = wc;
	else if (wc <= 2047)
	{
		f->conversion[0] = ((wc >> 6) + 0xC0);
		f->conversion[1] = ((wc & 0x3F) + 0x80);
	}
	else if (wc <= 65535)
	{
		f->conversion[0] = ((wc >> 12) + 0xE0);
		f->conversion[1] = (((wc >> 6) & 0x3F) + 0x80);
		f->conversion[2] = ((wc & 0x3F) + 0x80);
	}
	else if (wc <= 1114111)
	{
		f->conversion[0] = ((wc >> 18) + 0xF0);
		f->conversion[1] = (((wc >> 12) & 0x3F) + 0x80);
		f->conversion[2] = (((wc >> 6) & 0x3F) + 0x80);
		f->conversion[3] = ((wc & 0x3F) + 0x80);
	}
//		if (!(*str = ft_strjoin_and_free(*str, tmp)))
//			return (0);
//		ft_bzero(tmp, ft_strlen(tmp));
//		free(tmp);
	return (1);
}

/* VV A SUPPRIMER SI PAS UTILE VV */
void    ft_putwchar(wchar_t wc)
{
	if (wc <= 127)
		ft_putchar(wc);
	else if (wc <= 2047)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 65535)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 1114111)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}
