# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 12:58:09 by jiwonle2          #+#    #+#              #
#    Updated: 2023/07/22 17:48:42 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

SRCS = srcs/main.c srcs/path.c srcs/cmd.c
SRCS_B = bonus/main_bonus.c bonus/path_bonus.c bonus/cmd_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef BFLAGS
	OBJS_FIN = $(OBJS_B)
else
	OBJS_FIN = $(OBJS)
endif

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS_FIN)
	make -sC libft
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $^

bonus :
	make BFLAGS=1

clean :
	rm -rf $(OBJS) $(OBJS_B)
	make -sC libft clean

fclean : clean
	rm -rf $(NAME)
	make -sC libft fclean

re :
	make fclean
	make all

.PHONY: all bonus clean fclean re