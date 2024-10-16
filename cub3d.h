/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:10 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/16 15:41:43 by mrusu            ###   ########.fr       */
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
# include "math.h"

// Extra
# include "libft/inc/libft.h"
# include "mlx42/include/MLX42/MLX42.h"

// Define
# define MAX_HEIGHT 25
# define MAX_WIDTH 80
# define RES_X 1900
# define RES_Y 1000
# define FOV 60
# define ROTATION_SPEED 2
# define PLAYER_SPEED 4
# define SQUARE_SIZE 32

//	error - 4294967295
//	unset - 4294967294
# define COLOR_ERROR 0xFFFFFFFF
# define COLOR_UNSET 0xFFFFFFFE

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
	int	rgb;
}	t_color;

typedef struct s_map
{
	int			res_x;
	int			res_y;
	char		*north_tx;
	char		*south_tx;
	char		*west_tx;
	char		*east_tx;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char		**map_data;
	char		**map_copy;
	int			height;
	int			player_x;
	int			player_y;
	char		p;
}	t_map;

typedef struct s_player
{
	int		plyr_x;
	int		plyr_y;
	double	angle; // player angle
	float	fov_rd; // field of view in radians
	int 	rot; // rotation flag
	int		horz; // left right flag
	int 	vert; // up down flag
}	t_player;

typedef struct s_ray //the ray structure
{
	double	ray_ngl;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_data //the mlx structure
{
	mlx_image_t		*img; // the image
	mlx_t			*mlx;
	t_ray			*ray; // the ray structure
	t_map			*map; // the map data structure
	t_player		*ply; // the player structure
	mlx_texture_t	*texture;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_we;
	mlx_texture_t	*text_ea;
}	t_data;

// **********************====FUNCTION DECLARATION====*********************

// main.c

// check_map.c
int			check_map_validity(t_map *map);
int			check_boundary(char **map_data, int height, int width);
int			check_player(char **map_data, int height, int width, t_map *map);
void		check_texture_and_color(t_map *map);
void		add_player(t_map *map, int i, int j);

// parse_map.c
void		read_map(char *file_name, t_map *map);
int			open_file(char *file_name);
int			memory_allocation(t_map *map);
int			parse_map(int fd, t_map *map, char *first_map_line);
void		store_map_line(t_map *map, char *line);

// utils.c
void		clean_map(t_map *map);
void		printerr(char *msg);
int			ft_is_whitespace(char c);
void		print_map_data(t_map *map);
void		clean_txt(t_map *map);

// init.c
void		init_default(t_map *map);

// parse_utils.c
char		*trim_whitespace(char *line);
char		*skip_empty_line(int fd);
char		*gnl_noemptyline(int fd, t_map *map);

// parse_txt_col.c
char		*parse_texture_and_color(int fd, t_map *map);
int			set_values(char *line, t_map *map);
uint32_t	parse_color(char *line);

// execution
void		execution(t_map *data);
void		init_player(t_data *data);
void		game_loop(void *pointer);

// draw.c
void		draw_floor_ceiling(t_data *data);
double		calc_wall_height(t_data *data);
mlx_texture_t	*set_texture(t_data *data);
int			reverse_bytes(int c);

// raycasting.c
void		cast_rays(t_data *data);
int			find_wall(t_data *data, float x,  float y);
int			inter_check(float angle, float *inter, float *step, int is_horizon);
float		ft_h_ray(t_data *data);
float		ft_v_ray(t_data *data);

// moves.c
void		move_player(t_data *data, double move_x, double move_y);
void		rotate_player(t_player *ply, int rot);
void		hook(t_data *data, double move_x, double move_y);
void		key_release(mlx_key_data_t key_data, t_data *data);
void		key_hook(mlx_key_data_t key_data, void *pointer);

//rendering.c
void	render(t_data *data, int ray);

#endif
