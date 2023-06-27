/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:16:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/27 20:38:44 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	check_map(t_game *game)
{
	int	*visit;
	int	i;

	i = -1;
	visit = malloc (sizeof(int) * ft_strlen(game->map.line));
	for (int i=0;i<(int)ft_strlen(game->map.line);i++)
		visit[i] = 0;
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
		print_error(game, "Invalid map\n");
	if (game->map.row * (game->map.col + 1) - 1
		!= (int)ft_strlen(game->map.line))
		print_error(game, "The map must be rectangular!");
	check_closed(game);
	check_validpath(game, &visit, game->player.x, game->player.y);
}

void	check_closed(t_game *game)
{
	int	loc;
	int	i;

	i = 0;
	while (i < game->map.col)
	{
		loc = (game->map.row - 1) * (game->map.col + 1) + i;
		if (game->map.line[i] != '1' || game->map.line[loc] != '1')
			print_error(game, "The map must be closed by walls!\n");
		i++;
	}
	i = 1;
	while (i < game->map.row - 1)
	{
		loc = i * (game->map.col + 1) + game->map.col - 1;
		if (game->map.line[i * (game->map.col + 1)] != '1'
			|| game->map.line[loc] != '1')
			print_error(game, "The map must be closed by walls!\n");
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

void	check_validpath(t_game *game, int **visit, int x, int y)
{
	int	loc;

	loc = y * (game->map.col + 1) + x;
	if (!game->p && !game->c && !game->e)
	{
		write(1, "VALID MAP!\n", 11);
		exit(0);
	}
	while (!(*visit)[loc])
	{
		(*visit)[loc] = 1;
		printf("a\n");
		if (promising(game, x + 1, y))
		{
			check_validpath(game, visit, x + 1, y);
		}
		else if (promising(game, x - 1, y))
			check_validpath(game, visit, x - 1, y);
		else if (promising(game, x, y + 1))
			check_validpath(game, visit, x, y + 1);
		else if (promising(game, x, y - 1))
			check_validpath(game, visit, x, y - 1);
	}
}
