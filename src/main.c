/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 15:28:47 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 960
#define IMAGE_WIDTH 64
#define IMAGE_HEIGHT 64
#include <math.h>

void	calculate(t_game* game)
{
	char	map[50][50] = {{1,1,1,1,1},\
						{1,0,0,0,1},\
						{1,0,0,0,1},\
						{1,2,0,0,1},\
						{1,1,1,1,1}};
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	for (double i = 0, w = WINDOW_WIDTH; i < w; i++)
	{
		int			mapX = (int)game->player_x, mapY = (int)game->player_y;
		double		planeX = 0, planeY = 0.66;
		double		dirX = 0, dirY = 1;
		double	cameraX = 2 * i / (double)w - 1;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;
		double	deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double	deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double	stepX, stepY;
		double	sideDistX, sideDistY;
		double	perpWallDist;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player_y) * deltaDistY;
		}
		int hit = 0, side;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapX][mapY] == 1) hit = 1;
		}
		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		printf("distance:%f\n", perpWallDist);
		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
		printf("height:%d\n", lineHeight);
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawEnd >= WINDOW_HEIGHT)
			drawEnd = WINDOW_HEIGHT - 1;
		printf("drawStart:%d drawEnd:%d\n", drawStart, drawEnd);
		double wallX; //where exactly the wall was hit
		if (side == 0)
			wallX = game->player_y + perpWallDist * rayDirY;
		else
			wallX = game->player_x + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		//printf("wallX:%f\n", wallX);
		int texX = (int)(IMAGE_WIDTH * wallX);
		if(side == 0 && rayDirX > 0)
			texX = IMAGE_WIDTH - texX - 1;
		if(side == 1 && rayDirY < 0)
			texX = IMAGE_WIDTH - texX - 1;
		//printf("texX:%d\n", texX);
		for (int j = drawStart; j < drawEnd; j++)
		{
			mlx_put_pixel(game->image, i, j, 0x36CC89FF);
		}
	}
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	t_game* game = param;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	// 	calculate(game->mlx);
	//calculate(game);
	(void)game;
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game* game = param;
	if (keydata.key == MLX_KEY_S)
	{
		game->player_y -= 0.1;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
	else if (keydata.key == MLX_KEY_W)
	{
		game->player_y += 0.1;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
}

int32_t	main(void)
{
	t_game game;

	game.player_x = 1.5;
	game.player_y = 1.5;
	game.image = NULL;
	game.mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!game.mlx)
		ft_error();
	mlx_key_hook(game.mlx, key_press, &game);
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
