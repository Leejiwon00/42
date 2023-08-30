# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 16:40:28 by jiwonle2          #+#    #+#              #
#    Updated: 2023/08/30 16:22:55 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRCS = main.c utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re