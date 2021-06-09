# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsanaoui <bsanaoui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 18:37:09 by bsanaoui          #+#    #+#              #
#    Updated: 2021/06/04 18:54:36 by bsanaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re bonus
NAME = push_swap
BONUS = checker
CC = gcc
FLAGS =	-Werror -Wextra -Wall #-fsanitize=address -g

SRC = stack.c utils.c utils2.c utils3.c utils_libft.c fill_list.c operations.c operations2.c\
		random_2_3_5.c push_b_to_a.c push_a_to_b.c random_plus_100.c \
		random_under_100.c

all : $(NAME)

$(NAME):
	@$(CC) $(SRC) main.c -I. $(FLAGS) -o $(NAME)
	@$(CC) $(SRC) checker_operations.c checker_operations2.c checker.c get_next_line.c -I. $(FLAGS) -o $(BONUS)

fclean: clean
	@rm -f $(NAME) $(BONUS)

clean:
	@rm -f *.o

re: fclean all