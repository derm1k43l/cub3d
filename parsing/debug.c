/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:09:55 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/17 12:24:29 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	print_map_copy(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < MAX_WIDTH && map->map_copy[i][j])
		{
			ft_printf("%c", map->map_copy[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
