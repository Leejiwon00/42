# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 12:58:09 by jiwonle2          #+#    #+#              #
#    Updated: 2023/07/23 18:36:42 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = srcs/main.c srcs/path.c srcs/cmd.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	make -sC libft
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $^

clean :
	rm -rf $(OBJS)
	make -sC libft clean

fclean : clean
	rm -rf $(NAME)
	make -sC libft fclean

re :
	make fclean
	make all

.PHONY: all clean fclean re