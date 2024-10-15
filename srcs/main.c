/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:10:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/14 17:59:54 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	leaks()
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (printerr("Usage: ./cub3d <map>"), 1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (printerr("Problem wiht memory for map."), 1);
	init_default(map);
	read_map(av[1], map);
	clean_map(map);
	// atexit(leaks);
	// init_mlx(map);
	// mlx image to window
	return (0);
}
