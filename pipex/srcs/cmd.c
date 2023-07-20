/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:39 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/20 18:36:19 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_info *info)
{
	int		fd[2];
	pid_t	pid;
	char	**arg;

	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(info->outfile_fd, STDOUT_FILENO);
		arg = get_cmdpath(info, info->cmd2);
		if (!arg)
		{
			write(1, "first cmd not found\n", 20);
			exit(1);
		}
		execve(arg[0], arg, NULL);
		close(fd[0]);
	}
	else
	{	
		close(fd[0]);
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		arg = get_cmdpath(info, info->cmd1);
		if (!arg)
		{
			write(1, "second cmd not found\n", 20);
			exit(1);
		}
		execve(arg[0], arg, NULL);
		close(fd[1]);
	}
}