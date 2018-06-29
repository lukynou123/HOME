/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:57:50 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 12:34:25 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conversion_mod_mod(t_struct *f)
{
//	char *tmp;

	if (!(f->conversion = (char*)malloc(sizeof(char*) * 2)))
		return (0);
	f->conversion[0] = '%';
	f->conversion[1] = '\0';
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	f->conversion = f->conversion + 2;
	return (1);
}
int conversion_s(t_struct *f, char *arg)
{
	if(!(f->conversion = ft_strjoin("", arg)))
		return (0);
	return (1);
}
int conversion_c(t_struct *f, int arg)
{
//	char *tmp;
	if (arg == '\0')
	{
		f->jtab++;
		f->tab[f->jtab] = ft_strlen(f->str_with_parameters);
		f->largeur_champ--;
		f->precision_champ--;
	}
	
	
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 2)))
		return (0);
		f->conversion[0] = arg;
		f->conversion[1] = '\0';
	
	//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
	return (1);
}

int	conversion_d(t_struct *f, intmax_t arg)
{
//	char *tmp;
//	ft_putnbr(arg);
//	if (arg > 2147483647 || arg < -2147483648)
/*	ft_putstr("min:");
	ft_putnbr(INT_MIN);
	ft_putstr("max:");
	ft_putnbr(INT_MAX);
	ft_putnbr(arg);
	intmax_t a;
	intmax_t b;

	a = INT_MAX;
	b = INT_MIN;
	a = 100;
	b = -100;
	b = -42;
*/
	//	if (arg >= a )//&& arg >= b)
//	{
//		ft_putstr("j rentre ici");
	if (arg == 0 && f->point >= 1 && f->diez == 0 && f->precision_champ == 0)
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return (1);
	}
	if(!(f->conversion = ft_itoa(arg)))
		return (0);
//	}
/*	else
	{
		ft_putendl("error : format specifies type 'int' but the argument has type 'long' [-Wformat]");
		return (0);
	}*/
//	if (!(*str = ft_strjoin_and_free(*str, tmp)))
//		return (0);
//	ft_bzero(tmp, ft_strlen(tmp));
//	free(tmp);
	return (1);
}
