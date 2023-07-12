/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:55:25 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/09 14:48:12 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;
	size_t			i;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (u_s1[i] && u_s2[i])
	{
		if (i == n)
		{
			i--;
			break ;
		}
		if (u_s2[i] == u_s1[i])
			i++;
		else
			break ;
	}
	if (i == n)
		i--;
	return (u_s1[i] - u_s2[i]);
}
