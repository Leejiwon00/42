/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:56:48 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/08 15:35:56 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_front(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_set(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

static int	check_back(char const *s1, char const *set, int len)
{
	len--;
	while (len > 0)
	{
		if (!is_set(s1[len], set))
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		len;
	int		front_idx;
	int		back_idx;
	int		size;

	front_idx = check_front(s1, set);
	len = ft_strlen(s1);
	if (front_idx == len)
		return (ft_strdup(""));
	back_idx = check_back(s1, set, len);
	size = back_idx - front_idx + 1;
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	len = 0;
	while (front_idx <= back_idx)
	{
		arr[len] = s1[front_idx];
		len++;
		front_idx++;
	}
	arr[len] = '\0';
	return (arr);
}
