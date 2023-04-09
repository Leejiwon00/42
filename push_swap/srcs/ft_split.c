/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:00:16 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/25 15:36:59 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_split(char **str)
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

int	ft_getlen(char *str)
{
	int	len;
	int	flag;

	len = 0;
	flag = 0;
	while (*str)
	{
		if (*str != 32 && flag == 0)
		{
			len++;
			flag = 1;
		}
		else if (*str == 32)
			flag = 0;
		str++;
	}
	return (len);
}

char	*go_split2(int *cnt, int idx, char *str)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (*cnt + 1));
	if (!word)
		return (0);
	while (i < *cnt)
	{
		word[i] = str[idx];
		idx++;
		i++;
	}
	word[i] = 0;
	*cnt = 0;
	return (word);
}

char	**go_split1(char *str, char **arr, int *cnt)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] != 32)
		{
			(*cnt)++;
			if (i == ft_strlen(str) - 1)
			{
				arr[++j] = go_split2(cnt, i - *cnt + 1, str);
				if (!arr[j])
					return (free_split(arr));
			}
		}
		else if (str[i] == 32 && *cnt != 0)
		{
			arr[++j] = go_split2(cnt, i - *cnt, str);
			if (!arr[j])
				return (free_split(arr));
		}
	}
	return (arr);
}

char	**ft_split(char *s, int *size)
{
	char	**arr;
	int		cnt;

	cnt = 0;
	*size = ft_getlen(s);
	arr = malloc(sizeof(char *) * (*size + 1));
	if (!arr)
		return (0);
	arr = go_split1(s, arr, &cnt);
	arr[*size] = 0;
	(*size)++;
	if (!arr[0])
		error(1);
	return (arr);
}
