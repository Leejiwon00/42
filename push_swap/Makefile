# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 18:04:52 by jiwonle2          #+#    #+#              #
#    Updated: 2023/03/30 15:30:03 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_B = checker
SRCS_M = srcs/main.c srcs/check_error.c srcs/ft_split.c srcs/greedy.c srcs/greedy_utils.c \
		srcs/operations1.c srcs/operations2.c srcs/utils.c srcs/find.c srcs/about_five.c
SRCS_B = bonus/check_error_bonus.c bonus/ft_split_bonus.c bonus/operations1_bonus.c bonus/checker_utils_bonus.c \
				bonus/operations2_bonus.c bonus/main_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c
OBJS = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) -o $@ $^

bonus : $(NAME_B)

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all

.PHONY: all bonus clean fclean re