/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:49:55 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/08 15:59:27 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

static int	ft_getlen(char const *str, char c)
{
	int	len;
	int	flag;

	len = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			len++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (len);
}

static char	*go_split2(int *cnt, int idx, char const *str)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(*cnt + 1, sizeof(char));
	if (!word)
		return (0);
	while (i < *cnt)
	{
		word[i] = str[idx];
		idx++;
		i++;
	}
	*cnt = 0;
	return (word);
}

static	char	**go_split1(char const *str, char **arr, char c, int *cnt)
{
	size_t	i;
	int		j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] != c)
		{
			(*cnt)++;
			if (i == ft_strlen(str) - 1)
			{
				arr[++j] = go_split2(cnt, i - *cnt + 1, str);
				if (!arr[j])
					return (free_split(arr));
			}
		}
		else if (str[i] == c && *cnt != 0)
		{
			arr[++j] = go_split2(cnt, i - *cnt, str);
			if (!arr[j])
				return (free_split(arr));
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;
	int		cnt;

	cnt = 0;
	size = ft_getlen(s, c);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (0);
	arr = go_split1(s, arr, c, &cnt);
	return (arr);
}
