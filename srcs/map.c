/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:59:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/04 18:10:52 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	check_map_struct(char **map_data, int height, int width)
{
	int		i;
	int		j;
	int		player;
	char	c;

	i = 0;
	player = 0;
	ft_printf("Debugging map structure:\n");
	ft_printf("Height: %d, Width: %d\n", height, width);
	while (i < height)
	{
	j = 0;
		ft_printf("Line %d: ", i);
		while (j < width)
		{
			if (j < ft_strlen(map_data[i]))
				c = map_data[i][j];
			else
				c = ' ';  // Treat beyond end of line as space
			ft_printf("%c", c);
			if ((i == 0 || i == height - 1 || j == 0 || j == width - 1) && c != '1' && c != ' ')
			{
				ft_printf("\nError: Invalid boundary at (%d, %d) - expected '1' or ' ', got '%c'.\n", i, j, c);
				return (1);
			}
			if (ft_strchr("NSEW", c))
			{
				player++;
				ft_printf("\nPlayer found at (%d, %d) - direction: %c\n", i, j, c);
			}
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("Total player count: %d\n", player);
	if (player != 1)
	{
		ft_printf("Error\nInvalid player count: %d\n", player);
		return (1);
	}
	return (0);
}

int	check_map_validity(t_map *map)
{
	int	width;
	int	i;

	if (!map->map_data || !map->map_data[0])
	{
		ft_printf("Error\nMap data is not allocated.\n");
		return (1);
	}
    // Calculate the maximum width
	width = 0;
	for (i = 0; i < map->height; i++)
	{
		int line_width = ft_strlen(map->map_data[i]);
		if (line_width > width)
			width = line_width;
	}
	ft_printf("Calculated map width: %d\n", width);
	if (check_map_struct(map->map_data, map->height, width) != 0)
	{
		ft_printf("Error\nInvalid map structure.\n");
		return (1);
	}
	return (0);
}

void	process_valid_line(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < MAX_WIDTH - 1)
	{
		if (ft_is_whitespace(line[i]))
			map->map_data[map->height][j] = ' ';
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
}

void	process_map_line(t_map *map, char *line)
{
	if (map->height >= MAX_HEIGHT)
	{
		printerr("Error: Map height exceeds maximum height.\n");
		clean_map(map);
		exit(1);
	}
	map->map_data[map->height] = malloc((MAX_WIDTH + 1) * sizeof(char));
	if (!map->map_data[map->height])
	{
		printerr("Error\nFail to allocate memory for map data.\n");
		clean_map(map);
		exit(1);
	}
	ft_printf("Processing line: %s\n", line); //debug
	process_valid_line(map, line);
	map->height++;
}
