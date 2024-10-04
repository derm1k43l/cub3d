/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:02:44 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/04 10:58:22 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_data)
	{
		while (map->map_data[i])
		{
			free(map->map_data[i]);
			i++;
		}
		free(map->map_data);
	}
	if (map->north_tx)
		free(map->north_tx);
	if (map->south_tx)
		free(map->south_tx);
	if (map->west_tx)
		free(map->west_tx);
	if (map->east_tx)
		free(map->east_tx);
	free(map);
}

void	printerr(char *msg)
{
	write(2, "\033[1;31mError\n\033[0m%s\n", 18);
	write(2, msg, ft_strlen(msg));
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
	ft_printf("Printing map data:\n");
	ft_printf("res_x: %d, res_y: %d\n", RES_X, RES_Y);
	ft_printf("north_tx: %s\n", map->north_tx);
	ft_printf("south_tx: %s\n", map->south_tx);
	ft_printf("west_tx: %s\n", map->west_tx);
	ft_printf("east_tx: %s\n", map->east_tx);
	ft_printf("floor_color: %d\n", map->floor_color);
	ft_printf("ceiling_color: %d\n", map->ceiling_color);
	ft_printf("height: %d\n", map->height);
	while (map->map_data[i])
	{
		printf("%s\n", map->map_data[i]);
		i++;
	}
}
