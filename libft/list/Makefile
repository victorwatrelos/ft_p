# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 12:04:58 by vwatrelo          #+#    #+#              #
#    Updated: 2014/02/10 12:42:13 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror
NAME=libft_list.a
INCLUDES=-I ../includes
SRC=ft_lstadd.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstdelone.c \
	ft_lstnew.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): libft

libft: $(OBJ)
	ar -q $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
