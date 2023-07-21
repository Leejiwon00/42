/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:36:56 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/21 17:04:06 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	char	**path;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}	t_info;

void	get_path(char **envp, t_info *info);
char	**get_cmdpath(t_info *info, char *cmd);
void	execute_cmd(t_info *info, int i, int fd[2]);
void	make_process(t_info *info);
void	print_error(char *name, char *message);
#endif