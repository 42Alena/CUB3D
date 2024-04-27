/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/27 12:04:04 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotation(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = \
	player->dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
	player->dir_y = \
	old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) \
	- player->plane_y * sin(rot_speed);
	player->plane_y = \
	old_plane_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
	{
		if (!game->is_map)
			game->is_map = TRUE;
		else
			game->is_map = FALSE;
	}
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
}

void	pause_menu(t_game *game)
{
	game->is_settings = TRUE;
	game->textures.settings1->enabled = TRUE;
	game->textures.settings05->enabled = TRUE;
	game->textures.settings2->enabled = TRUE;
	if (game->move_speed == INITIAL_MOVE_SPEED)
		mlx_image_to_window(game->mlx, game->textures.settings1, 0, 0);
	else if (game->move_speed == INITIAL_MOVE_SPEED / 2)
		mlx_image_to_window(game->mlx, game->textures.settings05, 0, 0);
	else if (game->move_speed == INITIAL_MOVE_SPEED * 2)
		mlx_image_to_window(game->mlx, game->textures.settings2, 0, 0);
}

void	key_press(t_game *game, double time)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotation(&game->player, ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotation(&game->player, -ROTATION_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_TAB))
		pause_menu(game);
	else
		wasd(game, time);
}
