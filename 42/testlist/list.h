#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	char *str;
	t_list *next;
};

t_list *add_link(t_list *list, char *str);
void print_list(t_list *list);
void ft_putstr(char *str);

#endif
