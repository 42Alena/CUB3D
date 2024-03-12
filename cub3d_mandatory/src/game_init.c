/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:02:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/12 18:01:20 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map_structure(t_game *game)
{
	game->map.saved_map = NULL;
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.n_texture = NULL;
	game->map.s_texture = NULL;
	game->map.w_texture = NULL;
	game->map.e_texture = NULL;
	game->map.floor_color = NULL;
	game->map.ceiling_color = NULL;
}
void	init_ray_struct(t_game *game)
{
	game->ray.cameraX = 0;
	game->ray.deltaDistX = 0;
	game->ray.deltaDistY = 0;
	game->ray.draw_end = 0;
	game->ray.draw_start = 0;
	game->ray.hit = 0;
	game->ray.line_height = 0;
	game->ray.perpWallDist = 0;
	game->ray.rayDirX = 0;
	game->ray.rayDirY = 0;
	game->ray.side = 0;
	game->ray.sideDistX = 0;
	game->ray.sideDistY = 0;
	game->ray.step = 0;
	game->ray.stepX = 0;
	game->ray.stepY = 0;
	game->ray.tex_num = 0;
	game->ray.tex_x = 0;
	game->ray.wall_x = 0;
}

void	init_player_structure(t_game *game)
{
	////// version for tests
	game->player.pos_x = 2.5;
	game->player.pos_y = 1.5;
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
	/////////

	//version original
	// game->player.pos_x = 0;
	// game->player.pos_y = 0;
	// game->player.dir_x = 0;
	// game->player.dir_y = 0;
	// game->player.plane_x = 0;
	// game->player.plane_y = 0.66;
}

void	init_game_struct(t_game *game)
{
	game->window_height = 700;
	game->window_width = 1000;
	init_map_structure(game);
	init_player_structure(game);
	init_ray_struct(game);
	load_textures(game);
	game->textures.image = NULL;
	game->mlx = mlx_init(game->window_width, game->window_height, "CUB3D", true);
	if (!game->mlx)
		ft_error(game, "Could not initialize MLX");
}
