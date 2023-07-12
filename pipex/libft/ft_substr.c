/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:26:17 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/08 15:36:11 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (len > 0 && s[start])
	{
		arr[i++] = s[start++];
		len--;
	}
	arr[i] = '\0';
	return (arr);
}
