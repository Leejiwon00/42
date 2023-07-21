/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/21 17:54:11 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void leak()
{
	system("leaks --list -- pipex");
}

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

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	atexit(leak);
	if (ac == 5)
	{
		info.infile_fd = open(av[1], O_RDONLY);
		if (info.infile_fd < 0)
			print_error(av[1], ": No such file or directory\n");
		info.outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		info.cmd1 = av[2];
		info.cmd2 = av[3];
		info.envp = envp;
		get_path(envp, &info);
		make_process(&info);
		free_arr(info.path);
	}
}
