/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:22 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/03 17:24:11 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#define WIDTH 1920
#define HEIGHT 960

// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }
#include <math.h>
int32_t	main(void)
{
	char	map[50][50] = {{1,1,1,1,1},\
						{1,0,0,0,1},\
						{1,0,0,0,1},\
						{1,2,0,0,1},\
						{1,1,1,1,1}};
	double		posX = 1.5, posY = 1.8;
	int			mapX = 1, mapY = 1;
	double		planeX = 0, planeY = 0.1;
	double		dirX = 0, dirY = -1;
	for (double i = 0, w = 1; i < w; i++)
	{
		double	cameraX = 2 * i / w - 1;
		double rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    	double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		printf("%f camera %f raydirY %f deltaY\n", cameraX, rayDirY, deltaDistY);
		double stepX, stepY;
		double	sideDistX, sideDistY;
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
		printf("sideX:%f, sideY:%f\n", sideDistX, sideDistY);
		int hit = 0, side;
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
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
			//Check if ray has hit a wall
			if (map[mapX][mapY] == 1) hit = 1;
			printf("%d\n", hit);
		}
	}
	return (EXIT_SUCCESS);
}

// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// if (!mlx)
// 	ft_error();
// mlx_image_t* img = mlx_new_image(mlx, 1920, 960);

// // Set the channels of each pixel in our image to the maximum byte value of 255. 
// ft_memset(img->pixels, 200, img->width * img->height * 4);

// // Draw the image at coordinate (0, 0).
// mlx_image_to_window(mlx, img, 0, 0);
// mlx_loop_hook(mlx, ft_hook, mlx);
// mlx_loop(mlx);
// mlx_terminate(mlx);