/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:06:47 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/05 16:49:14 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	pipex(t_cmd *cmd, t_env **env_lst)
{
	make_process(cmd);
}

void	make_process(t_cmd *cmd)
{
	int		cmd_cnt;
	int		i;
	pid_t	pid;
	t_cmd	*tmp;
	t_cmd	*prev;

	cmd_cnt = 0;
	tmp = cmd;
	while (tmp)
	{
		cmd_cnt++;
		tmp = tmp->next;
	}
	tmp = cmd;
	i = -1;
	while (++i < cmd_cnt)
	{
		prev = tmp;
		if (i != 0)
			tmp = tmp->next;
		//pid = fork();
		// if (pid < 0)
		// 	exit(1);
		// if (pid == 0)
			// execute_cmd(tmp, prev, i, cmd_cnt);
	}
	close_fds(cmd);
	// i = -1;
	// while (++i < cmd_cnt)
	// 	wait(NULL);
	// i = -1;
	// while (++i < info->cmd_cnt - 1)
	// 	free(info->fd[i]);
	// free(info->fd);
}

void	execute_cmd(t_cmd *cmd, t_cmd *prev, int idx, int cmd_cnt)
{
	// printf("prev:%d-->fd_in:%d fd_out:%d, p_in:%d p_out:%d\n", idx, prev->fd_in, prev->fd_out, prev->pipe_in, prev->pipe_out);
	// printf("     %d-->fd_in:%d fd_out:%d, p_in:%d p_out:%d\n", idx, cmd->fd_in, cmd->fd_out, cmd->pipe_in, cmd->pipe_out);
	if (idx == 0)
	{	
		dup2(cmd->fd_in, STDIN_FILENO);
		dup2(cmd->pipe_out, STDOUT_FILENO);
	}
	else if (idx == cmd_cnt - 1)
	{
		dup2(prev->pipe_in, STDIN_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	else
	{
		dup2(prev->pipe_in, STDIN_FILENO);
		dup2(cmd->pipe_out, STDOUT_FILENO);
	}
	//close_fds(cmd);
	execve(cmd->argv[0], cmd->argv, NULL);
}

void	close_fds(t_cmd *cmd)
{
	t_cmd *tmp;

	tmp = cmd;
	while (tmp)
	{
		// close(tmp->fd_in);
		// close(tmp->fd_out);
		if (tmp->pipe_in)
			close(tmp->pipe_in);
		if (tmp->pipe_out)
			close(tmp->pipe_out);
		tmp = tmp->next;
	}
}