/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:10:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/04 18:07:02 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printerr("Error\nFail to open file: \n");
		printerr(file_name);
		printerr("\n");
		exit(1);
	}
	return (fd);
}

char	*skip_empty_line(int fd)
{
	char	*line;
	char	*trimmed_line;
	char	*end;

	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		trimmed_line = line;
		while (*trimmed_line && ft_is_whitespace(*trimmed_line))
			trimmed_line++;
		end = trimmed_line + ft_strlen(trimmed_line) - 1;
		while (end > trimmed_line && ft_is_whitespace(*end))
			end--;
		*(end + 1) = '\0';
		if (*trimmed_line)
		{
			if (trimmed_line != line)
			{
				trimmed_line = ft_strdup(trimmed_line);
				free(line);
			}
			return (trimmed_line);
		}
		free(line);
	}
}

void	memory_allocation(t_map *map)
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
