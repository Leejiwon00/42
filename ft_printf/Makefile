CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar -rc $@ $^

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re