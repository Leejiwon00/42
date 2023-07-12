/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:49:48 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/01/25 20:10:37 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		find_conversion(const char *format, va_list ap);
int		get_result(char c, va_list ap);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		get_i(long long num, int base);
int		get_u(unsigned long long num, int base);
int		ft_putnbr(long long num);
int		about_num(long long num, char flag);
int		about_hex(unsigned long long num, char flag);
int		ft_print_hex(unsigned long long num, char *hex);

#endif