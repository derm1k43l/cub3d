/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:35:09 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/14 14:32:51 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	move_player(t_data *data, double move_x, double move_y)
// {
// 	int	p_x;
// 	int p_y;

// 	p_x = roundf(data->ply->plyr_x + move_x) / SQAURE_SIZE;
// 	p_y = roundf(data->ply->plyr_y + move_y) / SQAURE_SIZE;
// 	if (data->map->map_data[p_y][p_x] != '1')
// 	{
// 		data->ply->plyr_x += move_x;
// 		data->ply->plyr_y += move_y;
// 	}
// }

// void	rotate_player(t_player *ply, int rot)
// {
// 	if (rot == 1)
// 	{
// 		ply->angle += (ROTATION_SPEED * M_PI) / 180;
// 		if (ply->angle > ROTATION_SPEED * M_PI)
// 			ply->angle -= ROTATION_SPEED * M_PI;
// 	}
// 	else
// 	{
// 		ply->angle -= (ROTATION_SPEED * M_PI) / 180;
// 		if (ply->angle < 0)
// 			ply->angle += ROTATION_SPEED * M_PI;
// 	}
// }

// void	hook(t_data *data, double move_x, double move_y)
// {
// 	t_player *ply = data->ply;

// 	if (ply->rot == 1)
// 		rotate_player(ply, 1);
// 	if (ply->rot == -1)
// 		rotate_player(ply, -1);
// 	if (ply->horz == 1)
// 	{
// 		move_x = -sin(ply->angle) * PLAYER_SPEED;
// 		move_y = cos(ply->angle) * PLAYER_SPEED;
// 	}
// 	if (ply->horz == -1)
// 	{
// 		move_x = sin(ply->angle) * PLAYER_SPEED;
// 		move_y = -cos(ply->angle) * PLAYER_SPEED;
// 	}
// 	if (ply->vert == 1)
// 	{
// 		move_x = -cos(ply->angle) * PLAYER_SPEED;
// 		move_y = -sin(ply->angle) * PLAYER_SPEED;
// 	}
// 	if (ply->vert == -1)
// 	{
// 		move_x = cos(ply->angle) * PLAYER_SPEED;
// 		move_y = sin(ply->angle) * PLAYER_SPEED;
// 	}
// 	move_player(data, move_x, move_y);
// }

// void	key_release(mlx_key_data_t key_data, t_data *data)
// {
// 	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_RELEASE)
// 		data->ply->rot = 0;
// 	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_RELEASE)
// 		data->ply->rot = 0;
// 	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
// 		data->ply->horz = 0;
// 	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
// 		data->ply->horz = 0;
// 	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
// 		data->ply->vert = 0;
// 	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
// 		data->ply->vert = 0;
// }

// void	key_hook(mlx_key_data_t key_data, void *pointer)
// {
// 	t_data *data = pointer;

// 	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
// 		data->ply->rot = 1;
// 	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
// 		data->ply->rot = -1;
// 	else if (key_data.key == MLX_KEY_D && key_data.action == MLX_PRESS)
// 		data->ply->horz = 1;
// 	else if (key_data.key == MLX_KEY_A && key_data.action == MLX_PRESS)
// 		data->ply->horz = -1;
// 	else if (key_data.key == MLX_KEY_W && key_data.action == MLX_PRESS)
// 		data->ply->vert = -1;
// 	else if (key_data.key == MLX_KEY_S && key_data.action == MLX_PRESS)
// 		data->ply->vert = 1;
// 	else if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
// 		mlx_close_window(data->mlx);
// 	key_release(key_data, data);
// }
