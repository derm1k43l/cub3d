/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:42:12 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/07 15:28:02 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cast_rays(t_mlx *mlx)
{

	int color = 0x00FF00;
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			mlx_put_pixel(mlx->img, i, j, color);
		}
	}
}

void	game_loop(void	*pointer)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)pointer;
	// if (mlx->img)
	// 	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, 50, 50);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
}

// void	get_angle(t_mlx *mlx)
// {
// 	mlx->ply->angle = M_PI;
// 	mlx->ply->plyr_x = (mlx->dt->p_x * TILE_SIZE) + TILE_SIZE / 2;
// 	mlx->ply->plyr_y = (mlx->dt->p_y * TILE_SIZE) + TILE_SIZE / 2;
// 	mlx->ply->fov_rd = (FOV * M_PI / 180);
// }

// void	execution(t_map *data)
// {
// 	t_mlx	mlx;

// 	mlx.dt = data;
// 	mlx.ply = malloc(sizeof(t_player));
// 	mlx.ply = malloc(sizeof(t_ray));
// 	mlx.mlx_p = mlx_init(500, 500, "Wolfenstein 42", 0);
// 	get_angle(&mlx);
// 	game_loop(&mlx);
// 	// mlx_loop_hook(mlx.mlx_p, &game_loop, &mlx);
// 	mlx_loop(mlx.mlx_p);
// }
