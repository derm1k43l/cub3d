/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:11:10 by mrusu             #+#    #+#             */
/*   Updated: 2024/10/18 15:28:36 by ashirzad         ###   ########.fr       */
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
# include "MLX42/include/MLX42/MLX42.h"

// Define
# define MAX_HEIGHT 25
# define MAX_WIDTH 80
# define RES_X 1900
# define RES_Y 1000
# define FOV 60
# define ROTATION_SPEED 2
# define PLAYER_SPEED 4
# define TILE 32

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
	double	angle;
	float	fov_rd;
	int		rot;
	int		horz;
	int		vert;
}	t_player;

// ray structure
typedef struct s_ray
{
	int		i;
	double	ray_ngl;
	double	hz_x;
	double	hz_y;
	double	vert_x;
	double	vert_y;
	double	distance;
	int		flag;
}	t_ray;

// mlx structure
typedef struct s_data
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_ray			*ray;
	t_map			*map;
	t_player		*ply;
	mlx_texture_t	*text;
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_we;
	mlx_texture_t	*text_ea;
	int				pixel;
}	t_data;

// **********************====FUNCTION DECLARATION====*********************

// main.c

// check_map.c
int				check_map_validity(t_map *map);
int				check_player(char **map_data, int height, int width, \
					t_map *map);
int				flood_fill(t_map *map, int x, int y);
void			check_texture_and_color(t_map *map);
void			add_player(t_map *map, int i, int j);

// parse_map.c
void			read_map(char *file_name, t_map *map);
int				open_file(char *file_name);
int				memory_allocation(t_map *map);
int				parse_map(int fd, t_map *map, char *first_map_line);
void			store_map_line(t_map *map, char *line);

// utils.c
void			clean_map(t_map *map);
void			clean_txt(t_map *map);
void			clean_map_copy(t_map *map);
void			printerr(char *msg);
int				ft_is_whitespace(char c);

// init.c
void			init_default(t_map *map);

// parse_utils.c
char			*trim_whitespace(char *line);
char			*skip_empty_line(int fd);
char			*gnl_noemptyline(int fd, t_map *map);
int				copy_map(t_map *map);

// parse_txt_col.c
char			*parse_texture_and_color(int fd, t_map *map);
int				set_values(char *line, t_map *map);
uint32_t		parse_color(char *line);

// execution
void			execution(t_map *data);
void			game_loop(void *pointer);
int				init_texture(t_data *data);
void			init_player(t_data *data);

//free
void			free_texture(t_data *dt);
void			ft_free(t_data *dt);

void			move_player(t_data *data, double move_x, double move_y);
void			rotate_player(t_player *ply, int rot);
void			hook(t_data *data, double move_x, double move_y);
void			ft_release(mlx_key_data_t key_data, t_data *data);
void			key_hook(mlx_key_data_t key_data, void *pointer);

// raycasting.c
int				find_wall(t_data *data, float x, float y);
float			ft_h_ray(t_data *data);
float			ft_v_ray(t_data *data);
void			cast_rays_walls(t_data *data);

// rendering.c
void			draw_floor_ceiling(t_data *dt);
void			my_pixel_put(t_data *dt, int x, int y, uint32_t color);
void			display_wall(t_data *dt, int top_pix, int bottom_pix, \
					double wall_h);
void			render(t_data *dt, int ray);

//utils.c
int				reverse_bytes(int c);
float			check_angle(float angle);
double			ft_dis(float x1, int x2, float y1, int y2);
double			calc_wall_height(t_data *dt);
mlx_texture_t	*set_texture(t_data *dt);

#endif
