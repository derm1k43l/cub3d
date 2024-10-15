/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:44 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/14 17:56:12 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
					printf("Freed row %d\n", i);
					map->map_data[i] = NULL;
				}
				i++;
			}
			free(map->map_data);
			map->map_data = NULL;
			ft_printf("Freed map_data array.\n"); //debug
		}
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
	while (map->map_data[i])
	{
		printf("%s\n", map->map_data[i]);
		i++;
	}
	ft_printf("---------------------------------------\n");
}
