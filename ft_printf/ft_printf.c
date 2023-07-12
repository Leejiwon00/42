/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:41:57 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/01/25 20:10:35 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_result(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
	{
		if (write (1, "0x", 2) == -1)
			return (-1);
		return (about_hex(va_arg(ap, unsigned long long), 'p'));
	}	
	else if (c == 'd' || c == 'i')
		return (about_num(va_arg(ap, int), 'd'));
	else if (c == 'u')
		return (about_num(va_arg(ap, unsigned int), 'u'));
	else if (c == 'x')
		return (about_hex(va_arg(ap, unsigned int), 'x'));
	else if (c == 'X')
		return (about_hex(va_arg(ap, unsigned int), 'X'));
	else if (c == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (-1);
}

int	find_conversion(const char *format, va_list ap)
{
	int	i;
	int	cnt;
	int	check;

	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check = get_result(format[i + 1], ap);
			if (check == -1)
				return (-1);
			cnt += check;
			i++;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = find_conversion(format, ap);
	va_end(ap);
	return (result);
}
