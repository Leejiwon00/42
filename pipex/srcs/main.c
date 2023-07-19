/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/19 18:13:05 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void leak()
{
	system("leaks pipex");
}

void	print_error(char *str)
{
	write(1, "pipex: ", 7);
	write(1, str, ft_strlen(str));
	write(1, ": No such file or directory\n", 28);
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	t_info	info;
	//atexit(leak);
	if (ac == 5)
	{
		info.infile_fd = open(av[1], O_RDONLY);
		if (info.infile_fd < 0)
			print_error(av[1]);
		get_path(envp, &info);
	}
}
