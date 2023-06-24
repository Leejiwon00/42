/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:40:08 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/24 18:49:00 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	put_image_when_move(t_map *map, int x, int y)
{
	int	loc;

	loc = y * (map->col + 1) + x;
	if (map->line[loc] != '1' && ((map->line[loc] != 'E') || !map->collectible))
	{
		mlx_put_image_to_window(map->mlx, map->win, map->backimg,
			map->player.x * 64, map->player.y * 64);
		if (map->line[loc] == 'C')
		{
			mlx_put_image_to_window(map->mlx, map->win, map->backimg,
				x * 64, y * 64);
			map->collectible--;
			map->line[loc] = '0';
		}
		mlx_put_image_to_window(map->mlx, map->win, map->player.p_img,
			x * 64, y * 64);
		map->player.x = x;
		map->player.y = y;
	}
}

void	player_move(int keycode, t_map *map)
{
	int	x;
	int	y;

	if (keycode == W)
	{
		x = map->player.x;
		y = map->player.y - 1;
	}
	else if (keycode == A)
	{
		x = map->player.x - 1;
		y = map->player.y;
	}
	else if (keycode == S)
	{
		x = map->player.x;
		y = map->player.y + 1;
	}
	else
	{
		x = map->player.x + 1;
		y = map->player.y;
	}
	put_image_when_move(map, x, y);
}

int	key_event(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		player_move(keycode, map);
		ft_putnbr(map->cnt++);
		write(1, "\n", 1);
	}
	return (0);
}
