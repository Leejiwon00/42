# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 12:58:09 by jiwonle2          #+#    #+#              #
#    Updated: 2023/07/19 18:58:02 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc #-g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = srcs/main.c srcs/path.c srcs/cmd.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $^

clean :
	rm -rf $(OBJS)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY: all clean fclean re