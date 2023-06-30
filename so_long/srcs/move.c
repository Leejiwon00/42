/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:40:08 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/30 16:45:45 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	game_end(t_game *game)
{
	write(1, "-----GAME SUCCESS-----\n", 23);
	free(game->map.line);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->map.backimg);
	mlx_destroy_image(game->mlx, game->map.img);
	mlx_destroy_image(game->mlx, game->player.p_img);
	exit(0);
}

void	start_game(t_game *game)
{
	mlx_key_hook(game->win, key_event, game);
	mlx_hook(game->win, 17, 0, exit_event, 0);
	mlx_loop(game->mlx);
}

void	put_image_when_move(t_game *game, int x, int y)
{
	int	loc;

	loc = y * (game->map.col + 1) + x;
	if (game->map.line[loc] != '1'
		&& ((game->map.line[loc] != 'E') || !game->c))
	{
		if (game->map.line[loc] == 'E' && !game->c)
			game_end(game);
		mlx_put_image_to_window(game->mlx, game->win, game->map.backimg,
			game->player.x * 64, game->player.y * 64);
		if (game->map.line[loc] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->map.backimg,
				x * 64, y * 64);
			game->map.line[loc] = '0';
			game->c--;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->player.p_img,
			x * 64, y * 64);
		game->player.x = x;
		game->player.y = y;
	}
}

void	player_move(int keycode, t_game *game)
{
	int	x;
	int	y;

	if (keycode == W)
	{
		x = game->player.x;
		y = game->player.y - 1;
	}
	else if (keycode == A)
	{
		x = game->player.x - 1;
		y = game->player.y;
	}
	else if (keycode == S)
	{
		x = game->player.x;
		y = game->player.y + 1;
	}
	else
	{
		x = game->player.x + 1;
		y = game->player.y;
	}
	put_image_when_move(game, x, y);
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		player_move(keycode, game);
		ft_putnbr(game->walk++);
		write(1, "\n", 1);
	}
	return (0);
}
