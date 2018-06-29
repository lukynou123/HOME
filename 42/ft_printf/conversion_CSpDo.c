/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:04:12 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 12:35:23 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_C(t_struct *f, wchar_t arg)
{
	if(!(ft_stockwchar(arg, f)))
		return (0);
	return (1);
}

int	conversion_S(t_struct *f, wchar_t *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if(!(conversion_C(f, arg[i])))
			return (0);
		i++;
	}
	return (1);
}

int	conversion_p(t_struct *f, void *arg)
{
//	char *tmp;

	if (!(f->conversion = (char*)malloc(sizeof(char*) * 50)))
		return (0);
	ft_bzero(f->conversion, 50);
	f->conversion[0] = '0';
	f->conversion[1] = 'x';
	if (!(f->conversion = ft_strjoin_and_free(f->conversion, ft_majtomin(ft_itoa_base((int)arg, 16)))))
		return (0);
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);

}

int		conversion_D(t_struct *f, unsigned long arg)
{
	if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}
	if (!(ft_putnbr_to_str(f, arg)))
		return (0);
	return (1);
}

int		conversion_o(unsigned int arg, t_struct *f)
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
	if (f->diez == 1 && arg > 0)
	{
		if (!(f->argdiez = ft_strjoin("0\0", f->argdiez)))
			return (0);
	f->largeur_champ--;
	}
/*	if (!(*str = ft_strjoin_and_free(*str, tmp)))
		return (0);*/
	return (1);
}
