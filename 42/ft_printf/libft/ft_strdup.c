/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:47:10 by lucdubos          #+#    #+#             */
/*   Updated: 2017/11/13 18:09:54 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *cpy;

	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (0);
	ft_strcpy(cpy, s1);
	return (cpy);
}
