/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:17:51 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 07:51:49 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_save_player(t_game *game, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	// {
	// 	if (game->player.count == 0)
	// 	{
			save_player_struct(game, c, x, y);
	// 		game->player.count += 1;
	// 	}
	// 	else // 		error_map_exit_game(game, "Only one player can be in game");
	// }
	// else
	// 	error_map_exit_game(game, "Set player direction to N,S,E or W");
}

void save_player_pos_dir(t_game *game, char player_dir, int x, int y)
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

void save_player_struct(t_game *game, char player_dir, int x, int y)
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