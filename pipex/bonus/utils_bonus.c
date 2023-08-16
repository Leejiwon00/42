/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:06:17 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/06 15:31:06 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *name, char *message)
{
	write(2, "pipex: ", 7);
	write(2, name, ft_strlen(name));
	write(2, message, ft_strlen(message));
	exit(1);
}

void	close_fds(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->cmd_cnt - 1)
	{
		//printf("%d %d\n", info->fd[i][0], info->fd[i][1]);
		close(info->fd[i][0]);
		close(info->fd[i][1]);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	init_cmd(t_info *info, int ac, char **av)
{
	int	i;
	int	j;

	info->cmd = malloc(sizeof(char *) * (ac - 2));
	i = 1;
	j = 0;
	while (++i < ac - 1)
	{
		info->cmd[j] = ft_strdup(av[i]);
		j++;
	}
}
