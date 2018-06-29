/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusdiezmoinsesp0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:06:02 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 13:26:39 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ajout_plus(t_struct *f)
{
    char *tmp;
    char *tmp2;
    int j;
    int i;
    
    i = -1;
    j = 0;
/*	ft_putstr("conversion :");
	ft_putstr(f->conversion);
	ft_putchar('\n');*/
    if (!(tmp = (char*)malloc(sizeof(char*) * (ft_strlen(f->conversion) + 1))))
        return (0);
    if (!(tmp2 = (char*)malloc(sizeof(char*) * (ft_strlen(f->conversion) + 1))))
        return (0);
    while (f->conversion[++i] == ' ')
        tmp[i] = f->conversion[i];
    tmp[i] = '+';
    tmp[i + 1] = '\0';
    while(f->conversion[i])
        tmp2[j++] = f->conversion[i++];
    tmp2[j] = '\0';
/*		ft_putstr("les espaces et + :");
	ft_putstr(tmp);
	ft_putchar('\n');
	ft_putstr("reste conv:");
	ft_putstr(tmp2);
	ft_putchar('\n');*/

    if (!(f->conversion = ft_strjoin_and_free(tmp,tmp2)))
        return (0);
    free(tmp2);
/*	ft_putstr("apres mis + conversion :");
	ft_putstr(f->conversion);
	ft_putchar('\n');*/

    return (1);
}

int        ajout_espace(t_struct *f)
{
    if(ft_atoi(f->conversion) >= 0)
    {
        if (!(f->conversion = ft_strjoin(" ",f->conversion)))
            return (0);
    }
    return (1);
}

int ajout_diez(t_struct *f) // ajoute diez
{
    char *tmp;
    char *tmp2;
    int j;
    int i;
    
    i = -1;
    j = 0;
 /*  ft_putstr(":");
   ft_putstr(f->conversion);
   ft_putchar('\n');*/
    if (!(tmp = (char*)malloc(sizeof(char*) * (ft_strlen(f->conversion) + 1))))
        return (0);
    if (!(tmp2 = (char*)malloc(sizeof(char*) * (ft_strlen(f->conversion) + 1))))
        return (0);
    while (f->conversion[++i] == ' ')
        tmp[i] = f->conversion[i];
//	tmp[i] = ' ';
	tmp[i] = '\0';
    if (!(tmp = ft_strjoin_and_free(tmp,f->argdiez)))
        return (0);
    free(f->argdiez);
    while(f->conversion[i])
        tmp2[j++] = f->conversion[i++];
    tmp2[j] = '\0';
    if (!(f->conversion = ft_strjoin_and_free(tmp,tmp2)))
        return (0);
    free(tmp2);
    return (1);
}

int ajout_zero(t_struct *f)
{
    return (1);
}

int ajout_moins(t_struct *f)
{
	return (1);
}
