/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:29:35 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/16 15:50:42 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, uint32_t color)
{
	if (x > 0 && x < data->map->res_x && y > 0 && y < data->map->res_y)
		mlx_put_pixel(data->img, x, y, color);
}

void display_wall(t_data *data, int ray, int top_pix, int bottom_pix, double wall_h)
{
	double x_o;
	double y_o;
	double factor;
	uint32_t color;

	color = 0;
	data->texture = set_texture(data);
	factor = (double)data->texture->height / wall_h;
	if (data->ray->flag == 1)
		x_o = (int)fmodf((data->ray->horiz_x * (data->texture->width / SQUARE_SIZE)), data->texture->width);
	else
		x_o = (int)fmodf((data->ray->vert_y * (data->texture->width / SQUARE_SIZE)), data->texture->width);
	y_o = (top_pix - (data->map->res_y / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (top_pix < bottom_pix)
	{
		color = ((uint32_t *)data->texture->pixels)[(int)y_o * data->texture->width + (int)x_o];
		my_mlx_pixel_put(data, ray, (int)top_pix, reverse_bytes(color));
		y_o += factor;
		top_pix++;
	}
}

void render(t_data *data, int ray)
{
	double wall_h;
	double bottom_pix;
	double top_pix;
	double ray_angle;

	ray_angle = data->ray->ray_ngl - data->ply->angle;
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	else if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	data->ray->distance *= cos(ray_angle);
	wall_h = calc_wall_height(data);
	bottom_pix = (data->map->res_y / 2) + (wall_h / 2);
	top_pix = (data->map->res_y / 2) - (wall_h / 2);
	if (bottom_pix > data->map->res_y)
		bottom_pix = data->map->res_y;
	if (top_pix < 0)
		top_pix = 0;
	display_wall(data, ray, top_pix, bottom_pix, wall_h);
}
