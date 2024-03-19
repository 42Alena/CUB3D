/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:17:51 by akurmyza          #+#    #+#             */
/*   Updated: 2024/03/18 11:45:24 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	save_player_pos_dir(t_game *game, char player_dir, int x, int y)
{
	if (player_dir == 'N')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (player_dir == 'S')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (player_dir == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (player_dir == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	game->player.pos_x = x;
	game->player.pos_y = y;
}

void	save_player_struct(t_game *game, char player_dir, int x, int y)
{
	if (player_dir == 'N' || player_dir == 'S')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
		save_player_pos_dir(game, player_dir, x, y);
	}
	else if (player_dir == 'W' || player_dir == 'E')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
		save_player_pos_dir(game, player_dir, x, y);
	}
}
