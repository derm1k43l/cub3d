/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:27 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/15 13:30:47 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_default(t_map *map)
{
	map->res_x = RES_X;
	map->res_y = RES_Y;
	map->north_tx = NULL;
	map->south_tx = NULL;
	map->west_tx = NULL;
	map->east_tx = NULL;
	map->floor_color = COLOR_UNSET;
	map->ceiling_color = COLOR_UNSET;
	map->map_data = NULL;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->p = '0';
}
