#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <ctype.h>

int     main(void)
{
    char c[20] = "SWAG";
   char d[20] = "OK";
    char *a = "plop";
	  char b;
	  char **strsplit;
	  int i;
    //char e[20] = "test2";
    //char f[20] = "test5";
    //char g[20] = "tes";
    //char h[20] = "KO";
    a = 0;
    b = 0;
	i = 0;

	ft_putstr(ft_strrchr("salut, pck cest ltropbiencamarche", 'l'));
	ft_putchar('\n');
	strsplit = ft_strsplit("****salut***les***etudiants**quiont*bcp trop*de***swag**et ** meme*la/chaine super*longue fonctionne*au*top!!!!!!!!*", '*');
	while (strsplit[i] != 0)
	{
		ft_putstr(strsplit[i]);
		ft_putchar('\n');
		i++;
	}

	ft_putchar('\n');
	ft_putstr(ft_itoa(0));
	ft_putchar('\n');
	ft_putstr(ft_itoa(-0));
	ft_putchar('\n');

	ft_putstr(ft_strjoin(c, d));
	ft_putchar('\n');
	ft_putendl(c);
    ft_putstr(memcpy(memset(ft_memalloc(1),48,1),memset(ft_memalloc(1),49,1),1));
    ft_putstr(" = ");
    ft_putstr(ft_memcpy(ft_memset(ft_memalloc(1),48,1),memset(ft_memalloc(1),49,1),1));
	ft_putchar('\n');

    ft_putstr(memset(ft_memalloc(1),79,1));
    ft_putstr(memset(ft_memalloc(1),75,1));
    ft_putstr(" = ");
    ft_putstr(ft_memset(ft_memalloc(1),79,1));
    ft_putstr(ft_memset(ft_memalloc(1),75,1));
    ft_putchar('\n');

    ft_putchar('a');
    ft_putchar('=');
    ft_putchar('a');
    ft_putchar('\n');
    ft_putnbr(123);
    ft_putstr(" = ");
    ft_putnbr(123);
    ft_putchar('\n');

    ft_putstr(strcpy(c, d));
    ft_putstr(" = ");
    ft_putstr(ft_strcpy(c, d));
    ft_putchar('\n');

    ft_putstr(strncpy(c, d, 3));
    ft_putstr(" = ");
    ft_putstr(ft_strncpy(c, d, 3));

}
