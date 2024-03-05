/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:01 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/04 22:15:59 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game* game = param;
	if (keydata.key == MLX_KEY_S)
	{
		game->player_y -= game->dir_y * MOVE_SPEED;
		game->player_x -= game->dir_x * MOVE_SPEED;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
	else if (keydata.key == MLX_KEY_W)
	{
		game->player_y += game->dir_y * MOVE_SPEED;
		game->player_x += game->dir_x * MOVE_SPEED;
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
	else if (keydata.key == MLX_KEY_D)
    {
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(-ROTATION_SPEED) - game->dir_y * sin(-ROTATION_SPEED);
		game->dir_y = oldDirX * sin(-ROTATION_SPEED) + game->dir_y * cos(-ROTATION_SPEED);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-ROTATION_SPEED) - game->plane_y * sin(-ROTATION_SPEED);
		game->plane_y = oldPlaneX * sin(-ROTATION_SPEED) + game->plane_y * cos(-ROTATION_SPEED);
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
    else if (keydata.key == MLX_KEY_A)
    {
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(ROTATION_SPEED) - game->dir_y * sin(ROTATION_SPEED);
		game->dir_y = oldDirX * sin(ROTATION_SPEED) + game->dir_y * cos(ROTATION_SPEED);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(ROTATION_SPEED) - game->plane_y * sin(ROTATION_SPEED);
		game->plane_y = oldPlaneX * sin(ROTATION_SPEED) + game->plane_y * cos(ROTATION_SPEED);
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		calculate(game);
	}
}
