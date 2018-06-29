/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:04:12 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 12:36:18 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion_O(t_struct *f, unsigned long int arg)
{
//	char *tmp;
	if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}

	if (!(f->conversion = ft_itoa_base((int)arg, 8)))
		return (0);
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

int		conversion_u(t_struct *f, unsigned int arg)
{
//	char *tmp;
	if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}

	if (!(f->conversion = ft_itoa_base((int)arg, 10)))
		return (0);
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

int		conversion_U(t_struct *f, unsigned long int arg)
{
//	char *tmp;
	if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}

	if (!(f->conversion = ft_itoa_base((int)arg, 10)))
		return (0);
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

int conversion_x(unsigned int arg, t_struct *f)
{
//	char *tmp;

		if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}

	if (!(f->conversion = ft_majtomin(ft_itoa_base((int)arg, 16))))
		return (0);
	if (f->diez == 1 && arg > 0)
	{
		if (!(f->argdiez = ft_strjoin("0x\0", f->argdiez)))
			return (0);
		f->largeur_champ = f->largeur_champ - 2;
	}
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

int conversion_X(unsigned int arg, t_struct *f)
{
//	char *tmp;
		if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}

	if (!(f->conversion = ft_itoa_base((int)arg, 16)))
		return (0);
	if (f->diez == 1 && arg > 0)
	{
		if (!(f->argdiez = ft_strjoin("0X\0", f->argdiez)))
			return (0);
		f->largeur_champ = f->largeur_champ - 2;
	}
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}
