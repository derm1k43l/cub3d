/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:19:47 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/15 13:39:34 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (close(fd), exit(1));
	if (parse_map(fd, map, first_map_line) != 0)
		return (close(fd), clean_map(map), exit(1));
	close(fd);
	if (check_map_validity(map) != 0)
		return (clean_map(map), exit(1));
	// print_map_data(map); //debug
}

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printerr("Fail to open file:");
		ft_printf("%s\n", file_name);
		exit(1);
	}
	if (!ft_strrchr(file_name, '.') || \
		ft_strncmp(ft_strrchr(file_name, '.'), ".cub", 4) != 0)
	{
		printerr("Invalid extension! We expect .cub");
		ft_printf("You gave: %s\n", file_name);
		exit(1);
	}
	return (fd);
}

int	memory_allocation(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_data = ft_calloc((MAX_HEIGHT), sizeof(char *));
	if (!map->map_data)
		return (printerr("Error\nFail to allocate memory for map data."), \
			clean_map(map), exit(1), 1);
	while (i < MAX_HEIGHT)
	{
		map->map_data[i] = ft_calloc((MAX_WIDTH), sizeof(char));
		if (!map->map_data[i])
			return (printerr("Error\nFail to allocate memory for map data."), \
				clean_map(map), exit(1), 1);
		j = 0;
		while (j < MAX_WIDTH)
		{
			map->map_data[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (0);
}

// call store map line for firt line we got
// enter a loop to read the "secound part of map"
// we store the line if corect char and height++
// only the last map line should be NULL rest is '\0'
int	parse_map(int fd, t_map *map, char *first_map_line)
{
	char	*line;

	store_map_line(map, first_map_line);
	map->height++;
	free(first_map_line);
	while (42)
	{
		line = gnl_noemptyline(fd, map);
		if (!line)
			break ;
		if (map->height > MAX_HEIGHT)
			return (printerr("Map height exceeds max height."), 1);
		store_map_line(map, line);
		free(line);
		map->height++;
	}
	return (0);
}

// as long as the width is less than MAX_WIDTH and the line is not empty
// if the char is space we repalce with 1
// if the char is valid we store it, else error, clean and ciao
// we set the last char of the line to '\0' and increment heigh
void	store_map_line(t_map *map, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < MAX_WIDTH)
	{
		if (line[i] == ' ')
			map->map_data[map->height][j] = '1';
		else if (ft_strchr("01NSEW\n", line[i]))
			map->map_data[map->height][j] = line[i];
		else
		{
			printerr("Invalid character in map.");
			clean_map(map);
			exit(1);
		}
		j++;
		i++;
	}
	map->map_data[map->height][j] = '\0';
}
