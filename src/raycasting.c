/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:06:47 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/07 19:22:05 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	distance_and_height(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perpWallDist = game->ray.sideDistX - game->ray.deltaDistX;
	else
		game->ray.perpWallDist = game->ray.sideDistY - game->ray.deltaDistY;
	game->ray.line_height = (int)(WINDOW_HEIGHT / game->ray.perpWallDist);
}

void	init_ray(t_game *game, int i, int w)
{
	game->ray.mapX = (int)game->player.pos_x;
	game->ray.mapY = (int)game->player.pos_y;
	game->ray.cameraX = 2 * i / (double)w - 1;
	game->ray.rayDirX = game->player.dir_x + game->player.plane_x * game->ray.cameraX;
	game->ray.rayDirY = game->player.dir_y + game->player.plane_y * game->ray.cameraX;
	game->ray.deltaDistX = (game->ray.rayDirX == 0) ? 1e30 : fabs(1 / game->ray.rayDirX);
	game->ray.deltaDistY = (game->ray.rayDirY == 0) ? 1e30 : fabs(1 / game->ray.rayDirY);
}

void	calculate_step(t_game *game)
{
	if (game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.pos_x - game->ray.mapX) * game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->ray.mapX + 1.0 - game->player.pos_x) * game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.pos_y - game->ray.mapY) * game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->ray.mapY + 1.0 - game->player.pos_y) * game->ray.deltaDistY;
	}
}

void	hit_wall(t_game* game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->ray.mapX += game->ray.stepX;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->ray.mapY += game->ray.stepY;
			game->ray.side = 1;
		}
		if (game->ray.mapY < 0 || game->ray.mapX < 0 ||\
		game->map.saved_map[game->ray.mapX][game->ray.mapY] == '1')
			game->ray.hit = 1;
	}
}

void	calculate_start_end(t_game *game)
{
	game->ray.draw_start = -game->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if(game->ray.draw_end >= WINDOW_HEIGHT)
		game->ray.draw_end = WINDOW_HEIGHT - 1;
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.pos_y + game->ray.perpWallDist * game->ray.rayDirY;
	else
		game->ray.wall_x = game->player.pos_x + game->ray.perpWallDist * game->ray.rayDirX;
	game->ray.wall_x -= floor((game->ray.wall_x));
	game->ray.tex_x = (int)(IMAGE_WIDTH * game->ray.wall_x);
	if(game->ray.side == 0 && game->ray.rayDirX > 0)
		game->ray.tex_x = IMAGE_WIDTH - game->ray.tex_x - 1;
	if(game->ray.side == 1 && game->ray.rayDirY < 0)
		game->ray.tex_x = IMAGE_WIDTH - game->ray.tex_x - 1;
	game->ray.step = 1.0 * IMAGE_HEIGHT / game->ray.line_height;
}

void	calculate_floor_ceiling(t_game *game, t_floor *floor)
{
	
	if(game->ray.side == 0 && game->ray.rayDirX > 0)
	{
		floor->floorXWall = game->ray.mapX;
		floor->floorYWall = game->ray.mapY + game->ray.wall_x;
	}
	else if(game->ray.side == 0 && game->ray.rayDirX < 0)
	{
		floor->floorXWall = game->ray.mapX + 1.0;
		floor->floorYWall = game->ray.mapY + game->ray.wall_x;
	}
	else if(game->ray.side == 1 && game->ray.rayDirY > 0)
	{
		floor->floorXWall = game->ray.mapX + game->ray.wall_x;
		floor->floorYWall = game->ray.mapY;
	}
	else
	{
		floor->floorXWall = game->ray.mapX + game->ray.wall_x;
		floor->floorYWall = game->ray.mapY + 1.0;
	}
	floor->distWall = game->ray.perpWallDist;
	floor->distPlayer = 0.0;
}

void	draw_floor_ceiling(t_game *game, int x)
{
	t_floor		floor;
	uint32_t	color;

	calculate_floor_ceiling(game, &floor);
	for(int y = game->ray.draw_end + 1; y < WINDOW_HEIGHT; y++)
	{
		floor.currentDist = WINDOW_HEIGHT / (2.0 * y - WINDOW_HEIGHT);
		floor.weight = (floor.currentDist - floor.distPlayer)\
		/ (floor.distWall - floor.distPlayer);
		floor.currentFloorX = floor.weight * floor.floorXWall + (1.0 - floor.weight) * game->player.pos_x;
		floor.currentFloorY = floor.weight * floor.floorYWall + (1.0 - floor.weight) * game->player.pos_y;
		floor.floorTexX = (int)(floor.currentFloorX * FLOOR_WIDTH) % FLOOR_WIDTH;
		floor.floorTexY = (int)(floor.currentFloorY * FLOOR_HEIGHT) % FLOOR_HEIGHT;
		color = game->floor[FLOOR_WIDTH * floor.floorTexY + floor.floorTexX];
		mlx_put_pixel(game->image, x, y, color);
		color = game->ceiling[FLOOR_WIDTH * floor.floorTexY + floor.floorTexX];
		mlx_put_pixel(game->image, x, WINDOW_HEIGHT - y, color);
	}

}

void	draw(t_game *game, int x)
{
	int 		texY;
	double		texPos;
	uint32_t	color;
	u_int32_t	*texture;

	if(game->ray.side == 0 && game->ray.rayDirX > 0)
		texture = game->wall_tex3;
    else if(game->ray.side == 0 && game->ray.rayDirX < 0)
		texture = game->wall_tex2;
    else if(game->ray.side == 1 && game->ray.rayDirY > 0)
		texture = game->wall_tex;
    else
		texture = game->wall_tex4;
	texPos = (game->ray.draw_start - WINDOW_HEIGHT / 2\
	+ game->ray.line_height / 2) * game->ray.step;
	for(int y = game->ray.draw_start; y < game->ray.draw_end; y++)
	{
		texY = (int)texPos;
		texPos += game->ray.step;
		color = texture[IMAGE_HEIGHT * texY + game->ray.tex_x];
		mlx_put_pixel(game->image, x, y, color);
	}
}

void	raycasting(t_game* game)
{
	int	x;

	x = 0;
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	while (x < WINDOW_WIDTH)
	{
		init_ray(game, x, WINDOW_WIDTH);
		calculate_step(game);
		hit_wall(game);
		distance_and_height(game);
		printf("distance:%f\n", game->ray.perpWallDist);
		calculate_start_end(game);
		draw(game, x);
		draw_floor_ceiling(game, x);
		x++;
	}
	mlx_image_to_window(game->mlx, game->image, 0, 0);
}