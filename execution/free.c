/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:15:56 by ashirzad          #+#    #+#             */
/*   Updated: 2024/10/18 16:05:15 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture(t_data *dt)
{
	if (dt->text)
		mlx_delete_texture(dt->text);
	if (dt->text_ea)
		mlx_delete_texture(dt->text_ea);
	if (dt->text_we)
		mlx_delete_texture(dt->text_we);
	if (dt->text_no)
		mlx_delete_texture(dt->text_no);
	if (dt->text_so)
		mlx_delete_texture(dt->text_so);
}

void	ft_free(t_data *dt)
{
	mlx_delete_image(dt->mlx, dt->img);
	free_texture(dt);
	free(dt->ray);
	free(dt->ply);
}
