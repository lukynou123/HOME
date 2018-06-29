/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:31:21 by lucdubos          #+#    #+#             */
/*   Updated: 2018/06/29 10:32:55 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# 
typedef struct t_struct
{
	int zero;
	int espace;
	int point;
	int moins;
	int diez;
	int plus;
	int largeur_champ; //taille complet du champs
	int precision_champ; //rajout de 0 avant le nombre
	int i;
	char *str_with_parameters;
	char *conversion;
	int *tab;
	int jtab;
	char *argdiez;

}					t_struct;

int			ft_printf(const char *str, ...);
char		*ft_strjoin_and_free(char *str, char *arg);
void		error_after_modulo(char c);
int			stock_str_param_from_str(const char *str, t_struct *f);
int			ft_stockwchar(wchar_t wc, t_struct *f);
int			conversion_C(t_struct *f, wchar_t arg);
int			conversion_S(t_struct *f, wchar_t *arg);
void		ft_putwchar(wchar_t wc);
int			conversion_p(t_struct *f, void *arg);
int			conversion_D(t_struct *f, unsigned long D);
int			ft_putnbr_to_str(t_struct *f, unsigned long n);
int			conversion_o(unsigned int arg, t_struct *f);
int			conversion_O(t_struct *f, unsigned long int arg);
int			conversion_u(t_struct *f, unsigned int arg);
int			conversion_U(t_struct *f, unsigned long int arg);
int			conversion_x(unsigned int arg, t_struct *f);
int			conversion_X(unsigned int arg, t_struct *f);
int			conversion_c(t_struct *f, int arg);
int			conversion_d(t_struct *f, long int arg);
int			all_conversion(const char *str, va_list *ap, t_struct *f);
int			conversion_s(t_struct *f, char *arg);
int			conversion_mod_mod(t_struct *f);
int			ajout_diez(t_struct *f);
int			ajout_moins(t_struct *f);
int			ajout_plus(t_struct *f);
int			ajout_espace(t_struct *f);
int			ajout_zero(t_struct *f);
int			creation_f(t_struct *f);
void		reinit_f(t_struct *f);
int			info(const char *str, t_struct *f);
void		ft_affichage(t_struct *f);
int			letter(char c);
void		taille_larg_pre_champ(t_struct *f, const char *str);
int			ajout_prec(t_struct *f);
int			ajout_larg(t_struct *f);



/*
 * Largeur de champs
 */

int			largeur_de_champs(char **str_with_parameters, const char *str, int *i, va_list *ap);

#endif
