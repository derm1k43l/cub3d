/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:10:15 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/01 12:55:37 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#define MAX_HEIGHT 500
#define MAX_WIDTH 500

#define RES_X 1920
#define RES_Y 1080

void	init_struct(t_map *map)
{
	map->res_x = RES_X;
	map->res_y = RES_Y;
	map->init = mlx_init(map->res_x, map->res_y, "Cub3D", true);
	if (!map->init)
		return (ft_printf("Error\nFail to init mlx"), exit(1));
	map->win = mlx_new_image(map->init, map->res_x, map->res_y);
	if(!map->win)
		return (ft_printf("Error\nFail to create window"), exit(1));
}

int	check_map_chars(char **mapd)
{
	int	i;
	int	j;

	i = 0;
	while (mapd[i])
	{
		j = 0;
		while (mapd[i][j])
		{
			if (mapd[i][j] != '1' && mapd[i][j] != '0' && mapd[i][j] != 'N' \
				&& mapd[i][j] != 'S' && mapd[i][j] != 'W' && mapd[i][j] != '\n'\
				&& mapd[i][j] != ' ' && mapd[i][j] != 'E')
				return (ft_printf("Error\nInvalid character in map.\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**get_map_data(int fd,int *height , int *width)
{
	int		i;
	char	*line;
	char	**map_data;

	i = 0;
	line = NULL;
	map_data = malloc(sizeof(char *) * MAX_HEIGHT);
	if (!map_data)
		return (ft_printf("Error\nFail to allocate memory.\n"), exit(1), NULL);
	while (42)
	{
		map_data[i] = malloc(sizeof(char) * MAX_WIDTH + 1);
		if (!map_data[i])
			return (ft_printf("Error\nFail to allocate mem.\n"), exit(1), NULL);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// remove trailgin spaces
		while (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == ' ')
			line[ft_strlen(line) - 1] = '\0';
		strncpy(map_data[i], line, MAX_WIDTH); // ft funcite replace
		map_data[i][MAX_WIDTH] = '\0';
		(*height)++;
		free(line);
		i++;
		if (i >= MAX_HEIGHT)
			return (ft_printf("Error\nMap is way too big.\n"), exit(1), NULL);
	}
	map_data[i] = NULL;
	*width = 0;
	while (map_data[0][*width])
		(*width)++;
	return (map_data);
}

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFail to open file.\n"), -1);
	return (fd);
}

int	check_map_struct(char **map_data)
{
	int		i;
	int		j;
	int		player;
	char	c;

	i = 0;
	player = 0;
	while (map_data[i])
	{
		j = 0;
		while (j < ft_strlen(map_data[i]))
		{
			c = map_data[i][j];
			if ((i == 0 || i == ft_strlen(*map_data) - 1 || j == 0 || j == ft_strlen(map_data[i]) - 1) && c != '1')
				return (ft_printf("Error\nInvalid map structure.\n"), 1);
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (ft_printf("Error\nInvalid player count.\n"), 1);
			// return (ft_printf("Error\nInvalid player count: %d (expected 1)\n", player), 1);
	return (0);
}
void	print_map_data(char **map_data)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		printf("%s\n", map_data[i]);
		i++;
	}
}

// void	read_map(char *file_name, t_map *map)
// {
// 	int		fd;
// 	int		width;
// 	int		height;
// 	char	**map_data;

// 	width = 0;
// 	height = 0;
// 	fd = open_file(file_name);
// 	map_data = get_map_data(fd, &height);
// 	if (!map_data)
// 		return (ft_printf("Error\nFail to read map data.\n"), exit(1));
// 	if (check_map_chars(map_data))
// 		return (ft_printf("Error\nInvalid map characters.\n"), exit(1));
// 	if (check_map_struct(map_data, width, height))
// 		return (ft_printf("Error\nInvalid map structure.\n"), exit(1));
// 	map->map_data = map_data;
// 	close(fd);
// }

void	read_map(char *file_name, t_map *map)
{
	int		fd;
	int		width;
	int		height;
	char	**map_data;

	width = 0;
	height = 0;
	fd = open_file(file_name);
	map_data = get_map_data(fd, &height, &width);
	if (!map_data)
	{
		print_map_data(map_data); // Print the map data before exiting
		return (ft_printf("Error\nFail to read map data.\n"), exit(1));
	}
	if (check_map_chars(map_data))
	{
		print_map_data(map_data); // Print the map data before exiting
		return (ft_printf("Error\nInvalid map characters.\n"), exit(1));
	}
	if (check_map_struct(map_data))
	{
		print_map_data(map_data); // Print the map data before exiting
		return (ft_printf("Error\nInvalid map structure.\n"), exit(1));
	}
	map->map_data = map_data;
	close(fd);
}


int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (ft_printf("Error\n Usage: ./cub3d <map>\n"), 1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_printf("Error\n Problem wiht memory for map."), 1);
	read_map(av[1], map);
	init_struct(map);
	// mlx image to window
	print_map_data(map->map_data);
	(void)ac;
	(void)av;
	return (0);
}
