/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:42:12 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/18 14:53:16 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	game_loop(void *pointer)
{
	t_data	*dt;

	dt = (t_data *)pointer;
	mlx_delete_image(dt->mlx, dt->img);
	dt->img = mlx_new_image(dt->mlx, dt->map->res_x, dt->map->res_y);
	hook(dt, 0, 0);
	draw_floor_ceiling(dt);
	cast_rays_walls(dt);
	mlx_image_to_window(dt->mlx, dt->img, 0, 0);
}

int	init_texture(t_data *dt)
{
	dt->text_ea = mlx_load_png(dt->map->east_tx);
	if (!dt->text_ea)
		return (printerr("Failed to load texture."), \
			clean_map(dt->map), exit(1), 1);
	dt->text_we = mlx_load_png(dt->map->west_tx);
	if (!dt->text_we)
		return (printerr("Failed to load texture."), \
			clean_map(dt->map), exit(1), 1);
	dt->text_so = mlx_load_png(dt->map->south_tx);
	if (!dt->text_so)
		return (printerr("Failed to load texture."), \
			clean_map(dt->map), exit(1), 1);
	dt->text_no = mlx_load_png(dt->map->north_tx);
	if (!dt->text_no)
		return (printerr("Failed to load texture."), \
			clean_map(dt->map), exit(1), 1);
	return (0);
}

void	init_player(t_data *dt)
{
	dt->ply = malloc(sizeof(t_player));
	dt->ply->rot = 0;
	dt->ply->horz = 0;
	dt->ply->vert = 0;
	dt->ply->plyr_x = (dt->map->player_x * TILE) + (TILE / 2);
	dt->ply->plyr_y = (dt->map->player_y * TILE) + (TILE / 2);
	dt->ply->fov_rd = (FOV * M_PI) / 180;
	if (dt->map->p == 'N')
		dt->ply->angle = 3 * M_PI / 2;
	else if (dt->map->p == 'S')
		dt->ply->angle = M_PI / 2;
	else if (dt->map->p == 'W')
		dt->ply->angle = M_PI;
	else if (dt->map->p == 'E')
		dt->ply->angle = 0;
}

void	execution(t_map *map)
{
	t_data	dt;

	dt.map = map;
	dt.mlx = mlx_init(map->res_x, map->res_y, "Wolfenstein 42", 0);
	if (!dt.mlx)
	{
		ft_printf("mlx_init failed\n");
		return ;
	}
	init_texture(&dt);
	init_player(&dt);
	mlx_key_hook(dt.mlx, key_hook, &dt);
	mlx_loop_hook(dt.mlx, game_loop, &dt);
	mlx_loop(dt.mlx);
	ft_free(&dt);
}
