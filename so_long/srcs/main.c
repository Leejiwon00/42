/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:28 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/24 20:15:42 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	checkmap(t_map *map, int x, int y)
{
	int	loc;

	loc = y * (map->col + 1) + x;
	if (loc < 0 || loc > ((map->row - 1) * (map->col + 1) + map->col - 1))
		exit(0);
}

void	start_game(t_map *map)
{
	mlx_key_hook(map->win, key_event, map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		w;
	int		h;

	if (ac == 2)
	{
		read_map(av[1], &map);
		set_background(&map);
		make_map(&map, -1, &w, &h);
		checkmap(&map, map.player.x, map.player.y);
		//start_game(&map);
	}

	// void	*mlx_ptr;
	// void	*win_ptr;
	// int		width;
	// int		height;

	// map.mlx = mlx_init();
	// map.win = mlx_new_window(map.mlx, 500, 500, "mlx_test");
	// void *img=mlx_xpm_file_to_image(map.mlx, "./image/1.xpm",&width,&height);
	// mlx_put_image_to_window(map.mlx, map.win, img, 10,10);
	// mlx_key_hook(map.win, key_event, &map);
	// mlx_loop(map.mlx);
	
}
