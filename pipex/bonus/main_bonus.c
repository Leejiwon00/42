/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/06 13:55:19 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void leak()
// {
// 	system("leaks pipex");
// }

int	main(int ac, char **av, char **envp)
{
	t_info	info;

	if (ac >= 5)
	{
		// if (ft_strnstr(av[1], "here_doc", 8))
		// 	heredoc(&info);
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
		free_arr(info.cmd);
		close(info.infile_fd);
		close(info.outfile_fd);
	}
	else
		write(1, "Invalid arguments\n", 18);
	return (0);
}
