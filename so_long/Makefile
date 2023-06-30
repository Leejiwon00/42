# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 14:58:37 by jiwonle2          #+#    #+#              #
#    Updated: 2023/06/30 16:49:33 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRCS = srcs/main.c srcs/set_map.c srcs/check_map.c srcs/utils.c srcs/move.c \
		srcs/get_next_line.c srcs/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re