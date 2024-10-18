/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:26:39 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/18 15:35:41 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_pixel(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	find_wall(t_data *data, float x, float y)
{
	int	x_step;
	int	y_step;

	if (x < 0 || y < 0)
		return (0);
	x_step = floor(x / TILE);
	y_step = floor(y / TILE);
	if (x_step >= MAX_WIDTH || y_step >= MAX_HEIGHT)
		return (0);
	if (data->map->map_data[y_step] \
	&& x_step < ft_strlen(data->map->map_data[y_step]))
		if (data->map->map_data[y_step][x_step] == '1')
			return (0);
	return (1);
}

float	ft_h_ray(t_data *dt)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		unit_circle;

	unit_circle = 0;
	x_step = TILE / tan(dt->ray->ray_ngl);
	y_step = TILE;
	h_y = floor(dt->ply->plyr_y / TILE) * TILE;
	dt->pixel = ft_pixel(dt->ray->ray_ngl, &h_y, &y_step, 1);
	h_x = dt->ply->plyr_x + (h_y - dt->ply->plyr_y) \
		/ tan(dt->ray->ray_ngl);
	if (dt->ray->ray_ngl > (M_PI / 2) && dt->ray->ray_ngl < (3 * M_PI) / 2)
		unit_circle = 1;
	if ((unit_circle && x_step > 0) || (!unit_circle && x_step < 0))
		x_step *= -1;
	while (find_wall(dt, h_x, h_y - dt->pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
	dt->ray->hz_x = h_x;
	dt->ray->hz_y = h_y;
	return (ft_dis(h_x, dt->ply->plyr_x, h_y, dt->ply->plyr_y));
}

float	ft_v_ray(t_data *dt)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		unit_circle;

	unit_circle = 0;
	x_step = TILE;
	y_step = TILE * tan(dt->ray->ray_ngl);
	v_x = floor(dt->ply->plyr_x / TILE) * TILE;
	dt->pixel = ft_pixel(dt->ray->ray_ngl, &v_x, &x_step, 0);
	v_y = dt->ply->plyr_y + (v_x - dt->ply->plyr_x) \
		* tan(dt->ray->ray_ngl);
	if (dt->ray->ray_ngl > 0 && dt->ray->ray_ngl < M_PI)
		unit_circle = 1;
	if ((unit_circle && y_step < 0) || (!unit_circle && y_step > 0))
		y_step *= -1;
	while (find_wall(dt, v_x - dt->pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	dt->ray->vert_x = v_x;
	dt->ray->vert_y = v_y;
	return (ft_dis(v_x, dt->ply->plyr_x, v_y, dt->ply->plyr_y));
}

void	cast_rays_walls(t_data *data)
{
	double	h_ray;
	double	v_ray;
	int		ray;

	ray = 0;
	data->ray = ft_calloc(sizeof(t_ray), 1);
	data->ray->ray_ngl = data->ply->angle - (data->ply->fov_rd / 2);
	while (ray < data->map->res_x)
	{
		data->ray->flag = 0;
		data->ray->ray_ngl = check_angle(data->ray->ray_ngl);
		h_ray = ft_h_ray(data);
		v_ray = ft_v_ray(data);
		if (v_ray <= h_ray)
			data->ray->distance = v_ray;
		else
		{
			data->ray->distance = h_ray;
			data->ray->flag = 1;
		}
		render(data, ray);
		ray++;
		data->ray->ray_ngl += (data->ply->fov_rd / data->map->res_x);
	}
}
