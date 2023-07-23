/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:39 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/23 18:34:46 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_pipe(t_info *info)
{
	int	i;

	i = -1;
	info->fd = malloc(sizeof(int *) * (info->cmd_cnt - 1));
	while (++i < info->cmd_cnt -1)
		info->fd[i] = malloc(sizeof(int) * 2);
	i = -1;
	while (++i < info->cmd_cnt - 1)
	{
		if (pipe(info->fd[i]) < 0)
			exit(1);
	}
}

void	make_process(t_info *info, int i)
{
	int		j;
	pid_t	pid;

	j = -1;
	while (++i < info->cmd_cnt)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
			execute_cmd(info, i);
	}
	while (++j < info->cmd_cnt - 1)
	{
		close(info->fd[j][0]);
		close(info->fd[j][1]);
	}
}

void	execute_cmd(t_info *info, int idx)
{
	char	**arg;

	arg = get_cmdpath(info, info->cmd[idx]);
	if (!arg)
		print_error(info->cmd[idx], ": command not found\n");
	if (idx == 0)
	{
		close(info->fd[idx][0]);
		dup2(info->infile_fd, STDIN_FILENO);
		dup2(info->fd[idx][1], STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
	else if (idx == info->cmd_cnt - 1)
	{
		close(info->fd[idx][1]);
		dup2(info->fd[idx][0], info->fd[idx - 1][1]);
		dup2(info->outfile_fd, STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
	else
	{
		dup2(info->fd[idx][0], info->fd[idx - 1][1]);
		dup2(info->fd[idx][1], STDOUT_FILENO);
		execve(arg[0], arg, info->envp);
	}
}
