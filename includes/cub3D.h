/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/07 20:22:02 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../lib_gnl/include/get_next_line.h"
# include "../lib_mlx42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
//open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//GAME
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 960
# define IMAGE_WIDTH 1024
# define IMAGE_HEIGHT 1024
# define FLOOR_WIDTH 512
# define FLOOR_HEIGHT 512
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.1
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3



typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_floor
{
	double	distWall;
	double	distPlayer;
	double	currentDist;
	double	floorXWall;
	double	floorYWall;
	double	currentFloorX;
	double	currentFloorY;
	double	weight;
	int 	floorTexX;
	int		floorTexY;

} t_floor;

typedef struct s_map
{
	char	**saved_map;
	int		cols;
	int		rows;
	char 	*n_texture;
	char 	*s_texture;
	char 	*w_texture;
	char 	*e_texture;
	char 	*floor_color;
	char 	*ceiling_color;
}	t_map;

typedef struct s_ray
{
	int			mapX;
	int			mapY;
	double		cameraX;
	double		stepX;
	double		stepY;
	double		sideDistX;
	double		sideDistY;
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			hit;
	int			side;
	int			line_height;
	double		draw_start;
	double		draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
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


typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	u_int32_t		*wall_tex;
	u_int32_t		*wall_tex2;
	u_int32_t		*wall_tex3;
	u_int32_t		*wall_tex4;
	u_int32_t		*floor;
	u_int32_t		*ceiling;
	mlx_image_t		*main_menu;
	int				is_menu;
	t_mouse			mouse;
	t_map			map;
	t_player		player;
	t_ray			ray;
}	t_game;


//main

//raycasting.c
void	raycasting(t_game *game);

//minimap
void	minimap(t_game *game);

//raycasting.c
void	distance_and_height(t_game *game);
void	init_ray(t_game *game, int i, int w);
void	calculate_step(t_game *game);
void	hit_wall(t_game* game);
void	calculate_start_end(t_game *game);
void	calculate_floor_ceiling(t_game *game, t_floor *floor);
void	draw_floor_ceiling(t_game *game, int x);
void	draw(t_game *game, int x);
void	raycasting(t_game* game);

//game.c
uint32_t	*get_color(mlx_texture_t *texture);

// game_init.c 
void	init_map_structure(t_game *game);
void	init_player_structure(t_game *game);
void	init_game_struct(t_game *game);

//player_save.c 
void save_player_pos_dir(t_game *game, char player_dir, int x, int y);
void	save_player_struct(t_game *game, char player_dir, int x, int y);

//error.c
void	ft_error(t_game *game, char *error_msg);

//key_press
void	key_press(mlx_key_data_t keydata, void *param);
void	rotation(t_game *game, double rot_speed);

//map_check

//////TO TEST
void print_map_pos_x_y(t_game *game);
void print_map(t_game *game);
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

