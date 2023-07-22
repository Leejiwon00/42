/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:39 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/22 18:52:32 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_process(t_info *info)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (++i < info->cmd_cnt)
	{
		if (pipe(info->fd) < 0)
			exit(1);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			execute_cmd(info, i);
		if (i == 1)
		{
			pid = fork();
			if (pid < 0)
				exit(1);
			if (pid == 0)
				execute_cmd(info, i);
		}
		close(info->fd[0]);
		close(info->fd[1]);
	}
	i = -1;
	while (++i < info->cmd_cnt)
		wait(NULL);
}

void	execute_cmd(t_info *info, int i)
{
	char	**arg;

	if (i == 0)
	{
		arg = get_cmdpath(info, info->cmd1);
		if (!arg)
			print_error(info->cmd1, ": command not found\n");
		close(info->fd[0]);
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->fd[1], STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
	else if (i == 1)
	{
		arg = get_cmdpath(info, info->cmd2);
		if (!arg)
			print_error(info->cmd2, ": command not found\n");
		close(info->fd[1]);
		dup2(info->fd[0], STDIN_FILENO);
		dup2(info->outfile_fd, STDOUT_FILENO);
		close(info->outfile_fd);
		execve(arg[0], arg, info->envp);
	}
}
