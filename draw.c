/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:43:21 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/16 15:36:54 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	median;

	x = 0;
	median = data->map->res_y / 2;

	while (x < data->map->res_x)
	{
		y = 0;
		while (y < median)
		{
			mlx_put_pixel(data->img, x, y, data->map->ceiling_color);
			mlx_put_pixel(data->img, x, data->map->res_y \
				- 1 - y, data->map->floor_color);
			y++;
		}
		x++;
	}
}

double	calc_wall_height(t_data *data)
{
	double	wall_height;

	wall_height = (SQUARE_SIZE / data->ray->distance) * (data->map->res_x / 2);
	return (wall_height);
}

mlx_texture_t	*set_texture(t_data *data)
{
	if (data->ray->ray_ngl < 0)
		data->ray->ray_ngl += 2 * M_PI;
	if (data->ray->ray_ngl > 2 * M_PI)
		data->ray->ray_ngl -= 2 * M_PI;
	if (data->ray->flag == 0)
	{
		if (data->ray->ray_ngl > M_PI / 2 && data->ray->ray_ngl < 3 * (M_PI / 2))
			return (data->text_ea);
		else
			return (data->text_we);
	}
	else
	{
		if (data->ray->ray_ngl > 0 && data->ray->ray_ngl < M_PI)
			return (data->text_so);
		else
			return (data->text_no);
	}
}
