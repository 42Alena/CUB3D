/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:32:28 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/05 15:05:22 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void init_game_struct(t_game *game)
{
	for (int x = 0; x < IMAGE_WIDTH; x++)
	{
		for (int y = 0; y < IMAGE_HEIGHT; y++)
		{
			int xorcolor = (x * 256 / IMAGE_WIDTH) ^ (y * 256 / IMAGE_HEIGHT);
			int ycolor = y * 256 / IMAGE_HEIGHT;
			int xycolor = y * 128 / IMAGE_HEIGHT + x * 128 / IMAGE_WIDTH;
			game->texture[0][IMAGE_WIDTH * y + x] = 65536 * 254 * (x != y && x != IMAGE_WIDTH - y);
			game->texture[1][IMAGE_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			game->texture[2][IMAGE_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			game->texture[3][IMAGE_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			game->texture[4][IMAGE_WIDTH * y + x] = 256 * xorcolor; //xor green
			game->texture[5][IMAGE_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			game->texture[6][IMAGE_WIDTH * y + x] = 65536 * ycolor; //red gradient
			game->texture[7][IMAGE_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
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

