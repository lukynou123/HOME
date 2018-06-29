/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:32:58 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 13:21:09 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <errno.h>
//int addn(int nbopd, ...)         /*   nbopd = nombre d'opérandes du add      */
// creation chaine str de ce qu il fqut renvoyer si on ne rencontre pas d erreur

void error_after_modulo(char c)
{
	ft_putstr("error : invalid conversion specifier '");
	ft_putchar(c);
	ft_putstr("' [-Werror, -Wformat-invalid-specifier]\n");
}


char *ft_strjoin_and_free(char *str, char *arg)
{
	char *new_str;

	new_str = ft_strjoin(str, arg);
	free((char*)str);
	return (new_str);
}

int ft_printf(const char *str,...)
{
	int len;
	va_list(ap);
	t_struct f;
	creation_f(&f);


	va_start(ap,str);
//	ft_putstr("ok");
	while(str[f.i])
	{
		if (str[f.i] == '%' && str[f.i + 1] == '%')
		{
			if(!(conversion_mod_mod(&f)))
				return (0);
		}
		if (str[f.i] == '%')
		{
			f.i++;
//			ft_putstr("avant info");
			if(!(info(str, &f)))
				return (0);
			if (!(all_conversion(str, &ap, &f))) // met dans f.conversion
				return(0);
//			ft_putstr(f.conversion);
//		ft_putendl("re");
			if (!(ajout_prec(&f)))
				return (0);
			if (f.espace >= 1)
				ajout_espace(&f);
			if (!(ajout_larg(&f)))
				return (0);
			if (f.plus >= 1)
			{
			if (!(ajout_plus(&f)))
				return (0);
			}
/*			if (f.moins >= 1)
			{
				if (!(ajout_moins(&f)))
					return (0);
			}*/
/*			if (f.zero >= 1)
			{
				if(!(ajout_zero(&f)))
					return (0);
			}*/
			if (f.diez >= 1)
			{
			if(!(ajout_diez(&f)))
				return (0);
			}
			if(!(f.str_with_parameters = ft_strjoin_and_free(f.str_with_parameters, f.conversion))) // met dans la chaine str la conversion
				return (0);

			f.i++;
			reinit_f(&f);
		}
		else // ecrit les caracteres de la chaines de base ""
		{
			stock_str_param_from_str(str, &f);
//			ft_putnbr(f.i);
		}
	}
	
	va_end(ap);
	len = ft_strlen(f.str_with_parameters);
//	ft_putendl("resultat :");
	ft_affichage(&f);
	ft_bzero(f.str_with_parameters, ft_strlen(f.str_with_parameters));
	free(f.str_with_parameters);
//	free(f.conversion);
//	free(f.argdiez);
	return (len);
}

