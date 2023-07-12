/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:57:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2022/12/09 14:30:01 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= (-1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	n_to_a(char *arr, int len, long long n)
{
	if (n < 0)
	{
		arr[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		arr[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int			len;
	long long	l_n;
	char		*arr;

	if (n == 0)
	{
		arr = malloc(sizeof(char) * 2);
		if (!arr)
			return (0);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	l_n = (long long)n;
	len = get_len(l_n);
	if (l_n < 0)
		len += 1;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	arr[len] = '\0';
	len--;
	n_to_a(arr, len, n);
	return (arr);
}
