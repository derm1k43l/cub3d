/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:44 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/15 13:36:16 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map_data)
		{
			while (i < MAX_HEIGHT)
			{
				if (map->map_data[i])
				{
					free(map->map_data[i]);
					map->map_data[i] = NULL;
				}
				i++;
			}
			free(map->map_data);
			map->map_data = NULL;
		}
	}
	clean_txt(map);
}

void	clean_txt(t_map *map)
{
	if (map->north_tx)
	{
		free(map->north_tx);
		map->north_tx = NULL;
	}
	if (map->south_tx)
	{
		free(map->south_tx);
		map->south_tx = NULL;
	}
	if (map->west_tx)
	{
		free(map->west_tx);
		map->west_tx = NULL;
	}
	if (map->east_tx)
	{
		free(map->east_tx);
		map->east_tx = NULL;
	}
}

void	printerr(char *msg)
{
	write(2, "\033[1;31mError\n\033[0m", 17);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\r' || c == '\f' || c == '\v');
}

//debug
void	print_map_data(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("---------------------------------------\n");
	ft_printf("north_tx: %s\n", map->north_tx);
	ft_printf("south_tx: %s\n", map->south_tx);
	ft_printf("west_tx: %s\n", map->west_tx);
	ft_printf("east_tx: %s\n", map->east_tx);
	ft_printf("floor_color: %u\n", map->floor_color);
	ft_printf("ceiling_color: %u\n", map->ceiling_color);
	ft_printf("height: %d\n", map->height);
	ft_printf("player_x: %d, player_y: %d\n", map->player_x, map->player_y);
	ft_printf("p: %c\n", map->p);
	while (i < MAX_HEIGHT && map->map_data[i])
	{
		printf("%s\n", map->map_data[i]);
		i++;
	}
	ft_printf("---------------------------------------\n");
}
