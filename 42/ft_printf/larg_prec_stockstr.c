/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_prec_stockstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:19:40 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 13:20:22 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void        taille_larg_pre_champ(t_struct *f,const char *str)
{
    if(str[f->i - 1] == '.')
    {
        while ((str[f->i] >= '0' && str[f->i] <= '9') && str[f->i] != '\0')
        {
            f->precision_champ = (f->precision_champ * 10) + (str[f->i] - 48);
            f->i++;
        }
    }
    else
    {
        while ((str[f->i] >= '0' && str[f->i] <= '9') && str[f->i] != '\0')
        {
            f->largeur_champ = (f->largeur_champ * 10) + (str[f->i] - 48);
            f->i++;
        }
    }
    f->i--;
}


int ajout_prec(t_struct *f)
{
    char *tmp;
    int i;
    int j;
    j = 0;
    i = f->precision_champ - ft_strlen(f->conversion);
    
    if (i > 0)
    {
        tmp = (char*)malloc(sizeof(char*) * (i + 2));
        if(ft_atoi(f->conversion) < 0)
        {
            tmp[j++] = '-';
            i++;
            f->conversion[0] = '0';
        }
		if (f->diez >= 1 && (f->moins == 0 && f->largeur_champ > f->precision_champ))
		{
			i--;
//			ft_putendl("merde je passe");
		}
//		ft_putnbr(f->diez);
//		ft_putnbr(f->largeur_champ);
//		ft_putnbr(f->precision_champ);
        while (i > j)
        {
            tmp[j] = '0';
            j++;
        }
        tmp[j] = '\0';
        //        if (atoi(f->conversion) < 0)
        
        if (!(f->conversion = ft_strjoin_and_free(tmp,f->conversion)))
            return (0);
    }
    return (1);
}

int        ajout_larg(t_struct *f)
{
    char *tmp;
    int i;
    int j;
    int flag;
    flag = 0;
    j = 0;
    i = f->largeur_champ - ft_strlen(f->conversion);
    if (i > 0)
    {
        tmp = (char*)malloc(sizeof(char*) * (i + 1));
        while (i > j)
        {
            if (f->zero >= 1)
            {
                if (ft_atoi(f->conversion) < 0 && flag == 0)
                {
                    tmp[j++] = '-';
                    //    ft_putstr("je passe\n");
                    f->conversion[0] = '0';
                    flag = 1;
                }
                if (i > j)
                    tmp[j] = '0';
            }
            else
                tmp[j] = ' ';
            j++;
        }
        tmp[j] = '\0';
        if (f->moins >= 1)
        {
            if (!(f->conversion = ft_strjoin_and_free(f->conversion,tmp)))
                return (0);
        }
        else
        {
            if (!(f->conversion = ft_strjoin_and_free(tmp,f->conversion)))
                return (0);
        }
    }
    return (1);
}

int stock_str_param_from_str(const char *str, t_struct *f)
{
    int j;
    int k;
    char *to_join;
    
    j = 0;
    k = f->i;
    while (str[f->i] != '%' && str[f->i] != '\0')
    {
        j++;
        f->i++;
    }
    if(!(to_join = (char*)malloc(sizeof(char*) * (j + 1))))
        return(0);
    j = 0;
    while(k < f->i)
    {
        to_join[j++] = str[k++];
    }
    to_join[j] = '\0';
    f->str_with_parameters = ft_strjoin_and_free(f->str_with_parameters, to_join);
    ft_bzero(to_join, ft_strlen(to_join));
    free(to_join);
    return (1);
}
