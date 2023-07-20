/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/20 19:03:33 by jiwonle2         ###   ########.fr       */
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
		printf("ddd");
		info.infile_fd = open(av[1], O_RDONLY);
		if (info.infile_fd < 0)
			print_error(av[1]);
		info.outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		info.cmd1 = av[2];
		info.cmd2 = av[3];
	 	get_path(envp, &info);
		execute_cmd(&info);
	 }
}
