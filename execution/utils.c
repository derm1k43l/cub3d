/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:37:16 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:03 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

float	check_angle(float angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

double	ft_dis(float x1, int x2, float y1, int y2)
{
	double	dis_one;
	double	dis_two;

	dis_one = pow(x1 - x2, 2);
	dis_two = pow(y1 - y2, 2);
	return (sqrt(dis_one + dis_two));
}

double	calc_wall_height(t_data *dt)
{
	double	wall_height;

	wall_height = (TILE / dt->ray->distance) * (dt->map->res_x / 2);
	return (wall_height);
}

mlx_texture_t	*set_texture(t_data *dt)
{
	if (dt->ray->flag == 0)
	{
		if (dt->ray->ray_ngl > M_PI / 2 && dt->ray->ray_ngl < 3 * (M_PI / 2))
			return (dt->text_ea);
		else
			return (dt->text_we);
	}
	else
	{
		if (dt->ray->ray_ngl > 0 && dt->ray->ray_ngl < M_PI)
			return (dt->text_so);
		else
			return (dt->text_no);
	}
}
