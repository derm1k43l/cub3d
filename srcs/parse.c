/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:36:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/03 18:14:47 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_texture_and_color(int fd, t_map *map)
{
	char	*line;
	int		parse_done;


	parse_done = 0;
	while (42)
	{
		line = skip_empty_line(fd);
		if (line == NULL)
			break ;
		if (parse_texture(line, map) != 0 && parse_color(line, map) != 0)
		{
			if (line[0] == '1' || line[0] == ' ')
				parse_done = 1;
			else
				return (free(line), ft_printf("Error\nInvalid line: %s\n", line), 1);
		}
		if (parse_done)
			break ;
		free(line);
	}
	if (parse_done == 0)
		return (ft_printf("Error\nMissing map data.\n"), 1);
	else
		return (0);
}

int	parse_texture(char *line, t_map *map)
{
	static int	found[4] = {0};

	while (ft_is_whitespace(*line))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0 && !found[0])
		return (map->north_tx = ft_strdup(line + 3), found[0] = 1, 0);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !found[1])
		return (map->south_tx = ft_strdup(line + 3), found[1] = 1, 0);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !found[2])
		return (map->west_tx = ft_strdup(line + 3), found[2] = 1, 0);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !found[3])
		return (map->east_tx = ft_strdup(line + 3), found[3] = 1, 0);
	else
		return (1);
}

int	parse_color(char *line, t_map *map)
{
	static int	found[2] = {0};

	while (ft_is_whitespace(*line))
		line++;
	if (ft_strncmp(line, "F ", 2) == 0 && !found[0])
	{
		if (parse_color_value(line + 2, &map->floor_color))
			return (1);
		found[0] = 1;
		return (0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0 && !found[1])
	{
		if (parse_color_value(line + 2, &map->ceiling_color))
			return (1);
		found[1] = 1;
		return (0);
	}
	else
		return (1);
}

int	parse_map(int fd, t_map *map)
{
	char	*line;

	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '1' || line[0] == ' ')
			break ;
		free(line);
	}
	while (42)
	{
		process_map_line(map, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	return (0);
}

int parse_color_value(char *line, t_color *color)
{
    int r, g, b;

    r = ft_atoi(line);
    if (r < 0 || r > 255)
        return (1);

    while (*line && *line != ',')
        line++;
    if (*line != ',')
        return (1);
    line++;

    g = ft_atoi(line);
    if (g < 0 || g > 255)
        return (1);

    while (*line && *line != ',')
        line++;
    if (*line != ',')
        return (1);
    line++;

    b = ft_atoi(line);
    if (b < 0 || b > 255)
        return (1);

    color->r = r;
    color->g = g;
    color->b = b;
    return (0);
}
