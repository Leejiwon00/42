/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:28 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/23 20:07:47 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	n_len = ft_strlen(needle);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			if (j == n_len - 1)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

// void	checkmap(t_map *map)
// {
	
// }

void ft_putchar(char c){
	write(1, &c, 1);
}

void	player_move(int keycode, t_map *map)
{
	int	w;
	int	h;

	map->img = mlx_xpm_file_to_image(map->mlx, "./image/P.xpm", &w, &h);
	if (keycode == W)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->backimg,
			map->player.x * 64, map->player.y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img,
			(map->player.x - 1) * 64, map->player.y * 64);
	}
}

int	key_event(int keycode, t_map *map)
{
	printf("AAA");
	if (keycode == 53)
	{
		//free(map->mlx);
		//free(map->win);
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	//ft_putchar('a');
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
		player_move(keycode, map);
	}
	return (0);
}

void	start_game(t_map *map)
{
	mlx_key_hook(map->win, key_event, &map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		read_map(av[1], &map);
		set_background(&map);
		make_map(&map);
		//checkmap(&map);
		start_game(&map);
	}
	// void	*mlx_ptr;
	// void	*win_ptr;
	// // int		width;
	// // int		height;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	// //void *img=mlx_xpm_file_to_image(mlx_ptr, "./images/1.xpm",&width,&height);
	// //mlx_put_image_to_window(mlx_ptr, win_ptr, img, 100,100);
	// mlx_loop(mlx_ptr);
	
}
