# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 20:20:04 by jiwonle2          #+#    #+#              #
#    Updated: 2023/08/14 20:44:55 by jiwonle2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
SRCS		= main.c \
				built_in_cd_util.c \
				built_in_cd.c \
				built_in_echo.c \
				built_in_env.c \
				built_in_exit.c \
				built_in_export.c \
				built_in_export_util.c \
				built_in_pwd.c \
				built_in_unset.c \
				execute_env_lst_to_envp.c \
				execute_parent.c \
				execute_pipex.c \
				execute_run_built_in.c \
				execute.c \
				exit_status.c \
				main_env_lst_util.c \
				main_envp_to_env_lst.c \
				main_clear.c \
				main_signal.c \
				parsing_env_after.c \
				parsing_env_replace.c \
				parsing_env_replace_util.c \
				parsing_env_util.c \
				parsing_lexical_analyzer.c \
				parsing_lexical_assign_tags.c \
				parsing_lexical_divide_delimiters.c \
				parsing_lexical_quotes.c \
				parsing_lexical_quotes_util.c \
				parsing_lexical_token_util.c \
				parsing_lexical_update_tokens.c \
				parsing_syntax_built_in.c \
				parsing_syntax_cmd_util.c \
				parsing_syntax_create_argv.c \
				parsing_syntax_heredoc.c \
				parsing_syntax_locate_cmd_util.c \
				parsing_syntax_locate_cmd.c \
				parsing_syntax_redirection.c \
				parsing_syntax.c \
				parsing.c \
				print_error.c
OBJS		= $(SRCS:%.c=%.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT		= libft
LINKERS		= -lft -L$(LIBFT) -lreadline -L${HOME}/.brew/opt/readline/lib
INCLUDES	= -I ./includes -I${HOME}/.brew/opt/readline/include
RM			= rm -rf
.PHONY:		all clean fclean re
%.o:		%.c ./minishell.h
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
all:		$(NAME)
$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT) all
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LINKERS) -o $(NAME)
clean:
			make -C $(LIBFT) clean
			$(RM) $(OBJS)
fclean:
			make clean
			make -C $(LIBFT) fclean
			$(RM) $(NAME)
re:
			make fclean
			make all