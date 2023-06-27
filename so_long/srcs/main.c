/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:28 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/27 18:21:55 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	start_game(t_game *game)
{
	mlx_key_hook(game->win, key_event, game);
	mlx_loop(game->mlx);
}
void leak()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_game	game;
	int		w;
	int		h;

	//atexit(leak);
	if (ac == 2)
	{
		read_map(av[1], &game);
		set_background(&game);
		make_map(&game, -1, &w, &h);
		check_map(&game);
		start_game(&game);
	}
}
