/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:40 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/12 16:28:50 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char **envp, t_info *info)
{
	int		i;
	int		j;
	char	*all_path;
	char	*tmp_cmd;

	i = -1;
	all_path = "";
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			all_path = envp[i] + 5;
			break ;
		}	
	}
	info->path = ft_split(all_path, ':');
	j = -1;
	while (++j < 2)
	{
		i = -1;
		while (info->path[++i])
		{
			all_path = ft_strjoin(info->path[i], "/");
			tmp_cmd = ft_strjoin(all_path, info->cmd[j]);
			free(all_path);
			if (!access(tmp_cmd, F_OK))
			{
				//free(info->cmd[j]);
				info->cmd[j] = tmp_cmd;
				free(tmp_cmd);
				break ;
			}
			free(tmp_cmd);
		}
	}
	i = -1;
	while (info->path[++i])
		free(info->path[i]);
	free(info->path);
	printf("%s\n%s\n", info->cmd[0], info->cmd[1]);
	free(info->cmd);
}
