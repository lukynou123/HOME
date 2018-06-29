/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creainfofaffichageletter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 10:15:02 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 13:43:18 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int creation_f(t_struct *f)
{
    f->zero = 0;
    f->espace = 0;
    f->point = 0;
    f->moins = 0;
    f->diez = 0;
    f->plus = 0;
    f->largeur_champ = 0;
    f->precision_champ = 0;
    f->i = 0;
    if(!(f->str_with_parameters = (char*)malloc(sizeof(char*) * 1)))
    {
        ft_putstr("error malloc base");
        return(0);
    }
    if (!(f->tab = (int*)malloc(sizeof(int*) * 1000))) // ceci est un malloc degueulasse)
    {
        ft_putstr("error malloc int tab");
        return (0);
    }
    f->jtab = -1;
    if(!(f->argdiez = (char*)malloc(sizeof(char*) * 1)))
    {
        ft_putstr("error malloc base");
        return(0);
    }
    return(1);
}
    
    void reinit_f(t_struct *f)
    {
        f->zero = 0;
        f->espace = 0;
        f->point = 0;
        f->moins = 0;
        f->diez = 0;
        f->plus = 0;
        f->precision_champ = 0;
        f->largeur_champ = 0;
        ft_bzero(f->conversion,ft_strlen(f->conversion));
        free(f->conversion);
    }
    
    
int info(const char *str, t_struct *f)
{
    int flag;
    
    flag = 0;
    //    ft_putchar(str[f->i]);
    while (str[f->i] != '\0' && letter(str[f->i]) != 1)
    {
        if (str[f->i] >= '1' && str[f->i] <= '9')
            flag = 1;
        if (str[f->i] == '#')
            f->diez = 1;
        if (str[f->i] == '0' && flag == 0)
            f->zero++;
        if (str[f->i] == '-')
            f->moins++;
        if (str[f->i] == '+')
            f->plus = 1;
        if (str[f->i] == ' ')
            f->espace = 1;
        if (str[f->i] == '.')
            f->point++;
        if (str[f->i] >= '0' && str[f->i] <= '9')
            taille_larg_pre_champ(f,str);
        f->i++;
    }
    if (f->plus >= 1 && f->espace >= 1)
        return (0);
    if (f->diez >= 1 && str[f->i] != 'x' && str[f->i] != 'o' && str[f->i] != 'X')
        return (0);
    if (str[f->i] == '\0' || f->point > 1)
        return (0);
    if (f->zero >= 1 && f->point >= 1) // pas sur mais le 0 de la largeur est ecraser qd y a un point ???
        f->zero = 0;
    if (f->plus >= 1)
        f->largeur_champ--;
    /*    ft_putstr("precision :");
     ft_putnbr(f->precision_champ);
     ft_putendl("");
     ft_putstr("largeur :");
     ft_putnbr(f->largeur_champ);
     ft_putendl("");*/
    return (1);
}

void ft_affichage(t_struct *f)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (f->str_with_parameters[i] != '\0' || j <= f->jtab)
    {
        if (i == f->tab[j] && j <= f->jtab)
        {
            ft_putchar('\0');
            j++;
        }
        else
        {
            ft_putchar(f->str_with_parameters[i]);
            i++;
        }
    }
}

int letter(char c)
{
    if (c == 'S' || c == 's' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
        c == 'c' || c == 'C' || c == 'l' || c == '%')
        return (1);
    else
        return (0);
} 
