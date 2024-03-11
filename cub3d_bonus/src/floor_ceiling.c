/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:31:02 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/11 11:21:52 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_floor_ceiling(t_game *game, t_floor *floor)
{
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
	{
		floor->floor_x_wall = game->ray.map_x;
		floor->floor_y_wall = game->ray.map_y + game->ray.wall_x;
	}
	else if (game->ray.side == 0 && game->ray.ray_dir_x < 0)
	{
		floor->floor_x_wall = game->ray.map_x + 1.0;
		floor->floor_y_wall = game->ray.map_y + game->ray.wall_x;
	}
	else if (game->ray.side == 1 && game->ray.ray_dir_y > 0)
	{
		floor->floor_x_wall = game->ray.map_x + game->ray.wall_x;
		floor->floor_y_wall = game->ray.map_y;
	}
	else
	{
		floor->floor_x_wall = game->ray.map_x + game->ray.wall_x;
		floor->floor_y_wall = game->ray.map_y + 1.0;
	}
	floor->dist_wall = game->ray.perp_wall_dist;
	floor->dist_player = 0.0;
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
		floor.current_dist = game->window_height / \
		(2.0 * y - game->window_height);
		floor.weight = (floor.current_dist - floor.dist_player) \
		/ (floor.dist_wall - floor.dist_player);
		floor.current_floor_x = floor.weight * floor.floor_x_wall \
		+ (1.0 - floor.weight) * game->player.pos_x;
		floor.current_floor_y = floor.weight * floor.floor_y_wall \
		+ (1.0 - floor.weight) * game->player.pos_y;
		floor.tex_x = (int)(floor.current_floor_x * F_WIDTH) % F_WIDTH;
		floor.tex_y = (int)(floor.current_floor_y * F_HEIGHT) % F_HEIGHT;
		color = game->textures.floor[F_WIDTH * floor.tex_y + floor.tex_x];
		mlx_put_pixel(game->textures.image, x, y, color);
		color = game->textures.ceiling[F_WIDTH * floor.tex_y + floor.tex_x];
		mlx_put_pixel(game->textures.image, x, game->window_height - y, color);
		y++;
	}
}
