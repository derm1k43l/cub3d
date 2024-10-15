/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/14 11:53:58 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	if (check_boundary(map->map_data, map->height, width) != 0)
		return (printerr("Invalid map structure."), 1);
	if (check_player(map->map_data, map->height, width, map) != 0)
		return (printerr("Invalid player count."), 1);
	return (0);
}

// in the first and last ROW every character should be '1' or space
// in each line of the map the first and last character should be '1' or space
int	check_boundary(char **map_data, int height, int width)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < width)
	{
		if (j < ft_strlen(map_data[0]) && map_data[0][j] != '1')
			return (1);
		if (j < ft_strlen(map_data[height - 1]) \
			&& map_data[height - 1][j] != '1')
			return (1);
		j++;
	}
	while (i < height)
	{
		if (map_data[i][0] != '1')
			return (1);
		if (ft_strlen(map_data[i]) > 0 && \
			map_data[i][ft_strlen(map_data[i]) - 1] != '1')
			return (1);
		i++;
	}
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

void	check_texture_and_color(t_map *map)
{
	if (ft_strncmp(map->north_tx, "default.xpm", 11) == 0 || \
		ft_strncmp(map->south_tx, "default.xpm", 11) == 0 || \
		ft_strncmp(map->west_tx, "default.xpm", 11) == 0 || \
		ft_strncmp(map->east_tx, "default.xpm", 11) == 0)
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
