/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:50:22 by acetin            #+#    #+#             */
/*   Updated: 2022/12/20 12:01:01 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif
# define PLAYER_SIZE 10
# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720
# define CELL_SIZE 32
# define FOV 60

typedef struct s_coordinate
{
	float	x;
	float	y;
}	t_coordinate;

typedef struct s_int_coordinate
{
	int	x;
	int	y;
}	t_int_coordinate;

typedef struct s_image
{
	char	*directory;
	void	*ptr;
	char	*data;
	int		width;
	int		height;
	int		size;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_player
{
	int				speed;
	float			angle;
	t_coordinate	delta_;
	t_coordinate	coordinate_;
	t_coordinate	collision;
}	t_player;

typedef struct s_mouse
{
	int	first_x;
	int	last_x;
}	t_mouse;

typedef struct s_map
{
	int		widht;
	int		height;
	int		color_sky;
	int		color_floor;
	char	**map_world;
}	t_map;

typedef struct s_ray
{
	float			angle;
	float			distance_;
	float			wall_h;
	t_coordinate	coord;
}	t_rays;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	float		angle_ray;
	t_player	player_;
	t_map		map_;
	t_image		**img;
	t_image		scene;
	t_mouse		mouse;
	t_rays		**ray;
}	t_game;

int				sign(float x);
void			line_bres(t_game ptr, t_int_coordinate pos1,
					t_int_coordinate pos2);
int				ray(t_game *ptr);
double			to_radians(double deg);
float			fix_angle(float ang);
void			ray_collision(t_game ptr, t_rays *ray);
float			distance(t_game ptr, t_rays ray);
void			draw_texture(t_game *ptr, t_coordinate pos,
					int x, t_image img);
int				get_color(int x, int y, t_image img);
void			img_pixel_put(t_image *img, int x, int y, int color);
int				collision(t_game ptr, int x, int y);

void			point_size(t_game ptr, int x, int y, int color);
void			draw_player(t_game ptr);
void			draw_map(t_game ptr);
void			draw_floor(t_game *ptr);
void			draw_sky(t_game *ptr);
void			draw_wall(t_game *ptr);
void			free_double(void **ptr);
void			draw_scene(t_game *ptr, t_coordinate pos, int y2, int color);
int				find_wall_direction(t_game ptr, t_coordinate ray_);
void			init_cub_folder(t_game *ptr, char *file_name);
void			get_player_pos(t_game *ptr);
void			check_walls(t_game ptr);
int				init_textures(t_game *ptr, char *str);
int				create_rgb(int r, int g, int b);
void			*ft_realloc(void *ptr, size_t size);
int				get_index(char *s1, char *set);
int				check_folder(char *file_name, char *extension);
void			game_life_cycle(t_game *ptr);
int				char_count(char *str, char *set);
void			error_message(char *message);
int				white_space(char c);
int				check_map(char **map, t_rays ray);
int				is_print_str(t_game ptr, char *str);

int				key_hook(int key, t_game *ptr);
int				exit_screen(void);
int				mouse_move(t_game *ptr);
void			move_up(t_game *ptr);
void			move_down(t_game *ptr);
void			move_left(t_game *ptr);
void			move_right(t_game *ptr);
void			mouse_hide_or_show(t_game *ptr);
void			turn_right(t_game *ptr, int angle);
void			turn_left(t_game *ptr, int angle);
#endif