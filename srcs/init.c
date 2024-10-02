/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:27 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/02 16:08:25 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_default(t_map *map)
{
	map->init = NULL;
	map->win = NULL;
	map->res_x = RES_X;
	map->res_y = RES_Y;
	map->north_tx = ft_strdup(DEFAULT_TEXTURE);
	map->south_tx = ft_strdup(DEFAULT_TEXTURE);
	map->west_tx = ft_strdup(DEFAULT_TEXTURE);
	map->east_tx = ft_strdup(DEFAULT_TEXTURE);
	map->floor_color = DEFAULT_COLOR;
	map->ceiling_color = DEFAULT_COLOR;
	map->map_data = NULL;
	map->height = 0;
}
