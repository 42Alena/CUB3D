/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_save.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurmyza <akurmyza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:17:51 by akurmyza          #+#    #+#             */
/*   Updated: 2024/04/14 11:04:45 by akurmyza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void check_save_player(t_game *game, char c, int x, int y)
{
	printf("player|%c|, x=%d, y= %d\n", c,x, y);
	printf("x-1=|%c|, x+1=|%c|\n",game->map.saved_map[y][x - 1], game->map.saved_map[y][x + 1] );
	printf("y-1=|%c|, y+1=|%c|\n",game->map.saved_map[y - 1][x], game->map.saved_map[y + 1][x] );
	if (game->map.saved_map[y][x - 1] && game->map.saved_map[y][x + 1] &&\
		game->map.saved_map[y - 1][x] && game->map.saved_map[y + 1][x])
	{
		if	(game->map.tmp_line[x - 1] != '0' && game->map.tmp_line[x - 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		if ((game->map.tmp_line[x + 1] != '0' && game->map.tmp_line[x + 1] != '1'))
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.tmp_line[y - 1] != '0' && game->map.tmp_line[y - 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");
		if (game->map.tmp_line[y + 1] != '0' && game->map.tmp_line[y + 1] != '1')
			error_map_exit_game(game, "Map: Player's position is not valid");	
	}
	else
		error_map_exit_game(game, "Map: Player's position is not valid");
	game->player.map_start_dir = c;	
	save_player_struct(game, x, y);
}



void save_player_struct(t_game *game, int x, int y)
{
	if (game->player.map_start_dir == 'N' || game->player.map_start_dir== 'S')
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
		save_player_pos_dir(game, x, y);
	}
	else if (game->player.map_start_dir == 'W' || game->player.map_start_dir == 'E')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
		save_player_pos_dir(game, x, y);
	}
}

void save_player_pos_dir(t_game *game, int x, int y)
{
	if (game->player.map_start_dir == 'N')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->player.map_start_dir == 'S')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->player.map_start_dir == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->player.map_start_dir == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	game->player.pos_x = x;
	game->player.pos_y = y;
}
