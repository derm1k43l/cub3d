/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:10 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/02 16:12:53 by mrusu            ###   ########.fr       */
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

// Define
#define MAX_HEIGHT 25
#define MAX_WIDTH 80
#define RES_X 1920
#define RES_Y 1080
#define FOV 60
#define DEFAULT_TEXTURE "default.xpm"
#define DEFAULT_COLOR 0x000000

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
	int		height;
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
void	clean_map(t_map *map);
void	printerr(char *msg);
int		ft_is_whitespace(char c);
char	*ft_strtrim1(const char *s);
void	print_map_data(t_map *map);

// init.c
void	init_default(t_map *map);

// parse.c
int		open_file(char *file_name);


#endif