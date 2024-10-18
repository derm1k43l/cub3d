/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/17 12:24:19 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map_validity(t_map *map)
{
	int	width;
	int	i;
	int	line_width;

	width = 0;
	i = 0;
	while (i < map->height)
	{
		line_width = ft_strlen(map->map_data[i]);
		if (line_width > width)
			width = line_width;
		i++;
	}
	copy_map(map);
	if (check_player(map->map_data, map->height, width, map) != 0)
		return (printerr("Invalid player count."), 1);
	if (flood_fill(map, map->player_x, map->player_y) != 0)
		return (printerr("Map is not closed."), 1);
	return (0);
}

// Check if there is only one player in the map
// only check the inner part of the map (star from 1 and go until -1)
int	check_player(char **map_data, int height, int width, t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 1;
	player = 0;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map_data[i][j] == 'N' || map_data[i][j] == 'S' \
				|| map_data[i][j] == 'E' || map_data[i][j] == 'W')
			{
				player++;
				add_player(map, i, j);
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

void	add_player(t_map *map, int i, int j)
{
	map->player_x = j;
	map->player_y = i;
	map->p = map->map_data[i][j];
}

// check boundary, of the map for x and y then check char at
// x and y if it is 1 or V (visited) if not return 0
int	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= MAX_WIDTH || y < 0 || y >= map->height)
		return (1);
	if (map->map_copy[y][x] == '1' || map->map_copy[y][x] == 'V')
		return (0);
	map->map_copy[y][x] = 'V';
	if (flood_fill(map, x + 1, y) != 0)
		return (1);
	if (flood_fill(map, x - 1, y) != 0)
		return (1);
	if (flood_fill(map, x, y + 1) != 0)
		return (1);
	if (flood_fill(map, x, y - 1) != 0)
		return (1);
	return (0);
}

void	check_texture_and_color(t_map *map)
{
	if (map->north_tx == NULL || map->south_tx == NULL || \
		map->west_tx == NULL || map->east_tx == NULL)
	{
		printerr("Invalid texture path.");
		clean_map(map);
		exit(1);
	}
	if (map->floor_color == COLOR_ERROR || map->ceiling_color == COLOR_ERROR || \
		map->floor_color == COLOR_UNSET || map->ceiling_color == COLOR_UNSET)
	{
		printerr("Invalid color value.");
		clean_map(map);
		exit(1);
	}
}
