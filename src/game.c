/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 14:06:28 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void init_game_struct(t_game *game)
{
	for (int x = 0; x < IMAGE_WIDTH; x++)
	{
		for (int y = 0; y < IMAGE_HEIGHT; y++)
			game->texture[0][IMAGE_WIDTH * y + x] = 65536 * 254 * (x != y && x != IMAGE_WIDTH - y);
	}
	game->player.player_x = 2.5;
	game->player.player_y = 2.5;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->image = NULL;
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error(game, "Could not initialize MLX");
}

