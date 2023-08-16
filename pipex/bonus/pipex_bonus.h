/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:36:56 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/31 17:08:06 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_info
{
	int		infile_fd;
	int		outfile_fd;
	int		cmd_cnt;
	int		**fd;
	char	**path;
	char	**cmd;
	char	**envp;
}	t_info;

void	get_path(char **envp, t_info *info, int i);
char	**get_cmdpath(t_info *info, char *cmd);
void	execute_cmd(t_info *info, int idx);
void	make_process(t_info *info, int i);
void	print_error(char *name, char *message);
void	free_arr(char **arr);
void	init_cmd(t_info *info, int ac, char **av);
void	make_pipe(t_info *info);
void	close_fds(t_info *info);

#endif