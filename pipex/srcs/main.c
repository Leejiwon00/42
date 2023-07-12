/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:41 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/12 16:34:52 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void leak()
// {
// 	system("leaks pipex");
// }

int	main(int ac, char **av, char **envp)
{
	t_info	info;
	//atexit(leak);
	if (ac == 5 && av[0])
	{
		info.cmd = malloc(sizeof(char *) * 2);
		info.cmd[0] = av[2];
		info.cmd[1] = av[3];
		get_path(envp, &info);
	}
}
