/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 12:24:30 by akurmyza         ###   ########.fr       */
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

// #define NULL ((void*)0)

//GAME
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 960
# define IMAGE_WIDTH 64
# define IMAGE_HEIGHT 64
# define MOVE_SPEED 0.2
# define ROTATION_SPEED 0.1


typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_map
{
	int	cols;
	int	rows;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *floor_color;
	char *ceiling_color;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	t_map		map_info;
	t_bool		playable;
	int			player_count;
	char		player_direction;
	double		player_x;
	double		player_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_game;


//main

//calculate.c
double	distance(int side, double sideDistX, double sideDistY, double deltaDistX, double deltaDistY);
void	calculate(t_game* game);

//game.c
void	ft_hook(void* param);
void init_game_struct(t_game *game);
void	game_init(t_game *game);

//error.c
void	ft_error(t_game *game, char *error_msg);

//key_press
void	key_press(mlx_key_data_t keydata, void *param);

//map_check
int	check_input(int argc, char **argv);
void print_map(t_game *game);
// void	check_map_walls(t_game *game);
// void	check_characters(t_game *game, char c, int x, int y);
// void	check_maps_characters(t_game *game);

//map_save.c
void map_init(t_game *game);
void	map_read(t_game *game, char *filename);
void	check_maps_cols_rows(t_game *game, int fd);
void	check_map(t_game *game, char *filename);

#endif

// void	draw_wall(t_game *game, int perpWallDist, int i)
// {
// 	int lineHeight;
// 	int drawStart;
// 	int drawEnd;
	
// 	lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
// 	printf("height:%d\n", lineHeight);
// 	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
// 	if (drawStart < 0)
// 		drawStart = 0;
// 	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
// 	if(drawEnd >= WINDOW_HEIGHT)
// 		drawEnd = WINDOW_HEIGHT - 1;
// 	for (int j = drawStart; j < drawEnd; j++)
// 		mlx_put_pixel(game->image, i, j, 0x36CC89FF);
// }
