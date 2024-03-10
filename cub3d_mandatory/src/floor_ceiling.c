/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:31:02 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/10 15:38:35 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_floor_ceiling(t_game *game, t_floor *floor)
{
	if (game->ray.side == 0 && game->ray.rayDirX > 0)
	{
		floor->floorXWall = game->ray.mapX;
		floor->floorYWall = game->ray.mapY + game->ray.wall_x;
	}
	else if (game->ray.side == 0 && game->ray.rayDirX < 0)
	{
		floor->floorXWall = game->ray.mapX + 1.0;
		floor->floorYWall = game->ray.mapY + game->ray.wall_x;
	}
	else if (game->ray.side == 1 && game->ray.rayDirY > 0)
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

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_floor_ceiling(t_game *game, int x)
{
	t_floor		floor;
	uint32_t	color;
	int			y;

	calculate_floor_ceiling(game, &floor);
	y = game->ray.draw_end + 1;
	while (y < game->window_height)
	{
		floor.currentDist = game->window_height / \
		(2.0 * y - game->window_height);
		floor.weight = (floor.currentDist - floor.distPlayer) \
		/ (floor.distWall - floor.distPlayer);
		floor.currentFloorX = floor.weight * floor.floorXWall \
		+ (1.0 - floor.weight) * game->player.pos_x;
		floor.currentFloorY = floor.weight * floor.floorYWall \
		+ (1.0 - floor.weight) * game->player.pos_y;
		floor.tex_x = (int)(floor.currentFloorX * F_WIDTH) % F_WIDTH;
		floor.tex_y = (int)(floor.currentFloorY * F_HEIGHT) % F_HEIGHT;
		color = get_rgba(200, 200, 200, 255);
		mlx_put_pixel(game->textures.image, x, y, color);
		color = get_rgba(50, 50, 50, 255);
		mlx_put_pixel(game->textures.image, x, game->window_height - y, color);
		y++;
	}
}
