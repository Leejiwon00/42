/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:37:28 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/06/19 19:45:20 by jiwonle2         ###   ########.fr       */
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

int	checkmap(char *map_name)
{
	int		start;
	int		fd;
	char	*map;
	char	*tmp;

	start = ft_strlen(map_name) - 4;
	if (!ft_strnstr(map_name + start, ".ber", 4))
	{
		write(1, "Invalid extension\n", 18);
		exit(1);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	map = "";
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		map = ft_strjoin(map, tmp);
	}
	printf("%s", map);
	return (0);
}
void ft_putchar(char c){
	write(1, &c, 1);
}
/*int deal_key(){
	ft_putchar('X');
	mlx_pixel_put(mlx_ptr,win_ptr)
	return (0);
}*/
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		checkmap(av[1]);
	}
	void	*mlx_ptr;
	void	*win_ptr;
	int width;
	int height;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_test");
	void *img=mlx_xpm_file_to_image(mlx_ptr, "./images/background.xpm",&width,&height);
	//mlx_key_hook(win_ptr, deal_key,(void*)0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 10,10);
	mlx_loop(mlx_ptr);
	
}
