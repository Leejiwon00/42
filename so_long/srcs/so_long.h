/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:07:59 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/27 20:00:44 by jiwonle2         ###   ########.fr       */
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

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_player
{
	int		x;
	int		y;
	void	*p_img;
}	t_player;

typedef struct s_map
{
	int				col;
	int				row;
	char			*line;
	void			*img;
	void			*backimg;
}	t_map;

typedef struct s_game
{
	int				walk;
	int				collectible;
	int				p;
	int				c;
	int				e;
	void			*mlx;
	void			*win;
	struct s_map	map;
	struct s_player	player;
}	t_game;

void	read_map(char *map_name, t_game *game);
void	set_background(t_game *game);
void	make_map(t_game *g, int i, int *w, int *h);
void	check_map(t_game *game);
void	check_closed(t_game *game);
void	check_validpath(t_game *game, int **visit, int x, int y);
void	start_game(t_game *game);
int		key_event(int keycode, t_game *game);
void	player_move(int keycode, t_game *game);
void	put_image_when_move(t_game *game, int x, int y);

void	ft_putnbr(int num);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);
void	print_error(t_game *game, char *message);

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