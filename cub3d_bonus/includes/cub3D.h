/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/18 11:40:34 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../lib_gnl/include/get_next_line.h"
# include "../../lib_mlx42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define IMAGE_WIDTH 512
# define IMAGE_HEIGHT 512
// minimap and bigmap
# define WALL_WIDTH 15
# define WALL_HEIGHT 15
# define BIG_WALL_WIDTH 10
# define BIG_WALL_HEIGHT 10
// floor and ceiling size
# define F_WIDTH 512
# define F_HEIGHT 512
# define INITIAL_MOVE_SPEED 0.05
# define ROTATION_SPEED 0.1
# define TIMER_SPEED 20
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3
# define VMOVE 128.0
# define SPRITE_WIDTH 128
# define SPRITE_HEIGHT 128

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_sprite
{
	double	transform_x;
	double	transform_y;
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	int		v_move_screen;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_y;
	int		draw_start_x;
	int		draw_end_y;
	int		draw_end_x;
	int		d;
	int		tex_y;
	int		tex_x; 
}	t_sprite;

typedef struct s_map
{
	char	**saved_map;
	int		cols;
	int		rows;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*floor_color;
	char	*ceiling_color;
}	t_map;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		camera_x;
	double		step_x;
	double		step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int			line_height;
	double		draw_start;
	double		draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		*z_buffer;
	int			tex_num;
}	t_ray;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_mouse
{
	double	mouse_x;
	double	mouse_y;
}	t_mouse;

typedef struct s_textures
{
	mlx_image_t		*image;
	u_int32_t		*north;
	u_int32_t		*south;
	u_int32_t		*west;
	u_int32_t		*east;
	u_int32_t		*door;
	u_int32_t		*door_open;
	u_int32_t		*win_image;
	u_int32_t		*floor;
	u_int32_t		*ceiling;
	u_int32_t		*c3po;
	u_int32_t		*c3po2;
	u_int32_t		*bottom_image;
	u_int32_t		*r2d2;
	mlx_texture_t	*cursor;
	mlx_image_t		*main_menu;
	mlx_image_t		*end;
	mlx_image_t		*congrats;
	mlx_image_t		*settings05;
	mlx_image_t		*settings1;
	mlx_image_t		*settings2;
}	t_textures;

typedef struct s_game
{
	mlx_t			*mlx;
	int				window_width;
	int				window_height;
	int				is_menu;
	int				is_settings;
	int				is_map;
	int				is_opened;
	int				dead_cursor;
	int				is_win;
	int				end;
	double			move_speed;
	t_textures		textures;
	t_mouse			mouse;
	t_map			map;
	t_player		player;
	t_sprite		sprite;
	t_ray			ray;
}	t_game;

//main

//raycasting.c
void	raycasting(t_game *game);

//free.c
void	free_double_array(char **array);
void	free_mlx(t_game *game);

//calculations_raycasting.c
void	calculate_start_end(t_game *game);
void	hit_wall(t_game	*game);
void	calculate_step(t_game *game);
void	init_ray(t_game *game, int i, int w);
void	distance_and_height(t_game *game);

//textures.c
void	load_images(t_game *game);
void	load_textures(t_game *game);
void	extra_textures(t_game *game);

//main_menu.c
void	launch_game(t_game *game);
void	back_to_main_menu(t_game *game);
void	settings(t_game *game);
int		move_speed(t_game *game);

//bigmap.c
void	bigmap(t_game *game);

//minimap.c
void	minimap(t_game *game);

//sprites.c
void	draw_sprites(t_game *game);

//floor_ceiling.c
void	draw_floor_ceiling(t_game *game, int x);

//mouse.c
void	cursor(double xpos, double ypos, void *param);
void	mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

//raycasting.c
void	distance_and_height(t_game *game);
void	init_ray(t_game *game, int i, int w);
void	calculate_step(t_game *game);
void	hit_wall(t_game *game);
void	calculate_start_end(t_game *game);
void	draw_floor_ceiling(t_game *game, int x);
void	draw_walls(t_game *game, int x);
void	raycasting(t_game *game);

//utils.c
uint32_t	*get_color(mlx_texture_t *texture);
int			distance_to_wall(t_player *player, char **saved_map, double x, double y);
void		timer(mlx_image_t *image, int height, int width, double time);

// game_init.c 
void	init_map_structure(t_game *game);
void	init_player_structure(t_game *game);
void	init_game_struct(t_game *game);

//player_save.c 
void	save_player_pos_dir(t_game *game, char player_dir, int x, int y);
void	save_player_struct(t_game *game, char player_dir, int x, int y);

//error.c
void	ft_error(t_game *game, char *error_msg);

//key_press
void	key_press(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	rotation(t_player *player, double rot_speed);

//map_check

//////TO TEST
void	print_map_pos_x_y(t_game *game);
void	print_map(t_game *game);
///END_TO TEST////////////////

int		check_input(int argc, char **argv);
void	print_map(t_game *game);
void	check_maps_characters(t_game *game);

//map_save.c
t_bool	save_player_structure(t_game *game, char player_pos_dir);
void	map_save(t_game *game);
void	map_read(t_game *game, char *filename);
void	check_maps_cols_rows(t_game *game, int fd);
void	check_map(t_game *game, char *filename);

#endif
