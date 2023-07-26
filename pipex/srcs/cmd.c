/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:39 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/26 18:31:02 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_process(t_info *info)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	if (pipe(fd) < 0)
		exit(1);
	i = -1;
	while (++i < 2)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			execute_cmd(info, i, fd);
	}
	close(fd[0]);
	close(fd[1]);
	i = -1;
	while (++i < 2)
		wait(NULL);
}

void	execute_cmd(t_info *info, int i, int fd[2])
{
	char	**arg;

	if (i == 0)
	{
		arg = get_cmdpath(info, info->cmd1);
		if (!arg)
			print_error(info->cmd1, ": command not found\n");
		close(fd[0]);
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
	else if (i == 1)
	{
		arg = get_cmdpath(info, info->cmd2);
		if (!arg)
			print_error(info->cmd2, ": command not found\n");
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(info->outfile_fd, STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
}
