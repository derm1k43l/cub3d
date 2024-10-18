/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:29:35 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/18 15:26:17 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// devide the y (vertical) by 2 to get the median
// from 0 to the median we draw pixel by pixel the ceiling
// from the median to the end we draw pixel by pixel the floor
// we use a mirror effect to draw the ceiling and the floor at the same time
void	draw_floor_ceiling(t_data *dt)
{
	int	x;
	int	y;
	int	median;

	x = 0;
	median = dt->map->res_y / 2;
	while (x < dt->map->res_x)
	{
		y = 0;
		while (y < median)
		{
			mlx_put_pixel(dt->img, x, y, dt->map->ceiling_color);
			mlx_put_pixel(dt->img, x, dt->map->res_y \
				- 1 - y, dt->map->floor_color);
			y++;
		}
		x++;
	}
}

void	my_pixel_put(t_data *dt, int x, int y, uint32_t color)
{
	if (x < 0 || x >= dt->map->res_x)
		return ;
	if (y < 0 && y >= dt->map->res_y)
		return ;
	mlx_put_pixel(dt->img, x, y, color);
}

void	display_wall(t_data *dt, int top_pix, int bottom_pix, double wall_h)
{
	double		x_o;
	double		y_o;
	double		factor;
	uint32_t	color;

	color = 0;
	dt->text = set_texture(dt);
	factor = (double)dt->text->height / wall_h;
	if (dt->ray->flag == 1)
		x_o = (int)fmodf((dt->ray->hz_x * (dt->text->width / TILE)), \
			dt->text->width);
	else
		x_o = (int)fmodf((dt->ray->vert_y * (dt->text->width / TILE)), \
			dt->text->width);
	y_o = (top_pix - (dt->map->res_y / 2) + (wall_h / 2)) * factor;
	x_o = fmax(0, x_o);
	y_o = fmax(0, y_o);
	while (top_pix < bottom_pix)
	{
		color = ((uint32_t *)dt->text->pixels)[(int)y_o * \
			dt->text->width + (int)x_o];
		my_pixel_put(dt, dt->ray->i, top_pix, reverse_bytes(color));
		y_o += factor;
		top_pix++;
	}
}

void	render(t_data *dt, int ray)
{
	double	wall_h;
	double	bottom_pix;
	double	top_pix;

	dt->ray->distance *= cos(check_angle(dt->ray->ray_ngl - dt->ply->angle));
	wall_h = calc_wall_height(dt);
	bottom_pix = (dt->map->res_y / 2) + (wall_h / 2);
	top_pix = (dt->map->res_y / 2) - (wall_h / 2);
	if (bottom_pix > dt->map->res_y)
		bottom_pix = dt->map->res_y;
	if (top_pix < 0)
		top_pix = 0;
	dt->ray->i = ray;
	display_wall(dt, top_pix, bottom_pix, wall_h);
}
