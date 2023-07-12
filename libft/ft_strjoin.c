/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:54:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/09 14:47:53 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}
