/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:28 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/04 13:20:03 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		w;
	int		h;

	if (ac == 2)
	{
		game.map.line = "";
		game.map.row = 0;
		game.walk = 1;
		read_map(av[1], &game);
		check_map(&game);
		set_background(&game);
		make_map(&game, -1, &w, &h);
		start_game(&game);
	}
	return (0);
}
