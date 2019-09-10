# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 17:16:30 by ggeordi           #+#    #+#              #
#    Updated: 2019/09/10 17:43:49 by ggeordi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
FLAGS = -Wall -Wextra -Werror
HEADERS = .
OPTIONS = -c -I $(HEADERS)
RESULT = -o $(NAME)
SRC = *.c
OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTIONS) $(SRC)
	gcc $(OBJ) $(RESULT)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
