/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_raycasting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:58:28 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/03/18 11:08:15 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	distance_and_height(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = \
		game->ray.side_dist_x - game->ray.delta_dist_x;
	else
		game->ray.perp_wall_dist = \
		game->ray.side_dist_y - game->ray.delta_dist_y;
	game->ray.line_height = \
	(int)(game->window_height / game->ray.perp_wall_dist);
}

void	init_ray(t_game *game, int i, int w)
{
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.camera_x = 2 * i / (double)w - 1;
	game->ray.ray_dir_x = \
	game->player.dir_x + game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = \
	game->player.dir_y + game->player.plane_y * game->ray.camera_x;
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

void	calculate_step(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = \
		(game->player.pos_x - game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = \
		(game->ray.map_x + 1.0 - game->player.pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = \
		(game->player.pos_y - game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = \
		(game->ray.map_y + 1.0 - game->player.pos_y) * game->ray.delta_dist_y;
	}
}

void	hit_wall(t_game	*game)
{
	game->ray.hit = 0;
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.saved_map[game->ray.map_y][game->ray.map_x] > '0')
			game->ray.hit = 1;
	}
}

void	calculate_start_end(t_game *game)
{
	game->ray.draw_start = -game->ray.line_height / 2 + game->window_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + game->window_height / 2;
	if (game->ray.draw_end >= game->window_height)
		game->ray.draw_end = game->window_height - 1;
	if (game->ray.side == 0)
		game->ray.wall_x = \
		game->player.pos_y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->ray.wall_x = \
		game->player.pos_x + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	game->ray.wall_x -= floor((game->ray.wall_x));
	game->ray.tex_x = (int)(IMAGE_WIDTH * game->ray.wall_x);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		game->ray.tex_x = IMAGE_WIDTH - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		game->ray.tex_x = IMAGE_WIDTH - game->ray.tex_x - 1;
	game->ray.step = 1.0 * IMAGE_HEIGHT / game->ray.line_height;
}
