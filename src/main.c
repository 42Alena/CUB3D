/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 12:23:38 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 960
#define IMAGE_WIDTH 64
#define IMAGE_HEIGHT 64
#include <math.h>

void	calculate(mlx_t* mlx)
{
	char	map[50][50] = {{1,1,1,1,1},\
						{1,0,0,0,1},\
						{1,0,0,0,1},\
						{1,2,0,0,1},\
						{1,1,1,1,1}};
	double		posX = 1.5, posY = 1.5;
	int			mapX = 1, mapY = 1;
	double		planeX = 0, planeY = 0;
	double		dirX = 0, dirY = 1;
	mlx_image_t *image = mlx_new_image(mlx, 2000, 1000);
	mlx_image_to_window(mlx, image, 0, 0);
	for (double i = 0, w = 1; i < w; i++)
	{
		double	cameraX = 2 * i / (double)w - 1;
		double rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double stepX, stepY;
		double	sideDistX, sideDistY;
		double	perpWallDist;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		int hit = 0, side;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				printf("mapX:%d\n", mapX);
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				printf("mapY:%d sideY:%f\n", mapY, sideDistY);
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
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		printf("wallX:%f\n", wallX);
		int texX = (int)(IMAGE_WIDTH * wallX);
		if(side == 0 && rayDirX > 0)
			texX = IMAGE_WIDTH - texX - 1;
		if(side == 1 && rayDirY < 0)
			texX = IMAGE_WIDTH - texX - 1;
		printf("texX:%d\n", texX);
		for (int j = drawStart; j < drawEnd; j++)
		{
			mlx_put_pixel(image, i, j, 0xFF0000FF);
			printf("pixel\n");
		}
	}
}

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_hook(void* param)
{
	mlx_t* mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_UP))
		calculate(mlx);
}

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!mlx)
		ft_error();

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
