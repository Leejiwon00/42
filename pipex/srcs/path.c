/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:40 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/21 19:10:15 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char **envp, t_info *info)
{
	int		i;
	char	*all_path;
	char	**tmp;

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
	tmp = info->path;
	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	//free(tmp);
	i = -1;
	while (info->path[++i])
		info->path[i] = ft_strjoin(info->path[i], "/");
}

char	**get_cmdpath(t_info *info, char *cmd)
{
	int		i;
	char	*tmp;
	char	**args;

	i = -1;
	args = ft_split(cmd, ' ');
	while (info->path[++i])
	{
		tmp = ft_strjoin(info->path[i], args[0]);
		if (!access(tmp, F_OK))
		{
			args[0] = tmp;
			free(tmp);
			return (args);
		}
		free(tmp);
	}
	return (NULL);
}
