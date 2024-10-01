/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:10 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/01 10:59:22 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Standard
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>

// Extra
# include "../libft/inc/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"

// Typdef
typedef struct s_map
{
	void	*init;
	void	*win;
	int		res_x;
	int		res_y;
	char	*north_tx;
	char	*south_tx;
	char	*west_tx;
	char	*east_tx;
	int		floor_color; //maybe tetxure?
	int		ceiling_color;
	char 	**map_data; // 2D array
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	double	plane;
}	t_player;

// Forward declaration of structs

// **********************====ENUM====*********************
// code for 

// **********************====STRUCT====*********************
// Strucutre for simulation enviroment

// Strucutre for 

// **********************====FUNCTION DECLARATION====*********************
// main.c

// utils.c

#endif