/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:59:38 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/06 19:08:14 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	execute(t_cmd *cmds, t_env **env_lst, t_info *info)
{
	//pipex_gichlee(cmds, env_lst);
	pipex(cmds, env_lst, info);
	cmds_clear(&cmds, free);
	return (0);
}