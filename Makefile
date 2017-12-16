# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgricour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:10:43 by kgricour          #+#    #+#              #
#    Updated: 2017/12/14 20:32:04 by kgricour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = backtrack.c ft_check_all.c ft_check_write.c ft_diese_to_alpha.c ft_tab_tetri.c main.c
LIB = ./libft
LIB_A = libft.a
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c $(FLAG) $<
$(NAME): $(OBJ) $(LIB)
	make -C $(LIB)
	gcc $(FLAG) $(OBJ) $(LIB)/$(LIB_A) -o $(NAME)

clean:
	make clean -C $(LIB)
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) $(LIB)/$(LIB_A)

re: fclean all

.PHONY: all clean fclean re
