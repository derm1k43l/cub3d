/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:36:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/15 18:02:23 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// get the trimmed line and stop if EOF
// check for the 6 identifiers and store them
// if we get 1 we finish and check for them to be different from default
// if we get -1 we print already did clean and print we just return null
// if we get 0 we keep going the loop until we get 1 or -1
// if we finish but don't get 1 means we didn't get all the identifiers
char	*parse_texture_and_color(int fd, t_map *map)
{
	char	*line;
	int		flag;

	while (42)
	{
		line = skip_empty_line(fd);
		if (line == NULL)
			break ;
		flag = set_values(line, map);
		if (flag == 1)
			return (check_texture_and_color(map), line);
		else if (flag == -1)
			return (NULL);
		free(line);
	}
	printerr("Missing identifiers/no map data.");
	clean_map(map);
	return (NULL);
}

int	set_values(char *line, t_map *map)
{
	static int	found[6] = {0};

	if (line[0] == '1')
		return (1);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && !found[0])
		return (map->north_tx = ft_strdup(line + 3), found[0] = 1, 0);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && !found[1])
		return (map->south_tx = ft_strdup(line + 3), found[1] = 1, 0);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && !found[2])
		return (map->west_tx = ft_strdup(line + 3), found[2] = 1, 0);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && !found[3])
		return (map->east_tx = ft_strdup(line + 3), found[3] = 1, 0);
	else if (line[0] == 'F' && line[1] == ' ' && !found[4])
		return (map->floor_color = parse_color(line + 2), found[4] = 1, 0);
	else if (line[0] == 'C' && line[1] == ' ' && !found[5])
		return (map->ceiling_color = parse_color(line + 2), found[5] = 1, 0);
	else
	{
		printerr("Invalid texture path.");
		free(line);
		clean_map(map);
		return (-1);
	}
}

// we return bitshift with alpha 255
uint32_t	parse_color(char *line)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	ptr = line;
	r = ft_atoi(ptr);
	ptr = ft_strchr(ptr, ',');
	if (!ptr)
		return (COLOR_ERROR);
	ptr++;
	g = ft_atoi(ptr);
	ptr = ft_strchr(ptr, ',');
	if (!ptr)
		return (COLOR_ERROR);
	ptr++;
	b = ft_atoi(ptr);
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	if (*ptr != '\0')
		return (COLOR_ERROR);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (COLOR_ERROR);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
