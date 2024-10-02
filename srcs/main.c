/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:10:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/02 16:53:58 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	process_valid_line(t_map *map, char *line)
{
	int	i;
	int	j;

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

int	parse_texture_color(char *line, t_map *map)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->north_tx = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		map->south_tx = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		map->west_tx = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		map->east_tx = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		map->floor_color = ft_atoi(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		map->ceiling_color = ft_atoi(line + 2);
	else
		return (1);
	return (0);
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

void memory_allocation(t_map *map)
{
	int	i;

	i = 0;
	map->map_data = malloc((MAX_HEIGHT + 1) * sizeof(char *));
	if (!map->map_data)
	{
		ft_printf("Error\nFail to allocate memory for map data.\n");
		clean_map(map);
		exit(1);
	}
	while (i < MAX_HEIGHT + 1)
	{
		map->map_data[i] = NULL;
		i++;
	}
}

void	read_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	int		is_map;

	is_map = 0;
	fd = open_file(file_name);
	memory_allocation(map);
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!is_map && parse_texture_color(line, map))
		{
			if (line[0] == '1')
				is_map = 1;
		}
		if (is_map)
			process_map_line(map, line);
		free(line);
	}
	close(fd);
	print_map_data(map); //debug
	if (check_map_validity(map) != 0)
		return (clean_map(map), exit(1));
}

void	init_mlx(t_map *map)
{
	map->init = mlx_init(map->res_x, map->res_y, "Cub3D", true);
	if (!map->init)
		return (ft_printf("Error\nFail to init mlx"), exit(1));
	map->win = mlx_new_image(map->init, map->res_x, map->res_y);
	if (!map->win)
		return (ft_printf("Error\nFail to create window"), exit(1));
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
	// init_mlx(map);
	// mlx image to window
	return (0);
}
