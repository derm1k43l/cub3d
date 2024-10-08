/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:10:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/08 14:32:12 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[1;31mError\n\033[0mFail to open file: %s\n", file_name);
		exit(1);
	}
	if (!ft_strrchr(file_name, '.') || \
		ft_strncmp(ft_strrchr(file_name, '.'), ".cub", 4) != 0)
	{
		ft_printf("\033[1;31mError\n\033[0mInvalid extension: %s\n", file_name);
		exit(1);
	}
	return (fd);
}

char	*skip_empty_line(int fd)
{
	char	*input_line;
	char	*trimmed_line;
	char	*end;

	while (42)
	{
		input_line = get_next_line(fd);
		if (!input_line)
			return (NULL);
		trimmed_line = input_line;
		while (*trimmed_line && ft_is_whitespace(*trimmed_line))
			trimmed_line++;
		end = trimmed_line + ft_strlen(trimmed_line) - 1;
		while (end > trimmed_line && ft_is_whitespace(*end))
			end--;
		*(end + 1) = '\0';
		if (*trimmed_line)
		{
			if (trimmed_line != input_line)
			{
				trimmed_line = ft_strdup(trimmed_line);
				free(input_line);
			}
			return (trimmed_line);
		}
		free(input_line);
	}
}

void	store_map_line(t_map *map, char *line) // only incise j if we store?
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < MAX_WIDTH - 1)
	{
		if (line[i] == '\n')
		{
			i++;
			continue ;
		}
		else if (line[i] == ' ')
			map->map_data[map->height][j] = '1';
		else if (ft_strchr("01NSEW\n", line[i]))
			map->map_data[map->height][j] = line[i];
		j++;
		i++;
	}
	map->map_data[map->height][j] = '\0';
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
