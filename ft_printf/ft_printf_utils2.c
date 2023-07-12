/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:53:32 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/01/25 20:10:34 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		i++;
		cnt++;
	}
	if (write(1, str, cnt) == -1)
		return (-1);
	return (cnt);
}

int	get_i(long long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len += 1;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

int	get_u(unsigned long long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}
