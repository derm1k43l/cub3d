/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:42:12 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/16 15:37:11 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_loop(void *pointer)
{
	t_data *data = (t_data *)pointer;

	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->map->res_x, data->map->res_y);
	if (!data->img)
	{
		ft_printf("some error\n");
		return ; //eror here
	}
	hook(data, 0, 0);
	draw_floor_ceiling(data);
	cast_rays(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

void	init_texture(t_data *data)
{
	data->text_ea = mlx_load_png(data->map->east_tx);
	data->text_we = mlx_load_png(data->map->west_tx);
	data->text_so = mlx_load_png(data->map->south_tx);
	data->text_no = mlx_load_png(data->map->north_tx);
}

void	init_player(t_data *data)
{
	int y = 3;
	int x = 18;
	char p = 'N';
	data->ply = malloc(sizeof(t_player));
	data->ply->rot = 0;
	data->ply->horz = 0;
	data->ply->vert = 0;
	data->ply->plyr_x = (x * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	data->ply->plyr_y = (y * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	data->ply->fov_rd = (FOV * M_PI) / 180;
	if (p == 'N')
		data->ply->angle = 3 * M_PI / 2;
	else if (p == 'S')
		data->ply->angle = M_PI / 2;
	else if (p == 'W')
		data->ply->angle = M_PI;
	else if (p == 'E')
		data->ply->angle = 0;
}

void	execution(t_map *map)
{
	t_data	data;

	data.map = map;
	data.mlx = mlx_init(map->res_x, map->res_y, "Wolfenstein 42", 0);
	if (!data.mlx)
		exit(1);
	init_player(&data);
	init_texture(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
}
