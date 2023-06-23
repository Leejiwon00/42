/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:43:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/23 20:02:13 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	read_map(char *map_name, t_map *map)
{
	int		fd;
	char	*tmp;

	if (!ft_strnstr(map_name + ft_strlen(map_name) - 4, ".ber", 4))
	{
		write(1, "Invalid extension\n", 18);
		exit(1);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	map->line = "";
	map->row = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map->line = ft_strjoin(map->line, tmp);
		map->row++;
		map->col = ft_strlen(tmp);
	}
}

void	set_background(t_map *map)
{
	int		w;
	int		h;
	int		x;
	int		y;

	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->col * 64, map->row * 64, "map");
	map->backimg
		= mlx_xpm_file_to_image(map->mlx, "./image/0.xpm", &w, &h);
	y = 0;
	while (y < map->row * 64)
	{
		x = 0;
		while (x < map->col)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->backimg, x * 64, y);
			x++;
		}	
		y += 64;
	}
}

void	make_map(t_map *map)
{
	int		w;
	int		h;
	int		x;
	int		y;
	int		i;

	i = -1;
	while (map->line[++i])
	{
		x = i - ((map->col + 1) * (i / (map->col + 1)));
		y = i / (map->col + 1);
		if (map->line[i] == 'P')
		{
			map->img = mlx_xpm_file_to_image(map->mlx, "./image/P.xpm", &w, &h);
			map->player.x = x;
			map->player.y = y;
		}
		else if (map->line[i] == '1')
			map->img = mlx_xpm_file_to_image(map->mlx, "./image/1.xpm", &w, &h);
		else if (map->line[i] == 'C')
			map->img = mlx_xpm_file_to_image(map->mlx, "./image/C.xpm", &w, &h);
		else if (map->line[i] == 'E')
			map->img = mlx_xpm_file_to_image(map->mlx, "./image/E.xpm", &w, &h);
		if (map->line[i] != '0')
			mlx_put_image_to_window(map->mlx, map->win, map->img,
				x * 64, y * 64);
	}
	printf("%p", map->img);
	//mlx_loop(map->mlx);
}
