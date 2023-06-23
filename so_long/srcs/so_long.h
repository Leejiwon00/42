/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:59 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/23 20:07:48 by jiwonle2         ###   ########.fr       */
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

# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	int				col;
	int				row;
	char			*line;
	void			*mlx;
	void			*win;
	void			*img;
	void			*backimg;
	struct s_player	player;
}	t_map;

void	read_map(char *map_name, t_map *map);
void	set_background(t_map *map);
void	make_map(t_map *map);
void	start_game(t_map *map);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);

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