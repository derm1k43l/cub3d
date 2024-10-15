/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:10:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/14 14:49:13 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*trim_whitespace(char *line)
{
	char	*trimed_line;
	char	*end;

	trimed_line = line;
	while (*trimed_line && ft_is_whitespace(*trimed_line))
		trimed_line++;
	end = trimed_line + ft_strlen(trimed_line) - 1;
	while (end > trimed_line && ft_is_whitespace(*end))
		end--;
	*(end + 1) = '\0';
	return (trimed_line);
}

char	*skip_empty_line(int fd)
{
	char	*input_line;
	char	*trimmed_line;

	while (42)
	{
		input_line = get_next_line(fd);
		if (!input_line)
			return (NULL);
		trimmed_line = trim_whitespace(input_line);
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

// in parsing map if we get empty line we exit
char	*gnl_noemptyline(int fd, t_map *map)
{
	char	*input_line;
	char	*trimmed_line;

	while (42)
	{
		input_line = get_next_line(fd);
		if (!input_line)
			return (NULL);
		trimmed_line = trim_whitespace(input_line);
		if (*trimmed_line == '\0')
		{
			printerr("Empty line in map.");
			free(input_line);
			clean_map(map);
			exit(1);
		}
		if (trimmed_line != input_line)
		{
			trimmed_line = ft_strdup(trimmed_line);
			free(input_line);
		}
		return (trimmed_line);
	}
}

