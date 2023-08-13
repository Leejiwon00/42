/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:05:35 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/08/13 20:07:23 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_pwd_str(t_env **env_lst, char **pwd)
{
	t_env	*env;

	env = *env_lst;
	while (env != 0)
	{
		if (!ft_strncmp(env->key, "PWD", 4))
		{
			*pwd = ft_strdup(env->value);
			break ;
		}
		env = env->next;
	}
	if (!env)
		return (1);
	return (0);
}

int	built_in_pwd(t_env **env_lst)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		if (get_pwd_str(env_lst, &pwd))
			return (print_error(NULL, "not found PWD"));
	}
	ft_putendl_fd(pwd, 1);
	free(pwd);
	return (0);
}
