/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/08 14:19:11 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// open file and alcoat memory for map_data
// check for texture and color
// parse map data
// check map validity
void	read_map(char *file_name, t_map *map)
{
	int		fd;
	char	*first_map_line;

	fd = open_file(file_name);
	memory_allocation(map);
	first_map_line = parse_texture_and_color(fd, map);
	if (first_map_line == NULL)
		return (close(fd), clean_map(map), exit(1));
	if (parse_map(fd, map, first_map_line) != 0)
		return (close(fd), clean_map(map), exit(1));
	close(fd);
	print_map_data(map); //debug
	if (check_map_validity(map) != 0)
		return (clean_map(map), exit(1));
}

int	check_map_validity(t_map *map)
{
	int	width;
	int	i;
	int	line_width;

	width = 0;
	i = 0;
	if (!map->map_data || !map->map_data[0])
		return (ft_printf("Error\nMap data is not allocated.\n"), 1);
	while (i < map->height)
	{
		line_width = ft_strlen(map->map_data[i]);
		if (line_width > width)
			width = line_width;
		i++;
	}
	ft_printf("Calculated map width: %d\n", width); // debug we dont care about width just to impose a limit
	if (check_boundary(map->map_data, map->height, width) != 0)
		return (ft_printf("Error\nInvalid map structure.\n"), 1);
	if (check_player(map->map_data, map->height, width) != 0)
		return (ft_printf("Error\nInvalid player count.\n"), 1);
	return (0);
}

int	check_boundary(char **map_data, int height, int width) // no need to print the error message just return 1
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < width)
	{
		if (j < ft_strlen(map_data[0]) && map_data[0][j] != '1' && map_data[0][j] != ' ')
		{
			ft_printf("\nError: Invalid boundary at (0, %d) - expected '1', got '%c'.\n", j, map_data[0][j]);
			return (1);
		}
		if (j < ft_strlen(map_data[height - 1]) && map_data[height - 1][j] != '1' && map_data[height - 1][j] != ' ')
		{
			ft_printf("\nError: Invalid boundary at (%d, %d) - expected '1', got '%c'.\n", height - 1, j, map_data[height - 1][j]);
			return (1);
		}
		j++;
	}
	while (i < height)
	{
		if (map_data[i][0] != '1' && map_data[i][0] != ' ')         // Check the first column
		{
			ft_printf("\nError: Invalid boundary at (%d, 0) - expected '1', got '%c'.\n", i, map_data[i][0]);
			return (1);
		}
		if (ft_strlen(map_data[i]) > 0 && map_data[i][ft_strlen(map_data[i]) - 1] != '1' && map_data[i][ft_strlen(map_data[i]) - 1] != ' ')
		{
			ft_printf("\nError: Invalid boundary at (%d, %zu) - expected '1', got '%c'.\n", i, ft_strlen(map_data[i]) - 1, map_data[i][ft_strlen(map_data[i]) - 1]);
			return (1);
		}
		i++;
	}
	return (0);
}

// Check if there is only one player in the map
// only check the inner part of the map (star from 1 and go until -1)
int	check_player(char **map_data, int height, int width)
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
				ft_printf("Player found at (%d, %d) - direction: %c\n", i, j, map_data[i][j]); //debug delet after
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}
