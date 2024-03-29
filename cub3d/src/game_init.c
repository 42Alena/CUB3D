/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:02:10 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/28 18:28:49 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map_structure(t_game *game)
{
	game->map.saved_map = NULL;
	game->map.cols = 0;
	game->map.rows = 0;
	game->map.n_texture = 0;
	game->map.s_texture = 0;
	game->map.w_texture = 0;
	game->map.e_texture = 0;
	game->map.floor_color = 0;
	game->map.ceiling_color = 0;
}

void	init_ray_struct(t_game *game)
{
	game->ray.camera_x = 0;
	game->ray.delta_dist_x = 0;
	game->ray.delta_dist_y = 0;
	game->ray.draw_end = 0;
	game->ray.draw_start = 0;
	game->ray.hit = 0;
	game->ray.line_height = 0;
	game->ray.perp_wall_dist = 0;
	game->ray.ray_dir_x = 0;
	game->ray.ray_dir_y = 0;
	game->ray.side = 0;
	game->ray.side_dist_x = 0;
	game->ray.side_dist_y = 0;
	game->ray.step = 0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.tex_num = 0;
	game->ray.tex_x = 0;
	game->ray.wall_x = 0;
	game->ray.z_buffer = malloc(sizeof(double) * (game->window_width + 1));
	if (!game->ray.z_buffer)
		ft_error(game, "Out of memory!");
}

void	init_player_structure(t_game *game)
{
	game->player.count = 0;
	game->player.pos_x = 2.5;
	game->player.pos_y = 1.5;
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
}

void	init_game_struct(t_game *game)
{
	game->window_height = 960;
	game->window_width = 1980;
	init_map_structure(game);
	init_player_structure(game);
	init_ray_struct(game);
	load_textures(game);
	game->textures.image = NULL;
	game->end = FALSE;
	game->is_win = FALSE;
	game->is_menu = TRUE;
	game->is_opened = FALSE;
	game->is_map = FALSE;
	game->is_settings = FALSE;
	game->dead_cursor = FALSE;
	game->move_speed = INITIAL_MOVE_SPEED;
	game->mouse.mouse_x = 0;
	game->mouse.mouse_y = 0;
	game->mlx = \
	mlx_init(game->window_width, game->window_height, "CUB3D", true);
	if (!game->mlx)
		ft_error(game, "Could not initialize MLX");
	load_images(game);
}
