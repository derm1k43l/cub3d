/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:10 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/04 11:05:18 by mrusu            ###   ########.fr       */
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
# define MAX_HEIGHT 25
# define MAX_WIDTH 80
# define RES_X 1920
# define RES_Y 1080
# define FOV 60
# define DEFAULT_TEXTURE "default.xpm"
# define DEFAULT_FLOOR (t_color){0, 0, 0}
# define DEFAULT_CEILING (t_color){0, 0, 0}

// Typdef foreward declaration
typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_color	t_color;

// **********************====STRUCT====*********************
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

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
	t_color	floor_color;
	t_color	ceiling_color;
	char	**map_data;
	int		height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	double	plane;
}	t_player;

// **********************====FUNCTION DECLARATION====*********************

// main.c

// map.c
void	read_map(char *file_name, t_map *map);
int		check_map_struct(char **map_data, int height, int width);
int		check_map_validity(t_map *map);
void	process_valid_line(t_map *map, char *line);
void	process_map_line(t_map *map, char *line);

// utils.c
void	clean_map(t_map *map);
void	printerr(char *msg);
int		ft_is_whitespace(char c);
void	print_map_data(t_map *map);

// init.c
void	init_default(t_map *map);

// parse.c
char	*parse_texture_and_color(int fd, t_map *map);
int		parse_texture(char *line, t_map *map);
int		parse_color(char *line, t_map *map);
int		parse_color_value(char *line, t_color *color);
int		parse_map(int fd, t_map *map, char *first_map_line);

// parse_utils.c
int		open_file(char *file_name);
char	*skip_empty_line(int fd);
void	memory_allocation(t_map *map);

#endif