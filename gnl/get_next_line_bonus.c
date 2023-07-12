/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:55:12 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/01/16 19:19:02 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*set_line(char **save)
{
	char	*line;
	char	*temp;

	if (is_line(*save) >= 0)
	{
		line = ft_strdup(*save, is_line(*save) + 1);
		temp = ft_strdup(*save + is_line(*save) + 1, -1);
		free(*save);
		*save = temp;
	}
	else
	{
		line = ft_strdup(*save, -1);
		free(*save);
		*save = NULL;
	}
	return (line);
}

void	free_ptr(char **ptr, char *init)
{
	free(*ptr);
	*ptr = init;
}

char	*read_file(char **save, char *buf, int fd)
{
	char	*temp;
	int		read_size;

	if (!*save)
	{
		*save = ft_strdup("", -1);
		if (!*save)
			return (NULL);
	}
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0 && **save)
			return (set_line(save));
		if (read_size <= 0)
			break ;
		buf[read_size] = '\0';
		temp = ft_strjoin(*save, buf);
		if (!temp)
			break ;
		free_ptr(save, temp);
		if (is_line(*save) >= 0)
			return (set_line(save));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free_ptr(&save[fd], NULL);
		return (NULL);
	}
	line = read_file(&save[fd], buf, fd);
	free_ptr(&buf, NULL);
	if (!line)
	{
		free_ptr(&save[fd], NULL);
		return (NULL);
	}
	return (line);
}
