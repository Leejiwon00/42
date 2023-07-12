/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:56:53 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/09 14:48:19 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			if (j == n_len - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (0);
}
