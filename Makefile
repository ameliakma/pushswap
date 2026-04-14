# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 21:18:03 by akhalfou          #+#    #+#              #
#    Updated: 2026/04/14 18:50:03 by akhalfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de la bibliotheque
NAME = push_swap

#Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#Fichiers
SRC =	operations_swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	main.c \
	free.c \
	utils/node.c \
	utils/ft_atol.c \
	utils/ft_split.c \
	utils/ft_lstadd_back.c \
	utils/verify_duplicate.c \
	utils/check_digit.c \
	algo/index_and_bits.c \
	algo/ft_lstsize.c \
	algo/radix_sort.c

#fichiers objets
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
