/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:32:55 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/09 14:33:11 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*u_dst;
	unsigned char	*u_src;

	if (!dst && !src)
		return (0);
	u_dst = (unsigned char *)dst;
	u_src = (unsigned char *)src;
	if (u_dst > u_src)
	{
		while (len--)
			u_dst[len] = u_src[len];
	}	
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
