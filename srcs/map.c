/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/03 18:17:53 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	read_map(char *file_name, t_map *map)
{
	int		fd;

	fd = open_file(file_name);
	memory_allocation(map);
	if (parse_texture_and_color(fd, map) != 0)
		return (close(fd), clean_map(map), exit(1));
	if (parse_map(fd, map) != 0)
		return (close(fd), clean_map(map), exit(1));
	close(fd);
	print_map_data(map); //debug
	if (check_map_validity(map) != 0)
		return (clean_map(map), exit(1));
}

int check_map_struct(char **map_data, int height, int width)
{
	int		i;
	int		j;
	int		player;
	char	c;

	i = 0;
	player = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			c = map_data[i][j];
			if ((i == 0 || i == height - 1 || j == 0 || j == width - 1) && c != '1')
			{
				ft_printf("Error: Invalid boundary at (%d, %d) - expected '1', got '%c'.\n", i, j, c);
				return (1);
			}
			if (ft_strchr("NSEW", c))
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (ft_printf("Error\nInvalid player count.\n"), 1);
	return (0);
}

int check_map_validity(t_map *map)
{
	int	width;

	width = 0;
	if (!map->map_data || !map->map_data[0])
	{
		ft_printf("Error\nMap data is not allocated.\n");
		return (1);
	}
	width = ft_strlen(map->map_data[0]);
	if (check_map_struct(map->map_data, map->height, width) != 0)
	{
		ft_printf("Error\nInvalid map structure.\n");
		return (1);
	}
	return (0);
}

void process_valid_line(t_map *map, char *line)
{
    int i;
    int j;

    i = 0;
    j = 0;
    map->map_data[map->height] = malloc(MAX_WIDTH * sizeof(char));
    if (!map->map_data[map->height])
    {
        printerr("Error\nFail to allocate memory for map data.\n");
        clean_map(map);
        exit(1);
    }
    while (line[i] && j < MAX_WIDTH - 1)
    {
        if (ft_is_whitespace(line[i]))
            map->map_data[map->height][j] = '1';
        else if (ft_strchr("01NSEW\n", line[i]))
            map->map_data[map->height][j] = line[i];
        else
        {
            ft_printf("Error\nInvalid character '%c' found at position %d in line: %s\n", line[i], i, line);
            clean_map(map);
            exit(1);
        }
        j++;
        i++;
    }
    map->map_data[map->height][j] = '\0';
    map->height++;
}

void	process_map_line(t_map *map, char *line)
{
	char	*trimmed_line;

	trimmed_line = ft_strtrim1(line);
    if (ft_strlen(trimmed_line) == 0)
	{
		free(trimmed_line);
		return;
	}
	if (map->height >= MAX_HEIGHT) 
	{
		printerr("Error: Map height exceeds maximum height.\n");
		clean_map(map);
		free(trimmed_line); // Handle memory allocation failure
		exit(1);
	}
	ft_printf("Processing line: %s\n", trimmed_line); //debug
	process_valid_line(map, trimmed_line);
	free(trimmed_line);
}
