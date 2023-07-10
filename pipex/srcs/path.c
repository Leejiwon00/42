/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:41:40 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/10 14:32:02 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

void	get_path(char **envp, t_info *info)
{
	int		i;
	char	*all_path;

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
}
