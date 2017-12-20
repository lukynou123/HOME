#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 11:08:14 by lucdubos          #+#    #+#              #
#    Updated: 2017/09/20 17:24:05 by lucdubos         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = do-op

SRC =	main.c\
		ft_tools.c

OBJ =	$(SRC:.c=.o)

all:	$(OBJ) $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -o $(NAME) $(SRC) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all