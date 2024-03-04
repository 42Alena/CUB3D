/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:37:52 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 18:01:09 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
// libft
# include "../libft/libft.h"
//MLX42
# include "../lib_mlx42/include/MLX42/MLX42.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

# define TRUE 1
# define FALSE 0

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 960
# define IMAGE_WIDTH 64
# define IMAGE_HEIGHT 64
# define MOVE_SPEED 0.2
# define ROTATION_SPEED 0.1

typedef struct s_game
{
	mlx_t*	mlx;
	mlx_image_t *image;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_game;


//main


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