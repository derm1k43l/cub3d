/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:10:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/04 15:32:09 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_mlx(t_map *map)
{
	map->init = mlx_init(map->res_x, map->res_y, "Cub3D", true);
	if (!map->init)
		return (ft_printf("Error\nFail to init mlx"), exit(1));
	map->win = mlx_new_image(map->init, map->res_x, map->res_y);
	if (!map->win)
		return (ft_printf("Error\nFail to create window"), exit(1));
}

void leaks()
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (ft_printf("Error\n Usage: ./cub3d <map>\n"), 1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_printf("Error\n Problem wiht memory for map."), 1);
	init_default(map);
	read_map(av[1], map);
	// atexit(leaks);
	// init_mlx(map);
	// mlx image to window
	return (0);
}
