/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:29:20 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 22:30:56 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
// printf("height:%d\n", lineHeight);
// int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
// if (drawStart < 0)
// 	drawStart = 0;
// int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
// if(drawEnd >= WINDOW_HEIGHT)
// 	drawEnd = WINDOW_HEIGHT - 1;
// printf("drawStart:%d drawEnd:%d\n", drawStart, drawEnd);
// for (int j = drawStart; j < drawEnd; j++)
// {
// 	mlx_put_pixel(game->image, i, j, 0x36CC89FF);
// }

double	distance(int side, double sideDistX, double sideDistY, double deltaDistX, double deltaDistY)
{
	if (side == 0)
		return (sideDistX - deltaDistX);
	else
		return (sideDistY - deltaDistY);
}

// int	draw_wall(t_game *game, double perpWallDist, int i, int color)
// {
// 	int	lineHeight;
// 	int	drawStart;
// 	int	drawEnd;
	
// 	lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
// 	drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
// 	if (drawStart < 0)
// 		drawStart = 0;
// 	drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
// 	if(drawEnd >= WINDOW_HEIGHT)
// 		drawEnd = WINDOW_HEIGHT - 1;
// 	for (int j = drawStart; j < drawEnd; j++)
// 		mlx_put_pixel(game->image, i, j, 0x36CC89FF);
// 	(void)color;
// 	return (lineHeight);
// }
//0x36CC89FF

void	calculate(t_game* game)
{
	char	map[50][50] = {{1,1,1,1,1},\
						{1,0,0,0,1},\
						{1,0,0,0,1},\
						{1,2,0,0,1},\
						{1,1,1,1,1}};
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	//int color = rand () % 0x100000000;
	for (double i = 0, w = WINDOW_WIDTH; i < w; i++)
	{
		int			mapX = (int)game->player_x;
		int			mapY = (int)game->player_y;
		double	cameraX = 2 * i / (double)w - 1;
		double	rayDirX = game->dir_x + game->plane_x * cameraX;
		double	rayDirY = game->dir_y + game->plane_y * cameraX;
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
		perpWallDist = distance(side, sideDistX, sideDistY, deltaDistX, deltaDistY);
		printf("distance:%f\n", perpWallDist);
		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
		if(drawEnd >= WINDOW_HEIGHT)
			drawEnd = WINDOW_HEIGHT - 1;
		for (int j = drawStart; j < drawEnd; j++)
		{
			mlx_put_pixel(game->image, i, j, 0x36CC89FF);
		}
		// double wallX; //where exactly the wall was hit
		// if (side == 0)
		// 	wallX = game->player_y + perpWallDist * rayDirY;
		// else
		// 	wallX = game->player_x + perpWallDist * rayDirX;
		// wallX -= floor((wallX));
		// int texX = (int)(IMAGE_WIDTH * wallX);
		// if(side == 0 && rayDirX > 0)
		// 	texX = IMAGE_WIDTH - texX - 1;
		// if(side == 1 && rayDirY < 0)
		// 	texX = IMAGE_WIDTH - texX - 1;
		// double step = 1.0 * IMAGE_HEIGHT / lineHeight;
		// // Starting texture coordinate
		// int texNum = map[mapX][mapY] - 1;
		// double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;
		// for(int y = drawStart; y < drawEnd; y++)
		// {
		// 	// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		// 	int texY = (int)texPos & (IMAGE_HEIGHT - 1);
		// 	texPos += step;
		// 	Uint32 color = texture[texNum][IMAGE_HEIGHT * texY + texX];
		// }
	}
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}
