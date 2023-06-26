/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:16:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/26 20:32:28 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	check_map(t_game *game)
{
	int	i;

	i = -1;
	game->p = 0;
	game->c = 0;
	game->e = 0;
	while (game->map.line[++i])
	{
		if (game->map.line[i] == 'P')
			game->p++;
		else if (game->map.line[i] == 'C')
			game->c++;
		else if (game->map.line[i] == 'E')
			game->e++;
	}
	if (game->p != 1 || game->c == 0 || game->e != 1)
		print_error("Invalid map\n");
	check_closed(game);
	check_validpath(game, game->player.x, game->player.y);
}

void	check_closed(t_game *game)
{
	int	loc;
	int	i;

	i = 0;
	while (i < game->map.col)
	{
		loc = (game->map.col + 1) + i;
		if (game->map.line[loc] != '1')
			print_error("The map must be closed by walls!\n");
		i++;
	}
}

int	promising(t_game *game, int x, int y)
{
	int	loc;

	loc = y * (game->map.col + 1) + x;
	if (game->map.line[loc] != '1')
	{
		if (game->map.line[loc] == 'P')
			game->p--;
		else if (game->map.line[loc] == 'C')
			game->c--;
		else if (game->map.line[loc] == 'E')
			game->e--;
		return (1);
	}	
	return (0);
}

void	check_validpath(t_game *game, int x, int y)
{
	if (!game->p && !game->c && !game->e) // valid
	{
		printf("AAA\n");
		write(1, "Valid Map!!\n", 12);
		exit(0);
	}
	printf("x:%d y:%d", x, y);
	while ((x >= 0 && x < game->map.col) && (y >= 0 && y < game->map.row))
	{
		if (promising(game, x + 1, y))
			check_validpath(game, x + 1, y);
		else if (promising(game, x - 1, y))
			check_validpath(game, x - 1, y);
		else if (promising(game, x, y + 1))
			check_validpath(game, x, y + 1);
		else if (promising(game, x, y - 1))
			check_validpath(game, x, y - 1);
	}
}
