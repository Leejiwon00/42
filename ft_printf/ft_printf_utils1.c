/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:22:15 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/01/25 20:10:32 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	about_num(long long num, char flag)
{
	int	len;

	if (flag == 'd')
		len = get_i(num, 10);
	else
		len = get_u(num, 10);
	if (ft_putnbr(num) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(long long num)
{
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		ft_putnbr(-num);
	}
	else if (num >= 0 && num <= 9)
	{
		if (ft_putchar(num + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_putnbr(num / 10) == -1)
			return (-1);
		if (ft_putnbr(num % 10) == -1)
			return (-1);
	}
	return (0);
}

int	about_hex(unsigned long long num, char flag)
{
	int	len;

	len = get_u(num, 16);
	if (flag == 'p')
		len += 2;
	if (flag == 'p' || flag == 'x')
	{
		if (ft_print_hex(num, "0123456789abcdef") == -1)
			return (-1);
	}
	else
	{
		if (ft_print_hex(num, "0123456789ABCDEF") == -1)
			return (-1);
	}
	return (len);
}

int	ft_print_hex(unsigned long long num, char *hex)
{
	if (num >= 0 && num <= 15)
	{
		if (write(1, &hex[num % 16], 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_hex(num / 16, hex) == -1)
			return (-1);
		if (ft_print_hex(num % 16, hex) == -1)
			return (-1);
	}
	return (0);
}
