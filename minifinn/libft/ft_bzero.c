/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:45:42 by gichlee           #+#    #+#             */
/*   Updated: 2022/12/04 15:38:31 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	if (n == 0)
		return ;
	else
	{
		idx = 0;
		while (idx < n)
		{
			((char *)s)[idx] = 0;
			idx++;
		}
	}
}
