/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:57:39 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/06 15:29:35 by jiwonle2         ###   ########.fr       */
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
	pid_t	pid;

	//printf("%d\n", info->cmd_cnt);
	while (++i < info->cmd_cnt)
	{
		//printf("prev:%d-->p_in:%d p_out:%d\n", i, info->fd[i][0], info->fd[i][1]);
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
		{
			//printf("a\n");
			execute_cmd(info, i);
		}	
	}
	close_fds(info);
	i = -1;
	while (++i < info->cmd_cnt)
		wait(NULL);
	i = -1;
	while (++i < info->cmd_cnt - 1)
		free(info->fd[i]);
	free(info->fd);
}

void	execute_cmd(t_info *info, int idx)
{
	char	**arg;

	// printf("idx:%d\n", idx);
	//printf("%d %d", info->fd[idx][1], info->fd[idx - 1][0]);
	arg = get_cmdpath(info, info->cmd[idx]);
	if (!arg)
		print_error(info->cmd[idx], ": command not found\n");
	if (idx == 0)
	{	
		dup2(0, STDIN_FILENO);
		dup2(info->fd[idx][1], STDOUT_FILENO);
	}
	else if (idx == info->cmd_cnt - 1)
	{
		dup2(info->fd[idx - 1][0], STDIN_FILENO);
		dup2(STDOUT_FILENO, STDOUT_FILENO);
	}
	else
	{
		dup2(info->fd[idx - 1][0], STDIN_FILENO);
		dup2(info->fd[idx][1], STDOUT_FILENO);
	}
	// printf("dddd\n");
	close_fds(info);
	execve(arg[0], arg, info->envp);
}
