/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:43:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/30 20:54:37 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	read_map(char *map_name, t_game *game)
{
	int		fd;
	char	*tmp;
	char	*tmp2;

	if (!ft_strnstr(map_name + ft_strlen(map_name) - 4, ".ber", 4))
		print_error("Invalid extension\n");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp2 = game->map.line;
		game->map.line = ft_strjoin(game->map.line, tmp);
		if (*tmp2)
			free(tmp2);
		game->map.col = ft_strlen(tmp);
		game->map.row++;
		free(tmp);
	}
	close(fd);
}

void	set_background(t_game *game)
{
	int		w;
	int		h;
	int		x;
	int		y;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.col * 64, game->map.row * 64, "map");
	game->map.backimg
		= mlx_xpm_file_to_image(game->mlx, "./image/0.xpm", &w, &h);
	y = 0;
	while (y < game->map.row * 64)
	{
		x = 0;
		while (x < game->map.col)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->map.backimg, x * 64, y);
			x++;
		}	
		y += 64;
	}
}

void	make_map(t_game *g, int i, int *w, int *h)
{
	while (g->map.line[++i])
	{
		if (g->map.line[i] == 'P')
		{
			g->player.p_img
				= mlx_xpm_file_to_image(g->mlx, "./image/P.xpm", w, h);
			mlx_put_image_to_window(g->mlx, g->win, g->player.p_img,
				g->player.x * 64, g->player.y * 64);
		}
		else if (g->map.line[i] == '1')
			g->map.img = mlx_xpm_file_to_image(g->mlx, "./image/1.xpm", w, h);
		else if (g->map.line[i] == 'C')
		{
			g->map.img = mlx_xpm_file_to_image(g->mlx, "./image/C.xpm", w, h);
			g->c++;
		}
		else if (g->map.line[i] == 'E')
			g->map.img = mlx_xpm_file_to_image(g->mlx, "./image/E.xpm", w, h);
		if (g->map.line[i] != '0' && g->map.line[i] != 'P')
			mlx_put_image_to_window(g->mlx, g->win, g->map.img,
				(i - ((g->map.col + 1) * (i / (g->map.col + 1)))) * 64,
				(i / (g->map.col + 1)) * 64);
	}
}
