# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:54:36 by xgilbert          #+#    #+#              #
#    Updated: 2017/11/28 17:32:04 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_atoi.c\
		./ft_bzero.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isascii.c\
		./ft_isdigit.c\
		./ft_isprint.c\
		./ft_isspace.c\
		./ft_itoa.c\
		./ft_memalloc.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memdel.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_putchar.c\
		./ft_putchar_fd.c\
		./ft_putendl.c\
		./ft_putendl_fd.c\
		./ft_putnbr.c\
		./ft_putnbr_fd.c\
		./ft_putstr.c\
		./ft_putstr_fd.c\
		./ft_strcat.c\
		./ft_strchr.c\
		./ft_strclr.c\
		./ft_strcmp.c\
		./ft_strcpy.c\
		./ft_strdel.c\
		./ft_strdup.c\
		./ft_strequ.c\
		./ft_striter.c\
		./ft_striteri.c\
		./ft_strjoin.c\
		./ft_strlcat.c\
		./ft_strlen.c\
		./ft_strmap.c\
		./ft_strmapi.c\
		./ft_strncat.c\
		./ft_strncmp.c\
		./ft_strncpy.c\
		./ft_strnequ.c\
		./ft_strnew.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strsplit.c\
		./ft_strstr.c\
		./ft_strsub.c\
		./ft_strtrim.c\
		./ft_tolower.c\
		./ft_toupper.c\
		./ft_lstadd.c\
		./ft_lstdel.c\
		./ft_lstdelone.c\
		./ft_lstiter.c\
		./ft_lstmap.c\
		./ft_lstnew.c

RM = rm -f

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
