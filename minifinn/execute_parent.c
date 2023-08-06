#include "main.h"

void	close_fd(t_cmd *cmds)
{
	t_cmd	*cmd;

	cmd = cmds;
	while (cmd != 0)
	{
		if (cmd->fd_in != 0)
			close(cmd->fd_in);
		if (cmd->fd_out != 1)
			close(cmd->fd_out);
		if (cmd->pipe_in != 0)
			close(cmd->pipe_in);
		if (cmd->pipe_out != 0)
			close(cmd->pipe_out);
		cmd = cmd->next;
	}
}

void	waiting(void)
{
	int			exit_status;
	int			status_code;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (wait(&exit_status) != -1 || errno != ECHILD)
	{
		if (WIFSIGNALED(exit_status) != 0)
		{
			ft_putchar_fd('\n', 1);
			status_code = WTERMSIG(exit_status) + 128;
		}
		else if (WIFEXITED(exit_status))
		{
			status_code = WEXITSTATUS(exit_status);
		}
	}
	set_signal();
}