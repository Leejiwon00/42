/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:23:46 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/30 16:19:57 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!arr)
		return (NULL);
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

char	*ft_strdup(char *str, int idx)
{
	char	*arr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	if (idx != -1)
		len = idx;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{	
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
