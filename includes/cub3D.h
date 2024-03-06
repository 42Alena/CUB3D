/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/06 17:45:42 by dtolmaco         ###   ########.fr       */
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
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 0.1


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
	char 	*no_texture;
	char 	*so_texture;
	char 	*we_texture;
	char 	*ea_texture;
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
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

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
	t_map			map;
	t_player		player;
	t_ray			ray;
}	t_game;


//main

//raycasting.c
void	raycasting(t_game *game);

//game.c
void	init_game_struct(t_game *game);

//error.c
void	ft_error(t_game *game, char *error_msg);

//key_press
void	key_press(mlx_key_data_t keydata, void *param);

//map_check
int		check_input(int argc, char **argv);
void	print_map(t_game *game);

//map_save.c
void	map_init(t_game *game);
void	map_read(t_game *game, char *filename);
void	check_maps_cols_rows(t_game *game, int fd);
void	check_map(t_game *game, char *filename);

#endif

