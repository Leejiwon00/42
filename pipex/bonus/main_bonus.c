/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/23 17:24:41 by jiwonle2         ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac >= 5)
	{
		info.outfile_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (info.outfile_fd < 0)
			print_error(av[ac - 1], ": No such file or directory\n");
		info.infile_fd = open(av[1], O_RDONLY);
		if (info.infile_fd < 0)
			print_error(av[1], ": No such file or directory\n");
		init_cmd(&info, ac, av);
		info.cmd_cnt = ac - 3;
		info.envp = envp;
		get_path(envp, &info, -1);
		make_pipe(&info);
		make_process(&info, -1);
		free_arr(info.path);
		close(info.infile_fd);
		close(info.outfile_fd);
	}
	else
		write(1, "Invalid arguments\n", 18);
	return (0);
}
