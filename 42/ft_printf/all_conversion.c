/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:03:14 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 13:45:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			all_conversion(const char *str, va_list *ap, t_struct *f)
{
//	intmax_t		i;
/*	if (*ap == NULL)
	{
		ft_putendl("NULLL");
		return (0);
	}
*/   // trouvez sisteme pour si plus d argument !!
/*	if (f->point >= 1 && f->diez == 0 && ( str[f->i] == 'i' ||
				str[f->i] == 'o' || str[f->i] == 'D' || str[f->i] == 'O' || str[f->i] == 'U' 
				|| str[f->i] == 'X' || str[f->i] == 'x'))
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 1)))
			return (0);
		f->conversion[0] = '\0';
		return(1);
	}*/
//		if (!(conversion_1point(f, va_arg(*ap, intmax_t)

	if (str[f->i] == 's')
	{
		if(!(conversion_s(f, va_arg(*ap, char*))))
			return (0);
	}
	else if (str[f->i] == '%')
	{
		if (!(f->conversion = (char*)malloc(sizeof(char*) * 2)))
			return (0);
		f->conversion[0] = '%';
		f->conversion[1] = '\0';
//		return (1);
	}
	else if (str[f->i] == 'd' || str[f->i] == 'i')
	{
//		i = va_arg(*ap, intmax_t);
		if(!(conversion_d(f, va_arg(*ap, intmax_t))))
			return(0);
	}
	else if (str[f->i] == 'S')
	{
		if(!(conversion_S(f, va_arg(*ap, wchar_t*))))
			return (0); //free
	}
	else if (str[f->i] == 'l' && str[f->i + 1] == 'c')
	{
		if (!(conversion_C(f, va_arg(*ap, wchar_t))))
			return (0); // free
		f->i++;
	}
	else if (str[f->i] == 'C')
	{
		if (!(conversion_C(f, va_arg(*ap, wchar_t))))
			return (0); // free
	}
	else if (str[f->i] == 'p')
	{
		if (!(conversion_p(f, va_arg(*ap, void*))))
			return (0); // free
	}
	else if (str[f->i] == 'l' && str[f->i + 1] == 'd')
	{
		if (!(conversion_D(f, va_arg(*ap, long int))))
			return (0); // free
	}
	else if (str[f->i] == 'D')
	{
		if (!(conversion_D(f, va_arg(*ap, long int))))
			return (0); // free
	}
	else if (str[f->i] == 'o')
	{
		if (!(conversion_o(va_arg(*ap, unsigned int), f)))
			return (0); // free
	}
	else if (str[f->i] == 'O')
	{
		if (!(conversion_O(f, va_arg(*ap, unsigned long int))))
			return (0); // free
	}
	else if (str[f->i] == 'u')
	{
		if (!(conversion_u(f, va_arg(*ap, unsigned int))))
			return (0); // free
	}
	else if (str[f->i] == 'U')
	{
		if (!(conversion_U(f, va_arg(*ap, unsigned long int))))
			return (0); // free
	}
	else if (str[f->i] == 'x')
	{
		if (!(conversion_x(va_arg(*ap, unsigned int), f)))
			return (0); // free
	}
	else if (str[f->i] == 'X')
	{
		if (!(conversion_X(va_arg(*ap, unsigned int), f)))
			return (0); // free
	}
	else if (str[f->i] == 'c')
	{
		if (!(conversion_c(f, va_arg(*ap, int))))
			return (0);
	}
	else
	{
		free(f->str_with_parameters);
		error_after_modulo(str[f->i]);
		return(0);
	}
	return (1);
}
