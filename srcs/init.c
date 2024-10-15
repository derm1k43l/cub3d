/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:27 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/14 15:25:23 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_default(t_map *map)
{
	map->init = NULL;
	map->win = NULL;
	map->res_x = RES_X;
	map->res_y = RES_Y;
	map->north_tx = ft_strdup("default.xpm");
	map->south_tx = ft_strdup("default.xpm");
	map->west_tx = ft_strdup("default.xpm");
	map->east_tx = ft_strdup("default.xpm");
	map->floor_color = COLOR_UNSET;
	map->ceiling_color = COLOR_UNSET;
	map->map_data = NULL;
	map->height = 0;
	map->player_x = -1;
	map->player_y = -1;
	map->p = '0';
}
