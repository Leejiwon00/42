/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:16:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/07/04 18:55:11 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	int	*visit;
	int	i;

	i = 0;
	visit = malloc (sizeof(int) * ft_strlen(game->map.line));
	if (!visit)
		exit(1);
	while (i < (int)ft_strlen(game->map.line))
	{
		visit[i] = 0;
		i++;
	}
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->valid = 0;
	if (game->map.row * (game->map.col + 1) - 1
		!= (int)ft_strlen(game->map.line))
		print_error(game, "The map must be rectangular!\n");
	check_char(game);
	check_closed(game);
	check_validpath(game, visit, game->player.x, game->player.y);
	free(visit);
	// for (int i=0;i<(int)ft_strlen(game->map.line); i++)
	// 	printf("%d ", visit[i]);
	if (!game->valid)
		print_error(game, "The map must have valid path!\n");
}

void	check_char(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.line[++i])
	{
		if (game->map.line[i] == 'P')
		{
			game->player.x
				= i - ((game->map.col + 1) * (i / (game->map.col + 1)));
			game->player.y = i / (game->map.col + 1);
			game->p++;
		}	
		else if (game->map.line[i] == 'C')
			game->c++;
		else if (game->map.line[i] == 'E')
			game->e++;
		if (game->map.line[i] != '0' && game->map.line[i] != '1'
			&& game->map.line[i] != 'P' && game->map.line[i] != 'C'
			&& game->map.line[i] != 'E' && game->map.line[i] != '\n')
			print_error(game, "Invalid character!\n");
	}
	if (game->p != 1 || game->c == 0 || game->e != 1)
		print_error(game, "The map must contain 1 E, at least 1 C, and 1 P!\n");
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

int	promising(t_game *game, int *visit, int x, int y)
{
	int	loc;

	loc = y * (game->map.col + 1) + x;
	if (game->map.line[loc] != '1' && !visit[loc])
	{
		if (game->map.line[loc] == 'C')
			game->c--;
		else if (game->map.line[loc] == 'E')
			game->e--;
		printf("x:%d y:%d loc:%d c:%d\n", x, y, loc, game->c);
		return (1);
	}
	return (0);
}

void	check_validpath(t_game *game, int *visit, int x, int y)
{
	int	loc;

	loc = y * (game->map.col + 1) + x;
	if (!game->c && !game->e)
	{
		game->valid = 1;
		return ;
	}
	// if (!game->e)
	// {
	// 	//printf("test %d %d\n", game->c, game->e);
	// 	game->e = 1;
	// 	return ;
	// }
	while (!visit[loc])
	{
		// printf("x:%d y:%d\n", x, y);
		// printf("c:%d\n", game->c);
		visit[loc] = 1;
		if (promising(game, visit, x + 1, y))
			check_validpath(game, visit, x + 1, y);
		if (promising(game, visit, x - 1, y))
			check_validpath(game, visit, x - 1, y);
		if (promising(game, visit, x, y + 1))
			check_validpath(game, visit, x, y + 1);
		if (promising(game, visit, x, y - 1))
			check_validpath(game, visit, x, y - 1);
	}
}
