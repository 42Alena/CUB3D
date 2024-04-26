/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:17:51 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/26 11:46:50 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_check_save(t_game *game, int row, int col)
{
	game->player.map_start_dir = game->map.saved_map[row][col];
	game->player.row = row;
	game->player.col = col;
	game->player.pos_x = col;
	game->player.pos_y = row;
	save_player_struct(game);
	if (col > 0 && col < game->map.cols - 1)
	{
		if (game->map.saved_map[row][col - 1] != '0' && \
			game->map.saved_map[row][col - 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		if ((game->map.saved_map[row][col + 1] != '0' && \
			game->map.saved_map[row][col + 1] != '1'))
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.saved_map [row - 1][col] != '0' && \
			game->map.saved_map[row - 1][col] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.saved_map[row + 1][col] != '0' && \
			game->map.saved_map[row + 1][col] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
	}
}

void	save_player_struct(t_game *game)
{
	if (game->player.map_start_dir == 'W' || \
		game->player.map_start_dir == 'E')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
		save_player_dir(game);
	}
	else if (game->player.map_start_dir == 'N' || \
		game->player.map_start_dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
		save_player_dir(game);
	}
}

void	save_player_dir(t_game *game)
{
	if (game->player.map_start_dir == 'W')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->player.map_start_dir == 'E')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
		game->player.plane_y = -0.66;
	}
	else if (game->player.map_start_dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (game->player.map_start_dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
}
