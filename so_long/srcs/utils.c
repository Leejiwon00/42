/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:38:55 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/02 16:41:37 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	n_len = ft_strlen(needle);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			if (j == n_len - 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 0 && num <= 9)
	{
		c = num + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

void	print_error(t_game *game, char *message)
{
	if (*game->map.line)
		free(game->map.line);
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	exit(1);
}

int	exit_event(void)
{
	exit(0);
}
