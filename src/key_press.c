/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 13:19:07 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game* game = param;
	if (keydata.key == MLX_KEY_S)
	{
		game->player.player_y -= game->player.dir_y * MOVE_SPEED;
		game->player.player_x -= game->player.dir_x * MOVE_SPEED;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		raycasting(game);
	}
	else if (keydata.key == MLX_KEY_W)
	{
		game->player.player_y += game->player.dir_y * MOVE_SPEED;
		game->player.player_x += game->player.dir_x * MOVE_SPEED;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		raycasting(game);
	}
	else if (keydata.key == MLX_KEY_D)
    {
		double oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROTATION_SPEED) - game->player.dir_y * sin(-ROTATION_SPEED);
		game->player.dir_y = oldDirX * sin(-ROTATION_SPEED) + game->player.dir_y * cos(-ROTATION_SPEED);
		double oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-ROTATION_SPEED) - game->player.plane_y * sin(-ROTATION_SPEED);
		game->player.plane_y = oldPlaneX * sin(-ROTATION_SPEED) + game->player.plane_y * cos(-ROTATION_SPEED);
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		raycasting(game);
	}
    else if (keydata.key == MLX_KEY_A)
    {
		double oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROTATION_SPEED) - game->player.dir_y * sin(ROTATION_SPEED);
		game->player.dir_y = oldDirX * sin(ROTATION_SPEED) + game->player.dir_y * cos(ROTATION_SPEED);
		double oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(ROTATION_SPEED) - game->player.plane_y * sin(ROTATION_SPEED);
		game->player.plane_y = oldPlaneX * sin(ROTATION_SPEED) + game->player.plane_y * cos(ROTATION_SPEED);
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		raycasting(game);
	}
}
