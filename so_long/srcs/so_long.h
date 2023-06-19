/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:59 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/19 17:21:42 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* gnl */
char	*get_next_line(int fd);
char	*ft_strdup(char *str, int idx);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		is_line(char *str);
char	*read_file(char **save, char *buf, int fd);
char	*set_line(char **save);
void	free_ptr(char **ptr, char *init);

#endif